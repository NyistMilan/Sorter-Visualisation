#include "sorters/base_sorter.h"
#include "sorters/bubble_sorter.cpp"
#include "sorters/gnome_sorter.cpp"
#include "sorters/selection_sorter.cpp"
#include "sorters/cocktail_sorter.cpp"
#include "columns/column.h"
#include "view/view.h"

#include <cstdlib>
#include <ctime>
#include <memory>

template <typename T>
void sort(std::unique_ptr<BaseSorter<T>>& sorter, int size, View& application){
    if(sorter == nullptr) return;

    Column columns[size];
    Column::setCompares(0);
    Column::setSwaps(0);

    for(int i = 0; i < size; i++)
        columns[i] = Column{rand() % 80, i};

    application.setColumns(columns, size);
    sorter->sort(columns, size, [](Column a, const Column& b){return a <= b;});

    application.waitScreen();
    application.startScreen();
}

int main(int argc, char* argv[]){
    View application(600, 600);
    if(!application.initialize()) return 1;
    application.startScreen();

    SDL_Event event;
    srand(time(0));
    bool running = true;
    int size = 12;

    while(running) {
        std::unique_ptr<BaseSorter<Column>> sorter;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }

            if (event.type == SDL_KEYDOWN) {
                SDL_KeyboardEvent keyEvent = event.key;

                switch (keyEvent.keysym.scancode) {
                    case SDL_SCANCODE_1:
                        sorter = std::make_unique<BubbleSorter<Column>>();
                        break;
                    case SDL_SCANCODE_2:
                        sorter = std::make_unique<CocktailSorter<Column>>();
                        break;
                    case SDL_SCANCODE_3:
                        sorter = std::make_unique<GnomeSorter<Column>>();
                        break;
                    case SDL_SCANCODE_4:
                        sorter = std::make_unique<SelectionSorter<Column>>();
                        break;
                    case SDL_SCANCODE_5:
                        if (size - 1 > 2)
                            size--;
                        break;
                    case SDL_SCANCODE_6:
                        if(size <= 50)
                            size++;
                        break;
                    case SDL_SCANCODE_ESCAPE:
                        running = false;
                        break;
                    default:
                        break;
                }
            }
        }
        sort(sorter, size, application);
    }
    application.exit();
    return 0;
}

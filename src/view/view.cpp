//
// Created by milanyist on 2022.10.30..
//

#include "view.h"

View::View(int width, int height): width{width}, height{height}{}

bool View::initialize(){
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }

    if(TTF_Init() == -1){
        SDL_Log("TTF_Init Error: %s", TTF_GetError());
        SDL_Quit();
        return false;
    }

    window = SDL_CreateWindow("Visual Sorting", 600, 200, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr){
        SDL_Log("SDL_CreateWindow Error: %s", SDL_GetError());
        SDL_Quit();
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr){
        SDL_Log("SDL_CreateRenderer Error: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    font = TTF_OpenFont("fonts/BebasNeue-Regular.ttf", 35);
    if(font == nullptr){
        SDL_Log("Failed to load font: %s", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    return true;
}

void View::startScreen(){
    std::string string = "1 - Bubble Sort\n"
                    "2 - Cocktail Sort\n"
                    "3 - Gnome Sort\n"
                    "4 - Selection Sort\n"
                    "5 - Array--\n"
                    "6 - Array++";
    std::string author = "Made By Milan Konor Nyist";

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    writeToScreen(string, makeRect((int)(width/3.5), (int)(height/3.5), width, height));
    writeToScreen(author, makeRect(130, 550, width, height));
}

void View::waitScreen(){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    std::string end = "Press to end sorting...";
    writeToScreen(end, makeRect(0,  90, width, height));

    SDL_Event event;
    bool isPressed = false;

    while(!isPressed){
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_KEYDOWN){
                isPressed = true;
            }
        }
    }
}

void View::writeToScreen(std::string& string, SDL_Rect rectangle){
    SDL_Color textColor = {0, 0, 0, 255};
    textSurface = TTF_RenderText_Blended_Wrapped(font, string.c_str(), textColor, width);
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    SDL_FreeSurface(textSurface);
    SDL_QueryTexture(textTexture, nullptr, nullptr, &rectangle.w, &rectangle.h);
    SDL_RenderCopy(renderer,textTexture, nullptr, &rectangle);
    SDL_RenderPresent(renderer);
}

void View::exit(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    SDL_Quit();
}

void View::drawColumn(size_t index, SDL_Color color){
    const int MAX_VALUE = 80;
    int x = width / size * index + 5;
    int y = height - (height / (MAX_VALUE + 1)) * (columns[index].getValue() + 1);
    int w = width / size - 10;
    int h = (height / (1 + MAX_VALUE)) * (columns[index].getValue() + 1);
    SDL_Rect columnRectangle = makeRect(x, y, w, h);

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer,&columnRectangle);
}

bool View::renderScreen(int a = -1, int b = -1, bool isSwapping = false){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    for(int i = 0; i < size; i++){
        SDL_Color color;
        if(a == i || b == i){
            if(isSwapping){
                color = {0, 255, 0, 0};
            }else{
                color = {255, 255, 0, 0};
            }
        }else{
            color = {0, 0, 0, 255};
        }
        drawColumn(i, color);
    }
    int compares = Column::getCompares();
    int swaps = Column::getSwaps();

    std::stringstream stream;
    stream << "Compares:" << compares << "\nSwaps:" << swaps;
    std::string string = stream.str();
    writeToScreen(string, makeRect(0, 0, width, height));

    SDL_RenderPresent(renderer);
    SDL_Delay(delay);
    return true;
}

void View::setColumns(Column* col, size_t size){
    columns = col;
    this->size = size;

    for(int i = 0; i < size; i++){
        columns[i].setListener(this);
    }
}

void View::compare(int a, int b, bool swap){
    renderScreen(a, b, swap);
}

SDL_Rect View::makeRect(int x, int y, int w, int h){
    SDL_Rect rectangle;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = w;
    rectangle.h = h;
    return rectangle;
}

View::~View() = default;

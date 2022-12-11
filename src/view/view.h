//
// Created by milanyist on 2022.10.30..
//

#ifndef CPP_HF2_VIEW_H
#define CPP_HF2_VIEW_H

#include "../columns/column.h"
#include "column_listener.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <string>
#include <iomanip>

class View : public ColumnListener{
    SDL_Texture* textTexture;
    SDL_Surface* textSurface;
    SDL_Renderer* renderer;
    const int delay = 10;
    SDL_Window* window;
    Column* columns;
    TTF_Font* font;
    size_t size;
    int height;
    int width;

    void drawColumn(size_t index, SDL_Color color);
    void writeToScreen(std::string& string, SDL_Rect writeToScreen);
public:
    View(int width, int height);
    static SDL_Rect makeRect(int x, int y, int w, int h);
    bool renderScreen(int a, int b, bool isSwapping);
    void compare(int a, int b, bool swap) override;
    void setColumns(Column* col, size_t size);
    void startScreen();
    bool initialize();
    void waitScreen();
    void exit();
    ~View();
};

#endif //CPP_HF2_VIEW_H

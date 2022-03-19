#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class board
{
private:
    int boardState[9] = {0}; // -1 = X, 0 = non, 1 = O
public:
    board();
    ~board();

    // Functions
    void update();
    void render(SDL_Renderer* renderer);
    void clean();
};



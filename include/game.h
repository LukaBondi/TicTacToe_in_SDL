#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class game
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool running;

public:
    game(const char* wName, int w, int h, Uint32 flags);
    ~game();

    //Getters
    bool isRunning();

    // Functions
    void handleEvents();
    void update();
    void render();
    void clean();
};

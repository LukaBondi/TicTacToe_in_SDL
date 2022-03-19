#include "board.h"

board::board() {}
board::~board() {}

void board::update()
{

}

void board::render(SDL_Renderer* renderer)
{
    std::cout << "Rendering board contents\n";
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer, 109, 30, 109, 329); // Vertical line 1
    SDL_RenderDrawLine(renderer, 209, 30, 209, 329); // Vertical line 2
    SDL_RenderDrawLine(renderer, 10, 129, 319, 129); // Horizontal line 1
    SDL_RenderDrawLine(renderer, 10 , 229, 319, 229); // Horizontal line 2
}

void board::clean()
{

}
#include "board.h"

board::board() 
{
    winStates = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6},
    };
    boardState.assign(9, 'N');
}
board::~board() {}

char board::winCheck() const 
{
    char a, b, c;
    bool draw = true;
    for(auto state : winStates)
    {
        a = boardState[state[0]];
        b = boardState[state[1]];
        c = boardState[state[2]];
        if(a != 'N' && a == b && a == c) { return a; }
        else if (a == 'N' || b == 'N' || c == 'N') { draw = false; }
    }
    return draw ? 'd' : 'n';
}

void board::update()
{
    xTurn = !xTurn;
    winner = winCheck();
}

void board::render(SDL_Renderer* renderer)
{
    // Rendering the XO table
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer, 109, 30, 109, 329); // Vertical line 1
    SDL_RenderDrawLine(renderer, 209, 30, 209, 329); // Vertical line 2
    SDL_RenderDrawLine(renderer, 10, 129, 319, 129); // Horizontal line 1
    SDL_RenderDrawLine(renderer, 10 , 229, 319, 229); // Horizontal line 2

    // Rendering the XO components
    //~~~~~~~//
}

void board::clean()
{

}
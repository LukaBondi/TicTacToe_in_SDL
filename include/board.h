#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

class board
{
private:
    bool xTurn = true; // When true, it is X's turn.
    char winner = 'n';
    std::vector<std::vector<int8_t>> winStates;
    std::vector<char> boardState; // X, O, N

    char winCheck() const;
    
public:
    board();
    ~board();

    // Functions
    void update();
    void render(SDL_Renderer* renderer);
    void clean();
};



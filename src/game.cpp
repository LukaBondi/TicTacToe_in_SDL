#include "game.h"
#include "board.h"

game::game(const char* wName, int w, int h, Uint32 flags) 
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL init success\n";
        window = SDL_CreateWindow(
            wName, // Window name
            SDL_WINDOWPOS_UNDEFINED, // Initial x position
            SDL_WINDOWPOS_UNDEFINED, // Initial y position
            w, h, flags // Width, Height & Flags.
            );
        if(window != 0)
        {
            std::cout << "Window creation success\n";
            renderer = SDL_CreateRenderer(window, -1, 0);
            if(renderer != 0)
            {
                std::cout << "Renderer creation success\n";
                std::cout << "Initiation success\n";
                running = true;
            }
            else
            {
                std::cout << "Renderer init failed\n";
                running = false;
            }
        }    
        else
        {
            std::cout << "Window init failed\n";
            running = false;
        }
    }
    else
    {
        std::cout << "SDL init failed\n";
        running = false;
    }

    if(running) 
    {
        // Start loading the game contents if SDL
        // successfully initializes the its components
        std::cout << "Initializing game contents\n";
        gameBoard = new board();
    }
}

game::~game() 
{
    std::cout << "Bye!" << std::endl;
}

bool game::isRunning() { return running; }

void game::handleEvents() 
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                running = false;
                break;
            default:
                break;
        }
    }
}

void game::update() 
{

}

void game::render() 
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    gameBoard->render(renderer);
    SDL_RenderPresent(renderer);
}

void game::clean() 
{
    std::cout << "Cleaning up game\n";
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
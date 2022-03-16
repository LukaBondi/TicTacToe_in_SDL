#include "game.h"

int main(int argc, char* argv[]) 
{
    game *mGame = new game("Window", 640, 360, 0);
    while(mGame->isRunning())
    {
        mGame->handleEvents();
        mGame->update();
        mGame->render();
    }
    mGame->clean();
    return 0;
}

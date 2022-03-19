#include "game.h"

int main(int argc, char* argv[]) 
{
    game* theGame = new game("Window", 640, 360, 0);
    while(theGame->isRunning())
    {
        theGame->handleEvents();
        theGame->update();
        theGame->render();
    }
    theGame->clean();
    delete theGame;
    return 0;
}

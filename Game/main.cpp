#include"GameLoop.h"
GameLoop* g = new GameLoop();

int main(int argc, char** argv)
{
    double first;
    double last = 0;
    g->Initialize();
    while ( g->getGameState())
    {
        g->Render();
        g->Event();
        g->Update();
        first = SDL_GetTicks();
        if (first - last < 16.7)
        {
            SDL_Delay(16.7 - (first - last));
            std::cout << 1000/(16.7 - (first - last)) + first - last << std::endl;
        }
       
        last = first;
    }
    g->Clear();
    return 0;
}
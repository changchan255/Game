#include"GameLoop.h"

GameLoop::GameLoop()
{
    window = NULL;
    renderer = NULL;
    GameState = 0;
    //Source Dimension
    p.setSource(0, 0, 68, 48);
    //Destination Dimension
    p.setDest(10, 200, 68, 48);
}

bool GameLoop::getGameState()
{
    return GameState;
}

void GameLoop::Initialize()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
    if (window)
    {
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            cout << "Succeeded!" << endl;
            GameState = true;
            p.CreateTexture("Image/chim.png", renderer);
            b.CreateTexture("Image/background.png", renderer);
        }
        else
        {
            cout << "Not created!" << endl;
        }
    }
    else
    {
        cout << "Window not created!" << endl;
    }
}

void GameLoop::Event()
{
    SDL_PollEvent(&event1);
    if (event1.type == SDL_QUIT)
    {
        GameState = false;
    }
    if (event1.type == SDL_KEYDOWN)
    {
        if (event1.key.keysym.sym == SDLK_UP)
        {
            cout << "pressed" << endl;
        }
    }
    
}
void GameLoop::Update()
{
    p.Update();
}

void GameLoop::Render()
{
    SDL_RenderClear(renderer);
    b.Render(renderer);
    p.Render(renderer);
    SDL_RenderPresent(renderer);

}

void GameLoop::Clear()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
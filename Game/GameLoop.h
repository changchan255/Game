#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "TextureManager.h"
#include "Object.h"
#include "Player.h"
#include "Background.h"
using namespace std;

class GameLoop
{
private:
    Player p;
    Background b;
    const int HEIGHT = 640;
    const int WIDTH = 800;
    bool GameState;
    SDL_Window* window;
    SDL_Event event1;
    SDL_Renderer* renderer;
    SDL_Texture* player;
    SDL_Texture* background;
  
public:
    GameLoop();
    bool getGameState();
    void Update();
    void Initialize();
    void Event();
    void Render();
    void Clear();
};

#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>
#include "TextureManager.h"
#include "Object.h"
#include "Player.h"
#include "Background.h"
#include "Base.h"
#include "Pipe.h"
#include "CollisionManager.h"
#include "MainMenu.h"
#include "GameOver.h"
#include "TextManager.h"
using namespace std;

class GameLoop
{
private:
    Player p;
    Background b;
    Base base1, base2;
    Pipe pipeA1, pipeA2, pipeA3;
    Pipe pipeB1, pipeB2, pipeB3;
    MainMenu mainmenu;
    GameOver gameover;
    TextManager score;

    const int HEIGHT = 720;
    const int WIDTH = 540;
    bool GameState;
    SDL_Window* window;
    SDL_Event event;
    SDL_Renderer* renderer;
    SDL_Texture* player;
    SDL_Texture* background;

    int points = 0;
    int var1 = rand() % 201 - 100;
    int var2 = rand() % 201 - 100;
    int var3 = rand() % 201 - 100;

    bool touchBase = false;
    bool playing = false;
    bool isDead = false;
    bool checkDie = true;

    int tableYpos = 600;
    double speed = 0;
    double a = 0.3;
  
public:
    GameLoop();
    void MainMenu();
    bool getGameState();
    void NewGame();
    void Update();
    void CollisionDetection();
    void Die();
    void Reset();
    void Initialize();
    void Event();
    void Render();
    void Clear();
};

#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>
#include <fstream>
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
#include "Mouse.h"
#include "Button.h"

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
    GameOver replay;
    TextManager s, s_outline;
    TextManager hs, hs_outline;

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
    bool checkScore = false;
    bool isPressed = false;

    int tableYpos = 600;
    double speed = 0;
    double a = 0.3;

    TTF_Font* scoreFont;
    TTF_Font* scoreOutline;
    TTF_Font* hsOutline;
    
    int textWidth = 35;
    int textHeight = 50;
    int fontSize = 32;
    unsigned int highscore;
    unsigned int score = 0;
    unsigned int SCORE = 0;

    SDL_Color white = { 250, 250, 250 };
    SDL_Color brown = { 94, 54, 67 };

    Mouse* m = new Mouse;
    enum ButtonNames { REPLAY, EXIT };
    Button* button[2];
    SDL_Texture* buttonTex;

public:
    GameLoop();
    ~GameLoop();
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

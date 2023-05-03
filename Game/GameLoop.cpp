#include"GameLoop.h"

GameLoop::GameLoop()
{
    window = NULL;
    renderer = NULL;
    GameState = false;
    //Source Dimension
    p.setSource(0, 0, 34, 24);
    //Destination Dimension
    p.setDest(25, HEIGHT/2, 34, 24);

    base1.setSource(0, 0, 350, 140);
    base1.setDest(0, 600, 720, 120);
    base2.setSource(0, 0, 350, 140);
    base2.setDest(0, 600, 720, 120);
    pipeA1.setSource(0, 0, 65, 373);
    pipeA1.setDest(400, -200, 65, 400);
    pipeB1.setSource(0, 0, 65, 373);
    pipeB1.setDest(400, 350, 65, 400);
    pipeA2.setSource(0, 0, 65, 373);
    pipeA2.setDest(400, -200, 65, 373);
    pipeB2.setSource(0, 0, 65, 320);
    pipeB2.setDest(400, 350, 65, 400);
    pipeA3.setSource(0, 0, 65, 373);
    pipeA3.setDest(400, -200, 65, 400);
    pipeB3.setSource(0, 0, 65, 373);
    pipeB3.setDest(400, 350, 65, 400);
    gameover.setSource(0, 0, 250, 209);
}

bool GameLoop::getGameState()
{
    return GameState;
}

void GameLoop::Initialize()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window)
    {
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            cout << "Succeeded!" << endl;
            GameState = true;
            p.CreateTexture("Image/chim1.png", renderer);
            p.CreateTexture1("Image/chim2.png", renderer);
            p.CreateTexture2("Image/chim3.png", renderer);
            b.CreateTexture("Image/background.png", renderer);
            base1.CreateTexture("Image/land.png", renderer);
            base2.CreateTexture("Image/land.png", renderer);
            pipeA1.CreateTexture("Image/pipe_Above.png", renderer);
            pipeA2.CreateTexture("Image/pipe_Above.png", renderer);
            pipeA3.CreateTexture("Image/pipe_Above.png", renderer);
            pipeB1.CreateTexture("Image/pipe_Below.png", renderer);
            pipeB2.CreateTexture("Image/pipe_Below.png", renderer);
            pipeB3.CreateTexture("Image/pipe_Below.png", renderer);
            gameover.CreateTexture("Image/gameOver.png", renderer);
            score.CreateFont("Font/font.ttf", 16);

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

void GameLoop::MainMenu()
{
    mainmenu.Initialize(renderer);
    while (!mainmenu.getClicked())
    {
        if (mainmenu.EventHandling(event) == -1)
        {
            GameState = false;
            break;
        }
        SDL_RenderClear(renderer);
        mainmenu.MenuRender(renderer);
        SDL_RenderPresent(renderer);
    }
}



void GameLoop::Event()
{
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT)
    {
        GameState = false;
    }
    else if (event.key.keysym.sym == SDLK_SPACE)
    {
        if (!p.JumpState() && !isDead)
        {
            p.Jump();
        }
        if(!isDead)
        {
            playing = true;
            isDead = false;
            touchBase = false;
        }
    }
    else
    {
        Update();
        CollisionDetection();
    }
    
    
}
void GameLoop::Update()
{
    p.Gravity(touchBase, playing);
    
    std::string s;
    s = "Score" + std::to_string(points);
    score.Text(s, 255, 255, 255, renderer);

    bool flag1 = false, flag2 = false;
    flag1 = pipeA1.PipeA1_Update(var1, points);
    flag2 = pipeB1.PipeB1_Update(var1);
    if (flag1 && flag2)
    {
        srand(SDL_GetTicks());
        var1 = rand() % 201 - 100;
        pipeA1.PipeA1_Update(var1, points);
        pipeB1.PipeB1_Update(var1);
    }

    flag1 = pipeA2.PipeA2_Update(var1, points);
    flag2 = pipeB2.PipeB2_Update(var1);
    if (flag1 && flag2)
    {
        srand(SDL_GetTicks());
        var2 = rand() % 201 - 100;
        pipeA2.PipeA2_Update(var1, points);
        pipeB2.PipeB2_Update(var1);
    }

    flag1 = pipeA3.PipeA3_Update(var1, points);
    flag2 = pipeB3.PipeB3_Update(var1);
    if (flag1 && flag2)
    {
        srand(SDL_GetTicks());
        var3 = rand() % 201 - 100;
        pipeA3.PipeA3_Update(var1, points);
        pipeB3.PipeB3_Update(var1);
    }

    base1.BaseUpdate1(isDead);
    base2.BaseUpdate1(isDead);
    CollisionDetection();
   
}

void GameLoop::CollisionDetection()
{
    if (CollisionManager::IsCollide(&p.getDest(), &pipeA1.getDest()) || CollisionManager::IsCollide(&p.getDest(), &pipeB1.getDest()) || CollisionManager::IsCollide(&p.getDest(), &pipeA2.getDest()) ||
        CollisionManager::IsCollide(&p.getDest(), &pipeB2.getDest()) || CollisionManager::IsCollide(&p.getDest(), &pipeA3.getDest()) || CollisionManager::IsCollide(&p.getDest(), &pipeB3.getDest()))
    {
        isDead = true;
    }

    if (CollisionManager::IsCollide(&p.getDest(), &base1.getDest()) || CollisionManager::IsCollide(&p.getDest(), &base2.getDest()) || p.GetYpos() < 0)
    {
        isDead = true;
        touchBase = true;
    }
}

void GameLoop::Die()
{
    if (isDead)
    {
        SDL_Delay(500);
     
        while (tableYpos > (HEIGHT - 282) / 3)
        {
            tableYpos -= speed / 5;
            speed += a;
            gameover.setDest((WIDTH - 250)/2, tableYpos, 250, 209);
            Render();
        }
        
        
    }
}

void GameLoop::Reset()
{
     points = 0;
     var1 = rand() % 201 - 100;
     var2 = rand() % 201 - 100;
     var3 = rand() % 201 - 100;
     p.Reset();
     pipeA1.Reset();
     pipeB1.Reset();
     pipeA2.Reset();
     pipeB2.Reset();
     pipeA3.Reset();
     pipeB3.Reset();
}

void GameLoop::Render()
{
    SDL_RenderClear(renderer);
    b.Render(renderer);
    pipeA1.PipeRender(renderer);
    pipeB1.PipeRender(renderer);
    pipeA2.PipeRender(renderer);
    pipeB2.PipeRender(renderer);
    pipeA3.PipeRender(renderer);
    pipeB3.PipeRender(renderer);
    score.Render(renderer, 270, 10);
    p.Render(renderer);
    base1.BaseRender(renderer);
    base2.BaseRender(renderer);
    
    if (isDead)
    {
        gameover.Render(renderer, 0);
    }

    SDL_RenderPresent(renderer);

    

}

void GameLoop::Clear()
{
    score.CloseFont();
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

}
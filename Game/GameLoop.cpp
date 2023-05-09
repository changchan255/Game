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

    base1.setSource(0, 0, 720, 120);
    base2.setSource(0, 0, 720, 120);
    
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
    gameover.setSource(0, 0, 444, 282);
    replay.setSource(0, 0, 100, 56);
    s.setSource(0, 0, NULL, NULL);
    s_outline.setSource(0, 0, NULL, NULL);
    hs.setSource(0, 0, NULL, NULL);
    hs_outline.setSource(0, 0, NULL, NULL);

   
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
            replay.CreateTexture("Image/replay.png", renderer);

           

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

    if (TTF_Init() < 0)
    {
        cout << "Text could not initialize! Text_Error: " << TTF_GetError() << endl;
        Clear();
    }
    else
    {
        scoreFont = TTF_OpenFont("Font/font.ttf", fontSize);
        scoreOutline = TTF_OpenFont("Font/font.ttf", fontSize);
        TTF_SetFontOutline(scoreOutline, 10);
        hsOutline = TTF_OpenFont("Font/font.ttf", fontSize);
        TTF_SetFontOutline(hsOutline, 10);
    }

    ifstream file("Highscore.txt");
    if (!file.is_open())
    {
        cout << "Unable to open highscore file!";
        Clear();
    }
    else
    {
        file.close();
    }

    if (Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG) < 0)
    {
        cout << "Sound could not initialize! Mix_Error: " << Mix_GetError() << endl;
        Clear();
    }
    else if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) < 0) 
    {
        cout << "Sound could not initialize! Mix_Error: " << Mix_GetError() << endl;
        Clear();
    }
    else
    {
        
        ingamesound = Mix_LoadMUS("Sound/ingame.mp3");
        clickSound = Mix_LoadWAV("Sound/mouse_click.wav");
        wingSound = Mix_LoadWAV("Sound/sfx_wing.wav");
        pointSound = Mix_LoadWAV("Sound/sfx_point.wav");
        hitSound = Mix_LoadMUS("Sound/sfx_hit.wav");
        dieSound = Mix_LoadMUS("Sound/sfx_die.wav");
        swooshingSound = Mix_LoadMUS("Sound/sfx_swooshing.wav");
        
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
        if (mainmenu.EventHandling(event) == 0)
        {
           
            if (mainmenu.getPlayed())
            {
                Mix_VolumeMusic(10);
            }
            else
            {
                Mix_VolumeMusic(0);
            }
        }
        SDL_RenderClear(renderer);
        mainmenu.MenuRender(renderer);
        mainmenu.SoundRender(renderer);
        SDL_RenderPresent(renderer);
    }
    if (mainmenu.getClicked())
    {
        Mix_HaltMusic();
        Mix_PlayMusic(ingamesound, -1);
    }
    
}

void GameLoop::NewGame()
{ 
    if ( checkDie && isPressed)
    {
        Mix_PlayMusic(ingamesound, -1);
        Reset();
        p.Gravity(touchBase, false);
        score = 0;
        SCORE = 0;
        isPressed = false;
        touchBase = true;
        playing = false;
        isDead = false;
        checkDie = false;
        checkScore = false;
        tableYpos = 600;
        speed = 0;
        a = 0.3;
        gameover.setDest(0, 0, NULL, NULL);
        s.setDest(73, 13, textWidth, textHeight);
        s_outline.setDest(73, 13, textWidth - 3, textHeight);
    }

}

void GameLoop::Event()
{
    SDL_PollEvent(&event);
    switch (event.type)
    {
        if (isDead)
        { 
    

    case SDL_MOUSEBUTTONDOWN:
    {
        Mix_VolumeChunk(clickSound, 10);
        Mix_PlayChannel(1, clickSound, 0);
        if (event.motion.x > 220 && event.motion.x < 320 && event.motion.y > 440 && event.motion.y < 496)
        {
            
            isPressed = true;
             NewGame();
            
        }
        break;
    }
        }
        else
        {
    case SDL_KEYDOWN:
    {
        if (event.key.keysym.sym == SDLK_SPACE)
        {
            if (!p.JumpState() && !isDead)
            {
                p.Jump();
                Mix_VolumeChunk(wingSound, 20);
                Mix_PlayChannel(1, wingSound, 0);
            }
            if (!checkDie)
            {
                playing = true;
                isDead = false;
                touchBase = false;
            }
        }
        break;
    }
    case SDL_QUIT:
    {
        GameState = false;
        break;
    }
        }
    default:

    {
        Update();
        CollisionDetection();
        if (checkScore && !isDead)
        {
           
            s.setDest(73, 13, textWidth, textHeight);
            s_outline.setDest(73, 13, textWidth - 3, textHeight);
            score++;
            SCORE = score;
            
                Mix_VolumeChunk(pointSound, 15);
                Mix_PlayChannel(2, pointSound, 0);
                if (SCORE >= 10)
                {
                    s.setDest(70, 13, textWidth * 2, textHeight);
                    s_outline.setDest(70, 13, textWidth * 2 - 6, textHeight);
                }
                if (SCORE >= 100)
                {
                    s.setDest(70, 13, textWidth * 3, textHeight);
                    s_outline.setDest(70, 13, textWidth * 3 - 4, textHeight);
                }
            
            checkScore = false;
        }
        break;
    }
   
    }
}
   
void GameLoop::Update()
{
    p.Gravity(touchBase, playing);
    
    bool flag1 = false, flag2 = false;
    flag1 = pipeA1.PipeA1_Update(var1, isDead);
    flag2 = pipeB1.PipeB1_Update(var1, isDead);
    if (flag1 && flag2)
    {
        srand(SDL_GetTicks());
        var1 = rand() % 201 - 100;
        pipeA1.PipeA1_Update(var1, isDead);
        pipeB1.PipeB1_Update(var1, isDead);
        checkScore = true;
    }

    flag1 = pipeA2.PipeA2_Update(var2, isDead);
    flag2 = pipeB2.PipeB2_Update(var2, isDead);
    if (flag1 && flag2)
    {
        srand(SDL_GetTicks());
        var2 = rand() % 201 - 100;
        pipeA2.PipeA2_Update(var2, isDead);
        pipeB2.PipeB2_Update(var2, isDead);
        checkScore = true;
    }

    flag1 = pipeA3.PipeA3_Update(var3, isDead);
    flag2 = pipeB3.PipeB3_Update(var3, isDead);
    if (flag1 && flag2)
    {
        srand(SDL_GetTicks());
        var3 = rand() % 201 - 100;
        pipeA3.PipeA3_Update(var3, isDead);
        pipeB3.PipeB3_Update(var3, isDead);
        checkScore = true;
    }

    base1.BaseUpdate1(isDead);
    base2.BaseUpdate2(isDead);

    s.WriteText(std::to_string(score), scoreFont, brown, renderer);
    s_outline.WriteText(std::to_string(score), scoreOutline, white, renderer);
   
  
   
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
    if (isDead && !checkDie)
    {
        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
        Mix_VolumeMusic(20);
        Mix_PlayMusic(hitSound, 0);
        SDL_Delay(500);
        Mix_PlayMusic(dieSound, 0);
        
     
        while (tableYpos > (HEIGHT - 282) / 3)
        {
            s.setDest(0, 0, NULL, NULL);
            s_outline.setDest(0, 0, NULL, NULL);

            tableYpos -= speed / 5;
            speed += a;
            gameover.setDest((WIDTH - 444)/2, tableYpos, 438, 290);
            replay.setDest((WIDTH - 100) / 2, 440, 100, 56);
            Render();
        }
        
        ifstream read("HighScore.txt");
        read >> highscore;
        read.close();
        if (SCORE > highscore)
        {
            highscore = SCORE;
        
           

            ofstream file("HighScore.txt");
            file << SCORE;
            file.close();
        }
        textWidth = 47;
        textHeight = 67;
        if (SCORE >= 100)
        {
            s.setDest(120, 255, textWidth * 3, textHeight);
            s_outline.setDest(120, 255, textWidth * 3 - 5, textHeight);
        }
        else if (SCORE >= 10)
        {
            s.setDest(145, 255, textWidth * 2, textHeight);
            s_outline.setDest(145, 255, textWidth * 2 - 5, textHeight);
        }
        else
        {
            s.setDest(170, 255, textWidth, textHeight);
            s_outline.setDest(170, 255, textWidth - 5, textHeight);
        }

        textWidth /= 1.55;
        textHeight /= 1.55;
        if (highscore >= 100)
        {
            hs.setDest(323, 235, textWidth * 3, textHeight);
            hs_outline.setDest(323, 235, textWidth * 3 - 5, textHeight);
        }
        else if (highscore >= 10)
        {
            hs.setDest(340, 235, textWidth * 2, textHeight);
            hs_outline.setDest(340, 235, textWidth * 2 - 3, textHeight);
        }
        else
        {
            hs.setDest(353, 235, textWidth, textHeight);
            hs_outline.setDest(353, 235, textWidth - 3, textHeight);
        }
        hs.WriteText(to_string(highscore), scoreFont, brown, renderer);
        hs_outline.WriteText(to_string(highscore), hsOutline, white, renderer);

        checkDie = true;
    }
    
}

void GameLoop::Reset()
{
     
     var1 = rand() % 201 - 100;
     var2 = rand() % 201 - 100;
     var3 = rand() % 201 - 100;
    
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
    p.Render(renderer);
    base1.BaseRender(renderer);
    base2.BaseRender(renderer);
    
    if (isDead)
    {
        
        gameover.Render(renderer, 0);
        replay.Render(renderer, 0);
        s_outline.Render(renderer);
        s.Render(renderer);
        hs_outline.Render(renderer);
        hs.Render(renderer);

       
    }
    if(!isDead)
    {
        s_outline.Render(renderer);
        s.Render(renderer);
    }

    SDL_RenderPresent(renderer);

    

}

void GameLoop::Clear()
{
    
    TTF_Quit();
    Mix_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    

}
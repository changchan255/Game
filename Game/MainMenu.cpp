#include "MainMenu.h"

MainMenu::MainMenu()
{
	isClicked = false;
	isPlay = true;
	soundOn.setSource(0, 0, 32, 24);
	soundOn.setDest(450, 575, 32, 24);
	soundOff.setSource(0, 24, 32, 24);
	soundOff.setDest(450, 575, 32, 24);
}

void MainMenu::Initialize(SDL_Renderer* ren)
{
	MenuBg.CreateTexture("Image/MainMenu.png", ren);
	soundOn.CreateTexture("Image/sound.png", ren);
	soundOff.CreateTexture("Image/sound.png", ren);
	backgroundsound = Mix_LoadMUS("Sound/bg.mp3");
	Mix_PlayMusic(backgroundsound, -1);
}

int MainMenu::EventHandling(SDL_Event& e)
{
	SDL_PollEvent(&e);
	if (e.type == SDL_QUIT)
	{
		return -1;
	}
	else if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > 196 && e.motion.x < 344 && e.motion.y > 575 && e.motion.y < 627)
	{
		isClicked = true;
	}
	else if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > 450 && e.motion.x < 482 && e.motion.y > 575 && e.motion.y < 627)
	{
	
		isPlay = !isPlay;
	
	}
	return 0;
}

void MainMenu::MenuRender(SDL_Renderer* ren)
{
	MenuBg.Render(ren);
}

void MainMenu::SoundRender(SDL_Renderer* ren)
{
	if (isPlay)
	{
		soundOn.SoundRender(ren);
	}
	else
	{
		soundOff.SoundRender(ren);
	}
}

bool MainMenu::getClicked()
{
	return isClicked;
}

bool MainMenu::getPlayed()
{
	return isPlay;
}

MainMenu::~MainMenu()
{
	isClicked = false;
	
}
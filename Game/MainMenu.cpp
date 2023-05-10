#include "MainMenu.h"

MainMenu::MainMenu()
{
	isClicked = false;
	isPlay = true;
	soundOn.setSource(0, 0, 32, 24);
	soundOn.setDest(415, 500, 60, 48);
	soundOff.setSource(0, 24, 32, 24);
	soundOff.setDest(415, 500, 60, 48);
}

void MainMenu::Initialize(SDL_Renderer* ren)
{
	MenuBg.CreateTexture("Image/main.png", ren);
	soundOn.CreateTexture("Image/sound.png", ren);
	soundOff.CreateTexture("Image/sound.png", ren);
	backgroundsound = Mix_LoadMUS("Sound/cupid.mp3");
	Mix_PlayMusic(backgroundsound, -1);
}

int MainMenu::EventHandling(SDL_Event& e)
{
	SDL_PollEvent(&e);
	if (e.type == SDL_QUIT)
	{
		return -1;
	}
	else if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > 180 && e.motion.x < 360 && e.motion.y > 500 && e.motion.y < 552)
	{
		isClicked = true;
	}
	else if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > 415 && e.motion.x < 479 && e.motion.y > 500 && e.motion.y < 548)
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
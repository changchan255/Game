#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "Background.h"

class MainMenu
{
private:
	bool isClicked, isPlay;
	Background MenuBg;
	Background soundOn, soundOff;
	Mix_Music* backgroundsound;
public:
	MainMenu();
	~MainMenu();
	void Initialize(SDL_Renderer* ren);
	int EventHandling(SDL_Event& e);
	void MenuRender(SDL_Renderer* ren);
	void SoundRender(SDL_Renderer* ren);
	bool getClicked();
	bool getPlayed();

};

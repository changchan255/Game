#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Background.h"

class MainMenu
{
private:
	bool isClicked;
	Background MenuBg;
public:
	MainMenu();
	~MainMenu();
	void Initialize(SDL_Renderer* ren);
	int EventHandling(SDL_Event& e);
	void MenuRender(SDL_Renderer* ren);
	bool getClicked();

};

#include "MainMenu.h"

MainMenu::MainMenu()
{
	isClicked = false;
}

void MainMenu::Initialize(SDL_Renderer* ren)
{
	MenuBg.CreateTexture("Image/MainMenu.png", ren);
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
	return 0;
}

void MainMenu::MenuRender(SDL_Renderer* ren)
{
	MenuBg.Render(ren);
}

bool MainMenu::getClicked()
{
	return isClicked;
}

MainMenu::~MainMenu()
{
	isClicked = false;
}
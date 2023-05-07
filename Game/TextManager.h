#pragma once
#include <SDL_ttf.h>
#include <string>
#include <iostream>
#include "Object.h"

class TextManager :public Object
{
private:
	SDL_Texture* texture;
	SDL_Surface* textSurface;
public:
	TextManager();
	~TextManager();

	TTF_Font* font;

	SDL_Texture* getTextTexture();
	void WriteText(std::string text, TTF_Font* textFont, SDL_Color color, SDL_Renderer* ren);
	void Render(SDL_Renderer* ren);
};

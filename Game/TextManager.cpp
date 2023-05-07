#include "TextManager.h"

TextManager::TextManager()
{
	textSurface = NULL;
	
}

TextManager::~TextManager()
{
	TTF_CloseFont(font);
	font = NULL;
}

SDL_Texture* TextManager::getTextTexture()
{
	return texture;
}

void TextManager::WriteText(std::string text, TTF_Font* textFont, SDL_Color color, SDL_Renderer* ren)
{
	if (texture != NULL)
	{
		SDL_DestroyTexture(texture);
		texture = NULL;
		font = NULL;
	}

	font = textFont;
	if (font == NULL)
	{
		std::cout << "Unable to open font! Error: " << TTF_GetError() << std::endl;
	}
	else
	{
		textSurface = TTF_RenderText_Solid(font, text.c_str(), color);

		if (textSurface == NULL)
		{
			std::cout << "Unable to load text! Error: " << TTF_GetError() << std::endl;
		}
		else
		{
			texture = SDL_CreateTextureFromSurface(ren, textSurface);
			if (texture == NULL)
			{
				std::cout << "Unable to create texture from rendered text! SDL_ttf Error: " << TTF_GetError() << std::endl;
			}
			else
			{
				TTF_SizeText(font, text.c_str(), &(getSrc().w), &(getSrc().h));
			}
			SDL_FreeSurface(textSurface);
		}
	}
}

void TextManager::Render(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTextTexture(), &getSrc(), &getDest());
}
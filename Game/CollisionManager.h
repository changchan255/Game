#pragma once
#include <SDL.h>
#include <SDL_image.h>

class CollisionManager
{
private:
public:
	static bool IsCollide(SDL_Rect* A, SDL_Rect* B);
};

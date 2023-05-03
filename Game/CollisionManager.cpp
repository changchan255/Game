#include "CollisionManager.h"

bool CollisionManager::IsCollide(SDL_Rect* A, SDL_Rect* B)
{
	SDL_bool Collision = SDL_HasIntersection(A, B);
	if (Collision)
	{
		return true;
	}
	else
	    return false;
}

#pragma once
#include "Object.h"

class GameOver : public Object
{
private:
public:
	void Render(SDL_Renderer* ren, const double angle);
};
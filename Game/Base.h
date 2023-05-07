#pragma once
#include "Object.h"

class Base :public Object
{
private:
	int distance1 = 0;
	int distance2 = 540;

public:
	void BaseUpdate1(bool isDead);
	void BaseUpdate2(bool isDead);
	void BaseRender(SDL_Renderer* ren);
};

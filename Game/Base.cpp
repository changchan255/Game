#include "Base.h"

void Base::BaseRender(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}

void Base::BaseUpdate1(bool isDead)
{
	if (distance1 <= -720)
	{
		distance1 = 0;
	}
	else
	{
		if (!isDead)
		{
			distance1--;
		}
		setSource(0, 0, 350, 140);
		setDest(distance1, 600, 720, 120);
	}
}

void Base::BaseUpdate2(bool isDead)
{
	if (distance2 <= 0)
	{
		distance2 = 7200;
	}
	else
	{
		if (!isDead)
		{
			distance2--;
		}
		setSource(0, 0, 350, 140);
		setDest(distance2, 600, 720, 120);
	}
}
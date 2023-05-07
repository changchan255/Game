#include "Pipe.h"

void Pipe::PipeRender(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}

bool Pipe::PipeA1_Update(int incY)
{
	this->incY1 = incY;
	if (pipeDistance1 <= -100)
	{
		pipeDistance1 += 900;
		return true;
	}
	else
	{
		pipeDistance1 -= 2;
		setSource(0, 0, 65, 373);
		setDest(pipeDistance1, -200 + this->incY1, 65, 400);
		return false;
	}
}

bool Pipe::PipeB1_Update(int incY)
{
	this->incY1 = incY;
	if (pipeDistance1 <= -100)
	{
		pipeDistance1 += 900;
		return true;
	}
	else
	{
		pipeDistance1 -= 2;
		setSource(0, 0, 65, 373);
		setDest(pipeDistance1, 350 + this->incY1, 65, 400);
		return false;
	}
}

bool Pipe::PipeA2_Update(int incY)
{
	this->incY2 = incY;
	if (pipeDistance2 <= -100)
	{
		pipeDistance2 += 900;
		return true;
	}
	else
	{
		pipeDistance2 -= 2;
		setSource(0, 0, 65, 373);
		setDest(pipeDistance2, -200 + this->incY2, 65, 400);
		return false;
	}
}

bool Pipe::PipeB2_Update(int incY)
{
	this->incY2 = incY;
	if (pipeDistance2 <= -100)
	{
		pipeDistance2 += 900;
		return true;
	}
	else
	{
		pipeDistance2 -= 2;
		setSource(0, 0, 65, 373);
		setDest(pipeDistance2, 350 + this->incY2, 65, 400);
		return false;
	}
}

bool Pipe::PipeA3_Update(int incY)
{
	this->incY3 = incY;
	if (pipeDistance3 <= -100)
	{
		pipeDistance3 += 900;
		return true;
	}
	else
	{
		pipeDistance3 -= 2;
		setSource(0, 0, 65, 373);
		setDest(pipeDistance3, -200 + this->incY3, 65, 400);
		return false;
	}
}
bool Pipe::PipeB3_Update(int incY)
{
	this->incY3 = incY;
	if (pipeDistance3 <= -100)
	{
		pipeDistance3 += 900;
		return true;
	}
	else
	{
		pipeDistance3 -= 2;
		setSource(0, 0, 65, 373);
		setDest(pipeDistance3, 350 + this->incY3, 65, 400);
		return false;
	}
}


void Pipe::Reset()
{
	pipeDistance1 = 1000;
	pipeDistance2 = 1300;
	pipeDistance3 = 1600;
	incY1 = 0;
	incY2 = 0;
	incY3 = 0;

}
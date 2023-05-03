#include "Pipe.h"

void Pipe::PipeRender(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}

bool Pipe::PipeA1_Update(int incY, int &score)
{
	this->incY1 = incY;
	if (pipeDistance1 <= -100)
	{
		pipeDistance1 += 900;
		score++;
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
		setDest(pipeDistance1, 350 + this-> incY1, 65, 400);
		return false;
	}
}

bool Pipe::PipeA2_Update(int incY, int &score)
{
	this->incY2 = incY;
	if (pipeDistance2 <= -100)
	{
		pipeDistance2 += 900;
		score++;
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

bool Pipe::PipeA3_Update(int incY, int &score)
{
	this->incY3 = incY;
	if (pipeDistance3 <= -100)
	{
		pipeDistance3 += 900;
		score++;
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

int Pipe::getPipe1X()
{
	return pipeDistance1;
}

int Pipe::getPipe1Y()
{
	return 300 + this->incY1;
}

int Pipe::getPipe2X()
{
	return pipeDistance2;
}

int Pipe::getPipe2Y()
{
	return 300 + this->incY2;
}

int Pipe::getPipe3X()
{
	return pipeDistance3;
}

int Pipe::getPipe3Y()
{
	return 300 + this->incY3;
}

void Pipe::Reset()
{
	int pipeDistance1 = 400; 
	int pipiDistance2 = 700;
	int pipeDistance3 = 1000;
	int incY1 = 0;
	int incY2 = 0; 
	int incY3 = 0;

}
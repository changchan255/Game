#pragma once
#include "Object.h"

class Pipe :public Object
{
private:
	int pipeDistance1 = 1000;
	int pipeDistance2 = 1300;
	int pipeDistance3 = 1600;
	int incY1 = 0;
	int incY2 = 0;
	int incY3 = 0;
public:
	bool PipeA1_Update(int incY);
	bool PipeB1_Update(int incY);
	bool PipeA2_Update(int inc);
	bool PipeB2_Update(int incY);
	bool PipeA3_Update(int incY);
	bool PipeB3_Update(int incY);
	void PipeRender(SDL_Renderer *ren);
	void Reset();
};

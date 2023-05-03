#pragma once
#include "Object.h"

class Pipe :public Object
{
private:
	int pipeDistance1 = 400;
	int pipeDistance2 = 700;
	int pipeDistance3 = 1000;
	int incY1 = 0;
	int incY2 = 0;
	int incY3 = 0;
public:
	bool PipeA1_Update(int incY, int &score);
	bool PipeB1_Update(int incY);
	bool PipeA2_Update(int incY, int& score);
	bool PipeB2_Update(int incY);
	bool PipeA3_Update(int incY, int& score);
	bool PipeB3_Update(int incY);
	int getPipe1X();
	int getPipe1Y();
	int getPipe2X();
	int getPipe2Y();
	int getPipe3X();
	int getPipe3Y();
	void PipeRender(SDL_Renderer *ren);
	void Reset();
};

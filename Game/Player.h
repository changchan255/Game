#pragma once
#include "Object.h"

class Player :public Object
{
private:
	double gravity = 0.5;
	double Ypos = 200;
	bool inJump = false;
	double jumpHeight = -7.5;
	double jumpTimer;
	double lastJump = 0;
	SDL_Texture* Tex1;
	SDL_Texture* Tex2;
	int animationTimer;
	float angle;
	double speed =0;
	SDL_Point coordinate;
public:
	int GetYpos();
	void Gravity(bool touchBase, bool playing);
	double GetJumpTime(double jumpTimer);
	void Jump();        //c check if we can jump or not
	bool JumpState();
	void Reset();
	void CreateTexture1(const char* address, SDL_Renderer* ren);
	void CreateTexture2(const char* address, SDL_Renderer* ren);
	void Render(SDL_Renderer* ren);
	void SetCoordinate(int x, int y);
	SDL_Point* GetCoordinate();
};

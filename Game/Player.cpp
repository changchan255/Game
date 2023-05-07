#include"Player.h"

void Player::Render(SDL_Renderer* ren)
{
	animationTimer++;
	if (animationTimer < 25)
	{
		SDL_RenderCopyEx(ren, getTexture(), &getSrc(), &getDest(), angle, GetCoordinate(), SDL_FLIP_NONE);
	}
	else if (animationTimer >= 25 && animationTimer <= 50)
	{
		SDL_RenderCopyEx(ren, Tex1, &getSrc(), &getDest(), angle, GetCoordinate(), SDL_FLIP_NONE);
	}
	else if (animationTimer > 50)
	{
		SDL_RenderCopyEx(ren, Tex2, &getSrc(), &getDest(), angle, GetCoordinate(), SDL_FLIP_NONE);
	}
	if (animationTimer > 75)
	{
		animationTimer = 0;
	}
}

int Player::GetYpos()
{
	return Ypos;
}

void Player::SetCoordinate(int x, int y)
{
	coordinate.x = x;
	coordinate.y = y;
}

SDL_Point* Player::GetCoordinate()
{
	return &coordinate;
}

void Player::Gravity(bool touchBase, bool playing)
{
	if (JumpState())
	{
		
			inJump = false;
			speed = jumpHeight;
		
	}
	if (!touchBase)
		Ypos += speed / 4.55;

	if (Ypos <= -24)
	{
		Ypos = -24;
	}
	
	speed += gravity / 2.5;
	setDest(110, Ypos, 68, 48);
	SetCoordinate(10, 12);
	angle = (speed / 2) * 10 - 5;

	if (angle <= -45)
	{
		angle = -45;
	}
	else if (angle >= 90)
	{
		angle = 90;
	}
	if (!playing)
	{
		Ypos = 300;
		speed = 0;
		angle = 0;
	}
	
	
}

void Player::Jump()
{
	jumpTimer = GetJumpTime(jumpTimer);
	if (jumpTimer - lastJump > 165)
	{
		
		inJump = true;
		lastJump = jumpTimer;
	}
	else
	{
		inJump = false;
	}
}

double Player::GetJumpTime(double jumpTimer)
{
	return SDL_GetTicks();
}

bool Player::JumpState()
{
	return inJump;
}

void Player::Reset()
{
	Ypos = 200;
	lastJump = 0;
}

void Player::CreateTexture1(const char* address, SDL_Renderer* ren)
{
	Tex1 = TextureManager::Texture(address, ren);
}

void Player::CreateTexture2(const char* address, SDL_Renderer* ren)
{
	Tex2 = TextureManager::Texture(address, ren);
}
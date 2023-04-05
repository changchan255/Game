#include"Player.h"

void Player::Render(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}

void Player::Update()
{
	gravity = gravity + 0.5;
	setSource(0, 0, 68, 48);
	setDest(0, gravity, 68, 48);
}
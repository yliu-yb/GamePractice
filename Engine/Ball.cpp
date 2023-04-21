#include "Ball.h"

Ball::Ball(Vec2 pos_in, Vec2 vel_in)
	:
	pos(pos_in),
	vel(vel_in)
{
}

void Ball::update(const float & dt)
{
	pos += vel * dt;
}

void Ball::reboundX()
{
	vel.x = -vel.x;
}

void Ball::reboundY()
{
	vel.y = -vel.y;
}

void Ball::Draw(Graphics& gfx)
{
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::boundaryCheck(int width, int height)
{
	if (pos.x - 7 <= 0) 
	{
		pos.x = 7;
		reboundX();
	}
	else if(pos.x + 7 >= width)
	{
		pos.x = width - 7 - 1;
		reboundX();
	}
	
	if (pos.y - 7 <= 0)
	{
		pos.y = 7;
		reboundY();
	}
	else if(pos.y + 7 >= height)
	{
		pos.y = height - 7 - 1;
		reboundY();
	}
}

#include "Ball.h"
#include <cmath>

Ball::Ball(Vec2 center_in, Vec2 vel_in)
	:
	center(center_in),
	vel(vel_in),
	center_old(center)
{
}

void Ball::update(const float & dt)
{
	center_old = center;
	center += vel * dt;
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
	SpriteCodex::DrawBall(center, gfx);
}

bool Ball::wallCollision(const myRectangle & wall)
{
	bool collisioned = false;

	if (center.x - radius <= wall.GetLeft())
	{
		center.x = wall.GetLeft() + radius;
		reboundX();
		collisioned = true;
	}
	else if (center.x + radius >= wall.GetRight())
	{
		center.x = wall.GetRight() - radius - 1;
		reboundX();
		collisioned = true;
	}

	if (center.y - radius <= wall.GetTop())
	{
		center.y = wall.GetTop() + radius;
		reboundY();
		collisioned = true;
	}
	else if (center.y + radius >= wall.GetBottom())
	{
		center.y = wall.GetBottom() - radius - 1;
		reboundY();
		collisioned = true;
	}

	return collisioned;
}

bool Ball::boardCollision(const myRectangle & board)
{
	bool collisioned = false;
	myRectangle ballRec(center, radius);
	
	if (ballRec.GetRight() >= board.GetLeft() && ballRec.GetLeft() <= board.GetRight()
		&& ballRec.GetTop() <= board.GetBottom() && ballRec.GetBottom() >= board.GetTop()) 
	{

		if (center_old.x + radius <= board.GetLeft())
		{
			center.x = board.GetLeft() - radius;
			reboundX();
			collisioned = true;
		}
		else if (center_old.x - radius >= board.GetRight())
		{
			center.x = board.GetRight() + radius;
			reboundX();
			collisioned = true;
		}
		else if (center_old.y + radius <= board.GetTop())
		{
			center.y = board.GetTop() - radius;
			reboundY();
			collisioned = true;
		}
		else if(center_old.y - radius >= board.GetBottom())
		{
			center.y = board.GetBottom() + radius;
			reboundY();
			collisioned = true;
		}

	}

	return collisioned;
}


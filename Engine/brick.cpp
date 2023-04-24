#include "brick.h"

brick::brick(Vec2& pos_in, float width_in, float height_in, Color c_in)
	:
	pos(pos_in),
	width(width_in),
	height(height_in),
	c(c_in)
{
}

void brick::draw(Graphics & gfx)
{
	if (!destroyed) 
	{
		gfx.DrawRectangle(GetRect(), c);
	}
}

bool brick::doBallCollision(Ball & ball)
{
	bool collision = false;

	myRectangle ballRec = ball.GetRect();
	myRectangle padRec = GetRect();

	if (!destroyed && ballRec.GetRight() >= padRec.GetLeft() && ballRec.GetLeft() <= padRec.GetRight()
		&& ballRec.GetTop() <= padRec.GetBottom() && ballRec.GetBottom() >= padRec.GetTop())
	{
		if (ball.center_old.x + Ball::radius <= padRec.GetLeft())
		{
			ball.center.x = padRec.GetLeft() - Ball::radius;
			ball.reboundX();
			collision = true;
		}
		else if (ball.center_old.x - Ball::radius >= padRec.GetRight())
		{
			ball.center.x = padRec.GetRight() + Ball::radius;
			ball.reboundX();
			collision = true;
		}
		else if (ball.center_old.y + Ball::radius <= padRec.GetTop())
		{
			ball.center.y = padRec.GetTop() - Ball::radius;
			ball.reboundY();
			collision = true;
		}
		else if (ball.center_old.y - Ball::radius >= padRec.GetBottom())
		{
			ball.center.y = padRec.GetBottom() + Ball::radius;
			ball.reboundY();
			collision = true;
		}
		destroyed = true;
	}

	return collision;
}

myRectangle brick::GetRect()
{
	return myRectangle::FromCenter(pos, width * 0.5f, height * 0.5f);
}

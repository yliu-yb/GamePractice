#include "pad.h"

pad::pad(Vec2& pos_in, float width_in, float height_in, Vec2 vel_in, Color c_in)
	:
	pos(pos_in),
	width(width_in),
	height(height_in),
	vel(vel_in),
	c(c_in)
{
}

void pad::update(const Keyboard & kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		pos.x += -vel.x * dt;
	}
	else if (kbd.KeyIsPressed(VK_RIGHT))
	{
		pos.x += vel.x * dt;
	}
	else if (kbd.KeyIsPressed(VK_UP))
	{
		pos.y += -vel.y * dt;
	}
	else if (kbd.KeyIsPressed(VK_DOWN))
	{
		pos.y += vel.y * dt;
	}
}

void pad::draw(Graphics & gfx)
{
	gfx.DrawRectangle(AddWings(), RGB(255,255,0));
	gfx.DrawRectangle(GetRect(), c);
}

void pad::doWallCollision(const myRectangle & wallRec)
{
	myRectangle rec = AddWings();
	if (rec.GetLeft() <= wallRec.GetLeft())
	{
		pos.x = wallRec.GetLeft() + rec.GetWidth() * 0.5f;
	}
	else if (rec.GetRight() >= wallRec.GetRight())
	{
		pos.x = wallRec.GetRight() - rec.GetWidth() * 0.5f;
	}

	if (rec.GetTop() <= wallRec.GetTop())
	{
		pos.y = wallRec.GetTop() + rec.GetHeight() * 0.5f;
	}
	else if (rec.GetBottom() >= wallRec.GetBottom())
	{
		pos.y = wallRec.GetBottom() - rec.GetHeight() * 0.5f;
	}
}

bool pad::doBallCollision(Ball & ball)
{
	bool collision = false;

	myRectangle ballRec = ball.GetRect();
	myRectangle padRec = GetRect();

	if (ballRec.GetRight() >= padRec.GetLeft() && ballRec.GetLeft() <= padRec.GetRight()
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
	}

	return collision;
}

myRectangle pad::GetRect()
{
	return myRectangle::FromCenter(pos, width * 0.5f, height * 0.5f);
}

myRectangle pad::AddWings()
{
	return myRectangle::FromCenter(pos, width * 0.5f + 14, height * 0.5f);
}

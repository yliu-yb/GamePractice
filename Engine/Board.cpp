#include "Board.h"
#include <cmath>

Board::Board(Vec2 center_in, int width, int height, Vec2 vel_in, Color c_in)
	:
	rec(myRectangle::FromCenter(center_in, width * 0.5f, height * 0.5f)),
	vel(vel_in),
	c(c_in)
{
}

void Board::draw(Graphics &gfs)
{
	if (show) 
	{
		gfs.DrawRectangle(rec, c);
	}
}

void Board::update(Keyboard &kb, float dt)
{
	if (kb.KeyIsPressed(VK_LEFT)) 
	{
		rec.MoveHorizontal(-vel.x * dt);
	}
	else if (kb.KeyIsPressed(VK_RIGHT)) 
	{
		rec.MoveHorizontal(vel.x * dt);
	}
	else if (kb.KeyIsPressed(VK_UP))
	{
		rec.MoveVertical(-vel.y * dt);
	}
	else if (kb.KeyIsPressed(VK_DOWN))
	{
		rec.MoveVertical(vel.y * dt);
	}
}

void Board::wallCollision(const myRectangle & wall)
{
	if (rec.GetLeft() <= wall.GetLeft())
	{
		rec.MoveHorizontal(wall.GetLeft() - rec.GetLeft());
	}
	else if (rec.GetRight() >= wall.GetRight()) 
	{
		rec.MoveHorizontal(wall.GetRight() - rec.GetRight());
	}
	
	if (rec.GetTop() <= wall.GetTop()) 
	{
		rec.MoveVertical(wall.GetTop() - rec.GetTop());
	}
	else if (rec.GetBottom() >= wall.GetBottom())
	{
		rec.MoveVertical(wall.GetBottom() - rec.GetBottom());
	}
}



bool Board::isOverlapping(myRectangle & rec_in)
{
	return rec.isOverlapped(rec_in);
}

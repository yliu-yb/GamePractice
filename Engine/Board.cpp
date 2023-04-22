#include "Board.h"
#include <cmath>

Board::Board(Vec2 center_in, int width, int height, Vec2 vel_in, Color c_in)
	:
	rec(center_in, width, height),
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
		rec.center.x += -vel.x * dt;
	}
	else if (kb.KeyIsPressed(VK_RIGHT)) 
	{
		rec.center.x += vel.x * dt;
	}
	else if (kb.KeyIsPressed(VK_UP))
	{
		rec.center.y -= vel.y * dt;
	}
	else if (kb.KeyIsPressed(VK_DOWN))
	{
		rec.center.y += vel.y * dt;
	}
}

void Board::wallCollision(const myRectangle & wall)
{
	if (rec.GetLeft() <= wall.GetLeft())
	{
		rec.center.x = wall.GetLeft() + rec.width * 0.5f;
	}
	else if (rec.GetRight() >= wall.GetRight()) 
	{
		rec.center.x = wall.GetRight() - rec.width * 0.5f;
	}
	
	if (rec.GetTop() <= wall.GetTop()) 
	{
		rec.center.y = wall.GetTop() + rec.height * 0.5f;
	}
	else if (rec.GetBottom() >= wall.GetBottom())
	{
		rec.center.y = wall.GetBottom() - rec.height *0.5f;
	}
}



bool Board::isOverlapping(const myRectangle & rec_in)
{
	bool overlapped = false;

	if (std::fabs(rec.center.x - rec_in.center.x) <= (rec.width * 0.5f + rec_in.width * 0.5f)
		&&
		std::fabs(rec.center.y - rec_in.center.y) <= (rec.height * 0.5f + rec_in.height * 0.5f))
	{
		overlapped = true;
		//show = false;
	}

	return overlapped;
}

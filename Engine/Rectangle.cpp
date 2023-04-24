#include "Rectangle.h"
#include <cmath>

myRectangle::myRectangle(float left_in, float right_in, float top_in, float bottom_in)
	:
	left(left_in),
	right(right_in),
	top(top_in),
	bottom(bottom_in)
{
}

myRectangle::myRectangle(Vec2 topleft, float width, float height)
	:
	left(topleft.x),
	right(topleft.x + width),
	top(topleft.y),
	bottom(topleft.y + height)
{
}

myRectangle myRectangle::FromCenter(Vec2 center, float halfwidth, float halfheight)
{
	return myRectangle(Vec2( center.x - halfwidth, center.y - halfheight), halfwidth * 2.0f, halfheight * 2.0f);
}

bool myRectangle::isOverlapped(const myRectangle &rec)
{
	bool overlapped = false;

	if (std::fabs(GetCenter().x - rec.GetCenter().x) <= (GetWidth() + rec.GetWidth()) * 0.5f 
		&&
		std::fabs(GetCenter().y - rec.GetCenter().y) <= (GetHeight() + rec.GetHeight()) * 0.5f)
	{
		overlapped = true;
	}

	return overlapped;
}

float myRectangle::GetWidth() const
{
	return right - left;
}

float myRectangle::GetHeight() const
{
	return bottom - top;
}

Vec2 myRectangle::GetCenter() const
{
	return Vec2(left + 0.5f * (GetWidth()), top + 0.5f * (GetBottom()));
}

float myRectangle::GetLeft() const
{
	return left;
}

float myRectangle::GetRight() const
{
	return right;
}

float myRectangle::GetTop() const
{
	return top;
}

float myRectangle::GetBottom() const
{
	return bottom;
}

void myRectangle::MoveHorizontal(float x)
{
	left += x;
	right += x;
}

void myRectangle::MoveVertical(float y)
{
	top += y;
	bottom += y;
}



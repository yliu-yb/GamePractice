#include "Rectangle.h"

myRectangle::myRectangle(Vec2 center_in, int width_in, int height_in)
	:
	center(center_in),
	width(width_in),
	height(height_in)
{
}

myRectangle::myRectangle(int top, int left, int right, int bottom)
	:
	myRectangle(Vec2(left + (right - left) * 0.5f, top + (bottom - top) * 0.5f), right - left, bottom - top)
{
}

myRectangle::myRectangle(Vec2 center, int radius)
	:
	myRectangle(center, radius * 2, radius * 2)
{
}

float myRectangle::GetLeft() const
{
	return center.x - width * 0.5f;
}

float myRectangle::GetRight() const
{
	return center.x + width * 0.5f;
}

float myRectangle::GetTop() const
{
	return center.y - height * 0.5f;
}

float myRectangle::GetBottom() const
{
	return center.y + height * 0.5f;
}



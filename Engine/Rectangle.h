#pragma once
#include"Vec2.h"

class myRectangle
{
public:
	myRectangle() = default;
	myRectangle(Vec2 center, int width, int height);
	myRectangle(int top, int left, int right, int bottom);
	myRectangle(Vec2 center, int radius);

	float GetLeft() const;
	float GetRight() const;
	float GetTop() const;
	float GetBottom() const;

public:	
	Vec2 center;
	float width;
	float height;
};


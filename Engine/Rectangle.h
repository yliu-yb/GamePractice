#pragma once
#include"Vec2.h"

class myRectangle
{
public:
	myRectangle() = default;
	myRectangle(float left, float right, float top, float bottom);
	myRectangle(Vec2 topleft, float width, float height);
	static myRectangle FromCenter(Vec2 center, float halfwidth, float halfheight);
	
	bool isOverlapped(const myRectangle &rec);
	float GetWidth() const;
	float GetHeight() const;
	Vec2 GetCenter() const;

	float GetLeft() const;
	float GetRight() const;
	float GetTop() const;
	float GetBottom() const;

	void MoveHorizontal(float x);
	void MoveVertical(float y);

public:	
	float left;
	float right;
	float top;
	float bottom;
};


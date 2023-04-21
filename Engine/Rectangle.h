#pragma once
#include"Vec2.h"

class Rectangle
{
public:
	Rectangle() = default;
	Rectangle(int top, int left, int right, int bottom);

public:
	Vec2 topLeft;
	Vec2 bottomRight;
};


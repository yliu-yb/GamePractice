#pragma once
#include "Vec2.h"
#include "Colors.h"
#include "Rectangle.h"
#include "Ball.h"
#include "Graphics.h"

class brick
{
	brick() = default;
	brick(Vec2 &pos_in, float width_in, float height_in, Color c_in);
	void draw(Graphics &gfx);
	bool doBallCollision(Ball &ball);
	myRectangle GetRect();

public:
	Vec2 pos;
	Color c;
	float width;
	float height;
	bool destroyed = false;
};


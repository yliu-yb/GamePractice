#pragma once
#include "Vec2.h"
#include "Colors.h"
#include "Rectangle.h"
#include "Ball.h"
#include "Graphics.h"
#include "Keyboard.h"

class pad
{
public:
	pad() = default;
	pad(Vec2 pos_in, float width_in, float height_in, Vec2 vel_in, Color c_in);
	void update(const Keyboard& kbd, float dt);
	void draw(Graphics& gfx);
	void doWallCollision(const myRectangle& wallRec);
	bool doBallCollision(Ball& ball);
	myRectangle GetRect();
	myRectangle AddWings();

public:
	Vec2 pos;
	float width;
	float height;
	Vec2 vel;
	Color c;
};


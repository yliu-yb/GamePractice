#pragma once
#include "Vec2.h"
#include "Colors.h"
#include "Rectangle.h"
#include "Graphics.h"
#include "Keyboard.h"

class Board
{
public:
	Board() = default;
	Board(Vec2 center_in, int width, int height, Vec2 vel_in, Color c_in);

	void draw(Graphics &gfs);
	void update(Keyboard &kb, float dt);
	void wallCollision(const myRectangle& wall);
	bool isOverlapping(myRectangle& rec_in);
public:
	myRectangle rec;
	Color c;

	Vec2 vel;
	bool show = true;
};


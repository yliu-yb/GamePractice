#pragma once
#include "Vec2.h"
#include "SpriteCodex.h"
#include "Graphics.h"


class Ball 
{
public:
	Ball(Vec2 pos_in, Vec2 vel_in);
	void update(const float& dt);
	void reboundX();
	void reboundY();
	void Draw(Graphics& gfx);
	void boundaryCheck(int width, int height);
public:
	Vec2 pos;
	Vec2 vel;
};
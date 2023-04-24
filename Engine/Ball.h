#pragma once
#include "Vec2.h"
#include "SpriteCodex.h"
#include "Graphics.h"
#include "Rectangle.h"

class Ball 
{
public:
	Ball(Vec2 center_in, Vec2 vel_in);
	void update(const float& dt);
	void reboundX();
	void reboundY();
	void Draw(Graphics& gfx);
	bool wallCollision(const myRectangle &wall);
	bool boardCollision(const myRectangle &board);

public:
	Vec2 center;
	Vec2 vel;
	Vec2 center_old;

	static constexpr float radius = 7.0f;
};
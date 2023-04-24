/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ball(Vec2(10, 10), Vec2(300, 300)),
	paddle(Vec2(500, 300), 100, 20, Vec2(1000, 300), RGB(0, 255, 0)),
	wall(0, Graphics::ScreenWidth, 0, Graphics::ScreenHeight),
	arkbrick(L".\\Sounds\\arkbrick.wav", false),
	arkpad(L".\\Sounds\\arkpad.wav", false)
{
	Vec2 topleft(50,50);
	Color bks_c[5] = { RGB(255, 0, 0), RGB(0, 255, 0), RGB(0, 0, 255),  RGB(255, 255, 0),  RGB(0, 255, 255) };

	for (int i = 0; i < bks_row; ++i) 
	{
		for (int j = 0; j < bks_column; ++j)
		{
			bricks[i * bks_column + j] = brick(topleft + Vec2(bk_width * j, bk_height * i), bk_width, bk_height, bks_c[i]);
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	auto dt = ft.Mark();

	ball.update(dt);
	ball.wallCollision(wall);

	paddle.update(wnd.kbd, dt);
	paddle.doWallCollision(wall);

	if (paddle.doBallCollision(ball))
	{
		arkpad.Play();
	}

	for (brick& b : bricks) 
	{
		if (b.doBallCollision(ball))
		{
			arkbrick.Play();
			break;
		}
	}
}

void Game::ComposeFrame()
{
	for (brick& b : bricks)
	{
		b.draw(gfx);
	}
	paddle.draw(gfx);
	ball.Draw(gfx);
}

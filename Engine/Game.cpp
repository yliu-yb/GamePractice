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
	ball(Vec2(10, 10), Vec2(2000, 400)),
	board(Vec2(200, 200), 200, 200, Vec2(0, 0), RGB(255, 0, 0)),
	moveBoard(Vec2(500, 300), 100, 300, Vec2(300, 300), RGB(0, 255, 0)),
	wall(Vec2(0 + Graphics::ScreenWidth * 0.5, 0 + Graphics::ScreenHeight * 0.5), Graphics::ScreenWidth, Graphics::ScreenHeight),
	arkbrick(L".\\Sounds\\arkbrick.wav", false),
	arkpad(L".\\Sounds\\arkpad.wav", false)

{
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

	if (ball.boardCollision(board.rec))
	{
		arkbrick.Play();
	}

	if (ball.boardCollision(moveBoard.rec))
	{
		arkpad.Play();
	}
	
	moveBoard.update(wnd.kbd, dt);
	moveBoard.wallCollision(wall);
}

void Game::ComposeFrame()
{
	moveBoard.draw(gfx);
	board.draw(gfx);
	ball.Draw(gfx);
}

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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	player(100,100,&gfx,&wnd.kbd,&wnd.mouse)
{
	int i;
	for (i = 0; i < nEnemies; i++)
	{
		enemies[i] = new Enemy(100 + 100 * i, 500, &gfx,this);
		enemies[i]->SetTarget(&player);
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
	player.Update();
	int i;
	for (i = 0; i < nEnemies; i++)
	{
		if (enemies[i])
		enemies[i]->Update();
	}
}

void Game::ComposeFrame()
{
	gfx.DrawCircle(100, 100, 10, Colors::White);
	player.Draw();
	int i;
	for (i = 0; i < nEnemies; i++)
	{
		if(enemies[i])
			enemies[i]->Draw();
	}
	gfx.DrawLine(0, 0, 800, 600, Colors::Blue);
}

void Game::RemoveEnemy(Enemy* toRemove)
{
	int i;
	for (i = 0; i < nEnemies; i++)
	{
		if (enemies[i] == toRemove)
		{
			enemies[i] = NULL;
		}
	}
}
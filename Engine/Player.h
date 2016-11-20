#pragma once
#include "Includes.h"
#include "Bullet.h"
#include "Shooter.h"

class Player: public Shooter
{
public:
	Player(int startX, int startY, Graphics* inGfx, Keyboard* inKbd, Mouse* inMouse);
	const void Draw();

	void Update();

	void KeyboardActions();
	void MouseActions();

	//Newly added, temp bullet system
	void AddHostileBullets(Bullet* newBullet);
	void DeleteHostileBullets(Bullet* toDelete);
	
	
private:
	//Player data
	int speed;
	int healthPoints = 10;
	const int width = 20;
	const int height = 20;
	//Bullet Tracker
	Bullet** bulletList;


	//Pointers to game objects
	Keyboard * kbd;
	Graphics * gfx;
	Mouse * mouse;


	//Newly added, temp bullet system
	int nHostileBullets;
	Bullet** hostileBullets;
};
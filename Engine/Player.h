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
	
private:
	//Player data
	int speed;
	
	//Bullet Tracker
	Bullet** bulletList;

	//Pointers to game objects
	Keyboard * kbd;
	Graphics * gfx;
	Mouse * mouse;
};
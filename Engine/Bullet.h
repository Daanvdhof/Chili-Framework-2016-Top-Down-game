#pragma once
#include "Includes.h"

class Shooter;
class Bullet
{
public:
	Bullet(float startX, float startY, float angleIn, Graphics* inGfx, Shooter* myShooterIn);
	~Bullet();

	const int GetX();
	const int GetY();
	void Update();
	void Draw();
private:
	float x;
	float y;
	float speed;
	float angle;

	//Pointers to game objects
	Graphics* gfx;
	Shooter* myShooter;
};
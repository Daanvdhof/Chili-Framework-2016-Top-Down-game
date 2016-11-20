#pragma once
#include "Includes.h"
#include "Player.h"
#include "Shooter.h"

class Game;
class Enemy: public Shooter
{
public:
	Enemy(int startX, int startY, Graphics* inGfx, Game* inMyGame);
	const void Draw();
	void SetTarget(Player* newTarget);
	void Update();
	~Enemy();
	void Shoot(float angle);
private:
	Bullet** bulletList;
	int nBullets;

	int width;
	int height;
	int speed;
	int healthPoints;
	Player* target;
	Graphics* gfx;
	Game* myGame;
};
#pragma once
#include "Bullet.h"
class Shooter
{
public:
	const int GetX();
	const int GetY();
	void BulletActions();
	void DeleteBullet(Bullet* toDelete);
	void ShooterInits(Graphics* inGfx);
	void Shoot(float angle);
	void DrawBullets();
	void TestDraw();
	Bullet** GetBullets();
protected:
	int x;
	int y;
	int nBullets;
	int bulletCooldown;
	int bulletTimer;
	bool canShoot;

	//Bullet Tracker
	Bullet** bulletList;

	//Graphics pointer
	Graphics* gfx; 
};
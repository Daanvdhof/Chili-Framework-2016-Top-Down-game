#include "Shooter.h"
void Shooter::Shoot(float angle)
{

		Bullet* newBullet = new Bullet(x, y, angle, gfx, this);

		bulletList[nBullets] = newBullet;
		nBullets++;

		bulletList = (Bullet**)realloc(bulletList, sizeof(Bullet*)*(nBullets + 1));
		bulletList[nBullets] = NULL;
		bulletTimer = bulletCooldown;
	
		canShoot = false;
	
}
Bullet* Shooter::GetLastBullet()
{
	return bulletList[nBullets - 1];
}
void Shooter::DeleteBullet(Bullet* toDelete)
{
	int i;
	for (i = 0; i < nBullets; i++)
	{
		if (bulletList[i] == toDelete)
		{
			bulletList[i] = 0;
			int j;
			for (j = 0; j < nBullets - i - 1; j++)
			{
				bulletList[i + j] = bulletList[i + j + 1];
			}
			nBullets--;
		}
	}
}
void Shooter::ShooterInits(Graphics* inGfx)
{
	canShoot = true;
	bulletTimer = 0;
	bulletCooldown = 60;
	bulletList = (Bullet**)malloc(sizeof(Bullet*));
	bulletList[0] = NULL;
	nBullets = 0;

	gfx = inGfx;
}
void Shooter::TestDraw()
{
	gfx->DrawCircle(x, y, 40, Colors::Yellow);
}
const int Shooter::GetX()
{
	return x;
}
const int Shooter::GetY()
{
	return y;
}
void Shooter::BulletActions()
{
	int i;
	for (i = 0; i < nBullets; i++)
	{
		if (&bulletList[i] != 0)
			bulletList[i]->Update();
	}

	if (bulletTimer > 0)
	{
		bulletTimer--;
	}
	else
	{
		canShoot = true;
	}
}
void Shooter::DrawBullets()
{
	int i;
	for (i = 0; i < nBullets; i++)
	{
		if (&bulletList[i] != 0)
			bulletList[i]->Draw();
	}
}
Bullet** Shooter::GetBullets()
{
	return bulletList;
}
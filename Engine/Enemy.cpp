#include "Enemy.h"
#include "Game.h"
Enemy::~Enemy()
{
	int i;
	for (i = 0; i < nBullets; i++)
	{
		DeleteBullet(bulletList[i]);
	}
	myGame->RemoveEnemy(this);
}
Enemy::Enemy(int startX, int startY, Graphics* inGfx, Game* inMyGame)
{
	myGame = inMyGame;
	x = startX;
	y = startY;

	speed = 5;
	gfx = inGfx;
	target = NULL;

	width = 20;
	height = 20;
	healthPoints = 10;
	ShooterInits(inGfx);
}

const void Enemy::Draw()
{
	gfx->DrawCircle(x, y, 10, Colors::Blue);
	DrawBullets();
}
void Enemy::SetTarget(Player* newTarget)
{
	target = newTarget;
}
void Enemy::Shoot(float angle)
{
	Shooter::Shoot(angle);
	target->AddHostileBullets(GetLastBullet());
}
void Enemy::Update()
{
	if (target)
	{
		float angle;
		float dx = (float)(x - target->GetX());
		float dy = (float)(y - target->GetY());
		angle = atan(dy / dx);
		if (x >= target->GetX())
		{
			angle = angle + 3.14159;
		}
		if(canShoot)
			Shoot(angle);
	}
	Bullet** playerBullets = target->GetBullets();
	int i = 0;
	while (playerBullets[i] != NULL)
	{
	
		if(CheckCollision(x, y, width, height, playerBullets[i]->GetX(), playerBullets[i]->GetY(), 5, 5) == true)
		{
			delete playerBullets[i];
			healthPoints--;
			if (healthPoints <= 0)
				delete this;
		}
		i++;
	}
	
	BulletActions();
}

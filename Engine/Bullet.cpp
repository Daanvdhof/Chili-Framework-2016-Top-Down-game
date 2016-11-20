#include "Bullet.h"
#include "Shooter.h"

Bullet::Bullet(float startX, float startY, float angleIn, Graphics* inGfx, Shooter* myShooterIn)
{
	x = startX;
	y = startY;
	angle = angleIn;
	speed = 20;
	myShooter= myShooterIn;
	gfx = inGfx;
}
Bullet::~Bullet()
{
	myShooter->DeleteBullet(this);
}

void Bullet::Update()
{
	x += speed*cos(angle);
	y += speed*sin(angle);

	if (x < 0 || x > Graphics::ScreenWidth || y < 0 || y > Graphics::ScreenHeight)
	{
		
		delete this;
	}
}
void Bullet::Draw()
{
	gfx->DrawCircle((int)x, (int)y, 2, Colors::Yellow);
}
const int Bullet::GetX()
{
	return (int)x;
}
const int Bullet::GetY()
{
	return (int)y;
}
#include "Player.h"

/*
Player constructor
Give in the start position for the player and the pointers to the game objects
*/
Player::Player(int startX, int startY, Graphics* inGfx, Keyboard* inKbd, Mouse* inMouse)
{
	x = startX;
	y = startY;
	gfx = inGfx;
	kbd = inKbd;
	mouse = inMouse;
	speed = 5;

	ShooterInits(inGfx);
}

void Player::Update()
{
	KeyboardActions();
	MouseActions();
	BulletActions();

}
void Player::KeyboardActions()
{
	if (kbd->KeyIsPressed('A'))
	{
		x -= speed;
	}
	else if (kbd->KeyIsPressed('D'))
	{
		x += speed;
	}
	if (kbd->KeyIsPressed('W'))
	{
		y -= speed;
	}
	else if (kbd->KeyIsPressed('S'))
	{
		y += speed;
	}
}
void Player::MouseActions()
{
	if (mouse->LeftIsPressed())
	{
		float angle = atan((float)(y - mouse->GetPosY()) / (float)(x - mouse->GetPosX()));
		if (x >= mouse->GetPosX())
		{
			angle = angle + 3.14159;
		}
		if (canShoot)
		{
			Shoot(angle);
			
		}
	}
	else if (mouse->RightIsPressed())
	{
		speed--;
		
	}
	speed = Constraint(speed, 0, 10);
}


const void Player::Draw()
{
	gfx->DrawCircle(x, y, 10, Colors::White);
	DrawBullets();
}


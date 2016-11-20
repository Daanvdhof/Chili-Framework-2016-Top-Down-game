#include "Player.h"
#include "Game.h"
/*
Player constructor
Give in the start position for the player and the pointers to the game objects
*/
Player::Player(int startX, int startY, Graphics* inGfx, Keyboard* inKbd, Mouse* inMouse, Game* pInMyGame)
{
	x = startX;
	y = startY;
	gfx = inGfx;
	kbd = inKbd;
	mouse = inMouse;
	speed = 5;

	hostileBullets = (Bullet**)malloc(sizeof(Bullet*));
	hostileBullets[0] = NULL;
	nHostileBullets = 0;
	ShooterInits(inGfx);
	pMyGame = pInMyGame;
}
Player::~Player()
{
	pMyGame->InvokeGameOver();
}
void Player::AddHostileBullets(Bullet* newBullet)
{
	hostileBullets[nHostileBullets] = newBullet;
	nHostileBullets++;

	hostileBullets = (Bullet**)realloc(hostileBullets, sizeof(Bullet*)*(nHostileBullets + 1));
	hostileBullets[nHostileBullets] = NULL;

}
void Player::DeleteHostileBullets(Bullet* toDelete)
{
	int i;
	for (i = 0; i < nHostileBullets; i++)
	{
		if (hostileBullets[i] == toDelete)
		{
			hostileBullets[i] = 0;
			int j;
			for (j = 0; j < nBullets - i - 1; j++)
			{
				hostileBullets[i + j] = hostileBullets[i + j + 1];
			}
			hostileBullets--;
		}
	}
}
void Player::Update()
{

	int i = 0;
	while (hostileBullets[i] != NULL)
	{

		if (CheckCollision(x, y, width, height, hostileBullets[i]->GetX(), hostileBullets[i]->GetY(), 5, 5) == true)
		{
			delete hostileBullets[i];
			healthPoints--;
			if (healthPoints <= 0)
			{
				delete this;
				return;
			}
		}
		i++;
	}



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


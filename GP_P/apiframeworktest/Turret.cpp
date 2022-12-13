#include "pch.h"
#include "Turret.h"
#include "Bullet.h"

Turret::Turret()
{
}
 
Turret::~Turret()
{
}

void Turret::FireBullet(Vec2 basePos, Vec2 dir, float power)
{
	Bullet* pBullet = new Bullet;
	pBullet->SetName(L"Bullet_Player");
	pBullet->SetPos(basePos);
	pBullet->SetScale(Vec2(25.f, 25.f));
	pBullet->SetDir(dir * power);
	CreateObject(pBullet, GROUP_TYPE::BULLET_PLAYER);
}

void Turret::CircleFireBullet(Vec2 basePos, Vec2 baseDir, int count, float power)
{
	float rad = (3.14 * 2) / count;

	for (int i = 0; i < count; i++)
	{
		float x = cos(rad * i);
		float y = sin(rad * i);
		FireBullet(basePos, Vec2(x,y).Normalize(), power);
	}
}

void Turret::CircleFireBullet(Vec2 basePos, Vec2 baseDir, int count, float power, float duration)
{
}



void Turret::Update()
{
}

#include "pch.h"
#include "Turret.h"
#include "Bullet.h"
#include "TimeMgr.h"

Turret::Turret() :
	m_fShotTime(0),
	m_fTime(0)
{
	m_fRand = 0;
}
 
Turret::~Turret()
{
}

void Turret::Time(float duration)
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

void Turret::CircleFireBullet(Vec2 basePos, Vec2 baseDir, int count, float power,bool isRandow)
{
	float rad = (3.14 * 2) / count;

	if (isRandow)
	{
		m_fRand += 60;
	}
	else
	{
		m_fRand = 0;
	}


	for (int i = 0; i < count; i++)
	{
		float x = cos(rad * i + m_fRand);
		float y = sin(rad * i + m_fRand) ;
		FireBullet(basePos, Vec2(x,y).Normalize(), power);
	}
}

void Turret::CircleFireBullet(Vec2 basePos, Vec2 baseDir, int count, float power, float duration, bool isRandow)
{

	if (m_fTime > m_fShotTime + duration)
	{
		m_fShotTime = m_fTime;
		CircleFireBullet(basePos, baseDir, count, power, isRandow);
	}
}

void Turret::Update()
{
	m_fTime += fDT;
}
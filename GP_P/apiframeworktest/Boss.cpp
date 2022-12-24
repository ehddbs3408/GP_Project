#include "pch.h"
#include "Boss.h"
#include "TimeMgr.h"
#include "Collider.h"
Boss::Boss() : m_fSpeed(100.f)
, m_fMaxDistance(50.f)
, m_iDir(Vec2(0,0))
, m_iPatternCounter(1)
, m_TimerCounter(0)
{
	m_tTurret = new Turret();
}

Boss::~Boss()
{
	m_iPatternCounter = 1;
}

void Boss::Update()
{
	Move();
	m_tTurret->Update();
	m_TimerCounter += fDT;
	FirstPattern();
	SecondPattern();
	ThirdPattern();
}

void Boss::EnterCollision(Collider* _pOther)
{
	_pOther->GetObj();
}

void Boss::FirstPattern()
{
	if (m_iPatternCounter != 1) return;

	if (PatternTimeSet(1, 2))
	{
		//BossToMove(Vec2(1, 1));
	}

	if (PatternTimeSet(2, 3))
	{
		m_tTurret->CircleFireBullet(GetPos(), Vec2(0, 0), 100, 10);
		m_iPatternCounter++;
		m_TimerCounter = 0;
	}
}

void Boss::SecondPattern()
{
	if (m_iPatternCounter != 2) return;

	if (PatternTimeSet(1, 2))
	{
		m_tTurret->CircleFireBullet(GetPos(), Vec2(0, 0), 15, 5, 0.2f);
		BossToMove(Vec2(50, 50), 2);
	}

	if (PatternTimeSet(2, 4))
	{
		m_tTurret->CircleFireBullet(GetPos(), Vec2(0, 0), 15, 5, 0.2f);
		BossToMove(Vec2(1200, 50), 4);
	}

	if (PatternTimeSet(4, 6))
	{
		m_tTurret->CircleFireBullet(GetPos(), Vec2(0, 0), 15, 5, 0.2f);
		BossToMove(Vec2(1200, 700), 4);
	}

	if (PatternTimeSet(6, 8))
	{
		m_tTurret->CircleFireBullet(GetPos(), Vec2(0, 0), 15, 5, 0.2f);
		BossToMove(Vec2(50, 700), 5);
	}

	if (PatternTimeSet(10, 20))
	{
		m_iPatternCounter++;
		m_TimerCounter = 0;
	}
}

void Boss::ThirdPattern()
{
	if (m_iPatternCounter != 3) return;

	if (PatternTimeSet(1, 2))
	{
		int a = 1;
	}

	if (PatternTimeSet(2, 3))
	{
		m_iPatternCounter++;
		m_TimerCounter = 0;
	}
}

void Boss::Move()
{

}

void Boss::BossToMove(Vec2 dir, float power)
{
	Vec2 pos = GetPos();
	dir = dir - pos;
	SetPos(pos + dir.Normalize() * power);
}

bool Boss::PatternTimeSet(float firstTime, float secondTime)
{
	return firstTime < m_TimerCounter&& secondTime > m_TimerCounter;
}





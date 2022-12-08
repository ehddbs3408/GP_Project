#include "pch.h"
#include "Boss.h"
#include "TimeMgr.h"
#include "Collider.h"
Boss::Boss() : m_fSpeed(100.f)
, m_fMaxDistance(50.f)
, m_vCenterPos(Vec2(0.f, 0.f))
, m_iDir(1)
, m_iPatternCounter(1)
, m_TimerCounter(0)
{

}

Boss::~Boss()
{
	m_iPatternCounter = 1;
}

void Boss::Update()
{
	m_TimerCounter += fDT;
	FirstPattern();
	SecondPattern();
	ThirdPattern();
}

void Boss::EnterCollision(Collider* _pOther)
{

}

void Boss::FirstPattern()
{
	if (m_iPatternCounter != 1) return;

	if (PatternTimeSet(1,2))
	{
		int a = 1;
	}
}

void Boss::SecondPattern()
{
	if (m_iPatternCounter != 2) return;
}

void Boss::ThirdPattern()
{
	if (m_iPatternCounter != 3) return;
}

bool Boss::PatternTimeSet(float firstTime, float secondTime)
{
	return firstTime < m_TimerCounter && secondTime > m_TimerCounter;
}



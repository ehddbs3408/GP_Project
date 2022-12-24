#include "pch.h"
#include "Boss.h"
#include "TimeMgr.h"
#include "Collider.h"
#include "ResMgr.h"
#include "Image.h"
Boss::Boss() : m_fSpeed(100.f)
, m_fMaxDistance(50.f)
, m_iDir(Vec2(0,0))
, m_iPatternCounter(3)
, m_TimerCounter(0)
{
	m_pImage = ResMgr::GetInst()->ImgLoad(L"Boss", L"Image\\Boss.bmp");
	m_fBulletCount = 3;
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

	if (PatternTimeSet(0, 1))
	{
		SetPos(Vec2(1280/2, 768/2));
	}

	if (PatternTimeSet(1, 8))
	{
		//BossToMove(Vec2(1, 1));
		m_tTurret->CircleFireBullet(GetPos(), Vec2(0, 0), m_fBulletCount, 10,0.3f, true);
	}

	if (PatternTimeSet(8, 9))
	{
	
	m_iPatternCounter++;
	m_TimerCounter = 0;
	}
}

void Boss::SecondPattern()
{
	if (m_iPatternCounter != 2) return;

	if (PatternTimeSet(1, 2))
	{
		m_tTurret->CircleFireBullet(GetPos(), Vec2(0, 0), m_fBulletCount, 5, 0.2f,false);
		BossToMove(Vec2(50, 50), 2);
	}

	if (PatternTimeSet(2, 4))
	{
		m_tTurret->CircleFireBullet(GetPos(), Vec2(0, 0), m_fBulletCount, 5, 0.2f, false);
		BossToMove(Vec2(1200, 50), 4);
	}

	if (PatternTimeSet(4, 6))
	{
		m_tTurret->CircleFireBullet(GetPos(), Vec2(0, 0), m_fBulletCount, 5, 0.2f, false);
		BossToMove(Vec2(1200, 700), 4);
	}

	if (PatternTimeSet(6, 8))
	{
		m_tTurret->CircleFireBullet(GetPos(), Vec2(0, 0), m_fBulletCount, 5, 0.2f, false);
		BossToMove(Vec2(50, 700), 5);
	}

	if (PatternTimeSet(8, 9))
	{
		m_iPatternCounter++;
		m_TimerCounter = 0;
	}
}

void Boss::ThirdPattern()
{
	if (m_iPatternCounter != 3) return;

	if (PatternTimeSet(1, 1.5f))
	{
		BossToMove(Vec2(50, 350), 20);
	}
	if (PatternTimeSet(2, 4))
	{
		m_tTurret->CircleFireBullet(GetPos(), Vec2(0, 0), m_fBulletCount, 5, 0.1f, false);
	}
	if (PatternTimeSet(4, 4.8f))
	{
		BossToMove(Vec2(1200, 350), 20);
	}
	if (PatternTimeSet(5, 7))
	{
		m_tTurret->CircleFireBullet(GetPos(), Vec2(0, 0), m_fBulletCount, 5, 0.1f, false);
	}

	if (PatternTimeSet(8, 9))
	{
		m_iPatternCounter=1;
		m_fBulletCount++;
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
void Boss::Render(HDC _dc)
{
	Component_Render(_dc);
	int Width = (int)m_pImage->GetWidth();
	int Height = (int)m_pImage->GetHeight();

	Vec2 vPos = GetPos();

	//BitBlt(_dc
	//	,(int)(vPos.x - (float)(Width / 2))
	//	,(int)(vPos.y - (float)(Height / 2))
	//    , Width, Height
	//    , m_pImage->GetDC()
	//    , 0,0, SRCCOPY);

	//¸¶Á¨Å¸ »ö»ó »¬¶§ transparent: Åõ¸íÇÑ
	TransparentBlt(_dc
		, (int)(vPos.x - (float)(Width / 2))
		, (int)(vPos.y - (float)(Height / 2))
		, Width, Height
		, m_pImage->GetDC()
		, 0, 0, Width, Height
		, RGB(255, 0, 255));
}





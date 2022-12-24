#include "pch.h"
#include "Player.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Bullet.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"
#include "Core.h"
Player::Player() :
	moveSpeed(300.f),
	dashDistance(150.f),
	dashCooltime(0.f),
	direction(0),
	dashDelay(1),
	playerHP(4),
	isDead(false)
{
	// collider 생성
	CreateCollider();
	GetCollider()->SetScale(Vec2(40.f, 35.f));
	GetCollider()->SetOffsetPos(Vec2(0.f, 25.f));
	m_pImage = ResMgr::GetInst()->ImgLoad(L"Player", L"Image\\Playerm.bmp");
	//moveSpeed = 300.f;
	//dashDistance = 150.f;
	//dashCooltime = 0.f;
	//direction = 0;
	//dashDelay = 1;
	//playerHP = 4;
	//isDead = false;

	// image 업로드
	//Image* pImg = ResMgr::GetInst()->ImgLoad(L"Player", L"Image\\Player.bmp");

	// animator 생성 및 animation 사용
	//CreateAnimator();
	//GetAnimator()->CreateAnimation(L"Jiwoofront", pImg, Vec2(0.f, 150.f), Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.2f);
	//GetAnimator()->Play(L"Jiwoofront", true);

	//// animation offset 위로 올리기. 
	//Animation* pAnim = GetAnimator()->FindAnimation(L"Jiwoofront");
	//for(size_t i=0;i<pAnim->GetMaxFrame();i++)
	//	pAnim->GetFrame(i).vOffset = Vec2(10.f, -50.f);
}
Player::~Player()
{
	//if(nullptr !=m_pImage)
	//	delete m_pImage;
}
void Player::Update()
{
	Vec2 vPos = GetPos();
	dashCooltime += fDT * 2.f;

	if(KEY_HOLD(KEY::UP))
	{
		if (vPos.y - moveSpeed * fDT <= 0) {
			return;
		}
		vPos.y -= moveSpeed * fDT;
		direction = (int)Direction::Up;
	}
	if (KEY_HOLD(KEY::DOWN))
	{
		if (vPos.y + moveSpeed * fDT >= Core::GetInst()->GetResolution().y - (int)m_pImage->GetHeight()) {
			return;
		}
		vPos.y += moveSpeed * fDT;
		direction = (int)Direction::Down;
	}
	if (KEY_HOLD(KEY::LEFT))
	{
		if (vPos.x - moveSpeed * fDT <= (int)m_pImage->GetWidth() / 2) {
			return;
		}
		vPos.x -= moveSpeed * fDT;
		direction = (int)Direction::Left;
	}
	if (KEY_HOLD(KEY::RIGHT))
	{
		if (vPos.x + moveSpeed * fDT >= Core::GetInst()->GetResolution().x - (int)m_pImage->GetWidth() / 2) {
			return;
		}
		vPos.x += moveSpeed * fDT;
		direction = (int)Direction::Right;
	}
	if (KEY_TAP(KEY::SPACE))
	{
		if (dashCooltime < dashDelay) {
			return;
		}
		dashCooltime = 0.f;

		switch (direction)
		{
		case (int)Direction::Up:
			if (vPos.y - dashDistance <= 0) {
				vPos.y = 0;
				break;
			}
			vPos.y -= dashDistance;
			break;
		case (int)Direction::Down:
			if (vPos.y + dashDistance >= Core::GetInst()->GetResolution().y - (int)m_pImage->GetHeight()) {
				vPos.y = Core::GetInst()->GetResolution().y - (int)m_pImage->GetHeight();
				break;
			}
			vPos.y += dashDistance;
			break;
		case (int)Direction::Left:
			if (vPos.x - dashDistance <= (int)m_pImage->GetWidth() / 2) {
				vPos.x = 0 + (int)m_pImage->GetWidth() / 2;
				break;
			}
			vPos.x -= dashDistance; 
			break;
		case (int)Direction::Right:
			if (vPos.x + dashDistance >= Core::GetInst()->GetResolution().x - (int)m_pImage->GetWidth() / 2) {
				vPos.x = Core::GetInst()->GetResolution().x - (int)m_pImage->GetWidth() / 2;
				break;
			}
			vPos.x += dashDistance;
		//{
		//	float testdt = fDT;
		//	float test = dashSpeed * testdt;
		//	vPos.x += test;
		//}
			break;
		default:
			break;
		}

		//Dash(vPos);

		// CreateBullet();
	}
	SetPos(vPos);
	//GetAnimator()->Update();
}

void Player::CreateBullet()
{
	Vec2 vBulletPos = GetPos();
	vBulletPos.y -= GetScale().y / 2.f;

	// 
	Bullet* pBullet = new Bullet;
	pBullet->SetName(L"Bullet_Player");
	pBullet->SetPos(vBulletPos);
	pBullet->SetScale(Vec2(25.f, 25.f));
	pBullet->SetDir(Vec2(0.f, -1.f));
	CreateObject(pBullet, GROUP_TYPE::BULLET_PLAYER);
	//Scene* pCurScene = SceneMgr::GetInst()->GetCurScene();
	//pCurScene->AddObject(pBullet,GROUP_TYPE::BULLET);
}

void Player::Dash(Vec2 vPos) {

	switch (direction)
	{
	case (int)Direction::Up:
		vPos.y -= dashDistance * fDT;
		break;
	case (int)Direction::Down:
		vPos.y += dashDistance * fDT;
		break;
	case (int)Direction::Left:
		vPos.x -= dashDistance * fDT;
		break;
	case (int)Direction::Right:
		vPos.x += dashDistance * fDT;
		break;
	default:
		break;
	}

	SetPos(vPos);

}

void Player::EnterCollision(Collider* _pOther)
{
	Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Bullet_Player")
	{
		playerHP--;
		if (playerHP == 0 && !isDead) {
			isDead = true;
			//DeleteObject(this);
			ChangeScene(SCENE_TYPE::GAMEOVER);
		}
		//m_iHp -= 1;
		//if (m_iHp <= 0)
		//	DeleteObject(this);
	}
}


void Player::Render(HDC _dc)
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

	//마젠타 색상 뺄때 transparent: 투명한
	TransparentBlt(_dc
		, (int)(vPos.x - (float)(Width / 2))
		, (int)(vPos.y - (float)(Height / 2))
		, Width, Height
	    , m_pImage->GetDC()
	    ,0,0, Width, Height
	    , RGB(255,0,255));

	LOGFONT lf;

	HFONT font;

	lf.lfHeight = 0;
	lf.lfWidth = 0;
	lf.lfEscapement = 0;
	lf.lfOrientation = 0;
	lf.lfWeight = 0;
	lf.lfItalic = 0;
	lf.lfUnderline = 0;
	lf.lfStrikeOut = 0;
	lf.lfCharSet = HANGEUL_CHARSET;
	lf.lfOutPrecision = 0;
	lf.lfClipPrecision = 0;
	lf.lfQuality = 0;

	font = CreateFontIndirect(&lf);
	SelectObject(_dc, font);

	WCHAR buf[100];
	RECT rt = { Core::GetInst()->GetResolution().x / 2 - 100, 0, Core::GetInst()->GetResolution().x /2 + 100, 100 };
	wsprintf(buf, L"PlayerHP : %d", playerHP);

	DrawText(_dc, buf, lstrlen(buf), &rt, DT_CENTER | DT_WORDBREAK);
}

#include "pch.h"
#include "GGM_Player.h"
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

GGM_Player::GGM_Player()
{
	CreateCollider();
	GetCollider()->SetScale(Vec2(20.f, 20.f));

	// image ¾÷·Îµå
	Image* pImg = ResMgr::GetInst()->ImgLoad(L"PlayerPng", L"Image\\Player.bmp");

	moveSpeed = 300.f;
	jumpForce = 500.f;
	isJump = false;
	isDoubleJump = false;
}

GGM_Player::~GGM_Player()
{

}


void GGM_Player::Update()
{
	Vec2 vPos = GetPos();
	if (KEY_HOLD(KEY::LEFT))
	{
		vPos.x -= moveSpeed * fDT;
	}
	if (KEY_HOLD(KEY::RIGHT))
	{
		vPos.x += moveSpeed * fDT;
	}
	if (KEY_TAP(KEY::SPACE))
	{
		Jump(vPos);
	}
	SetPos(vPos);
}

void GGM_Player::Jump(Vec2 vPos)
{
	if (isDoubleJump) {
		return;
	}

	if (!isJump) {
		vPos.y += jumpForce * fDT;
		isJump = true;
	}

}

void GGM_Player::Render(HDC _dc)
{

}

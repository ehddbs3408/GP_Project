#include "pch.h"
#include "Scene_Main.h"
#include "Object.h"
#include "Player.h"
#include "Monster.h"
#include "Core.h"
#include "Image.h"
#include "PathMgr.h"
#include "CollisionMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
#include "Boss.h"
#include "TimeMgr.h"
#include "Scene_Over.h"
#include "ScoreMgr.h"

Scene_Main::Scene_Main() :
	score(0),
	temp(0)
{

}

Scene_Main::~Scene_Main()
{
}
void Scene_Main::Enter()
{
	ScoreMgr::GetInst()->InitScore();
	score = 0;
	SoundMgr::GetInst()->LoadSound(L"BGM", true, L"Sound\\pianobgm.wav");
	SoundMgr::GetInst()->Play(L"BGM");
	// Object �߰�
	Object* pObj = new Player;
	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x/2, (Core::GetInst()->GetResolution().y / 2)) );
	pObj->SetScale(Vec2(100.f,100.f));
	AddObject(pObj, GROUP_TYPE::MONSTER);

	Object* boss = new Boss;
	boss->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 - 50, (Core::GetInst()->GetResolution().y / 2)));
	boss->SetScale(Vec2(100.f, 100.f));
	AddObject(boss, GROUP_TYPE::MONSTER);

//	Object* pOtherPlayer = new Player(*(Player*)pObj);
	/*Object* pOtherPlayer = pObj->Clone();
	pOtherPlayer->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f + 100.f, Core::GetInst()->GetResolution().y / 2.f));
	AddObject(pOtherPlayer, GROUP_TYPE::PLAYER);*/

	//m_vecObj[(UINT)GROUP_TYPE::DEFAULT].push_back(pObj); 

	// Monster Object �߰�
	//Monster* pMonsterObj = new Monster;
	//pMonsterObj->SetPos(Vec2(640.f, 50.f));
	//pMonsterObj->SetScale(Vec2(50.f, 50.f));
	//pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
	//AddObject(pMonsterObj, GROUP_TYPE::MONSTER);

	//// ���� ��ġ
	//Vec2 vResolution(Vec2(Core::GetInst()->GetResolution()));
	//int iMonster = 16;
	//float fMoveDist = 25.f;
	//float fObjScale = 50.f;
	//float fTerm = (vResolution.x - ((fMoveDist + fObjScale /2.f) * 2)) / (float)(iMonster-1);
	//Monster* pMonsterObj = nullptr;
	//for (int i = 0; i < iMonster; i++)
	//{
	//	pMonsterObj = new Monster;
	//	pMonsterObj->SetName(L"Monster");
	//	pMonsterObj->SetPos(Vec2((fMoveDist + fObjScale / 2.f) + (float)i*fTerm, 50.f));
	//	pMonsterObj->SetScale(Vec2(fObjScale, fObjScale));
	//	pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
	//	pMonsterObj->SetMoveDistance(fMoveDist);
	//	AddObject(pMonsterObj, GROUP_TYPE::MONSTER);
	//}

	//pObj = new Object;

	//pObj->SetPos(Vec2(640.f, 384.f));
	//pObj->SetScale(Vec2(100.f, 100.f));

	//AddObject(pObj, GROUP_TYPE::DEFAULT);
	// �浹 ���� 
	// Player - Monster �׷� ���� �浹 üũ
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::BULLET_PLAYER, GROUP_TYPE::MONSTER);

}

void Scene_Main::Exit()
{
	DeleteAll();
	ScoreMgr::GetInst()->SaveScore(GetScore());
	CollisionMgr::GetInst()->CheckReset();
}

void Scene_Main::Update()
{  
	Scene::Update();

	temp += fDT;
	if (temp >= 1) {
		score += 100;
		temp -= 1;
	}
}

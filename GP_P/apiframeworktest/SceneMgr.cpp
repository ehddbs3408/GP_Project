#include "pch.h"
#include "SceneMgr.h"
#include "Scene_Main.h"
#include "Scene_Start.h"
#include "Scene_Over.h"
#include "EventMgr.h"
SceneMgr::SceneMgr()
	: m_pCurScene(nullptr)
	, m_arrScene{}
{
}

SceneMgr::~SceneMgr()
{
	// �� ���� ����
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; ++i)
	{
		if (nullptr != m_arrScene[i])
		{
			delete m_arrScene[i];
		}
	}
}

void SceneMgr::ChangeScene(SCENE_TYPE _eNext)
{
	m_pCurScene->Exit();
	m_pCurScene = m_arrScene[(UINT)_eNext];
	m_pCurScene->Enter();
}

void SceneMgr::Init()
{
	// Scene ����
	m_arrScene[(UINT)SCENE_TYPE::GAMESTART] = new Scene_Start;
	m_arrScene[(UINT)SCENE_TYPE::GAMESTART]->SetName(L"Start Scene");
	m_arrScene[(UINT)SCENE_TYPE::MAIN] = new Scene_Main;
	m_arrScene[(UINT)SCENE_TYPE::MAIN]->SetName(L"Main");
	m_arrScene[(UINT)SCENE_TYPE::GAMEOVER] = new Scene_Over;
	m_arrScene[(UINT)SCENE_TYPE::GAMEOVER]->SetName(L"Over Scene");

//	m_arrScene[(UINT)SCENE_TYPE::TOOL] = new Scene_Tool;
//	m_arrScene[(UINT)SCENE_TYPE::SCENE_02] = new Scene02;


	// ���� �� ����
	m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::GAMESTART];
	m_pCurScene->Enter();
}

void SceneMgr::Update()
{
	m_pCurScene->Update();
	m_pCurScene->FinalUpdate();
}

void SceneMgr::Render(HDC _dc)
{ 
	m_pCurScene->Render(_dc);
}

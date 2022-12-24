#include "pch.h"
#include "Scene_Over.h"
#include "KeyMgr.h"
#include "Scene_Main.h"
#include "Core.h"
#include "ScoreMgr.h"

Scene_Over::Scene_Over() :
	overScore(0)
{
}

Scene_Over::~Scene_Over()
{
}

void Scene_Over::Enter()
{
}

void Scene_Over::Exit()
{
}

void Scene_Over::Update()
{
	Scene::Update();
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::MAIN);
	}
}

void Scene_Over::Render(HDC _dc)
{
	WCHAR buf[100];
	RECT rt = { 0, Core::GetInst()->GetResolution().y / 2, Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y };

	overScore = ScoreMgr::GetInst()->GetScore();
	wsprintf(buf, L"Á¡¼ö : %d", overScore);

	DrawText(_dc, buf, lstrlen(buf), &rt, DT_CENTER | DT_WORDBREAK);
}
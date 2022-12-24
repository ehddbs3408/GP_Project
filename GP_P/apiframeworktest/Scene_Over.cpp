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
	WCHAR scoreBuf[100];
	WCHAR bestScoreBuf[100];
	RECT tRt = { 0, Core::GetInst()->GetResolution().y / 2 + 100, Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y + 150 };
	RECT sRt = { 0, Core::GetInst()->GetResolution().y / 2 + 10, Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y + 100 };
	RECT bRt = { 0, Core::GetInst()->GetResolution().y / 2 - 50, Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y };

	overScore = ScoreMgr::GetInst()->GetScore();
	wsprintf(scoreBuf, L"Score : %d", overScore);
	wsprintf(bestScoreBuf, L"BestScore : %d", ScoreMgr::GetInst()->GetBestScore());

	DrawText(_dc, scoreBuf, lstrlen(scoreBuf), &sRt, DT_CENTER | DT_WORDBREAK);
	DrawText(_dc, bestScoreBuf, lstrlen(bestScoreBuf), &bRt, DT_CENTER | DT_WORDBREAK);

	DrawText(_dc, L"Press Enter to Restart",-1, &tRt, DT_CENTER | DT_WORDBREAK);
}
#include "pch.h"
#include "Scene_Over.h"
#include "Scene_Main.h"
#include "KeyMgr.h"
#include "Core.h"

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
	float _score = Scene_Main::GetInst()->GetScore();

	_itow((int)_score, buf, 0);

	DrawText(_dc, buf, wcslen(buf), &rt, DT_CENTER | DT_WORDBREAK);
}

Scene_Over::Scene_Over()
{
}

Scene_Over::~Scene_Over()
{
}

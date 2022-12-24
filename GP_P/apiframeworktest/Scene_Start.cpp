#include "pch.h"
#include "Scene_Start.h"
#include "KeyMgr.h"
#include "SelectGDI.h"
#include "Core.h"
Scene_Start::Scene_Start()
{
}

Scene_Start::~Scene_Start()
{
}

void Scene_Start::Enter()
{
}

void Scene_Start::Exit()
{
}

void Scene_Start::Update()
{
	Scene::Update();
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::MAIN);
	}

}

void Scene_Start::Render(HDC _dc)
{
	//POINT& a = Core::GetResolution();
	RECT rt = { 0, Core::GetInst()->GetResolution().y/2, Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y };
	DrawText(_dc, L"Press Enter To Start!", -1, &rt, DT_CENTER | DT_WORDBREAK);
}

//void Scene_Start::Render(HDC _dc)
//{
//	RECT rt = { 100, 100, 500, 300 };
//	DrawText(_dc, L"Press Enter To Start!", -1, &rt, DT_CENTER | DT_WORDBREAK);
//}


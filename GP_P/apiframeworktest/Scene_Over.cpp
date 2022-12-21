#include "pch.h"
#include "Scene_Over.h"
#include "KeyMgr.h"

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
		ChangeScene(SCENE_TYPE::GAMESTART);
	}
}

Scene_Over::Scene_Over()
{
}

Scene_Over::~Scene_Over()
{
}

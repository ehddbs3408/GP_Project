#include "pch.h"
#include "Scene_Start.h"
#include "KeyMgr.h"
#include "SelectGDI.h"
#include "Core.h"
#include "SoundMgr.h"

Scene_Start::Scene_Start()
{
}

Scene_Start::~Scene_Start()
{
}

void Scene_Start::Enter()
{
	SoundMgr::GetInst()->LoadSound(L"BGM", true, L"Sound\\pianobgm.wav");
	SoundMgr::GetInst()->Play(L"BGM");
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
	LOGFONT lf;

	HFONT font;

	lf.lfHeight = 50;
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

	RECT tRt = { 0, Core::GetInst()->GetResolution().y / 2 - 100, Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y - 100 };
	DrawText(_dc, L"강대희 드립 피하기", -1, &tRt, DT_CENTER | DT_WORDBREAK);

	RECT rt = { 0, Core::GetInst()->GetResolution().y / 2, Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y };
	DrawText(_dc, L"Press Enter To Start!", -1, &rt, DT_CENTER | DT_WORDBREAK);
}

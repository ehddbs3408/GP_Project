#pragma once
#include "Scene.h"
class Scene_Over
    : public Scene
{
private:
    int overScore;
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
public:
    Scene_Over();
    virtual ~Scene_Over();
};
#pragma once
#include "Scene.h"
class Scene_Main :
    public Scene
{
private:
    int score;
    float temp;
public:
    SINGLE(Scene_Main);
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
public:
    Scene_Main();
    virtual ~Scene_Main();
public:
    int GetScore() { return score; }
};


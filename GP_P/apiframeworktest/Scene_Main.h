#pragma once
#include "Scene.h"
class Scene_Main :
    public Scene
{
private:
    float score;
public:
    SINGLE(Scene_Main);
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
    //static float GetScore() { return score; }
public:
    Scene_Main();
    virtual ~Scene_Main();
public:
    float GetScore() { return score; }
};


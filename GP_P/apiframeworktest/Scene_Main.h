#pragma once
#include "Scene.h"
class Scene_Main :
    public Scene
{
public:
    float score;
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
    //static float GetScore() { return score; }
public:
    Scene_Main();
    virtual ~Scene_Main();
};


#pragma once
#include "Object.h"

class GGM_Player : public Object
{
private:
    //Image* m_pImage;
    float moveSpeed;
    float jumpForce;
    bool isJump;
    bool isDoubleJump;
public:
    GGM_Player();
    ~GGM_Player();
private:
    void Jump(Vec2 vPos);
private:
    CLONE(GGM_Player);
public:
    void Update()       override;
    void Render(HDC _dc) override;
};


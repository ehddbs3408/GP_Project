#pragma once
#include "Object.h"

class Image;
class Player :
    public Object
{
private:
    Image* m_pImage;
    float moveSpeed;
    float dashDistance;
    float dashCooltime;
    float dashDelay;
    int direction;
    int playerHP;
public:
    Player();
    //Player(const Player& _origin) 
    //    : Object(_origin)
    //    , m_pImage(_origin.m_pImage)
    //{}
    ~Player();
private:
    void CreateBullet();
    void Dash(Vec2 vPos);

//    Player* Clone{ return new Player(*this); }
    CLONE(Player);
public:
    virtual void	EnterCollision(Collider* _pOther);
public:
    void Update()       override;
    void Render(HDC _dc) override;
};


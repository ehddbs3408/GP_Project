#pragma once
#include "Object.h"
#include "Turret.h"
class Image;
class Boss : public Object
{
private:
    float   m_fSpeed;
    //Vec2    m_vCenterPos;
    Image* m_pImage;
    float   m_fMaxDistance;
    Vec2     m_iDir; // 1, -1
    int     m_iPatternCounter;
    float  m_TimerCounter;

    float m_fBulletCount;

    Turret* m_tTurret;
public:
    float GetSpeed() { return m_fSpeed; }
    void SetSpeed(float _f) { m_fSpeed = _f; }
    //void SetCenterPos(Vec2 _vPos) { m_vCenterPos = _vPos; }
    void SetMoveDistance(float _f) { m_fMaxDistance = _f; }
public:

    virtual void	EnterCollision(Collider* _pOther);
    virtual void FirstPattern();
    virtual void SecondPattern();
    virtual void ThirdPattern();
    virtual void Move();
    virtual void BossToMove(Vec2 dir, float power);
    bool PatternTimeSet(float firstTime, float secondTime);
    

    
    CLONE(Boss);
public:
    Boss();
    ~Boss();
public:
    virtual void Update() override;
    void Render(HDC _dc) override;
};

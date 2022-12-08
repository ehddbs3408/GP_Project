#pragma once
#include "Object.h"
class Boss : public Object
{
private:
    float   m_fSpeed;
    Vec2    m_vCenterPos;
    float   m_fMaxDistance;
    int     m_iDir; // 1, -1
    int     m_iPatternCounter;
    float  m_TimerCounter;
public:
    float GetSpeed() { return m_fSpeed; }
    void SetSpeed(float _f) { m_fSpeed = _f; }
    void SetCenterPos(Vec2 _vPos) { m_vCenterPos = _vPos; }
    void SetMoveDistance(float _f) { m_fMaxDistance = _f; }
public:
    virtual void Update() override;
    virtual void	EnterCollision(Collider* _pOther);
    virtual void FirstPattern();
    virtual void SecondPattern();
    virtual void ThirdPattern();
    bool PatternTimeSet(float firstTime, float secondTime);
    CLONE(Boss);
public:
    Boss();
    ~Boss();
};


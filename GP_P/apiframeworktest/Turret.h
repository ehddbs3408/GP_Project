#pragma once
class Turret
{
private:
	Vec2 m_vDir;
	float m_fShotTime;
	float m_fTime;
	float m_fRand;
public:
	Turret();
	~Turret();
public:
	void FireBullet(Vec2 basePos,Vec2 dir, float power);
	void CircleFireBullet(Vec2 basePos,Vec2 baseDir,int count, float power, bool isRandow);
	void CircleFireBullet(Vec2 basePos, Vec2 baseDir, int count, float power, float duration, bool isRandow);

	void Time(float duration);
	void Update();
};


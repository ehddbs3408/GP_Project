#pragma once
class Turret
{
private:
	Vec2 m_vDir;
	float m_fShotTime;
	float m_fTime;

public:
	Turret();
	~Turret();
public:
	void FireBullet(Vec2 basePos,Vec2 dir, float power);
	void CircleFireBullet(Vec2 basePos,Vec2 baseDir,int count, float power);
	void CircleFireBullet(Vec2 basePos, Vec2 baseDir, int count, float power, float duration);
	void Time(float duration);
	void Update();
};


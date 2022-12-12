#pragma once
class Turret
{
private:
	Vec2 m_vDir;
public:
	Turret();
	~Turret();
public:
	void FireBullet(Vec2 basePos,Vec2 dir, float power);
	void CircleFireBullet(Vec2 basePos,Vec2 baseDir,int count, float power);
	void CircleFireBullet(Vec2 basePos,Vec2 baseDir, float power, float duration);

	void Update();
};


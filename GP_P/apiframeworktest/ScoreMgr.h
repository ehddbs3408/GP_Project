#pragma once
class ScoreMgr
{
private:
	int score;
public:
	ScoreMgr();
	~ScoreMgr();
public:
	SINGLE(ScoreMgr);
public:
	void SaveScore(int _score);
	int GetScore();
	void InitScore();
};


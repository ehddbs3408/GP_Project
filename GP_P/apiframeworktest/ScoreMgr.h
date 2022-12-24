#pragma once
class ScoreMgr
{
private:
	int score;
	int bestScore;
public:
	ScoreMgr();
	~ScoreMgr();
public:
	SINGLE(ScoreMgr);
public:
	void SaveScore(int _score);
	int GetScore();
	int GetBestScore();
	void InitScore();
};


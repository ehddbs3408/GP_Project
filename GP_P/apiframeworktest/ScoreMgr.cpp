#include "pch.h"
#include "ScoreMgr.h"

ScoreMgr::ScoreMgr() :
	score(0),
	bestScore(0)
{
}

ScoreMgr::~ScoreMgr()
{
}

void ScoreMgr::SaveScore(int _score)
{
	score = _score;
	if (score > bestScore) {
		bestScore = score;
	}
}

int ScoreMgr::GetScore()
{
	return score;
}

int ScoreMgr::GetBestScore()
{
	return bestScore;
}

void ScoreMgr::InitScore()
{
	score = 0;
}

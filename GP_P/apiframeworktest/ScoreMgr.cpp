#include "pch.h"
#include "ScoreMgr.h"

ScoreMgr::ScoreMgr() :
	score(0)
{
}

ScoreMgr::~ScoreMgr()
{
}

void ScoreMgr::SaveScore(int _score)
{
	score = _score;
}

int ScoreMgr::GetScore()
{
	return score;
}

void ScoreMgr::InitScore()
{
	score = 0;
}

#include "ScoreBoard.h"

ScoreBoard::ScoreBoard(int a,int b,int c):GameObject(0,0)
{
	NoOfLives=a;
	Score=b;
	Level=c;
}
void ScoreBoard::AddScore(int a){Score+=a;}
int ScoreBoard::getScore(){return Score;}
void ScoreBoard::setLevel(int a){Level=a;}
int ScoreBoard::getLevel(){return Level;}
void ScoreBoard::draw()
{
	string a=Num2Str(Score);
	DrawString(50, 800, a, colors[WHITE]);
}


#ifndef ScoreBoard_h
#define ScoreBoard_h
#include "GameObject.h"
#include <string>
class ScoreBoard:public GameObject
{
	protected:
	int NoOfLives;
	int Score;
	int Level;
	public:
	ScoreBoard(int=5,int=0,int=1);
	void AddScore(int);
	int getScore();
	void setLevel(int);
	int getLevel();
	void draw();
	

};
#endif

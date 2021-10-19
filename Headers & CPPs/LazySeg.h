#ifndef LazySeg_h
#define LazySeg_h
#include "Segment.h"
#include "ScoreBoard.h"
#include "Board.h"
class LazySeg: public Segment
{
	public:
	LazySeg(int=0,int=0);
	void draw();
	void move();
	void copyToArray(Board*);
	int collision(Board*);
	int returnHeadX();
	int returnHeadY();
	void set_X(int);
	void set_Y(int);
	void ch_Y(int);
	void ch_X(int);
	int get_Y();
	int get_X();
	void drawBlink();
	
//	void draws();
	private:
	int m;
};
#endif


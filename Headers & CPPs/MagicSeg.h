#ifndef MagicSeg_h
#define MagicSeg_h
#include "Segment.h"
#include "Board.h"
#include "Mushroom.h"
#include "ScoreBoard.h"
class MagicSeg:public Segment{
	public:
	MagicSeg(int,int);
	void draw();
	void move();
	void copyToArray(Board*);
	int returnHeadX();
	int returnHeadY();
	int collision(Board*);
	int get_X();
	int get_Y();
	void set_X(int);
	void set_Y(int);
	void ch_X(int);
	void ch_Y(int);
	void drawBlink();
	void isBlink(bool a);
	//void draws();
	private:
	int m;
	bool blinking;
	

};
#endif

#ifndef Centipede_h
#define Centipede_h
#include "Segment.h"
#include "ScoreBoard.h"
#include "Board.h"
class Centipede
{
	protected:
	int size;
	Segment **seg;
	Segment **nseg;
	int flag;
	int tempx;
	int tempy;
	int nsize;
	bool blinks;
	public:
	Centipede();
	Centipede(int);
	Centipede(int,int,int);
	void copyToArray(Board*);
	int collision(Board*);
	void move();
	void moves();
	void blink(bool);
	int getFlag();
	int getTempX();
	int getTempY();
	int getNSize();
};
#endif

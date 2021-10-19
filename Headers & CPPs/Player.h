#ifndef Player_h
#define Player_h

#include "MoveableObject.h"
#include "Board.h"

class Player:public MoveableObject{
	private:
	
	Board b;
	int newPosn;
	public:
	Player(int=30,int=30);
	void move();
	void draw();
	int returnX();
	int returnY();
	void copyToArray(int c[52][41]);
	void getPosn(int);
};
#endif

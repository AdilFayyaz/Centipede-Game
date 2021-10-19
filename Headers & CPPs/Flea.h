#ifndef Flea_h
#define Flea_h
#include "MoveableObject.h"
#include "Board.h"

class Flea:public MoveableObject
{
	private:
	bool allow;
	bool Out;
	public:
	Flea();
	void draw();
	void move();
	bool isTime();
	void set_X(int);
	void set_Y(int);
	int get_X();
	int get_Y();
	void copyToArray(Board*);
	void hasAllowed(bool);
	int collision(Board *);
	bool getOut();

};
#endif

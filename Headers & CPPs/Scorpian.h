#ifndef Scorpian_h
#define Scorpian_h
#include "MoveableObject.h"
#include "Board.h"
class Scorpian:public MoveableObject{
	private:
	bool allow;
	public:
	Scorpian();
	void move();
	void draw();
	void copyToArray(Board*);
	int collision(Board*);
	bool isTime();
	void hasAllowed(bool);
	void set_X(int);
	void set_Y(int);
	int get_X();
	int get_Y();
};
#endif

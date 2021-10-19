#ifndef GameObject_h
#define GameObject_h
#include <iostream>
#include "Position.h"
#include "Board.h"
#include "util.h"
class GameObject{
	protected:
	Position posn;
	public:
	//GameObject(Position);
	GameObject(int,int);
	virtual void draw()=0;
	//virtual bool collision(){};
	//virtual void copyToArray(Board* )=0;
};
#endif

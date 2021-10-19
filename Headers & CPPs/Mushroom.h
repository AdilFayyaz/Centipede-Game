#ifndef Mushroom_h
#define Mushroom_h
#include <iostream>
#include "GameObject.h"
#include "Board.h"
#include "Position.h"
#include <ctime>
#include <cstdlib>
using namespace std;

class Mushroom:public GameObject{
	private:
	int noOfMushrooms;
	int noOfHits;
	
	public:
	Mushroom(int=0);
	void draw();
	void poison(Board *);
	int collision(Board*);
	void isHit(int);
	void copyToArray(Board*);
	void resetArray(Board*);
	void makeNew(int,int);
	void setNoOfHits(int);
	int get_X();
	int get_Y();
	void set_X(int);
	void set_Y(int);
};
#endif

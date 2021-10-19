#ifndef MoveableObject_h
#define MoveableObject_h
#include "GameObject.h"
#include "util.h"
#include <iostream>
using namespace std;

class MoveableObject:public GameObject
{
	protected:
	
	public:
	MoveableObject(int,int,int=0);
	virtual void move()=0;

};
#endif

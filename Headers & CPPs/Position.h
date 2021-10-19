#ifndef Position_h
#define Position_h
#include <iostream>
using namespace std;

class Position
{
	protected:
	int x;
	int y;
	public:
	Position(int=0,int=0);
	void setX(int);
	void setY(int);
	int getX();
	int getY();
};
#endif



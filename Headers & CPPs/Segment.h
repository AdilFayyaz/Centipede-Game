#ifndef Segment_h
#define Segment_h

#include "MoveableObject.h"
#include "Board.h"
class Segment:public MoveableObject
{
	protected:
	
		
	public:
	Segment();
	Segment(int,int,int);
	void draw();
	virtual void copyToArray(Board*){};
	virtual int collision(Board*){};
	virtual void set_X(int){};
	virtual void set_Y(int){};
	virtual void ch_Y(int){};
	virtual void ch_X(int){};
	virtual int get_X(){};
	virtual int get_Y(){};	
	virtual void drawBlink(){};
	virtual void isBlink(bool){};
	//virtual ~Segment{};
};
#endif

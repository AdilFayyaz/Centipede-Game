#include "Scorpian.h"

Scorpian::Scorpian():MoveableObject(0,0,0)
{
	int rx=-1,ry=-1;
	while(ry%20!=0)
	{
		ry=20+rand()%1000;
		posn.setY(ry);			
	}
	rx=980;
	posn.setX(rx);
}
void Scorpian::move()
{
	if(posn.getX()>20)
	{
		//cout<<"In scorpian move.."<<endl;
		int rx,ry;	
		rx=posn.getX();
		rx-=10;
		posn.setX(rx);
	}
	else
	{
		posn.setX(1000);
	}
	
}
void Scorpian::draw()
{
	DrawCircle(posn.getX()-8,posn.getY()+8,10,colors[ALICE_BLUE]);
	DrawRectangle(posn.getX(),posn.getY(),40, 20, colors[MAROON]);	
}
void Scorpian::copyToArray(Board* b)
{
	b->board_array[posn.getX()/20-1][posn.getY()/20-1]=7;
}
int Scorpian::collision(Board* b)
{
	if(b->board_array[posn.getX()/20-1][posn.getY()/20-1]==1)
	{
		cout<<"Detected in scorpian..."<<endl;
		DrawSquare(posn.getX(),posn.getY(),20,colors[WHITE]);
		return 1;
	}
}
/*void Scorpian::move()
{
	int temp;
	if(posn.getX()>10 && isTime())
	{
		temp=posn.getX()-10;
		posn.setX(temp);
		
	}
}*/
bool Scorpian::isTime()
{
	if(allow==true)
	return 1;
	else
	return 0;
	
}
void Scorpian::hasAllowed( bool a)
{
	if(a==1)
	{
		allow=1;
	}
	else
	allow=0;
}

void Scorpian::set_X(int a){posn.setX(a);}
void Scorpian::set_Y(int b){posn.setY(b);}
int Scorpian::get_X(){return posn.getX();}
int Scorpian::get_Y(){return posn.getY();}


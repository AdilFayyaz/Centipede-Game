#include "Mushroom.h"
Mushroom::Mushroom(int a):GameObject(0,0)
{
			int rx=-1,ry=-1;
			noOfMushrooms=a;
			
			while(rx%20!=0 )
			{
				rx=40+rand()%960;
				posn.setX(rx);			
			}
			while(ry%20!=0 )
			{
				ry=80+rand()%740;
				posn.setY(ry);
			}	
			noOfHits=0;	
}
void Mushroom::draw()
{
			int rx,ry;
			//DrawTriangle(posn.getX(), posn.getY()+20, posn.getX()+20, posn.getY()+20, posn.getX()+10, posn.getY()+40, colors[67]);
			
			DrawCircle(posn.getX()+10,posn.getY(),10,colors[45]);
			DrawCircle(posn.getX()+10,posn.getY()-10,10,colors[BLACK]);
			DrawRectangle(posn.getX()+5,posn.getY()-10,10,15,colors[45]);
			
	
}
void Mushroom::poison(Board* b)
{
	b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]==8;
	DrawCircle(posn.getX()+10,posn.getY(),10,colors[GHOST_WHITE]);
	DrawCircle(posn.getX()+10,posn.getY()-10,10,colors[BLACK]);
	DrawRectangle(posn.getX()+5,posn.getY()-10,10,15,colors[GHOST_WHITE]);
}

int Mushroom::collision(Board *b)
{	
/*	if(noOfHits==1 && b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]==3)
	{
		cout<<"Hit twice.."<<endl;
		DrawSquare(posn.getX(),posn.getY(),20,colors[BLACK]);
		b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=0;
		noOfHits=0;
		return 2;
	}
	else if(noOfHits==0 && b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]==3)
	{
		cout<<"Hit once.."<<endl;
		//DrawSquare(posn.getX(),posn.getY(),20,colors[YELLOW]);
		noOfHits++;
		return 1;
	}	
*/
	if(b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]==7)
	{
		poison(b);
		return 1;
	}
}
void Mushroom::isHit(int index)
{
//	this[index].collision();
}
void Mushroom::copyToArray(Board *b)
{
	b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=1;	
	
}

void Mushroom::resetArray(Board *b)
{
	b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=0;
}

void Mushroom::makeNew(int x,int y)
{
	posn.setX(x);
	posn.setY(y);
	draw();
	
}
void Mushroom::setNoOfHits(int a) {noOfHits=a;}


int Mushroom::get_X(){return posn.getX();}
int Mushroom::get_Y(){return posn.getY();}
void Mushroom::set_X(int a){posn.setX(a);}
void Mushroom::set_Y(int b){posn.setY(b);}


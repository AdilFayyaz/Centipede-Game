#include "LazySeg.h"

LazySeg::LazySeg(int a,int b):Segment(0,0,0)
{
	posn.setX(a);
	posn.setY(b);
	m=0;
}
void LazySeg::draw()
{
	DrawCircle(posn.getX()+5,posn.getY()+7, 10, colors[LAWN_GREEN]);
}
void LazySeg::drawBlink()
{}
void LazySeg::move()
{
	int tempx,tempy;
	if(posn.getX()<=1000 && posn.getX()>=20 && m==0)
	{
		tempx=posn.getX()-5;
		posn.setX(tempx);
	}
	else
	{
		m=1;
	//	tempx=posn.getX()+5;
	//	posn.setX(tempx);
	
	}
	if(m==1 && posn.getX()<=1000 && posn.getX()>=20)
	{
		tempx=posn.getX()+5;
		posn.setX(tempx);
		
	}
	else
	{
			m=0;
		//	tempx=posn.getX()-5;
		//	posn.setX(tempx);
	
	}
	if(posn.getX()<20) 
	{
		tempx=posn.getX()+5;
		posn.setX(tempx);
		tempy=posn.getY();
		if(tempy>40)
		{
			tempy-=20;
			posn.setY(tempy);
		}
		else
		{
			tempy+=20;
			posn.setY(tempy);
		}
		m=1;
	}
	else if(posn.getX()>1000)
	{
		tempx=posn.getX()-5;
		posn.setX(tempx);
		tempy=posn.getY();
		if(tempy>40)
		{
			tempy-=20;
			posn.setY(tempy);
		}
		else
		{
			tempy+=20;
			posn.setY(tempy);
		}
		m=0;		
	}
	
	
}
int LazySeg::collision(Board* b)
{
	int tempy;
	
	if(b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]==1)
	{
		//cout<<"here collision......"<<endl;
		tempy=posn.getY()-20;
		posn.setY(tempy);
		if(m==1)
		m=0;
		else
		m=1;
		return 1;
		
	}
	if(b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]==3)
	{
		//cout<<"bullet hit.."<<endl;
		b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=0;
		DrawCircle(posn.getX()+5,posn.getY()+7, 10, colors[BLACK]);
		DrawSquare(posn.getX(),posn.getY(),20,colors[BLACK]);
		//tempy=posn.getY()-20;
		//posn.setY(tempy);
		if(m==1)
		m=0;
		else
		m=1;
	//	ScoreBoard S;
	//	S.AddScore(10);
	//	S.draw();
		
		return 3;
		
	}
	if(b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]==2)
	{
		
		b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=0;
		return 4;
	}
}
void LazySeg::copyToArray(Board* b){
if(posn.getX()%20==0 && posn.getY()%20==0)
	b->board_array[posn.getX()/20-1][posn.getY()/20-1]=5;
}


void LazySeg::set_X(int a)
{
	int tempx=posn.getX()+a;
	posn.setX(tempx);
}
void LazySeg::set_Y(int b)
{
	int tempy=posn.getY()-b;
	posn.setY(tempy);
}
int LazySeg::get_Y(){return posn.getY();}
int LazySeg::get_X(){return posn.getX();}
void LazySeg::ch_Y(int a)
{
	posn.setY(a);
}
void LazySeg::ch_X(int aa)
{
	posn.setX(aa);
}


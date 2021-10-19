#include "MagicSeg.h"
MagicSeg::MagicSeg(int a,int b):Segment(0,0,0)
{
	posn.setX(a);
	posn.setY(b);
	m=0;
}
void MagicSeg::draw()
{
	
	DrawCircle(posn.getX()+5,posn.getY()+7, 10, colors[DARK_MAGENTA]);	
}
void MagicSeg::drawBlink()
{
	DrawCircle(posn.getX()+5,posn.getY()+7, 10, colors[ORANGE]);
}
void MagicSeg::move()
{
	int tempx,tempy;
/*	if(posn.getY()<120 && m==0)
	{
		tempy=posn.getY();
		tempy+=20;
		posn.setY(tempy);
	}
	else
	m=1;
	if(m==1 && posn.getY()<120  )
	{
		tempy=posn.getY();
		tempy+=20;
		posn.setY(tempy);
	}
	else 
	m=0;
*/
	//old code
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
int MagicSeg::collision(Board *b)
{
	int tempy;
	
	if(b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]==1)
	{
		//cout<<"here collision......"<<endl;
		b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=0;
		tempy=posn.getY()-20;
		posn.setY(tempy);
		if(m==1)
		m=0;
		else
		m=1;
		return 1;
		
	}
	if(b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]==3 && blinking==0)
	{
		//cout<<"bullet hit.."<<endl;
		b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=0;
		
		DrawCircle(posn.getX()+5,posn.getY()+7, 10, colors[BLACK]);
		
		DrawSquare(posn.getX(),posn.getY(),20,colors[BLACK]);
		if(m==1)
		m=0;
		else
		m=1;
		//posn.setX(0);
		//posn.setY(0);
		return 2;
		
	}
	if(b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]==2)
	{
		
		b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=0;
		return 4;
	}
}
void MagicSeg::copyToArray(Board* b){

//cout<<"In magic copy..."<<endl;
if(posn.getX()%20==0 && posn.getY()%20==0)
	b->board_array[posn.getX()/20-1][posn.getY()/20-1]=4;
	
/*	int** x;
	x=new int*[51];
	for(int i=0;i<51;i++)
	{
		x[i]=new int[42];
	}
	
	for(int i=0;i<51;i++)
	{
		for(int j=0;j<42;j++)
		{
			x[i][j]=b->board_array[i][j];
		}
	}
	int flag;
	flag=collision(x);
	return flag;
*/
}

int MagicSeg::get_X(){return posn.getX();}
int MagicSeg::get_Y(){return posn.getY();}
void MagicSeg::set_X(int a){
	int temp;
	temp=posn.getX()+a;
	posn.setX(temp);
}
void MagicSeg::set_Y(int a)
{
	int temp;
	temp=posn.getY()+a;
	posn.setX(temp);
}

void MagicSeg::ch_X(int a){posn.setX(a);}
void MagicSeg::ch_Y(int b){posn.setY(b);}
void MagicSeg::isBlink(bool a){
	blinking=a;

}


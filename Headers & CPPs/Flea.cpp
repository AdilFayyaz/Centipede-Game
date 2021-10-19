#include "Flea.h"

Flea::Flea():MoveableObject(0,0,0)
{
	int rx=-1,ry=-1;
	while(rx%20!=0 )
	{
		rx=20+rand()%1000;
		posn.setX(rx);			
	}
	ry=820;
	posn.setY(ry);
	Out=false;
}
void Flea::draw()
{
	
	DrawTriangle(posn.getX(),posn.getY(),posn.getX()+20, posn.getY(), posn.getX()+10, posn.getY()+20, colors[RED]);
}
void Flea::move()
{
	int temp;
	if(posn.getY()>0 && isTime())
	{
		temp=posn.getY()-10;
		posn.setY(temp);
		
	}
}
bool Flea::isTime()
{
	if(allow==true)
	return 1;
	else
	return 0;
	
}
void Flea::hasAllowed( bool a)
{
	if(a==1)
	{
		allow=1;
	}
	else
	allow=0;
}
void Flea::copyToArray(Board *b)
{
	if(posn.getX()%20==0 && posn.getY()%20==0)
	b->board_array[posn.getX()/20-1][posn.getY()/20-1]=6;
	
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
*/
//	int flag;
//	flag=collision(x);
//	return flag;
	
}

void Flea::set_X(int a){posn.setX(a);}
void Flea::set_Y(int a){posn.setY(a);}

int Flea::get_X(){return posn.getX();}
int Flea::get_Y(){return posn.getY();}

int Flea::collision(Board *b)
{
	if(b->board_array[posn.getX()/20-1][posn.getY()/20-1]==3)
	{
		Out=true;
		if(posn.getY()>20)
		{	
		//	posn.setY(0);
			cout<<"Detected Bullet...."<<endl;
		}
		
		b->board_array[posn.getX()/20-1][posn.getY()/20-1]=0;
		
		return 1;
	}
	if(b->board_array[posn.getX()/20-1][posn.getY()/20-1]==2)
	{
		b->board_array[posn.getX()/20-1][posn.getY()/20-1]=0;
		return 2;
	}
}
bool Flea::getOut(){return Out;}


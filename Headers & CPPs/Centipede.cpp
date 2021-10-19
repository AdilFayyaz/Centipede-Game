#include "Centipede.h"

void Centipede::move()
{
	int tempx,tempy;
	if(blinks==0)
	{
		seg[0]->draw();
	}
	else
	{
		int j=rand()%2;
		if(j==0)
		seg[0]->drawBlink();
		else
		seg[0]->draw();
	}
	seg[0]->move();
	
	for(int i=1;i<size;i++)
	{
		seg[i]->draw();
		seg[i]->move();	
	}
	seg[size]=NULL;
	
}
void Centipede::moves()
{
	nseg[0]->draw();
	nseg[0]->move();
	
	for(int i=1;i<size;i++)
	{
		nseg[i]->draw();
		nseg[i]->move();	
	}

}
Centipede::Centipede(int a,int x,int y)
{
	flag=0;
	size=a;
	seg=new Segment*[size];
	seg[0]=new MagicSeg(x,y);
	for(int i=1;i<size;i++)
	{
		x-=20;
		seg[i]=new LazySeg(x,y);
	}
}
Centipede::Centipede(int a)
{
	flag=0;
	size=a;
	int x=1000;
	int y=820;
	seg=new Segment*[size];
	seg[0]=new MagicSeg(800,820);
	//seg[0]->draw();
	//seg[0]->move();
	for(int i=1;i<size;i++)
	{
		x-=20;
		seg[i]=new LazySeg(x,y);
		//seg[i]->draw();
		//seg[i]->move();
	}
}
Centipede::Centipede()
{
	flag=0;
	size=10;
	int x=1000;
	int y=820;
	seg=new Segment*[size+10];
	seg[0]=new MagicSeg(800,820);
	for(int i=1;i<size;i++)
	{
		x-=20;
		seg[i]=new LazySeg(x,y);
	}
}

void Centipede::copyToArray(Board* b)
{
	
	//int tempx,tempy;
	int tailx,taily;
	int startx,starty;
	
	seg[0]->copyToArray(b);
	//flag=seg[0]->collision(b);
	for(int i=1;i<size;i++)
	{
		seg[i]->copyToArray(b);
	}
	
	for(int i=0;i<size;i++)
	{

		flag=seg[i]->collision(b);
		
		if(flag!=0)
		{
			tempx=seg[i]->get_X();
			tempy=seg[i]->get_Y();
			
		/*	if(tempy<120)
			{
				cout<<"New should be called..";
				seg[size]=new MagicSeg(tempx,tempy);
				size++;
			}
			*/
			if(flag==3)
			{
			//	delete[] seg[i];     ///line added
				seg[i]=new MagicSeg(tempx,tempy);//line added
			}
			if(flag==2)
			{
				
				for(int k=i;k<size-1;k++)
				{	seg[k]=seg[k+1];}
				delete[] seg[i];
				seg[i+1]=new MagicSeg(tempx,tempy);				
			}
			
		//	int loopx=tempx;//line added
		
			break;
		}
	}
	
}
int Centipede::getFlag()
{
	return flag;
}
int Centipede::collision(Board* b)
{
	seg[0]->isBlink(blinks);
	seg[0]->collision(b);
	for(int i=1;i<size;i++)
	seg[i]->collision(b);
}

int Centipede::getTempX(){return tempx;}
int Centipede::getTempY(){return tempy;}
int Centipede::getNSize(){return nsize;}
void Centipede::blink(bool a)
{
	blinks=a;

}

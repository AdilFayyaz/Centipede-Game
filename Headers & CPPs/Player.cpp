#include "Player.h"

Player::Player(int a ,int b):MoveableObject(0,0,0)
{
	posn.setX(a);
	posn.setY(b);
}
void Player::draw()
{
	if(posn.getY()<120)
	{
		DrawSquare(posn.getX(),posn.getY(),20,colors[4]);
		b->board_array[(posn.getX()/20)-1][(posn.getY()/20)-1]=2;
	}
}
void Player::getPosn(int a)
{
	newPosn=a;
}
void Player::move()
{
	int playerX,playerY;
	
	if(newPosn==0)
	{
		if(posn.getX()<980 && posn.getX()>20 )
		{
			
		//	if(b->board_array[(posn.getX()-20)/51][posn.getY()/42]==0)
			{
				//cout<<"XXXX"<<posn.getX()<<"YYYY"<<posn.getY()<<endl;
				DrawSquare(posn.getX(),posn.getY(),20,colors[BLACK]);
				b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=0;
				playerX=posn.getX()-20;
				posn.setX(playerX);
				b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=2;
				DrawSquare(posn.getX(),posn.getY(),20,colors[4]);
			}
		}
		else if(posn.getX()>=980)
		{
			DrawSquare(posn.getX(),posn.getY(),20,colors[BLACK]);
			playerX=posn.getX()-20;
			posn.setX(playerX);
			b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=2;
			DrawSquare(posn.getX(),posn.getY(),20,colors[4]);	
		}
		else if(posn.getX()<=20)
		{
			DrawSquare(posn.getX(),posn.getY(),20,colors[BLACK]);
			playerX=posn.getX()+20;
			posn.setX(playerX);
			b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=2;
			DrawSquare(posn.getX(),posn.getY(),20,colors[4]);
		}	
	}
	else if(newPosn==1)
	{
			
		if(posn.getX()<980 && posn.getX()>20 )
		{
			
		//	if(b->board_array[(posn.getX()+20)/51][posn.getY()/42]==0)
			{
				DrawSquare(posn.getX(),posn.getY(),20,colors[BLACK]);
				b->board_array[(posn.getX()/20) -1][(posn.getY()/20) -1]=0;
				playerX=posn.getX()+20;
				posn.setX(playerX);
				b->board_array[(posn.getX()/20) -1][(posn.getY()/20) -1]=2;
				DrawSquare(posn.getX(),posn.getY(),20,colors[4]);
			}
		}
		else if(posn.getX()>=980)
		{
			DrawSquare(posn.getX(),posn.getY(),20,colors[BLACK]);
			playerX=posn.getX()-20;
			posn.setX(playerX);
			b->board_array[(posn.getX()/20) -1][(posn.getY()/20 )-1]=2;
			DrawSquare(posn.getX(),posn.getY(),20,colors[4]);	
		}
		else if(posn.getX()<=20)
		{
			DrawSquare(posn.getX(),posn.getY(),20,colors[BLACK]);
			playerX=posn.getX()+20;
			posn.setX(playerX);
			b->board_array[(posn.getX()/20) -1][(posn.getY()/20) -1]=2;
			DrawSquare(posn.getX(),posn.getY(),20,colors[4]);
		}
	}
	else if(newPosn==2)
	{
		if(posn.getY()<120 && posn.getY()>20 )
		{
			
		//	if(b->board_array[posn.getX()/51][(posn.getY()+20)/42]==0)
			{
				DrawSquare(posn.getX(),posn.getY(),20,colors[BLACK]);
				b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=0;
				playerY=posn.getY()+20;
				posn.setY(playerY);
				b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=2;
				DrawSquare(posn.getX(),posn.getY(),20,colors[4]);
			}
		}
		else if(posn.getY()>=120)
		{
			DrawSquare(posn.getX(),posn.getY(),20,colors[BLACK]);
			playerY=posn.getY()-20;
			posn.setY(playerY);
			b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=2;
			DrawSquare(posn.getX(),posn.getY(),20,colors[4]);	
		}
		else if(posn.getY()<=20)
		{
			DrawSquare(posn.getX(),posn.getY(),20,colors[BLACK]);
			playerY=posn.getY()+20;
			posn.setY(playerY);
			b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=2;
			DrawSquare(posn.getX(),posn.getY(),20,colors[4]);
		}
	}
	else if(newPosn==3)
	{
		if(posn.getY()<120 && posn.getY()>20 )
		{
			
		//	if(b->board_array[posn.getX()/51][(posn.getY()-20)/42]==0)
			{
				DrawSquare(posn.getX(),posn.getY(),20,colors[BLACK]);
				b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=0;
				playerY=posn.getY()-20;
				posn.setY(playerY);
				b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=2;
				DrawSquare(posn.getX(),posn.getY(),20,colors[4]);
			}
		}
		else if(posn.getY()>=120)
		{
			DrawSquare(posn.getX(),posn.getY(),20,colors[BLACK]);
			playerY=posn.getY()-20;
			posn.setY(playerY);
			b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=2;
			DrawSquare(posn.getX(),posn.getY(),20,colors[4]);	
		}
	
		else if(posn.getY()<=20)
		{
			DrawSquare(posn.getX(),posn.getY(),20,colors[BLACK]);
			playerY=posn.getY()+20;
			posn.setY(playerY);
			b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=2;
			DrawSquare(posn.getX(),posn.getY(),20,colors[4]);
		}
	}
	

}
int Player::returnX(){return posn.getX();}
int Player::returnY(){return posn.getY();}


void copyToArray(int c[52][41])
{
	b.board_array=&c;
}






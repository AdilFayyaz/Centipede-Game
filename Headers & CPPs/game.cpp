//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "Board.h"
#include "GameObject.h"
#include "GameObject.cpp"
#include "MoveableObject.h"
#include "MoveableObject.cpp"
//#include "Player.h"
//#include "Player.cpp"
//#include "Mushroom.h"
#include "Mushroom.cpp"
#include "ScoreBoard.h"
#include "ScoreBoard.cpp"
#include "Position.h"
#include "Position.cpp"
#include "Segment.cpp"
#include "Segment.h"
#include "MagicSeg.cpp"
#include "LazySeg.cpp"
#include "Centipede.cpp"
#include "Scorpian.cpp"
#include "Flea.cpp"
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
//Functions
void GameDisplay();

//Global Variables
int newPosn=-1;
Board *b;

time_t t1=time(0);
ScoreBoard S;


/// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
//Draw BackGround
void BG()
{
	for(int a=0;a<80;a++)
    	{
    		for(int b=0;b<60;b++)
    		{
    			DrawSquare( a*10 , b*10 ,10,colors[81]); 
    		}
    	}
}

//
//Border
void Border()
{
	DrawLine(0,0,0,1020,8,colors[64]);
	DrawLine(0,0,1020,0,8,colors[64]);
	DrawLine(1020,0,1020,840,8,colors[64]);
	DrawLine(1020,840,0,840,8,colors[64]);
}

///class Player

class Player:public MoveableObject{
	private:
	bool Out;
	public:
	Player(int=30,int=30);
	void move();
	void draw();
	int returnX();
	int returnY();
	void die();
	bool getOut();
};
Player::Player(int a ,int b):MoveableObject(0,0,0)
{
	posn.setX(a); 
	posn.setY(b);
}
void Player::draw()
{
	if(posn.getY()<=10)
	{
		DrawSquare(posn.getX(),posn.getY(),20,colors[BLACK]);
		b->board_array[(posn.getX()/20)-1][(posn.getY()/20)-1]=0;
		Out=true;
	} 
	if(posn.getY()<120)
	{ 
		DrawRoundRect(posn.getX(),posn.getY()+20, 10, 10, colors[7], 20.0);
		//DrawSquare(posn.getX(),posn.getY(),20,colors[4]);
		b->board_array[(posn.getX()/20)-1][(posn.getY()/20)-1]=2;
	}
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
				DrawRoundRect(posn.getX(),posn.getY()+20, 20, 10, colors[4], 20.0);
				DrawSquare(posn.getX(),posn.getY(),20,colors[4]);
			}
		}
		else if(posn.getX()>=980)
		{
			DrawSquare(posn.getX(),posn.getY(),20,colors[BLACK]);
			playerX=posn.getX()-20;
			posn.setX(playerX);
			b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=2;
			DrawRoundRect(posn.getX(),posn.getY()+20, 20, 10, colors[4], 20.0);
			DrawSquare(posn.getX(),posn.getY(),20,colors[4]);	
		}
		else if(posn.getX()<=20)
		{
			DrawSquare(posn.getX(),posn.getY(),20,colors[BLACK]);
			playerX=posn.getX()+20;
			posn.setX(playerX);
			b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=2;
			DrawRoundRect(posn.getX(),posn.getY()+20, 20, 10, colors[4], 20.0);
			DrawSquare(posn.getX(),posn.getY(),20,colors[4]);
		}	
	}
	else if(newPosn==1) 
	{
			
		if(posn.getX()<980 && posn.getX()>20 )
		{
			
		//	 if(b->board_array[(posn.getX()+20)/51][posn.getY()/42]==0)
			{
				DrawSquare(posn.getX(),posn.getY(),20,colors[BLACK]);
				b->board_array[(posn.getX()/20) -1][(posn.getY()/20) -1]=0;
				playerX=posn.getX()+20;
				posn.setX(playerX);
				b->board_array[(posn.getX()/20) -1][(posn.getY()/20) -1]=2;
				DrawRoundRect(posn.getX(),posn.getY()+20, 20, 10, colors[4], 20.0);
				DrawSquare(posn.getX(),posn.getY(),20,colors[4]);
			}
		}
		else if(posn.getX()>=980)
		{
			DrawSquare(posn.getX(),posn.getY(),20,colors[BLACK]);
			playerX=posn.getX()-20;
			posn.setX(playerX);
			b->board_array[(posn.getX()/20) -1][(posn.getY()/20 )-1]=2;
			DrawRoundRect(posn.getX(),posn.getY()+20, 20, 10, colors[4], 20.0);
			DrawSquare(posn.getX(),posn.getY(),20,colors[4]);	
		}
		else if(posn.getX()<=20)
		{
			DrawSquare(posn.getX(),posn.getY(),20,colors[BLACK]);
			playerX=posn.getX()+20;
			posn.setX(playerX);
			b->board_array[(posn.getX()/20) -1][(posn.getY()/20) -1]=2;
			DrawRoundRect(posn.getX(),posn.getY()+20, 20, 10, colors[4], 20.0);
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
				DrawRoundRect(posn.getX(),posn.getY()+20, 20, 10, colors[4], 20.0);
				DrawSquare(posn.getX(),posn.getY(),20,colors[4]);
			}
		}
		else if(posn.getY()>=120) 
		{
			DrawSquare(posn.getX(),posn.getY(),20,colors[BLACK]);
			playerY=posn.getY()-20;
			posn.setY(playerY);
			b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=2;
		  	DrawRoundRect(posn.getX(),posn.getY()+20, 20, 10, colors[4], 20.0);
			DrawSquare(posn.getX(),posn.getY(),20,colors[4]);	
		} 
		else if(posn.getY()<=20)
		{
			DrawSquare(posn.getX(),posn.getY(),20,colors[BLACK]);
			playerY=posn.getY()+20;
			posn.setY(playerY);
			b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=2;
			DrawRoundRect(posn.getX(),posn.getY()+20, 20, 10, colors[4], 20.0);
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
				DrawRoundRect(posn.getX(),posn.getY()+20, 20, 10, colors[4], 20.0);
				DrawSquare(posn.getX(),posn.getY(),20,colors[4]);
			}
		}
		else if(posn.getY()>=120)
		{
			DrawSquare(posn.getX(),posn.getY(),20,colors[BLACK]);
			playerY=posn.getY()-20;
			posn.setY(playerY);
			b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=2;
			DrawRoundRect(posn.getX(),posn.getY()+20, 20, 10, colors[4], 20.0);
			DrawSquare(posn.getX(),posn.getY(),20,colors[4]);	
		}
	
		else if(posn.getY()<=20)
		{
			DrawSquare(posn.getX(),posn.getY(),20,colors[BLACK]);
			playerY=posn.getY()+20;
			posn.setY(playerY);
			b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=2;
			DrawRoundRect(posn.getX(),posn.getY()+20, 20, 10, colors[4], 20.0);
			DrawSquare(posn.getX(),posn.getY(),20,colors[4]);
		}
	}
	

}
int Player::returnX(){return posn.getX();}
int Player::returnY(){return posn.getY();}
void Player::die()
{
	b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=0;
	posn.setX(1000);
	posn.setY(1000); 
	DrawSquare(posn.getX(),posn.getY(),20,colors[BLACK]);
}
bool Player::getOut(){return Out;}

GameObject **obj=new GameObject*[5];

Player A(60,40);
int size=20;
//Mushroom *B=new Mushroom[100];
Mushroom *B;  
//MagicSeg D(960,820);
//LazySeg E(980,820); 
Centipede F(10);
// 
//class Bomb 
class Bomb:public MoveableObject
{
	private:
	
	int Bul;
	int noOfHits;
	public:
	Bomb();
	bool getBul();
	void setBul(int);
	void move();
	void draw();
	int get_posn_y();
	int get_posn_x();
	bool collision();
	int getNoOfHits(); 
	void setNoOfHits(int);
	
};
Bomb::Bomb():MoveableObject(0,0,0){
	//DrawRectangle(A.returnX(), A.returnY(), 10, 20, colors[RED]);
	posn.setX(A.returnX());
	posn.setY(A.returnY());
	noOfHits=0;

}

void Bomb::draw()
{
	
	b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=3;
	DrawRoundRect(A.returnX()+5,posn.getY()+20, 8, 20, colors[RED], 10.0);
	posn.setX(A.returnX());

}  
void Bomb::move()
{
	int tempx,tempy; 
	
	if(posn.getY()<840)
	{
	
		DrawRoundRect(posn.getX()+5,posn.getY()+20, 10, 20, colors[BLACK], 10.0);
		b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=0;
		tempx=posn.getX();
		tempy=posn.getY()+20;
		posn.setX(tempx);
		posn.setY(tempy);
		b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=3;
		DrawRoundRect(posn.getX()+5,posn.getY(), 8, 20, colors[RED], 10.0);
	
		
	}
}
bool Bomb::getBul()
{	
	if(Bul==1)
	{
		if(posn.getY()>=840)
		{
			posn.setY(A.returnY()+20);
		}
		return 1;
	}
	else
	{
		return 0;
	}
}
void Bomb::setBul(int x)
{ 
	Bul=x;
	if(Bul==0)
	{
		DrawRoundRect(posn.getX()+5,posn.getY(), 8, 20, colors[BLACK], 10.0);
		b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=0;
	}
}

int Bomb::get_posn_y()
{
	return posn.getY();
}
int Bomb::get_posn_x()
{
	return posn.getX();
}
bool Bomb::collision()
{
/*	for(int i=0;i<20;i++)
	{
		if(B[i].get)
	}*/
	
	if(b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]==1)
	{
	noOfHits++;

		if(noOfHits==2)
		{
	//	cout<<"2 times hit"<<endl;
		DrawRectangle(posn.getX(), posn.getY(), 20, 20, colors[BLACK]);
		b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=0;
		
		}
		else if(noOfHits==1){
	//	cout<<"1 times hit"<<endl;
		DrawRectangle(posn.getX(), posn.getY(), 20, 20, colors[GREEN]);
		}
		
		posn.setX(A.returnX());
		posn.setY(A.returnY());
		
		setBul(0);
		
		if(noOfHits==2)
		//noOfHits=0;
		return true;

	}
	else if(b->board_array[posn.getX()/20-1][posn.getY()/20 -1]==6)
	{
		
		DrawRectangle(posn.getX(), posn.getY(), 60, 60, colors[BLACK]);
		b->board_array[posn.getX()/20 -1][posn.getY()/20 -1]=0;
		posn.setX(A.returnX());
		posn.setY(A.returnY());
		   
		
		setBul(0);
	}
	
}
int Bomb::getNoOfHits(){return noOfHits;}
void Bomb::setNoOfHits(int a){noOfHits=a;}

int i=-1;int j=0;

Bomb C;
//int max=20;
Flea G;

time_t t2=time(0);
time_t t3=time(0);
int count=3;
Scorpian Sp;
int ch;
int copyi;
int over;
/*
 * Main Canvas drawing function.
 * */

void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0.0/*Red Component*/, 0.0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	
	/*for(int k=0;k<51;k++)
	{
		for(int j=0;j<42;j++)
		{
			DrawSquare(k*20, j*20, 19, colors[PINK]);
		}
	}*/
	        
	Border();
	if(!A.getOut())
	A.draw();	

	bool z;
	int hits;
	int x;
	
		for(x=0;x<size;x++)
		{
	 		B[x].draw();
			B[x].copyToArray(b);
		
			z=C.collision();
			hits=C.getNoOfHits();
			if(z && hits==2)
			{
				S.AddScore(1);
				for(int a=x;a<size;a++)
				{
				  	B[a]=B[a+1];
				}
			  	size--;	
			 	C.setNoOfHits(0);
			}
		}
	
	int cnt=0;
	if(time(0)-t2>=11 && time(0)-t2<=13)
	{
		
		G.draw();
		G.hasAllowed(1);
		//int ch=G.copyToArray(b);
		G.copyToArray(b);
		int ch=G.collision(b);
		if(ch==2)
		{
			//cout<<"DIEEE";
			over=1;
			A.die();
		}
		if(ch==1)
		{
			S.AddScore(200);
		}
		if(!G.getOut())
		G.move();
		bool p=G.isTime();
		if(p==1 )
		{
			
			int rnd(rand()%100);
			if(rnd>95)
			{
				int xx=G.get_X();
				int yy=G.get_Y();
				B[size].makeNew(xx,yy);
				B[size].copyToArray(b);
				size++; 
			}  
		} 
	}
		 
	else if(time(0)-t2>13)
	{
		G.hasAllowed(0);
		t2=time(0);
		int rx=-1,ry=-1;
		while(rx%20!=0 )
		{
			rx=20+rand()%1000;
			G.set_X(rx);			
		}
		ry=820;
		G.set_Y(ry);	
	}
	cnt++;
	
	if(time(0)-t3>=15 && time(0)-t3<=16)
	{
		Sp.draw();
		Sp.move();
		Sp.hasAllowed(1);
		Sp.copyToArray(b);
		ch=Sp.collision(b);
		
		int g=Sp.get_X();
		
		for(int i=0;i<size;i++)
		{
			int a=B[i].collision(b);
			if(a==1)
			{
				copyi=i;
				
				//cout<<"Mushroom poisoned..."<<endl;
			}
		}
		
		if(g<=20)
		{
			t3-=10;
		}
		
		
	}
	if(time(0)-t3>16)
	{
		Sp.hasAllowed(0);
		t3=time(0);
		int rx=-1,ry=-1;
		while(ry%20!=0)
		{
			ry=20+rand()%1000;
			Sp.set_Y(ry);			
		}
		rx=980;  
		Sp.set_X(rx);  
	}
	B[copyi].poison(b);
	
	  
	
	if(C.getBul())
	{
		C.move();
	}
	if(C.get_posn_y()>=840)
	{
		C.setBul(0);
	} 
		

	S.draw();
	
	if(time(0)-t1>=0 && time(0)-t1<=5)  
	{F.blink(1);}
	else if(time(0)-t1>5 && time(0)-t1<10)
	{
		F.blink(0); 
	}
	else if(time(0)-t1>10)
	{
		t1=time(0);
	}
	 
	F.move();   
	
	F.copyToArray(b);
	int flag=F.getFlag();
	 //cout<<"FLag is: "<<flag<<endl;
	if(flag==2)
	{
		S.AddScore(100);
		//max++;
		/*B[size].draw();
		B[size].copyToArray(b);
		size++;*/
		int xx=F.getTempX();      
		int yy=F.getTempY();
		if(xx%20!=0)
		{
			xx+(xx%20); 
		}
		if(yy%20!=0)
		{ 
			yy+(yy%20);
		} 
		B[size].makeNew(xx,yy);
		B[size].copyToArray(b); 
		size++;
		   
	}    
	else if(flag==3)      
	{   
		// cout<<"In main flag=3"<<endl;
		S.AddScore(10); 
		int xx=F.getTempX();
		int yy=F.getTempY();
		if(xx%20!=0)
		{  
			xx+(xx%20);
		}
		if(yy%20!=0) 
		{
			yy+(yy%20);
		}
		//cout<<xx<<" "<<yy<<endl;
		B[size].makeNew(xx,yy); 
		B[size].copyToArray(b);
		size++;
	}
	else if(flag==4)
	{
		over=1;
		
		//DrawString(510, 420, "GAME OVER", colors[RED]);
	}
	if(over==1){
		for(int k=0;k<51;k++)
		{
			for(int j=0;j<42;j++)
			{
				DrawSquare(k*20, j*20, 50, colors[BLACK]);
			}
		}
		//DrawSquare(1020,840,856800,colors[BLACK]);
		DrawString(90000, 100000, 510, 420, "GAME OVER!",colors[RED]);
	}
	
	glutPostRedisplay();
	glutSwapBuffers(); // do not modify this line..

}
/*void display()
{
	Mushroom B(20);
	B.draw();
	cou;t<<"In display function.."<<endl;	
}*/

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */


void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
			newPosn=0;
				
			A.move();
	
	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
			newPosn=1;	
			A.move();

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
			newPosn=2;	
			A.move();
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
			newPosn=3;	
			A.move();
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		C.draw();
		C.setBul(1);
		
		
	//	cout << "b pressed" << endl;

	}
	
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();   
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *  
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	b = new Board(20, 20); // create a new board object to use in the Display Function ...
	
	
	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	b->InitalizeBoard(width, height);
	
	
	InitRandomizer(); // seed the random number generator...
	B=new Mushroom[100];
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Adil's Centipede Game"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
	
	
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

//	glutMouseFunc(MouseClicked);
//	glutPassiveMotionFunc(MouseMoved); // Mouse
//	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	
	glutMainLoop();
	//system("canberra-gtk-play -f Electro.wav");
	
	
	
	
	
	return 1;
}


#endif /* AsteroidS_CPP_ */

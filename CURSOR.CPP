/****************************************************************************
*****************************************************************************
*****									*****
***** TITLE: 	   'Cursor' class					*****
***** DESCRIPTION: The function of 'Cursor' class is to move the cursor *****
*****		   on the board and store it. When a function is called	*****
*****		   to get the current cursor position, it returns the 	*****
*****		   value of current cursor position.			*****
*****									*****
*****************************************************************************
*****************************************************************************/

//	## Include Files Predefined Header Files ##

#include<iostream.h>
#include<conio.h>
#include<graphics.h>

//	## Definition of Class 'Word' ##

class Cursor
{
 //Data Members
 int x,y;
 int r,c;
public:
 //Member Function
 char steer(int,int,int,int,int,int,int);         //steers the cursor position
						  //on board
 void current_position(int &a,int &b)             //sets the parameter value
 {                                                //to current postions
  a=r;
  b=c;
 }
};

//	## Definition of Cursor::steer() ##
char Cursor::steer(int x1=0,int y1=0,int x2=639,int y2=479,int xleap=1,int yleap=1,int spacing=25)
{
 x=x1;y=y1;
 r=0;c=0;
 char a,b;
 while(1)
 {
  moveto(x+(spacing/2+3),y+(spacing/2+3));
  setcolor(WHITE);
  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  outtext("*");
  a=getch();
  b=getch();
  if(a!=(char)0)return a;
  switch(b)
  {
   case (char)72:if(y-yleap>=y1)
		 {
		  y-=yleap;
		  r--;
		 }
		 break;
   case (char)80:if(y+yleap<=y2)
		 {
		  y+=yleap;
		  r++;
		 }
		 break;
   case (char)75:if(x-xleap>=x1)
		 {
		  x-=xleap;
		  c--;
		 }
		 break;
   case (char)77:if(x+xleap<=x2)
		 {
		  x+=xleap;
		  c++;
		 }
		 break;
  };
  gotoxy(x,y);
 }
}


/*************************** End of CURSOR.CPP *********************************/
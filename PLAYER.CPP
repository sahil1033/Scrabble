/****************************************************************************
*****************************************************************************
*****									*****
***** TITLE	 : 'Player' class					*****
***** DESCRIPTION: The 'Player' class asks users to input their screen	*****
*****		   name and then display it along with their current 	*****
*****		   respective points. It randomizes and allots the rack	*****
*****		   to both the players. Also, it  returns the score of  *****
*****		   both the players for comparison so that winner can 	*****
*****		   be declared.					        *****
*****                                                                   *****
*****************************************************************************
*****************************************************************************/

//	## Include Files Predefined Header Files ##

#include<iostream.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

//	## Global Variables ##

//Frequency of each letter
int freq[27]={9,2,2,4,12,2,3,2,9,1,1,4,2,6,8,2,1,6,4,6,4,2,2,1,2,1,2};
	    //A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,+

//	## Definition of Class 'PLAYER' ##

class Player
{
 //	Data Members
 char name[25];
 char letter[7];
 int points;

public:

 //Member Function prototypes
 Player();		//constructor to intialise object
 void setname();	//take input of player name
 void getname(int,int);	//prints the name of player on screen
 void getpoint(int,int);//prints the name of player on screen
 int getpoint()         //returns points of player
 {
  return points;
 }
 void get_random_letter(int);	//generates a random letter
 void set_point(int);           //increments points returned from 'Word' Class
 int  rack_check(char);         //checks whether char x is in the rack
 void renew_letters(int);	//renew letters of rack
 int  use_letter(char);         //use letter from rack
 void back_letter(char,int);	//if not valid word is formed, rollback rack
				//changes done in rack
 void get_rack(int,int);	//prints rack on-screen
};

//	## Definition of constructor,Player::player() ##
Player::Player()
{
 points=0;
 for(int i=0;i<7;i++)
  letter[i]='\0';
}

//	## Definition of Player::setname() ##
void Player::setname()
{
 char a;
 settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
 setcolor(YELLOW);
 int i=-1;
 while(i<5)
 {
  a=getch();
  if(a==' ')
   break;
  else if(a==(char)0)
  {
   getch();
   break;
  }
  else if(isdigit(a) && i ==-1)
   continue;
  else
  {
   i++;
   name[i]=a;
   name[i+1]='\0';
  }
  outtextxy(250,230,name);
  if(i+1==5)
  {
   while(getch()==(char)0);
    break;
  }
 }
 if(i==-1)strcpy(name,"PLYR#");
}

//	## Definition of Player::getname(int,int) ##
void Player::getname(int x,int y)
{
  outtextxy(x,y,name);
}

//	## Definition of getpoint(int,int) ##
void Player::getpoint(int x,int y)
{
 char str[10];
 sprintf(str,"%d",points);
 outtextxy(x,y,str);
}

//	## Definition of get_random_letter(int) ##
void Player::get_random_letter(int i)
{

 cout<<"\n";
 int x=0;
 again:
 if(random(2)==1) x=rand()%26;
 else
  switch(random(5))
  {
   case 0:x=0;break;
   case 1:x=4;break;
   case 2:x=8;break;
   case 3:x=14;break;
   case 4:x=20;break;
  }
 if(freq[x]==0)
  goto again;
 letter[i]=(char)(65+x);
 freq[x]--;
}

//	## Definition of Player::rack_check(char) ##
int Player::rack_check(char x)
{

 for(int i=0;i<7;i++)
 {
  if(x==letter[i])
   return 1;
 }

 setviewport(1,429,510,450,1);
 clearviewport();
 setviewport(0,0,getmaxx(),getmaxy(),0);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
 setfillstyle(SOLID_FILL,YELLOW);
 floodfill(2,431,WHITE);
 setcolor(RED);
 outtextxy(210,430,"This Letter is Not in Rack");
 delay(1000);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);

 return 0;
}

//	## Definition of Player::renew_letters() ##
void Player::renew_letters(int turn)
{
 if(turn==0)randomize();
 for(int i=0;i<7;i++)
 {
  if(letter[i]=='\0')
   get_random_letter(i);
 }
}

//	## Definition of Player::use_letter(char) ##
int Player::use_letter(char c)
{
  for(int i=0;i<7;i++)
  {
   if(letter[i]==c)
   {
    letter[i]='\0';
    return i;
   }
  }
  return -1;
}

//	## Definition of Player::back_letter(char,int) ##
void Player::back_letter(char c,int i)
{
  if(letter[i]=='\0')
  {
   letter[i]=c;
  }
}

//	## Definition of Player::get_rack(int,int) ##
void Player::get_rack(int x,int y)
{
 char str[2];
 setcolor(WHITE);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
 for(int i=0;i<7;i++)
 {
  if(letter[i]!='\0')
  {
   moveto(x+i*25+5,y+3);
   sprintf(str,"%c",letter[i]);
   outtext(str);
  }
  else
  {
   setviewport(x+i*25+5,y+3,x+i*25+20,y+18,0);
   clearviewport();
   setviewport(0,0,getmaxx(),getmaxy(),0);
  }
 }
}

//	## Definition of Player::set_point(int) ##
void Player::set_point(int x)
{
 points=points+x;
}


/*************************** End of PLAYER.CPP *********************************/
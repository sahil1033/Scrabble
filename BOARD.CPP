/****************************************************************************
*****************************************************************************
***** 									*****
***** TITLE:	   'Board' class					*****
***** DESCRIPTION: The design of board is stored and displayed in this	*****
*****		   class. Tile type along with their functionality is	*****
*****		   also stored in this class. The letters placed on the	*****
*****		   board is stored and displayed. It also validates	*****
*****		   the position of word on board			*****
*****									*****
*****************************************************************************
*****************************************************************************/

//	## Include Files Predefined Header Files ##

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>

//	## Include Files User defined Header Files ##

#include "WORD.CPP"

//	## Prototype of Function(s) ##

class Board
{
 //Data Members
 Word w;
 int flag;
 char tile[MAX_LEN][MAX_LEN];
 int tileState[MAX_LEN][MAX_LEN];
 char tileType[MAX_LEN][MAX_LEN];
public:

 //Member Function protypes
 Board();
 void print(int,int);
 void tentative_insert(char ,int ,int);
 int  permanent_insert(int);
 void  tentative_remove();
 void print_grid(int,int);
 int points_calculator();
 void renew_word();
 int validator(int);
 char charat(int x,int y)
 {
  return tile[x][y];
 }
};

//	## Definition of Constructor,Board::Board()  ##
Board::Board()
{
 flag=0;
 for(int i=0;i<MAX_LEN;i++)
  for(int j=0;j<MAX_LEN;j++)
  {
   tile[i][j]='_';
   tileState[i][j]=0;
   tileType[i][j]='x';
  }
 tileType[0][0]='a';
 tileType[0][3]='b';
 tileType[0][7]='a';
 tileType[0][11]='b';
 tileType[0][14]='a';

 tileType[1][1]='c';
 tileType[1][5]='d';
 tileType[1][9]='d';
 tileType[1][13]='c';

 tileType[2][2]='c';
 tileType[2][6]='b';
 tileType[2][8]='b';
 tileType[2][12]='c';

 tileType[3][0]='b';
 tileType[3][3]='c';
 tileType[3][7]='b';
 tileType[3][11]='c';
 tileType[3][14]='b';

 tileType[4][4]='c';
 tileType[4][10]='c';


 tileType[5][1]='d';
 tileType[5][5]='d';
 tileType[5][9]='d';
 tileType[5][13]='d';


 tileType[6][2]='b';
 tileType[6][6]='b';
 tileType[6][8]='b';
 tileType[6][12]='b';

 tileType[7][0]='a';
 tileType[7][3]='b';
 tileType[7][7]='c';
 tileType[7][11]='b';
 tileType[7][14]='a';

 tileType[14][0]='a';
 tileType[14][3]='b';
 tileType[14][7]='a';
 tileType[14][11]='b';
 tileType[14][14]='a';

 tileType[13][1]='c';
 tileType[13][5]='d';
 tileType[13][9]='d';
 tileType[13][13]='c';

 tileType[12][2]='c';
 tileType[12][6]='b';
 tileType[12][8]='b';
 tileType[12][12]='c';

 tileType[11][0]='b';
 tileType[11][3]='c';
 tileType[11][7]='b';
 tileType[11][11]='c';
 tileType[11][14]='b';

 tileType[10][4]='c';
 tileType[10][10]='c';


 tileType[9][1]='d';
 tileType[9][5]='d';
 tileType[9][9]='d';
 tileType[9][13]='d';

 tileType[8][2]='b';
 tileType[8][6]='b';
 tileType[8][8]='b';
 tileType[8][12]='b';
}

//	## Definition of Constructor,Board::print_grid(int,int)  ##
void Board::print_grid(int x=135,int y=50)
{
 int n=16;
 int i=0;
 setcolor(WHITE);
 for(i=0;i<n;i++)
 {
  line(x+i*25,y,x+i*25,y+(n-1)*25);
  line(x,y+i*25,(n-1)*25+x,y+i*25);
 }
 for(i=0;i<15;i++)
  for(int j=0;j<15;j++)
     switch(tileType[i][j])
     {
      case 'a':setfillstyle(SOLID_FILL, RED);
	       floodfill((x+1+(25*j)),(y+1+(25*i)),WHITE);
	       break;
      case 'b':setfillstyle(SOLID_FILL, CYAN);
	       floodfill((x+1+(25*j)),(y+1+(25*i)),WHITE);
	       break;
      case 'c':setfillstyle(SOLID_FILL, MAGENTA);
	       floodfill((x+1+(25*j)),(y+1+(25*i)),WHITE);
	       break;
      case 'd':setfillstyle(SOLID_FILL, BLUE);
	       floodfill((x+1+(25*j)),(y+1+(25*i)),WHITE);
	       break;
     }
 x=235;y=455;
 line(x,y,x+(25*7),y);
 line(x,y+20,x+(25*7),y+20);
 for(i=0;i<8;i++)
  line(x+i*25,y,x+i*25,y+20);

 setfillstyle(SOLID_FILL, YELLOW);
 floodfill(25,25,WHITE);
}

//	## Definition of Constructor,Board::print(int,int)  ##
void Board::print(int x=135,int y=50)
{
 char str[1];
 print_grid(x,y);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
 for(int i=0;i<MAX_LEN;i++)
 {
  for(int j=0;j<MAX_LEN;j++)
  {
   if(tile[i][j]!='_')
   {
    sprintf(str,"%c",tile[i][j]);
    outtextxy((x+6+(25*j)),(y+6+(25*i)),str);
   }
  }
 }
}

//	## Definition of Constructor,Board::tentative_insert(char,int,int)  ##
void Board::tentative_insert(char letter,int x,int y)
{
 w.input_char(letter,tileType[x][y]);
 if(tileState[x][y]==0)
 {
  tile[x][y]=letter;
  tileState[x][y]=-1;
 }
 else
  flag=1;
}

//	## Definition of Constructor,Board::renew_word()  ##
void Board::renew_word()
{
 w.renew();
 flag=0;
}

//	## Definition of Constructor,Board::permanent_insert(int)  ##
int Board::permanent_insert(int turn)
{
 if(w.validator()==1 && validator(turn)==1)
 {
  //cout<<"j";
  for(int i=0;i<MAX_LEN;i++)
   for(int j=0;j<MAX_LEN;j++)
    if(tileState[i][j]==-1)
     tileState[i][j]=1;
  return 1;
 }
 else
 {
  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  setfillstyle(SOLID_FILL,YELLOW);
  floodfill(1,430,WHITE);
  setcolor(RED);
  if(validator(turn)==0)
  if(tile[7][7]=='_')outtextxy(115,430,"Duh! Duh! Duh! You Forgot To Include The Center Tile!");
  else outtextxy(95,430,"Badamtuss! You've to make use of at least one on-board tile!");
  else outtextxy(150,430,"Error 404: Word is Not Found in Dictionary!");
  tentative_remove();
  return 0;
 }
}

//	## Definition of Constructor,Board::points_calculator()  ##
int Board::points_calculator()
{
 return w.points_calculator();
}

//	## Definition of Constructor,Board::tentative_remove()  ##
void Board::tentative_remove()
{
 for(int i=0;i<MAX_LEN;i++)
  for(int j=0;j<MAX_LEN;j++)
   if(tileState[i][j]==-1)
   {
    tileState[i][j]=0;
    tile[i][j]='_';
   }
 cout<<"\n";
}

//	## Definition of Constructor,Board::validtor(int)  ##
int Board::validator(int turn)
{
 if(turn==0)
 {
  if(tile[7][7]=='_')
   return 0;
  else return 1;
 }
 else
  return flag;
}


/*************************** End of BOARD.CPP *********************************/
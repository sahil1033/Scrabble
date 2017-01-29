/****************************************************************************
*****************************************************************************
*****									*****
***** TITLE: 	   'Game' class						*****
***** DESCRIPTION: The 'Game' class uses all the classes involved in 	*****
*****		   this program. The main functionalities dealt in this	*****
*****		   class includes displaying menu options of the game,	*****
*****		   transferring switch to the menu option selected,	*****
*****		   switching between player's chances and termination	*****
*****		   of the game.						*****
*****                                                                   *****
*****************************************************************************
*****************************************************************************/

//	## Include Files Predefined Header File ##

#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<dos.h>

//	## Include Files User defined Header File ##

#include"BOARD.CPP"
#include"CURSOR.CPP"
#include"PLAYER.CPP"
//	## Global Variables ##

static int gd=DETECT,gm,errorcode;

//	## Definition of Class 'Game'

class Game
{
 //Member Function prototypes
 static void creategraph();			//intiate graphics mode on
						//screen
 static void triangle(int,int);                 //draws triangle given position
 static void con_circle(int,int);		//draws concentric circle
 static void graph();				//draws a complete graph on
						//screen,for reference
 static void clearsection(int,int,int,int);	//clears particular section
						//of screen
 static int  main_menu();			//prints main menu of game
 static void mainplay();			//controls over all flow of
						//game, player turns data flow
 static void how_to_play();			//prints intruction of how to
						//play scrabble
 static void credits();				//prints complete credits
 static void about_game();			//shows a brief description
						//about game
public:
 static void scrabble();                        //final game function controling
						//flow of menu option
};

//	## Definition of Game::creategraph() ##
void Game::creategraph()
{
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 errorcode = graphresult();
 if (errorcode != grOk)
 {
  printf("Graphics error: %s\n", grapherrormsg(errorcode));
  printf("Press any key to halt:");
  getch();
  exit(1);
 }
}

//	## Definition of Game::triangle(int,int) ##
void Game::triangle(int x,int y)
{
   int poly[6]={x+20,y+30,x+40,y+30,x+30,y+50};
   setfillstyle(USER_FILL-1, getmaxcolor());
   fillpoly(3, poly);
}

//	## Definition of Game::con_circle(int,int) ##
void Game::con_circle(int x,int y)
{
 int i=0;
 settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
 int a;
 a=rand();
 if(a==WHITE)a=RED;
 setcolor(a);
 char s[]="SCRABBLE";
 for(i=0;i<25;i++)
 {
  circle(x,y,i);
  setcolor(WHITE);
  outtextxy(180,200,s);
  setcolor(a);
 }
 a=rand();
 if(a==WHITE)a=RED;
 setcolor(a);
 for(i=40;i<60;i++)
 {
  circle(x,y,i);
  setcolor(WHITE);
  outtextxy(180,200,s);
  setcolor(a);
 }
 a=rand();
 if(a==WHITE)a=RED;
 setcolor(a);

 for(i=80;i<100;i++)
 {
  circle(x,y,i);
  setcolor(WHITE);
  outtextxy(180,200,s);
  setcolor(a);
 }
 a=rand();
 if(a==WHITE)a=RED;
 setcolor(a);

 for(i=120;i<130;i++)
 {
  circle(x,y,i);
  setcolor(WHITE);
  outtextxy(180,200,s);
  setcolor(a);
 }
}
//	## Definition of Game::graph() ##
void Game::graph()
{
for(int i=0;i<getmaxx();i++)
  if(i%2==0)line(i,0,i,getmaxy());
for(int j=0;j<getmaxy();j++)
  if(j%2==0)line(0,j,getmaxy(),j);
}

//	## Definition of Game::clearsection(int,int,int,int) ##
void Game::clearsection(int x1,int y1,int x2,int y2)
{
 setviewport(x1,y1,x2,y2,1);
 clearviewport();
 setviewport(0,0,getmaxx(),getmaxy(),0);
}

//	## Definition of Game::main_menu() ##
int Game::main_menu()
{
 cleardevice();
 int option=1;
 char a,b;
 while(1)
 {
  if(option == 1)
  {
   clearsection(210,40,450,100);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
   setcolor(RED);
   outtextxy(220,40,"play game");
  }
  else
  {
   clearsection(210,40,450,100);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
   setcolor(WHITE);
   outtextxy(235,50,"play game");
  }
  if(option == 2)
  {
   clearsection(490,180,615,260);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
   setcolor(RED);
   outtextxy(495,180,"about");
   outtextxy(495,205,"game");
  }
  else
  {
   clearsection(490,180,615,260);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
   setcolor(WHITE);
   outtextxy(510,190,"about");
   outtextxy(510,215,"game");
  }
  if(option == 3)
  {
   clearsection(415,390,520,450);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
   setcolor(RED);
   outtextxy(415,390,"exit");
  }
  else
  {
   clearsection(415,390,520,450);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
   setcolor(WHITE);
   outtextxy(425,400,"exit");
  }
  if(option == 4)
  {
   clearsection(150,390,310,450);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
   setcolor(RED);
   outtextxy(150,390,"credits");
  }
  else
  {
   clearsection(140,390,310,450);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
   setcolor(WHITE);
   outtextxy(160,400,"credits");
  }
  if(option == 5)
  {
   clearsection(20,180,175,275);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
   setcolor(RED);
   outtextxy(25,180,"how to");
   outtextxy(40,215,"play");
  }
  else
  {
   clearsection(20,180,175,275);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
   setcolor(WHITE);
   outtextxy(35,190,"how to");
   outtextxy(50,215,"play");
  }
  con_circle(getmaxx()/2,getmaxy()/2);
  a=getch();
  b=getch();
  if(a!=(char)0 || a==' ')break;
  switch(b)
  {
   case 72:option--;break;
   case 80:option++;break;
   case 75:option--;break;
   case 77:option++;break;
  }
  if(option>5)option=1;
  if(option<1)option=5;
 }
 return option;
}

//	## Definition of Game::mainplay(); ##
void Game::mainplay()
{
 Player pl1,pl2;
 clearsection(140,175,510,275);
 setcolor(RED);
 rectangle(140,175,510,275);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
 setcolor(WHITE);
 outtextxy(160,185,"Enter Player 1's name ");
 gotoxy(24,1);
 setcolor(RED);
 pl1.setname();
 clearsection(140,175,510,275);
 rectangle(140,175,510,275);
 setcolor(WHITE);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
 outtextxy(160,185,"Enter Player 2's name ");
 gotoxy(24,2);
 pl2.setname();
 closegraph();
 creategraph();
 Board b;
 pl1.renew_letters(0);
 pl2.renew_letters(1);
 char c,dir='a';
 char temp[15];
 int tempi[15];
 int num=0;
 int x=0,y;
 int x1,y1;
 Cursor cr;
 int turn=0;
 while(1)
 {
  again:
  cleardevice();
  b.print();
  setcolor(BLACK);
  settextstyle(0,HORIZ_DIR,6);
  outtextxy(120,5,"SCRABBLE!");
  settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
  if(turn%2==0)
  triangle(33,172);
  else
  triangle(543,172);
  setcolor(RED);
  pl1.getname(25,225);
  setcolor(RED);
  pl2.getname(542,225);
  setcolor(GREEN);
  pl1.getpoint(60,245);
  pl2.getpoint(575,245);
  settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
  setcolor(GREEN);                                                //639,479
  outtextxy(90,430,"Press 'space' to see your rack!");
  while(getch()!=' ');
  if(turn%2==0)
   pl1.get_rack(235,455);
  else
   pl2.get_rack(235,455);
  gotoxy(1,1);
  setfillstyle(SOLID_FILL,YELLOW);
  floodfill(1,430,WHITE);
  setcolor(GREEN);
  outtextxy(175,430,"Down/Across (d/a)? ");
  ret:
  dir=getch();
  if(dir==' ')break;
  if(dir!='d' && dir!='a') goto ret;
  gotoxy(30,22);
  setfillstyle(SOLID_FILL,YELLOW);
  floodfill(1,430,WHITE);
  setcolor(GREEN);
  outtextxy(20,430,"Steer cursor to your desired position!");
  c=cr.steer(135,50,500,400,25,25,25);
  cr.current_position(x,y);
  cleardevice();
  b.print();
  setfillstyle(SOLID_FILL, YELLOW);
  floodfill(25,25,WHITE);
  setcolor(RED);
  b.renew_word();
  while(1)
  {
   failure:
   setfillstyle(SOLID_FILL,YELLOW);
   floodfill(1,430,WHITE);
   setcolor(GREEN);
   outtextxy(180,430,"Now Enter The Word!");
   setcolor(RED);
   if(turn%2==0)
    pl1.get_rack(235,455);
   else
    pl2.get_rack(235,455);
   wrong_input:
   c=getch();
   if(!isalpha(c)&&c!=' ')
    goto wrong_input;
   c=toupper(c);
   if(c==' ')break;
   if(b.charat(x,y)!=c)
   {
    if(turn%2==0)
     if(pl1.rack_check(c)==1||c==' ')
     {
      temp[num]=c;
      tempi[num++]=pl1.use_letter(c);
     }
     else
     {
      goto failure;
     }
    else
     if(pl2.rack_check(c)==1||c==' ')
     {
      temp[num]=c;
      tempi[num++]=pl2.use_letter(c);
     }
   }
   if(x<MAX_LEN && y<MAX_LEN)
   {
    b.tentative_insert(c,x,y);
    dir=='a'?y++:x++;
   }
   b.print();
  }
  if(b.permanent_insert(turn)==0)
  {
   while(num>=0)
   {
    num--;
    if(turn%2==0)
     pl1.back_letter(temp[num],tempi[num]);
    else
     pl2.back_letter(temp[num],tempi[num]);
   }
   getch();
   goto again;
  }
  else
  {
   if(turn%2==0)
   {
    pl1.set_point(b.points_calculator());
    pl1.renew_letters(1);
   }
   else
   {
    pl2.set_point(b.points_calculator());
    pl2.renew_letters(1);
   }
   turn++;num=0;
  }
 }
 char a[20];
 clearsection(160,175,485,275);
 setcolor(RED);
 rectangle(160,175,485,275);
 moveto(getmaxx()/2-115,getmaxy()/2-30);
 setcolor(WHITE);
 strcpy(a,"Bored Already?");
 outtext(a);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
 setcolor(RED);
 strcpy(a,"[F]orfeit   [Q]uit  [C]ancel");
 outtextxy(getmaxx()/2-120,getmaxy()/2,a);
 repeat:
 switch(getch())
 {
  case 'f':
  case 'F':clearsection(160,175,485,275);
	   setcolor(RED);
	   rectangle(160,175,485,275);
	   moveto(getmaxx()/2-115,getmaxy()/2-30);
	   setcolor(WHITE);
	   settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	   if(turn%2!=0) strcpy(a,"Player 1 WINS!!");
	   else strcpy(a,"Player 2 WINS!!");
	   outtext(a);
	   break;
  case 'c':
  case 'C':goto  again;
  case 'q':
  case 'Q':clearsection(160,175,485,275);
	   setcolor(RED);
	   rectangle(160,175,485,275);
	   setcolor(WHITE);
	   settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	   if(pl1.getpoint()==pl2.getpoint())
	   {
	    moveto(getmaxx()/2-90,getmaxy()/2-30);
	    outtext("Its A TIE!!");
	   }
	   else
	   {
	    if(pl1.getpoint()>pl2.getpoint())
	    {
	     moveto(getmaxx()/2-140,getmaxy()/2-40);
	     outtext("Player 1 WINS with");
	     sprintf(a,"%d points!!",pl1.getpoint());
	     moveto(getmaxx()/2-70,getmaxy()/2-10);
	     outtext(a);
	    }
	    else
	    {
	     moveto(getmaxx()/2-140,getmaxy()/2-40);
	     outtext("Player 2 WINS with");
	     sprintf(a,"%d points!!",pl2.getpoint());
	     moveto(getmaxx()/2-70,getmaxy()/2-10);
	     outtext(a);
	    }
	   }
	   break;
  default:goto repeat;
 }
}

//	## Definition of Game::how_to_play() ##
void Game::how_to_play()
{
 cleardevice();
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
 setcolor(RED);
 outtextxy(100,5,"How To Play SCRABBLE");
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
 setcolor(WHITE);

 outtextxy(5,80,"> The game starts with asking screen name of both the players i.e. Player 1 and");
 outtextxy(5,90,"  Player 2. Keep in mind that names should not exceed more than 5 characters and");
 outtextxy(5,100,"  no name should start with a numeral.");

 outtextxy(5,118,"> Press SPACEBAR to proceed. It's Player 1's turn and hit SPACEBAR again to");
 outtextxy(5,128,"  display Player 1's rack.");

 outtextxy(5,152,"> Select the direction of letter input sequence i.e. down(d) / across(a).");

 outtextxy(5,170,"> After selecting the direction, navigate to the desired position on board");
 outtextxy(5,180,"  using direction keys on keyboard.");
 outtextxy(5,205,"> Remember that the very first move of the game should include the center tile");
 outtextxy(5,215,"  (8,8) marked with pink color else you can't proceed.");
 outtextxy(5,240,"> Now, press SPACEBAR twice to start entering the letters from the rack and press");
 outtextxy(5,250,"  SPACEBAR once when done");
 outtextxy(5,275,"> If the combination of letters are validated by the dictionary as a qualified word,");
 outtextxy(5,285,"  points are awarded accordingly and chance is passed onto another player.");
 outtextxy(5,310,"> For consecutive chances, each player should make use of at least one letter");
 outtextxy(5,320,"  already placed on the board. For example, if Player 1 had placed the following tiles");
 outtextxy(5,330,"  in this manner:");
 setcolor(GREEN);
 outtextxy(300,338,"T I E");
 setcolor(WHITE);
 outtextxy(5,350,"> Player 2 should place the tiles either by using T or I or E or all of them. For");
 outtextxy(5,360,"  instance, following are valid combinations:");
 setcolor(GREEN);
 outtextxy(125,372,"T I E R");
 outtextxy(300,372,"I");
 outtextxy(300,382,"T I E");
 outtextxy(475,372,"T I E");
 outtextxy(475,382,"  N");
 setcolor(WHITE);
 outtextxy(5,392,"> If a player is unable to form a word from given set of tiles, he/she loses.");
 outtextxy(5,412,"> The end of game is marked by finishing off letters from the tile or in case of game");
 outtextxy(5,422,"  forfeited by any player.");
 outtextxy(5,442,"> For information on points awarding scheme and frequency of letter tiles in the game,");
 outtextxy(5,452,"  refer to ABOUT GAME section in the main menu.");
 setcolor(YELLOW);
 outtextxy(285,465,"Happy Gaming!");
}

//	## Definition of Game::credits() ##
void Game::credits()
{
 cleardevice();
 settextstyle(GOTHIC_FONT,HORIZ_DIR,7);
 setcolor(GREEN);
 outtextxy(300,0,"CREDITS");
 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
 setcolor(RED);
 outtextxy(30,15,"PROGRAMMED BY");
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
 setcolor(WHITE);
 outtextxy(85,45,"Saiyam Goel");
 outtextxy(85,60,"Sahil Singh");
 outtextxy(82,75,"Mayank Dawra");
 outtextxy(55,90,"Mohd. Mossdiq Hasan");

 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
 setcolor(RED);
 outtextxy(35,150,"CORE DEVELOPER");
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1); setcolor(WHITE);
 outtextxy(85,190,"Saiyam Goel");

 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
 setcolor(RED);

 outtextxy(350,120,"DESIGNED BY");
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1); setcolor(WHITE);
 outtextxy(390,150,"Sahil Singh");
 outtextxy(388,165,"Mayank Dawra");
 outtextxy(390,180,"Saiyam Goel");
 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
 setcolor(RED);

 outtextxy(350,225,"INTEGRATED &");
 outtextxy(370,245,"TESTED BY");
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1); setcolor(WHITE);
 outtextxy(388,275,"Mayank Dawra");
 outtextxy(368,290,"Mohd. Mossdiq Hasan");
 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
 setcolor(RED);
 outtextxy(30,240,"DOCUMENTED BY");
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);setcolor(WHITE);
 outtextxy(60,280,"Mohd. Mossdiq Hasan");
 outtextxy(83,295,"Sahil Singh");

 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
 setcolor(YELLOW);
 outtextxy(85,350,"MENTOR");
 setcolor(WHITE);
 outtextxy(180,350,": Mr. Pankaj Badoni");
 setcolor(YELLOW);
 outtextxy(50,380,"ACTIVITY");
 outtextxy(0,400,"COORDINATOR");
 setcolor(WHITE);
 outtextxy(180,390,": Mr. Ankit Khare");
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);

 outtextxy(285,450,"COPYRIGHT 2015 NOT HOT PRODUCTIONS, INC.");
}

//	## Definition of Game::about_game() ##
void Game::about_game()
{
 cleardevice();
 setcolor(RED);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
 outtextxy(175,5,"ABOUT GAME");
 setcolor(WHITE);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
 outtextxy(5,60,"Scrabble is a famous word game in which 2 players score points by placing tiles,");
 outtextxy(5,70,"each bearing a single letter, onto a game board which is divided into a 15 X 15 ");
 outtextxy(5,80,"grid of squares. Out of 225 squares on the board, there are 61 premium squares ");
 outtextxy(5,90,"which multiply the number of points awarded. The premium squares are marked with");
 outtextxy(5,100,"different colors like red, magenta, blue and cyan having significance as follows");
 setcolor(CYAN);
 outtextxy(5,120,"Cyan    : 2 X Letter Score");
 setcolor(BLUE);
 outtextxy(5,130,"Blue    : 3 X Letter Score");
 setcolor(MAGENTA);
 outtextxy(5,140,"Magenta : 2 X Word Score");
 setcolor(RED);
 outtextxy(5,150,"Red     : 3 X Word Score");
 setcolor(WHITE);
 outtextxy(5,170,"The tiles must form words which, in crossword fashion, flow left to right in");
 outtextxy(5,180,"rows or downwards in columns. The words must be defined in a standard dictionary");
 outtextxy(5,190,"Hitting the bonus squares can generate an extremely high score, hence one");
 outtextxy(5,200,"strategy is to try to always hit the bonus squares and prevent the opponent from");
 outtextxy(5,210,"doing the same. Another way of being successful is to prioritize using letters");
 outtextxy(5,220,"with high score, since they would not only generate a high total score to the");
 outtextxy(5,230,"player, but could also create difficult situations in the future if not used");
 outtextxy(5,240,"as soon as possible. The game can be played with a board disserted with a");
 outtextxy(5,250,"cross-like path. Each player is provided with a rack of 7 random letters");
 outtextxy(5,260,"at a time and the letter frequency along with point value is distributed");
 outtextxy(5,270,"as following:");
 setcolor(GREEN);
 outtextxy(30,290,"Letter"); outtextxy(100,290,"Points"); outtextxy(175,290,"Frequency");
 setcolor(WHITE);
 outtextxy(50,300,"A"); outtextxy(120,300,"1"); outtextxy(210,300,"9");
 outtextxy(50,310,"B"); outtextxy(120,310,"3"); outtextxy(210,310,"2");
 outtextxy(50,320,"C"); outtextxy(120,320,"3"); outtextxy(210,320,"2");
 outtextxy(50,330,"D"); outtextxy(120,330,"2"); outtextxy(210,330,"4");
 outtextxy(50,340,"E"); outtextxy(120,340,"1"); outtextxy(210,340,"12");
 outtextxy(50,350,"F"); outtextxy(120,350,"4"); outtextxy(210,350,"2");
 outtextxy(50,360,"G"); outtextxy(120,360,"2"); outtextxy(210,360,"3");
 outtextxy(50,370,"H"); outtextxy(120,370,"4"); outtextxy(210,370,"2");
 outtextxy(50,380,"I"); outtextxy(120,380,"1"); outtextxy(210,380,"9");
 outtextxy(50,390,"J"); outtextxy(120,390,"8"); outtextxy(210,390,"1");
 outtextxy(50,400,"K"); outtextxy(120,400,"5"); outtextxy(210,400,"1");
 outtextxy(50,410,"L"); outtextxy(120,410,"1"); outtextxy(210,410,"4");
 outtextxy(50,420,"M"); outtextxy(120,420,"3"); outtextxy(210,420,"2");
 setcolor(GREEN);
 outtextxy(400,290,"Letter"); outtextxy(470,290,"Points"); outtextxy(545,290,"Frequency");
 setcolor(WHITE);
 outtextxy(420,300,"N"); outtextxy(490,300,"1"); outtextxy(575,300,"6");
 outtextxy(420,310,"O"); outtextxy(490,310,"1"); outtextxy(575,310,"8");
 outtextxy(420,320,"P"); outtextxy(490,320,"3"); outtextxy(575,320,"2");
 outtextxy(420,330,"Q"); outtextxy(490,330,"10"); outtextxy(575,330,"1");
 outtextxy(420,340,"R"); outtextxy(490,340,"1"); outtextxy(575,340,"6");
 outtextxy(420,350,"S"); outtextxy(490,350,"1"); outtextxy(575,350,"4");
 outtextxy(420,360,"T"); outtextxy(490,360,"1"); outtextxy(575,360,"6");
 outtextxy(420,370,"U"); outtextxy(490,370,"1"); outtextxy(575,370,"4");
 outtextxy(420,380,"V"); outtextxy(490,380,"4"); outtextxy(575,380,"2");
 outtextxy(420,390,"W"); outtextxy(490,390,"4"); outtextxy(575,390,"2");
 outtextxy(420,400,"X"); outtextxy(490,400,"8"); outtextxy(575,400,"1");
 outtextxy(420,410,"Y"); outtextxy(490,410,"4"); outtextxy(575,410,"2");
 outtextxy(420,420,"Z"); outtextxy(490,420,"10"); outtextxy(575,420,"1");

 outtextxy(5,440,"There are double and triple word squares on the board. In the double word square");
 outtextxy(5,450,"if two tiles that will generate a meaning are placed there, the player will");
 outtextxy(5,460,"score a high mark likewise the triple word square. ");
}

//	## Definition of Game::scrabble() ##
void Game::scrabble()
{
 creategraph();
 while(1)
 {
  int option = main_menu();
  switch(option)
  {
   case 1:mainplay();
	  break;
   case 5:how_to_play();
	  break;
   case 3:goto bye;
   case 4:credits();
	  break;
   case 2:about_game();
	  break;
  }
  getch();
 }
 bye:
 credits();
 delay(5000);
 cleardevice();
 closegraph();
}



/*************************** End of GAMEPLAY.CPP ****************************/
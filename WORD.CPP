/****************************************************************************
*****************************************************************************
*****									*****
*****  TITLE       : 'Word' class					*****
*****  DESCRIPTION : The objective of this class is to validate a word  *****
*****		     entry on the board from the player and check from 	*****
*****		     dictionary whether it exists in the text file or	*****
*****		     not. If the word is found in the dictionary file, 	*****
*****		     points are accordingly awarded and returned.	*****
*****									*****
*****************************************************************************
*****************************************************************************/

//	## Include Files Predefined Header Files ##

#include<string.h>
#include<fstream.h>
#include<process.h>
#include<conio.h>

//	## Global Variables ##

const int MAX_LEN=15;		//Maximum length of Any Word

//	## Prototype of Function(s) ##

int letter_point(char);		//Function to know points of each letter

//	## Definition of Class 'Word' ##

class Word
{
 //	Data Member
 char wrd[MAX_LEN];		//For holding the actual Word
 char tileTypeCovered[MAX_LEN];	//Tile type that Word holds on Board
 int size;			//Size of Word

public:

 //Member Function prototypes
 Word();                        //Constuctor to initiate word value NULL
 void renew();		        //Renew word to Null
 int validator();	        //Checks Whether the Word is in dictionary
 int points_calculator();	//Calculates point of Word made. Also add
				//points of any special tyle, if present.
 void input_char(char,char);    //Function to add single character to Word.
 void input_string(char[]);	//Function to add a String to Word.
};


//	## Definition of Word::renew(); ##
void Word::renew()
{
 wrd[0]='\0';
 size=0;
}

//	## Definition of Constructor,Word::Word()  ##
Word::Word()
{
 renew();
}

//	## Definition of Word::validator() ##
int Word::validator()
{
 ifstream fin1;
 char line[15];
 fin1.open("WORDLIST.txt");
  //fin1.open("british.txt");
  if(!fin1)
  {
   cout << "Unable to open file" << endl;
   exit(1);
  }
  float pos;
  while(!fin1.eof())
  {
   fin1.getline(line,'\n');
   if(!strcmpi(line,wrd))
   {
    fin1.close();
    return 1;
   }
  }
 fin1.close();
 return 0;
}


//	## Definition of Words::points_calculator() ##
int Word::points_calculator()
{
 int point=0;
 for(int i=0;i<size;i++)
 {
  point+=letter_point(wrd[i]);
 }
 for(i=0;i<size;i++)
 {
  switch(tileTypeCovered[i])
  {
   case 'a':point=3*point;
	    break;
   case 'b':point=point+letter_point(wrd[i]);
	    break;
   case 'c':point=2*point;
	    break;
   case 'd':point=point+2*letter_point(wrd[i]);
	    break;
   default :break;
  }
 }
 return point;
}


//	## Definition of Word::input_char(char, char) ##
void Word::input_char(char letter,char tileType)
{
 tileTypeCovered[size]=tileType;
 wrd[size++]=letter;
 wrd[size+1]='\0';
}


//	## Definition of Word::input_string(char[]) ##
void Word::input_string(char str[])
{
 size=strlen(str);
 strcpy(str,wrd);
}


//	## Definition of letter_point(char) ##
int letter_point(char letter)
{
 switch(letter)
 {
  case 'a':
  case 'A':return 1;

  case 'b':
  case 'B':return 3;

  case 'c':
  case 'C':return 3;

  case 'd':
  case 'D':return 1;

  case 'e':
  case 'E':return 1;

  case 'f':
  case 'F':return 4;

  case 'g':
  case 'G':return 2;

  case 'h':
  case 'H':return 4;

  case 'i':
  case 'I':return 1;

  case 'j':
  case 'J':return 8;

  case 'k':
  case 'K':return 5;


  case 'l':
  case 'L':return 1;


  case 'm':
  case 'M':return 3;

  case 'n':
  case 'N':return 1;

  case 'o':
  case 'O':return 1;

  case 'p':
  case 'P':return 3;

  case 'q':
  case 'Q':return 10;

  case 'r':
  case 'R':return 1;


  case 's':
  case 'S':return 1;

  case 't':
  case 'T':return 1;

  case 'u':
  case 'U':return 1;

  case 'v':
  case 'V':return 4;

  case 'w':
  case 'W':return 1;

  case 'x':
  case 'X':return 8;

  case 'y':
  case 'Y':return 4;

  case 'z':
  case 'Z':return 10;

  default :return 0;
 }
}

/*************************** End of WORD.CPP *********************************/



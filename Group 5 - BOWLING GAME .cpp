/*
_________________GROUP 5_________________

20/ENG/007 -	S.A.A.J.M.Athukorala
20/ENG/113 -	R.H.A.L.S.Ranasinghe
20/ENG/094 -	T.D.Paranawithana

*/

// header files
#include <iostream>
#include <windows.h>
#include <time.h>
#include <string>
#include <stdio.h>
#include <limits>
#include <cwchar>
#include <iomanip>
#include <conio.h>    //kbhit() function resides here
#include <unistd.h>

using namespace std;

//Keyboard user inputs
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define SPACE_BAR 32
#define ENTER_KEY 13

//Global Variables
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); //color changer
char Design[88] = {' ','*','*','*', '*','*','\t','B','O','W','L','I','N','G',' ',' ','G','A','M','E','\t','*','*','*', '*','*','\t','B','O','W','L','I','N','G',' ',' ','G','A','M','E','\t','*','*','*', '*','*','\t','B','O','W','L','I','N','G',' ',' ','G','A','M','E','\t','*','*','*', '*','*','\t','B','O','W','L','I','N','G',' ',' ','G','A','M','E','\t','*','*','*','*','*' };
char LetsBowl[80] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','L','E','T','`','S',' ','B','O','W','L'};
char UserInput;
int playerX = 13;
int playerY = 55;
bool gameOver = false;
string UserName;
char Userdecision;
char Userdecision2;
char circle = 'O';
char choice;
int attempt=0;
int frame=0;
int score_1=0;
int score_2=0;
int score_3=0;
char row3[]= "x x x x"; //Array for the targets
char row4[]= "x x x";   //Array for the targets
char row5[]= "x x";     //Array for the targets
char row6[]= "x";       //Array for the targets
int A = 30; //Font Size
int force;
int Random_Number;
char KB_code; 
char Velocity_Power[5]= ">>>>";

//Functions
void Fullscreen();
void Fontsize();
void Startpage();
void Secondpage();
void InstructionsPage();
void DrawBoard();
void PlayerAlign();
void playerMovement();
void PlayerMovement();
void DirectionInput();
void updateScore_1();
void updateScore_2();
void updateScore_3();
void Power();
void frontpage();
int end();

int main()
{
	//Functions Calling
	Fontsize();
    frontpage();
    Fullscreen(); 
    A = 30;
    Fontsize();
	Startpage();
	
	return 0;
}

void Fullscreen() //Enable full screen
{
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

void Fontsize() //Change font size
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = A;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	std::wcscpy(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void frontpage()  
{
	A=90;
	Fontsize();
	SetConsoleTextAttribute(color, 6); //Change color
	cout << "\n\n\n\n	***ROCK n` BOWL***";
	Sleep(1500);
	system("CLS");
}

void Startpage()
{
		SetConsoleTextAttribute(color, 4); //red
		cout << " _______________________________________________________________________________________________________\n\n";
		SetConsoleTextAttribute(color, 11); //light blue
		cout << " \t\t\t\t\t\t  BOWLING GAME     \n";
		SetConsoleTextAttribute(color, 4); //red
		cout << " _______________________________________________________________________________________________________\n\n\n";

		//animation
		int i = 0;
		SetConsoleTextAttribute(color, 11);
		while (i < 89)
		{
			cout << Design[i];
			i++;
			Sleep(20);
		}

		cout << endl << endl;

		SetConsoleTextAttribute(color, 15); //white

	for(int r=1;r<=15;r++) //Printing the board in the start page
	{
		for(int c=1;c<=33;c++)
		{
			if(c>=1&&c<=23)
			cout << "  ";
			else if((r==13)&&(c==28))
			cout << " " << circle ;
		    else if(((r==3)&&(c>=27&&c<=30))||((r==5)&&(c>=28&&c<=29)))
			cout << "x ";
			else if(((r==4)&&(c>=27&&c<=29))||((r==6)&&(c==28)))
			cout << " x";
			else if((r>=3&&r<=13)&&(c==26||c==31))
			cout << "| ";
			else if(r==1||r==15||c==24||c==33)
			cout << "* ";
			else
			cout << "  ";
		}
		cout << endl;
	}

	cout << endl;
	cout << endl;
	SetConsoleTextAttribute(color, 14);
	cout << " \t\t\t\t    Please Press Y(Start) - N(Exit) : (Y/N)\b\b\b\b";
	SetConsoleTextAttribute(color, 12);
	cin >> UserInput;
	cin.ignore();
	cout << "\a";
	
	//Validate user input to continue
	switch (UserInput)
	{
		case 'y':
		case 'Y':
		{
			Sleep(1000);
			system("cls");
			Secondpage(); //calling the next page 
		}
		case 'n':
		case 'N':
		{
			break;
		}
		default:
		{
			cout << "\n\t\t\t\t\t\tINVALID INPUT!";
			Sleep(1000);
			system("cls");
			Startpage();
		}
	}
}

void Secondpage() //Input username and continue
{
		SetConsoleTextAttribute(color, 4); //red
		cout << " _______________________________________________________________________________________________________\n\n";
		SetConsoleTextAttribute(color, 11); //light blue
		cout << " \t\t\t\t\t\t  BOWLING GAME     \n";
		SetConsoleTextAttribute(color, 4); //red
		cout << " _______________________________________________________________________________________________________\n\n\n";

		int i = 0;
		SetConsoleTextAttribute(color, 11);
		while (i < 89)
		{
			cout << Design[i];
			i++;
		}
		cout << "\n\n\n" << endl;

		//animation
		int j = 0;
		SetConsoleTextAttribute(color, 3);
		while (j < 80)
		{
			cout << LetsBowl[j];
			j++;
			Sleep(20);
		}
		cout << "\n\n\n" << endl;
		SetConsoleTextAttribute(color, 14);
	cout << "    \n\n\n \t     Please enter your User Name	: ........\b\b\b\b\b\b\b\b";
	cin >> UserName;
	cout << "\n\n \t    *View Instructions - PRESS I" << endl;
	cout << " \t    *Launch Game - PRESS L" << endl;
	cout << " \t    *Exit - PRESS E" << endl;
	cout << " \t    : (I/L/E)\b\b\b\b";
	SetConsoleTextAttribute(color, 12);
	cin >> Userdecision;
	cin.ignore();
	cout << "\a";
	Sleep(1000);
	system("cls");
	
	//Validate userinput to continue or quit
	switch (Userdecision)
	{
		case 'I':
		case 'i':
			{
				InstructionsPage(); //Calling function to view the instructions 
				break;
			}
		case 'L':
		case 'l':
			{
				while (!gameOver) //Drawing the board until the game is over 
				{
					DrawBoard(); //Calling function to draw the board
					PlayerAlign(); //Calling the function to align the ball
				}
			}
		case 'E':
		case 'e':
			{	break;	}
		default:
			{
				Secondpage(); 
			}
	}
}

void InstructionsPage() //Displaying instructions 
{
		SetConsoleTextAttribute(color, 4); //red
		cout << " _______________________________________________________________________________________________________\n\n";
		SetConsoleTextAttribute(color, 11); //light blue
		cout << " \t\t\t\t\t\t  BOWLING GAME     \n";
		SetConsoleTextAttribute(color, 4); //red
		cout << " _______________________________________________________________________________________________________\n\n\n";

		//animation
		int i = 0;
		SetConsoleTextAttribute(color, 11);
		while (i < 89)
		{
			cout << Design[i];
			i++;
			Sleep(25);
		}
		
		//Displaying instructions 
		SetConsoleTextAttribute(color, 14);
		cout << "\n\n\n \t     INSTRUCTIONS..........\n\n";
		SetConsoleTextAttribute(color, 6);
		cout <<"\t\t1. You get 3 frames and each frame has 2 attempts to knock over the pins."<<endl;
		cout <<"\t\t2. You can change the position of the ball using ARROW KEYS."<<endl;
		cout << "\t\t\t Left Arrow Key   -  Align the ball LEFT before launching\n";
		cout << "\t\t\t Right Arrow Key  -  Align the ball RIGHT before launching\n";
		cout <<"\t\t3. Press ENTER KEY before choosing the direction."<<endl;
		cout <<"\t\t4. Press ENTER KEY again after choosing the direction. "<<endl;
		cout <<"\t\t5. Press SPACE BAR to launch the ball."<<endl;
		cout <<"\n\t\t>>Your score will be displayed after 2 attempts of each frame.\n\n "<<endl;

	SetConsoleTextAttribute(color, 14);
	cout << " \t     Launch Game - L\t Exit - E 	: (L/E)\b\b\b\b";
	SetConsoleTextAttribute(color, 12);
	cin >> Userdecision2;
	cin.ignore();
	cout << "\a";
	Sleep(1000);
	system("cls");
	switch (Userdecision2)
	{
		case 'L':
		case 'l':
			{
				while (!gameOver)
				{
    				DrawBoard();
  					PlayerAlign();

 				}
			 }
		case 'E':
		case 'e':
			{	break;	}
		default:
			{
				InstructionsPage();
			}
	}
}

void DrawBoard() 
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
	SetConsoleTextAttribute(color, 4); //red
    cout << " _______________________________________________________________________________________________________\n\n";
    SetConsoleTextAttribute(color, 11); //light blue
    cout << " \t\t\t\t\t\t  BOWLING GAME     \n";
    SetConsoleTextAttribute(color, 4); //red
    cout << " _______________________________________________________________________________________________________\n\n\n";

	SetConsoleTextAttribute(color, 15); //white
	
	//Draw the track and targets 
	for(int r=1;r<=15;r++)
	{
		for(int c=1;c<=64;c++)
		{
			if(c>=1&&c<=45)
			cout << " ";
			else if(r==playerX&&c==playerY)
			cout  << circle ;
			else if(r==3&&c==52)
		    {
		    	cout << row3[0];
			}
			else if(r==3&&c==53)
		    {
		    	cout << row3[1];
			}
			else if(r==3&&c==54)
		    {
		    	cout << row3[2];
			}
			else if(r==3&&c==55)
		    {
		    	cout << row3[3];
			}
			else if(r==3&&c==56)
		    {
		    	cout << row3[4];
			}
			else if(r==3&&c==57)
		    {
		    	cout << row3[5];
			}
			else if(r==3&&c==58)
		    {
		    	cout << row3[6];
			}

		//row 4
			else if(r==4&&c==53)
		    {
		    	cout << row4[0];
			}
			else if(r==4&&c==54)
		    {
		    	cout << row4[1];
			}
			else if(r==4&&c==55)
		    {
		    	cout << row4[2];
			}
			else if(r==4&&c==56)
		    {
		    	cout << row4[3];
			}
			else if(r==4&&c==57)
		    {
		    	cout << row4[4];
			}
		//row 5
			else if(r==5&&c==54)
		    {
		    	cout << row5[0];
			}
			else if(r==5&&c==55)
		    {
		    	cout << row5[1];
			}
			else if(r==5&&c==56)
		    {
		    	cout << row5[2];
			}
		//row 6
			else if(r==6&&c==55)
		    {
		    	cout << row6[0];
			}
			else if((r>=3&&r<=13)&&(c==51||c==59))
			cout << "|";
			else if((r==1||r==15||c==46||c==64)&&c%2==0)
			cout << "*";
			else
			cout << " ";
		}
		cout << endl;
	}
}

void PlayerAlign()
{
	SetConsoleTextAttribute(color, 14);
	
	//Print the scoreboard 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{80,12});
	{
		COORD c;
		c.X = 74;
		c.Y = 7;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
		cout<<"--------------------------";
	}
	{
		COORD c;
		c.X = 75;
		c.Y = 8;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
		cout<<"Player Name   : "<<UserName;
	}
	{
		COORD c;
		c.X = 74;
		c.Y = 9;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
		cout<<"--------------------------";
	}
	{
		COORD c;
		c.X = 75;
		c.Y = 10;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
		cout<<"Frame 1 Score : "<<score_1;
	}
	{
		COORD c;
		c.X = 74;
		c.Y = 11;
		SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),c);
		cout<<"--------------------------";
	}
	{
		COORD c;
		c.X = 75;
		c.Y = 12;
		SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),c);
		cout<<"Frame 2 Score : "<<score_2;
	}
	{
		COORD c;
		c.X = 74;
		c.Y = 13;
		SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),c);
		cout<<"--------------------------";
	}
	{
		COORD c;
		c.X = 75;
		c.Y = 14;
		SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),c);
		cout<<"Frame 3 Score : "<<score_3;
	}
	{
		COORD c;
		c.X = 74;
		c.Y = 15;
		SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),c);
		cout<<"--------------------------";
	}
	{
		COORD c;
		c.X = 75;
		c.Y = 16;
		SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),c);
		cout<<"TOTAL SCORE   : "<<(score_1+score_2+score_3);
	}
	{
		COORD c;
		c.X = 74;
		c.Y = 17;
		SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),c);
		cout<<"--------------------------";
	}
	//Display simple instruction
	{
		COORD c;
		c.X = 3;
		c.Y = 22;
		SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),c);
		cout<<"----------------------------------------";
	}
	{
		COORD c;
		c.X = 3;
		c.Y = 23;
		SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),c);
		cout<<"  To align the ball  - use ARROW KEYS ";
	}
	{
		COORD c;
		c.X = 3;
		c.Y = 24;
		SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),c);
		cout<<"----------------------------------------";
	}
	
//Checking number of frames 
if(frame<3)
{
if(attempt<2) //Repeat the game twice in each frame 
 {
  Sleep(0.01);
  //if a key has been pressed khbit returns non-zero value and otherwise it returns zero
  if (kbhit())
   {
    switch(getch()) //Align the ball 
	{
        case KEY_LEFT:
      	{playerY--;
      	    if(playerY<=52)
      			playerY=53;
		}
        break;
        case KEY_RIGHT:
      	{
      	 playerY++;
      		if(playerY>=58)
      			playerY=57;
		}
		break;
		case ENTER_KEY:
		{
			DirectionInput();
			if(getch()==SPACE_BAR)
			{
				PlayerMovement();
			}
		}
        break;
    }
  }
 }
 else //Update the score in each frame 
 {
 	Sleep(1000);

 	if(frame == 0)
 	{
 		updateScore_1();
	}
	else if(frame == 1)
 	{
 		updateScore_2();
	}
	else if(frame == 2)
 	{
 		updateScore_3();
	}
		
		//Rearraneg the board 
 		row3[0]= 'x';row3[2]= 'x';row3[4]= 'x';row3[6]= 'x';
		row4[0]= 'x';row4[2]= 'x';row4[4]= 'x';
		row5[0]= 'x';row5[2]= 'x';
		row6[0]= 'x';
		playerX=13;
		playerY=55;
		circle='O';
		attempt=0;
		frame++;
 		DrawBoard();
 		PlayerAlign();
 }
}

else //End the game and display final score 
{
	Sleep(1000);
	gameOver=1;
 	system("cls");
 	A = 60;
 	Fontsize();
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
 	cout <<"\n\n\n\n\n\t\t     GAME OVER !"<< endl;
	cout << "\n\t\t  YOUR SCORE  :  " << (score_1+score_2+score_3);
	cout << "\n\n\n\n\n";
	Sleep(1000);
	system("pause");
	system("cls");
	A = 30;
 	Fontsize();
	Startpage();
 }
}

void PlayerMovement()
{
	//Move the ball along the track according to assigned paths 
	switch(playerY)
	{
		//53 column
		case 53 :
		{
			if(choice=='1')
			{
				playerX=13; //Set the ball in to initial position
				Sleep(200);
				DrawBoard(); //Update the board according to changes 
				playerY=52;
				playerX=12;
				for(playerX=12;playerX>=4;playerX--) //For loop to move the ball towards targets
				{
					Sleep(200);
					DrawBoard();
				}
				row3[0]=' '; //Clear the target when the ball hits
				circle = ' '; 
				DrawBoard();
				Sleep(1000);
				playerX=13; //Set the ball to the initial position
				playerY=55;
				circle='O';
				PlayerAlign();
				attempt++; //Update the attempt
			}
			else if(choice=='2') //Set the direction according to the user inputs
			{
				for(playerX=13;playerX>=4;playerX--) //For loop to move the ball towards targets
				{
					Sleep(200);
					DrawBoard();
				}
				
				//after ball hits the targets
				
				if(force > 3) //When user applies force greater than 3
				{
					//Clear the targets when the ball hits
					row4[0]=' ';
					row3[0]=' ';
					row3[2]=' ';
				}
				else
				{
					//Clear the targets when the ball hits
					row4[0]=' ';
					row3[0]=' ';
				}
				
				circle = ' ';
				DrawBoard();
				Sleep(1000);
				playerX=13; //Set the ball into initial position
				playerY=55;
				circle='O';
				PlayerAlign();
				attempt++; //Update the attempts
			}
			else if(choice=='3')
			{
				//Assign the path 
				playerX=13;
				Sleep(100);
				DrawBoard();
				playerY=54;
				playerX=11;
				Sleep(200);
				DrawBoard();
				playerY=55;
				playerX=9;
				Sleep(200);
				DrawBoard();
				playerY=56;
				playerX=7;
				Sleep(200);
				DrawBoard();
				playerY=57;
				playerX=5;
				Sleep(200);
				DrawBoard();
				
				if(force > 3)
				{
					//Clear the targets when the ball hits
					row3[4]=' ';
					row3[6]=' ';
					row4[4]=' ';
				}
				else
				{
					//Clear the targets when the ball hits
					row3[6]=' ';
					row4[4]=' ';
				}
				circle = ' '; 
				DrawBoard();
				Sleep(1000);
				playerX=13;  //Set the ball to the initial position
				playerY=55;
				circle='O';
				PlayerAlign();
				attempt++; //Update the attempts
			}
			break;
		}
		//54 column
		case 54 :
		{
			if(choice=='1')
			{
				playerX=13;
				Sleep(200);
				DrawBoard();
				playerY=53;
				playerX=12;
				for(playerX=12;playerX>=5;playerX--)
				{
					Sleep(200);
					DrawBoard();
				}

                if(force>3)
                {
                	row3[0]=' ';
					row4[0]=' ';
					row3[2]=' ';
				}

				else
				{
					row3[0]=' ';
					row4[0]=' ';
				}
				circle = ' ';
				DrawBoard();
				Sleep(1000);
				playerX=13;
				playerY=55;
				circle='O';
				PlayerAlign();
				attempt++;
			}
			else if(choice=='2')
			{
				for(playerX=13;playerX>=5;playerX--)
				{
					Sleep(200);
					DrawBoard();
				}
				//after hitting the targets
				if(force > 3)
				{
					row5[0]=' ';
					row4[0]=' ';
					row4[2]=' ';
					row3[2]=' ';
					row3[4]=' ';
				}
				else
				{
					row5[0]=' ';
					row4[0]=' ';
					row4[2]=' ';
					row3[2]=' ';
				}
				circle = ' ';
				DrawBoard();
				Sleep(1000);
				playerX=13;
				playerY=55;
				circle='O';
				PlayerAlign();
				attempt++;
			}
			else if(choice=='3')
			{
				playerX=13;
				Sleep(100);
				DrawBoard();
				playerY=55;
				playerX=11;
				Sleep(200);
				DrawBoard();
				playerY=55;
				playerX=10;
				Sleep(200);
				DrawBoard();
				playerY=55;
				playerX=9;
				Sleep(200);
				DrawBoard();
				playerY=55;
				playerX=8;
				Sleep(200);
				DrawBoard();
				playerY=56;
				playerX=6;
				Sleep(200);
				DrawBoard();
				playerY=56;
				playerX=5;
				Sleep(200);
				DrawBoard();
				
				if(force > 3)
				{	
					row3[4]=' ';
					row3[6]=' ';
					row4[4]=' ';
					row5[2]=' ';
				}
				else
				{
					row3[6]=' ';
					row4[4]=' ';
					row5[2]=' ';
				}
				circle = ' ';
				DrawBoard();
				Sleep(1000);
				playerX=13;
				playerY=55;
				circle='O';
				PlayerAlign();
				attempt++;
			}
			break;
		}
		//55 column
		case 55 :
		{
			if(choice=='1')
			{
				playerX=13;
				Sleep(200);
				DrawBoard();
				playerY=54;
				playerX=11;
				for(playerX=11;playerX>=6;playerX--)
				{
					Sleep(200);
					DrawBoard();
				}
				
				if(force > 3)
				{
					row3[0]=' ';
					row3[2]=' ';
					row4[0]=' ';
					row5[0]=' ';
				}
				else
				{
					row3[0]=' ';
					row4[0]=' ';
					row5[0]=' ';
				}
				
				circle = ' ';
				DrawBoard();
				Sleep(1000);
				playerX=13;
				playerY=55;
				circle='O';
				PlayerAlign();
				attempt++;
			}
			else if(choice=='2')
			{
				for(playerX=13;playerX>=7;playerX--)
				{
					Sleep(200);
					DrawBoard();
				}
				//after hitting the targets
				
				if(force > 3)
				{
					row3[0]=' ';
					row3[2]=' ';
					row3[4]=' ';
					row4[0]=' ';
					row4[2]=' ';
					row4[4]=' ';
					row5[0]=' ';
					row5[2]=' ';
					row6[0]=' ';
				}
				else
				{
					row3[2]=' ';
					row3[4]=' ';
					row4[0]=' ';
					row4[2]=' ';
					row4[4]=' ';
					row5[0]=' ';
					row5[2]=' ';
					row6[0]=' ';
				}
				circle =' ';
				DrawBoard();
				Sleep(1000);
				playerX=13;
				playerY=55;
				circle='O';
				PlayerAlign();
				attempt++;
			}
			else if(choice=='3')
			{
				playerX=13;
				Sleep(200);
				DrawBoard();
				playerY=56;
				playerX=11;
				for(playerX=11;playerX>=5;playerX--)
				{
					Sleep(200);
					DrawBoard();
				}
				
				if(force > 3)
				{
					row5[2]=' ';
					row3[4]=' ';
					row3[6]=' ';
					row4[4]=' ';
				}
				else
				{
					row5[2]=' ';
					row3[6]=' ';
					row4[4]=' ';
				}
				
				circle = ' ';
				DrawBoard();
				Sleep(1000);
				playerX=13;
				playerY=55;
				circle='O';
				PlayerAlign();
				attempt++;
			}
			break;
		}
		//56 column
		case 56 :
		{
			if(choice=='1')
			{
				playerX=13;
				Sleep(200);
				DrawBoard();
				playerY=55;
				playerX=12;
				for(playerX=12;playerX>=5;playerX--)
				{
					Sleep(200);
					DrawBoard();
				}
				
				if(force > 3)
				{
					row3[0]=' ';
					row3[2]=' ';
					row3[4]=' ';
					row4[0]=' ';
					row4[2]=' ';
					row5[0]=' ';
					row6[0]=' ';
				}
				else
				{
					row3[0]=' ';
					row3[2]=' ';
					row4[0]=' ';
					row4[2]=' ';
					row5[0]=' ';
					row6[0]=' ';
				}
		
				circle = ' ';
				DrawBoard();
				Sleep(1000);
				playerX=13;
				playerY=55;
				circle='O';
				PlayerAlign();
				attempt++;
			}
			else if(choice=='2')
			{
				for(playerX=13;playerX>=6;playerX--)
				{
					Sleep(200);
					DrawBoard();
				}
				//after hitting the targets
				if(force > 3)
				{
					row3[4]=' ';
					row3[6]=' ';
					row4[2]=' ';
					row4[4]=' ';
					row5[2]=' ';
				}
				else
				{
					row3[4]=' ';
					row4[2]=' ';
					row4[4]=' ';
					row5[2]=' ';
				}
				circle =' ';
				DrawBoard();
				Sleep(1000);
				playerX=13;
				playerY=55;
				circle='O';
				PlayerAlign();
				attempt++;
			}
			else if(choice=='3')
			{
				playerX=13;
				Sleep(200);
				DrawBoard();
				playerY=57;
				playerX=11;
				for(playerX=11;playerX>=6;playerX--)
				{
					Sleep(200);
					DrawBoard();
				}
				
				if(force > 3)
				{
					row3[6]=' ';
					row3[4]=' ';
					row4[4]=' ';	
				}
				else
				{
					row3[6]=' ';
					row4[4]=' ';
				}
				
				circle = ' ';
				DrawBoard();
				Sleep(1000);
				playerX=13;
				playerY=55;
				circle='O';
				PlayerAlign();
				attempt++;
			}
			break;
		}

		//57 column
		case 57 :
		{
			if(choice=='1')
			{
				playerX=13;
				Sleep(200);
				DrawBoard();
				playerY=56;
				playerX=12;
				Sleep(200);
				DrawBoard();
				playerY=55;
				playerX=11;
				Sleep(200);
				DrawBoard();
				playerY=54;
				playerX=10;
				for(playerX=10;playerX>=5;playerX--)
				{
					Sleep(200);
					DrawBoard();
				}
				
				if(force > 3)
				{
					row3[0]=' ';
					row3[2]=' ';
					row3[4]=' ';
					row4[0]=' ';
					row4[2]=' ';
					row5[0]=' ';	
				}
				else
				{
					row3[0]=' ';
					row3[2]=' ';
					row4[0]=' ';
					row4[2]=' ';
					row5[0]=' ';
				}

				circle = ' ';
				DrawBoard();
				Sleep(1000);
				playerX=13;
				playerY=55;
				circle='O';
				PlayerAlign();
				attempt++;
			}
			else if(choice=='2')
			{
				for(playerX=13;playerX>=4;playerX--)
				{
					Sleep(200);
					DrawBoard();
				}
				//after hitting the targets
				row3[4]=' ';
				row3[6]=' ';
				row4[4]=' ';
				circle =' ';
				DrawBoard();
				Sleep(1000);
				playerX=13;
				playerY=55;
				circle='O';
				PlayerAlign();
				attempt++;
			}
			else if(choice=='3')
			{
				playerX=13;
				Sleep(200);
				DrawBoard();
				playerY=58;
				playerX=11;
				for(playerX=11;playerX>=3;playerX--)
				{
					Sleep(200);
					DrawBoard();
				}
				row3[6]=' ';
				circle = ' ';
			//	score += 10;
				DrawBoard();
				Sleep(1000);
				playerX=13;
				playerY=55;
				circle='O';
				PlayerAlign();
				attempt++;
			}
			break;
		}
	}
}

void DirectionInput()
{
	COORD c;
	c.X = 10; //Set the cursor position
	c.Y = 7;  //Set the cursor position

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
	SetConsoleTextAttribute(color, 14);
	cout<<"LIST OF DIRECTIONS"<<endl;
	{
		COORD c;
		c.X = 10;
		c.Y = 9;
		SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),c);
		cout << "1- Up-Left Direction" << endl;
	}
	{
		COORD c;
		c.X = 10;
		c.Y = 11;
		SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),c);
		cout << "2- Up-Straight Direction" << endl;
	}
	{
		COORD c;
		c.X = 10;
		c.Y = 13;
		SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),c);
		cout << "3- Up-Right Direction" << endl;
	}
	{
		COORD c;
		c.X = 10;
		c.Y = 15;
		SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),c);
		cout<<"What is your choice >>" << endl;
		cout << "\t\tPress 1 or 2 or 3 : ";
		cin>>choice; //Getting the user input for the direction
		
		if(choice!='1' || choice!='2' || choice!='3') //validate the user input for the direction
		{
			end(); //Calling the end function
		}	
	}
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
        COORD c;
		c.X = 10;
		c.Y = 15;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);

	//power selection
	do
	{
		int index = 0;

		while (index < 5)
		{
			Sleep(20);
			SetConsoleTextAttribute(color, 4); //Red Colour.
			cout << Velocity_Power[index];
			index++;
		}

	index = 4;

	while (index > 0)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
		Sleep(100);
		system("CLS"); //To clear the Power shell.
		DrawBoard();
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
		{
		    COORD c;
            c.X = 5;
            c.Y = 16;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
            cout << "Press ENTER key to get power  ";
		}
		
        {
		    COORD c;
            c.X = 36;
            c.Y = 16;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
            SetConsoleTextAttribute(color, 4); //Red Colour.
            cout << Velocity_Power[index];
		}

		index--;
	}

  	//To get ENTER key input.
    if (kbhit())
    KB_code = getch();

	} while(KB_code != 13); //To check the user pressed ENTER key.

	KB_code = 7;

	//To give power randomly.
	srand(time(NULL));
	Random_Number = rand()%5+1;

    /*
    velocity calculation
    F = (mv - mu)/t
    
	ASSUMPTIONS
	
	Initial velocity of the ball is 0.
    Force is applied for 1s time.
    Mass of the ball is 1kg.
    Friction of the track is neglegible.
    
    F = v
    */
	
	if (Random_Number == 1)
	{
		SetConsoleTextAttribute(color, 4); //Red Colour.
		cout << ">" << endl;
		force = 1;
	}

	else if (Random_Number == 2)
	{
        SetConsoleTextAttribute(color, 4); //Red Colour.
        cout << ">>" << endl;
        force = 2;
	}

	else if (Random_Number == 3)
	{
		SetConsoleTextAttribute(color, 4); //Red Colour.
		cout << ">>>" << endl;
		force = 3;
	}

	else if (Random_Number == 4)
	{
		SetConsoleTextAttribute(color, 4); //Red Colour.
		cout << ">>>>" << endl;
		force = 4;
	}
	else
	{
		SetConsoleTextAttribute(color, 4); //Red Colour.
		cout << ">>>>>" << endl;
		force = 5;
	}
	SetConsoleTextAttribute(color, 7); //White Colour.
		SetConsoleTextAttribute(color, 6);
		{
		    COORD c;
            c.X = 3;
            c.Y = 17;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
            cout<< "\n     Press SPACE BAR to launch the ball ";
		}
	}
}

void updateScore_1()  //update score of frame 1 according to the number of targets fallen
{
	{
		if(row3[0] != 'x')
		{
			score_1+=1;
		}
		else
		{
			score_1+=0;
		}
	}

	{
		if(row3[2] != 'x')
		{
			score_1+=1;
		}
		else
		{
			score_1+=0;
		}
	}

	{
		if(row3[4] != 'x')
		{
			score_1+=1;
		}
		else
		{
			score_1+=0;
		}
	}

	{
		if(row3[6] != 'x')
		{
			score_1+=1;
		}
		else
		{
			score_1+=0;
		}
	}

	{
		if(row4[0] != 'x')
		{
			score_1+=1;
		}
		else
		{
			score_1+=0;
		}
	}

	{
		if(row4[2] != 'x')
		{
			score_1+=1;
		}
		else
		{
			score_1+=0;
		}
	}

	{
		if(row4[4] != 'x')
		{
			score_1+=1;
		}
		else
		{
			score_1+=0;
		}
	}

	{
		if(row5[0] != 'x')
		{
			score_1+=1;
		}
		else
		{
			score_1+=0;
		}
	}

	{
		if(row5[2] != 'x')
		{
			score_1+=1;
		}
		else
		{
			score_1+=0;
		}
	}

	{
		if(row6[0] != 'x')
		{
			score_1+=1;
		}
		else
		{
			score_1+=0;
		}
	}
}

void updateScore_2()  //update score of frame 2 according to the number of targets fallen
{
	{
		if(row3[0] != 'x')
		{
			score_2+=1;
		}
		else
		{
			score_2+=0;
		}
	}

	{
		if(row3[2] != 'x')
		{
			score_2+=1;
		}
		else
		{
			score_2+=0;
		}
	}

	{
		if(row3[4] != 'x')
		{
			score_2+=1;
		}
		else
		{
			score_2+=0;
		}
	}

	{
		if(row3[6] != 'x')
		{
			score_2+=1;
		}
		else
		{
			score_2+=0;
		}
	}

	{
		if(row4[0] != 'x')
		{
			score_2+=1;
		}
		else
		{
			score_2+=0;
		}
	}

	{
		if(row4[2] != 'x')
		{
			score_2+=1;
		}
		else
		{
			score_2+=0;
		}
	}

	{
		if(row4[4] != 'x')
		{
			score_2+=1;
		}
		else
		{
			score_2+=0;
		}
	}

	{
		if(row5[0] != 'x')
		{
			score_2+=1;
		}
		else
		{
			score_2+=0;
		}
	}

	{
		if(row5[2] != 'x')
		{
			score_2+=1;
		}
		else
		{
			score_2+=0;
		}
	}

	{
		if(row6[0] != 'x')
		{
			score_2+=1;
		}
		else
		{
			score_2+=0;
		}
	}
}

void updateScore_3()  //update score of frame 3 according to the number of targets fallen
{
	{
		if(row3[0] != 'x')
		{
			score_3+=1;
		}
		else
		{
			score_3+=0;
		}
	}

	{
		if(row3[2] != 'x')
		{
			score_3+=1;
		}
		else
		{
			score_3+=0;
		}
	}

	{
		if(row3[4] != 'x')
		{
			score_3+=1;
		}
		else
		{
			score_3+=0;
		}
	}

	{
		if(row3[6] != 'x')
		{
			score_3+=1;
		}
		else
		{
			score_3+=0;
		}
	}

	{
		if(row4[0] != 'x')
		{
			score_3+=1;
		}
		else
		{
			score_3+=0;
		}
	}

	{
		if(row4[2] != 'x')
		{
			score_3+=1;
		}
		else
		{
			score_3+=0;
		}
	}

	{
		if(row4[4] != 'x')
		{
			score_3+=1;
		}
		else
		{
			score_3+=0;
		}
	}

	{
		if(row5[0] != 'x')
		{
			score_3+=1;
		}
		else
		{
			score_3+=0;
		}
	}

	{
		if(row5[2] != 'x')
		{
			score_3+=1;
		}
		else
		{
			score_3+=0;
		}
	}

	{
		if(row6[0] != 'x')
		{
			score_3+=1;
		}
		else
		{
			score_3+=0;
		}
	}
}

int end()
{
	return 0;
}



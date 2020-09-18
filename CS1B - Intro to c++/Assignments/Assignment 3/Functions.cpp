/***********************************************************
 * AUTHOR     	 : Cabbage
 * STUDENT ID 	 : 386273
 * ASSIGNMENT #3 : Multi-Dimensional Array - Tic Tac Toe
 * CLASS      	 : CS1B
 * SECTION   	 : M/W 8:30 - 12:20
 * DUE DATE  	 : 2/25/15
 ***********************************************************/
#include "header.h"

/**********************************************************
* FUNCTION PrintHeader
*_________________________________________________________
* This function receives an assignment name, type
* and number then outputs the appropriate header
* returns nothing.
*_________________________________________________________
* PRE-CONDITIONS
*	PROGRAMMER : Programmer's Name
* 	CLASS      : Student's Course
* 	SECTION    : Class Days and Times
*	LAB_NUM    : Lab Number (specific to this lab)
* 	LAB_NAME   : Title of the Lab
*
* POST-CONDITIONS
*	Does not change
* _________________________________________________________
***********************************************************/

void PrintHeader()
{
	cout << left;
	cout << "***********************************************************";
	cout << "\n*  PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n*  " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n*  " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n*  " << setw(12) << "ASSIGNMENT #" << ASSIGN_NUM << " : " << ASSIGN_NAME;
	cout << "\n***********************************************************\n\n";
	cout << right;
}


void OutputInstruct()
{

}


void InitBoard(char boardAr[][3])
{
	int rowCnt;
	int colCnt;

	for (rowCnt = 0; rowCnt < NUM_ROWS; rowCnt++)
	{

		for (colCnt = 0; colCnt < NUM_COLS; colCnt++)

		{

			boardAr[rowCnt][colCnt] = ' ';

		}

	}

}


void DisplayBoard(const char boardAr[][3])
{

	int i;
	int j;

	cout << setw(10) << "1" << setw(8) << "2" << setw(9) << "3\n";

	for (i = 0; i < 3; i++)
	{
		cout << setw(7) << "[" << i+1 << "][1] | " << "[" << i+1;
		cout << "][2] | " << "[" << i+1 << "][3]" << endl;
		cout << setw(14) << "|" << setw(9) << "|" << endl;

		for (j = 0; j < 3; j++)
		{

			switch(j)
			{
				case 0: cout << i + 1 << setw(9) << boardAr[i][j];
						cout << setw(4) << "|";
				 break;

				case 1: cout << setw(4) << boardAr[i][j];
						cout << setw(5) << "|";
				 break;

				case 2: cout << setw(4) << boardAr[i][j] << endl;
				 break;

				default: cout <<"ERROR!\n\n";

			}

		}

		cout << setw(14)<< "|" << setw(10) << "|\n";

		if (i != 2)
		{
			cout << setw(32) << "--------------------------\n";

		}
	}

	cout << endl << endl;

}


void GetPlayers(string& playerX,
				string& playerO)
{
	/*******************************************************
	 * INPUT - Get player names
	 *******************************************************/
	cout << "Enter player name for token X: ";
	getline(cin, playerX);

	cout << "Enter player name for token O: ";
	getline(cin, playerO);






}


void GetAndCheckInp(char boardAr[][3],
					char token,
					string playerX,
					string playerO)
{
	int inputRow;
	int inputCol;
	bool rowAndColCheck;
	bool rowCheck;
	bool colCheck;
	bool spotCheck;
	char whoWon;

	switch(token)
	{
	case 'X': 	do
				{
					cout << "\n" << playerX << "\'s turn! What\'s your play?: ";
					cin  >> inputRow >> inputCol;
					cin.ignore(1000, '\n');

					rowCheck	   = (inputRow > NUM_ROWS || inputRow < 1);
					colCheck	   = (inputCol > NUM_COLS || inputCol < 1);
					rowAndColCheck = (rowCheck && colCheck);
					spotCheck	   = (boardAr[inputRow - 1][inputCol - 1] == 'X' ||
									  boardAr[inputRow - 1][inputCol - 1] == 'O');


					if(rowAndColCheck) //NEEDS WORK
					{
						cout << "INVALID ROW & COLUMN\n";
						cout << "INPUT ROW = " << inputRow << endl;
						cout << "INPUT COLUMN = " << inputCol << endl;
					}
					else if(rowCheck)
					{
						cout << "INVALID ROW\n";
						cout << "INPUT ROW = " << inputRow << endl;
					}
					else if(colCheck)
					{
						cout << "INVALID COLUMN\n";
						cout << "INPUT COLUMN = " << inputCol << endl;
					}
					else if(spotCheck)
					{
						cout << "SPOT ALREADY TAKEN!\n";
					}

				}while(rowCheck || colCheck || rowAndColCheck || spotCheck);

				boardAr[inputRow - 1][inputCol - 1] = token;

				DisplayBoard(boardAr);


				break;

	case 'O':	do
				{

					cout << "\n" << playerO << "\'s turn! What\'s your play?: ";
					cin  >> inputRow >> inputCol;
					cin.ignore(1000, '\n');

					rowCheck	   = (inputRow > NUM_ROWS || inputRow < 1);
					colCheck	   = (inputCol > NUM_COLS || inputCol < 1);
					rowAndColCheck = (rowCheck && colCheck);
					spotCheck	   = (boardAr[inputRow - 1][inputCol - 1] == 'X' ||
									  boardAr[inputRow - 1][inputCol - 1] == 'O');

					if(rowAndColCheck) //NEEDS WORK
					{
						cout << "INVALID ROW & COLUMN\n";
						cout << "INPUT ROW = " << inputRow << endl;
						cout << "INPUT COLUMN = " << inputCol << endl;
					}
					else if(rowCheck)
					{
						cout << "INVALID ROW\n";
						cout << "INPUT ROW = " << inputRow << endl;
					}
					else if(colCheck)
					{
						cout << "INVALID COLUMN\n";
						cout << "INPUT COLUMN = " << inputCol << endl;
					}
					else if(spotCheck)
					{
						cout << "SPOT ALREADY TAKEN!\n";
					}

				}while(rowCheck || colCheck || rowAndColCheck || spotCheck);


				boardAr[inputRow - 1][inputCol - 1] = token;

				DisplayBoard(boardAr);


				break;

	}

}


char SwitchToken(char token)
{
	if(token == 'X')
	{
		token = 'O';
	}
	else if(token == 'O')
	{
		token = 'X';
	}
	else
	{
		cout << "INVALID TOKEN";
	}

	return token;
}


char CheckWin(const char boardAr[][3])
{
	char whoWon;
	bool rowOneCheck;
	bool rowTwoCheck;
	bool rowThreeCheck;
	bool colOneCheck;
	bool colTwoCheck;
	bool colThreeCheck;
	bool diagCrossCheck1;
	bool diagCrossCheck2;

	//INITIALIZE
//	rowOneCheck     = ((boardAr[0][0] == boardAr[0][1]) && (boardAr[0][1] == boardAr[0][2]));
//	rowTwoCheck     = ((boardAr[1][0] == boardAr[1][1]) && (boardAr[1][1] == boardAr[1][2]));
//	rowThreeCheck   = ((boardAr[2][0] == boardAr[2][1]) && (boardAr[2][1] == boardAr[2][2]));
//	colOneCheck     = ((boardAr[0][0] == boardAr[1][0]) && (boardAr[1][0] == boardAr[2][0]));
//	colTwoCheck     = ((boardAr[0][1] == boardAr[1][1]) && (boardAr[1][1] == boardAr[2][1]));
//	colThreeCheck   = ((boardAr[0][2] == boardAr[1][2]) && (boardAr[1][2] == boardAr[2][2]));
//	diagCrossCheck1 = ((boardAr[0][0] == boardAr[1][1]) && (boardAr[1][1] == boardAr[2][2]));
//	diagCrossCheck2 = ((boardAr[0][2] == boardAr[1][1]) && (boardAr[1][1] == boardAr[2][0]));

	/***********************************************************
	 * PROCESSING - Checks if there is a 3 in-a-row
	 ***********************************************************/
	if((boardAr[0][0] == boardAr[0][1]) && (boardAr[0][1] == boardAr[0][2]))
	{
		whoWon = boardAr[0][0];
	}
	else if((boardAr[1][0] == boardAr[1][1]) && (boardAr[1][1] == boardAr[1][2]))
	{
		whoWon = boardAr[1][0];
	}
	else if((boardAr[2][0] == boardAr[2][1]) && (boardAr[2][1] == boardAr[2][2]))
	{
		whoWon = boardAr[2][0];
	}
	else if((boardAr[0][0] == boardAr[1][0]) && (boardAr[1][0] == boardAr[2][0]))
	{
		whoWon = boardAr[0][0];
	}
	else if(((boardAr[0][1] == boardAr[1][1]) && (boardAr[1][1] == boardAr[2][1])))
	{
		whoWon = boardAr[0][1];
	}
	else if((boardAr[0][2] == boardAr[1][2]) && (boardAr[1][2] == boardAr[2][2]))
	{
		whoWon = boardAr[0][2];
	}
	else if((boardAr[0][0] == boardAr[1][1]) && (boardAr[1][1] == boardAr[2][2]))
	{
		whoWon = boardAr[0][0];
	}
	else if((boardAr[0][2] == boardAr[1][1]) && (boardAr[1][1] == boardAr[2][0]))
	{
		whoWon = boardAr[0][2];
	}
	else
	{
		whoWon = 'T';
	}

	cout << "WHOWON CHECK WIN = " << whoWon;

	return whoWon;
}


void OutputWinner(char whoWon,
				  string playerX,
				  string playerO)
{
	switch(whoWon)
	{
		case 'X' : cout << playerX << "is the winner!\n";
				 break;

		case 'O' : cout << playerO << "is the winner!\n";
				 break;

		default : cout << "Tie Game!";
				 break;
	}




}




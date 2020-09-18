/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #3: Tic Tac Toe
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 2-25-2015
 *************************************************************************/
#include "Header.h"

/**************************************************************************
 * Parallel Arrays - Account Balance Program
 * ________________________________________________________________________
 * This program will be able to search for a name, in a database, which
 * holds their name, id, and balance due. The Program will ask you what
 * input and output file you want to use, and then will prompt for a name
 * to search and will determine if that name is in the database. Then it
 * will output the searched id, name and balance due. It will also
 * calculate and output the average of all balances for the found names.
 * ________________________________________________________________________

 *
 *************************************************************************/
void GetAndCheckInp(char boardAr[][NUM_COLS], char token, string playerX,
												string playerO)
{
	int row;
	int col;
	int rowPlay;
	int colPlay;

	InitializeBoard(boardAr);
	colPlay =0;
	rowPlay =0;


	do
	{
		if(token == 'X')
		{
			cout << endl;
			cout << playerX << " it\'s your turn! What is your play?: ";
			cin >> rowPlay >> colPlay;
			cin.ignore(1000, '\n');
		}
		else
		{
			cout << endl;
			cout << playerO << " it\'s your turn! What is your play?: ";
			cin >> rowPlay >> colPlay;
			cin.ignore(1000, '\n');
		}

		if((rowPlay < 1 || rowPlay > 3) && (colPlay < 1 || colPlay > 3))
		{
			cout << "**INVALID ENTRIES! Please enter a column and a row "
					"value that is >= 1 or <= 3**" << endl;
		}
		else if(rowPlay < 1 || rowPlay > 3)
		{
		cout << "**INVALID ENTRY! Please enter a row value that is >= 1 or "
				"<= 3**" << endl;
		}
		else if(colPlay < 1 || colPlay > 3)
		{
			cout << "**INVALID ENTRY! Please enter a column value that are >= 1 or "
					"<= 3**" << endl;
		}
		else if(boardAr[rowPlay - 1][colPlay - 1] == 'X' ||
				boardAr[rowPlay - 1][colPlay - 1] == 'O')
		{
			cout << "That spot is already taken!!" << endl;
		}



	}while((rowPlay < 1 || rowPlay > 3) && (colPlay < 1 || colPlay > 3));

	for(row = 1; row < NUM_ROWS; row++)
	{
		for(col = 1; col < NUM_COLS; col++)
		{
			if(boardAr[rowPlay - 1][colPlay - 1] == ' ')
			{
				boardAr[rowPlay - 1][colPlay - 1] = token;
				DisplayBoard(boardAr);
			}
		}
	}






}

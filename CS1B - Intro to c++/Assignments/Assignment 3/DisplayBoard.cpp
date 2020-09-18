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
 * DisplayBoard Function
 * ________________________________________________________________________
 * This function is designed to have the tic-tac-toe board be displayed
 * in the console to keep a reference to. The board has the rows and columns
 * numbered for easy eye assurance.
 * ________________________________________________________________________
 * RETURNS -
 * 		boardAr - Which is the outline of the tic tac toe game board
 * 				and will be used to keep reference with it being updated
 * 				every time it switches players
 *
 *************************************************************************/
void DisplayBoard(const char boardAr[][NUM_COLS])
{

	int row;	//CALC - Setting the boarder and the number of rows
	int col;	//CALC - Setting the boarder and the number of columns

	cout << setw(10) << "1" << setw(8) << "2" << setw(9) << "3\n";

	for (row = 0; row < 3; row++)
	{
		cout << setw(7) << "[" << row+1 << "][1] | " << "[" << row+1;
		cout << "][2] | " << "[" << row+1 << "][3]" << endl;
		cout << setw(14) << "|" << setw(9) << "|" << endl;

		for (col = 0; col < 3; col++)
		{

			switch(col)
			{
				case 0: cout << row + 1 << setw(9) << boardAr[row][col];
						cout << setw(4) << "|";
				 break;

				case 1: cout << setw(4) << boardAr[row][col];
						cout << setw(5) << "|";
				 break;

				case 2: cout << setw(4) << boardAr[row][col] << endl;
				 break;

				default: cout <<"ERROR!\n\n";

			}

		}

		cout << setw(14)<< "|" << setw(10) << "|\n";

		if (row != 2)
		{
			cout << setw(32) << "--------------------------\n";

		}
	}

	cout << endl << endl;

}

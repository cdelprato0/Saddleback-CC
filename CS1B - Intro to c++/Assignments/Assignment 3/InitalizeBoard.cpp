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
 * InitializeBoard Function
 * ________________________________________________________________________
 * This function is designed to initialize the tic-tac-toe board by filling
 * all the necessary spaces with white spaces or ' '
 * ________________________________________________________________________
 * RETURNS -
 * 		boardAr - Which is the outline of the tic tac toe game board
 * 				and will be used to keep reference with it being updated
 * 				every time it switches players
 *
 *************************************************************************/
void InitializeBoard(char boardAr[][NUM_COLS])
{
	int rowCount;	//CALC - The count on rows to initialize all to ' '
	int colCount;	//CALC - The count on columns to initialize all to ' '

	//PROCESSING - Initializing all the spaces with a white space or ' '
	//Outer loop for rows
	for(rowCount = 0; rowCount < NUM_ROWS; rowCount++)
	{
		//Inner loop for columns
		for(colCount = 0; colCount < NUM_COLS; colCount++)
		{
			boardAr[rowCount][colCount] = ' ';
		}
	}

}

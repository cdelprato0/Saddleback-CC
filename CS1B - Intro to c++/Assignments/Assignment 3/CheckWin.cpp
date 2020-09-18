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
 * CheckWin Function
 * ________________________________________________________________________
 * This function will take and read in the tic-tac-toe board and will
 * determine if there are any possible winning scenarios whether they be
 * horizontal, vertical or diagonal 3-in-a-rows. It will also return if
 * the game was a tie or a cat's game.
 * ________________________________________________________________________
 * RETURNS -
 * 		whoWon - Which determines the character value that is stored in one
 * 				of the winning row and column. Returning 'X', 'O', 'T'
 * 				for a tie.
 *
 *************************************************************************/
char CheckWin(const char boardAr[][NUM_COLS])
{
	char whoWon;	//OUTPUT - The character that is in the winning play

	//CALC - Each part of the array is compared to determine if there is a
	//		winning play or if it was a tie game
	if((boardAr[0][0] == boardAr[0][1]) && (boardAr[0][1] == boardAr[1][2]))
	{
		//OUT - Will output a char back out into main(X, O, or T)
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
	else if((boardAr[0][1] == boardAr[1][1]) && (boardAr[1][1] == boardAr[2][1]))
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
		//Tied game or cats game.
		whoWon = 'T';
	}

	return whoWon;
}

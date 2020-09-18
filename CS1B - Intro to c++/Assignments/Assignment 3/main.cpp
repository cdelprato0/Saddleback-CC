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
 * Tic - Tac - Toe
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
int main()
{

	char boardAr[NUM_ROWS][NUM_COLS];
	string playerX;
	string playerO;
	int token;
	char winner;

	token = 'X';

	PrintHeader("Tic Tac Toe", 'A', 3);

	InitializeBoard(boardAr);

	GetPlayers(playerX, playerO);

	do
	{
		GetAndCheckInp(boardAr, token, playerX, playerO);

		winner = CheckWin(boardAr);

		token = SwitchToken(token);



	}while(winner != 'X' || winner != 'O');

	OutputWinner(winner, playerX, playerO);



	return 0;
}


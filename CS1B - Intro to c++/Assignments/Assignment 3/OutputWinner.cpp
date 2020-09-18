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
 * OutputWinner Function
 * ________________________________________________________________________
 * This function will take in the player X's name and player O's name and
 * the token that had won the game. Depending on which character is returned
 * playerX, playerO, or a cat's game tie could be the winning output. After
 * the winner is determined it will prompt the users if they would like to
 * play the game again and if not it will terminate the program
 * ________________________________________________________________________
 * RETURNS -
 * 		playerX - Whether they have won the game or not
 * 		playerO - Whether they have won the game or not
 *************************************************************************/
void OutputWinner(char whoWon, string playerX, string playerO)
{
	//PROCESSING - Determines who had the three in a row and congratulates them
	if (whoWon == 'X')
	{
		cout << "*Congratulations, " << playerX <<
				" you have one the Tic-Tac-Toe match!!*";
	}
	else if(whoWon == 'O')
	{
		cout << "*Congratulations, " << playerO <<
				" you have one the Tic-Tac-Toe match!!*";
	}
	else
	{
		//If no body won the game it becomes a cats games or a tie
		cout << "It was a cat\'s game! NO WINNER!" << endl;
	}
}

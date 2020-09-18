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
 * GetPlayers Function
 * ________________________________________________________________________
 * This function will prompt the players to enter their names for the person
 * who wants to be the token 'X' and the player who wants to be token 'O'.
 * Their names will be saved into strings so that they can be called on later.
 * ________________________________________________________________________
 * RETURNS -
 * 		playerX - The user's name for the person who wanted to be 'X'
 * 		playerO - The user's name for the person who wanted to be 'O'
 *
 *************************************************************************/
void GetPlayers(string& playerX, string& playerO)
{

	//INPUT - Prompting the 'X' user for their name to be saved.
	cout << "Enter the uses\'s name that will be playing \'X\': ";
	getline(cin, playerX);

	//INPUT - Prompting the 'O' user for their name to be saved.
	cout << "\nEnter the uses\'s name that will be playing \'O\': ";
	getline(cin, playerO);

}

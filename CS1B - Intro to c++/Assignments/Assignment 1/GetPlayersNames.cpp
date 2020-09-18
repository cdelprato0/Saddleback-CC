/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #1: Functions
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 2-9-2015
 *************************************************************************/
#include "Header.h"

/***************************************************************************
 * Functions - GetPlayersNames
 * -------------------------------------------------------------------------
 * This functions will prompt the users to enter the first player's name
 * and then will prompt for the second player to enter their name. Each
 * name will be save for later use throughout the program
 * -------------------------------------------------------------------------
 ****************************************************************************/
void GetPlayersNames(string& player1, string& player2)
{

	//INPUT - Prompts for the first player's name
	cout << "First player, please enter your name : ";
	getline(cin, player1);

	//INPUT - Prompts for the second player's name
	cout << "Second player, please enter your name: ";
	getline(cin, player2);
	cout << endl;

}

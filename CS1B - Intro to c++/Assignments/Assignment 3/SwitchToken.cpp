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
 * SwitchToken Function
 * ________________________________________________________________________
 * This function is designed to take in the pre-existing value that has
 * been assigned to token and will change the token so it is the other
 * players turn to choose a play.
 * ________________________________________________________________________
 * RETURNS -
 * 		token - Which is changed to the opposite value than of what it was
 * 				called in with
 *************************************************************************/
char SwitchToken(char token)
{
	//PROCESSING - Determines if the pre-existing token was an 'X' or an 'O'
	//				and then switches the token to the new value
	if(token == 'X')
	{
		token = 'O';
	}
	else
	{
		token = 'X';
	}

	return token;
}

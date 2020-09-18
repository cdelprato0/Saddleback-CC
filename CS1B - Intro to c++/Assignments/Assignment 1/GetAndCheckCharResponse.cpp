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
 * Function GetAndCheckCharResponse
 * -------------------------------------------------------------------------
 * This function prompts the user's if they want to play the game. If the
 * users enter the wrong characters the program will display that it was an
 * invalid input and re-prompt them. Once determined, it will return their
 * response.
 * -------------------------------------------------------------------------
 * VARIABLES -
 * 			response - Used to determine if the entered letter is valid
 ****************************************************************************/
char GetAndCheckCharResponse()
{
	char response; //INPUT - Used to determine if the entered letter is valid

	//This do-while will determine if the users had entered an invalid input
	do
	{
		//Prompts the users
		cout << "Would you like to play High Roller (y/n)? ";
		cin.get(response);
		cin.ignore(1000, '\n');

		if(response != 'Y'&& response != 'y' && response != 'N' &&
				response != 'n')
		{
			cout << "** INVALID INPUT - Please enter \'Y\' or \'N\' **" ;
			cout << endl << endl;
		}

	}while(response != 'Y'&& response != 'y' && response != 'N' &&
			response != 'n');

	return response;
}

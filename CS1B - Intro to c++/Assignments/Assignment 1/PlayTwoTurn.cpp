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
 * Functions - PlayTwoTurn
 * -------------------------------------------------------------------------
 * This function will take in the second players name and will prompt that
 * it is their turn and asks them to press the <enter> key to start the
 * roll of the die. It will randomly select a number from 1 to 6 and will
 * output the picture of the die that had rolled. Then will return then
 * number of that die.
 * -------------------------------------------------------------------------
 * VARIABLES -
 * 			randNum - The random number that is generated from the RollDie
 * 						function
 ****************************************************************************/
int PlayTwoTurn(string& player2, int& die)
{
	int randNum; //Calc - The random number that is generated from the RollDie
				//			function

	cout << player2 << "\'s turn" << endl;

	//Prompts the user to hit the <enter> key
	PressEnterToRoll();

	cout << player2 << " rolls:" << endl;

	//Determines the random number to be given
	die = RollDie(randNum);

	//Displays the die's picture and returns the value of it
	DisplayDie(die);
	cout << endl;

	return die;

}

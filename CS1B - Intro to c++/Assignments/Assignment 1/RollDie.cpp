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
 * Function RollDie
 * -------------------------------------------------------------------------
 * This function will produce a randomly generated number that will
 * determine what number die has been rolled for a user.
 * -------------------------------------------------------------------------
 ****************************************************************************/
int RollDie(int& randNum)
{

	srand(time(NULL));

	randNum = rand() % 6 + 1;

	return randNum;
}

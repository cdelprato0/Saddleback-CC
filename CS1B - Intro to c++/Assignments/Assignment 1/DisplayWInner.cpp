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
 * Function DisplayWinner
 * -------------------------------------------------------------------------
 * This function is going to take the dice number from each player and take
 * the players names' and will determine the winner of the game and will
 * out put who had won. If a tie comes up, the program will output both
 * names and state that they have tied.
 * -------------------------------------------------------------------------
 ****************************************************************************/
void DisplayWinner(int& dieNum1, int& dieNum2,string& player1,
		string& player2)
{
	//Determines the winner by checking to see who has the higher number or
	//if they tied
	if(dieNum1 > dieNum2)
	{
		cout << player1 << " is the WINNER!!!";
		cout << endl << endl;
	}
	else if(dieNum1 < dieNum2)
	{
		cout << player2 << " is the WINNER!!!";
		cout << endl << endl;
	}
	else
	{
		cout << player1 << " & " << player2 << " have tied!";
		cout << endl << endl;
	}
}

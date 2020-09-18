/*************************************************************************
 * AUTHOR     : Professor X & BBC
 * LAB #16    : Intro to Recursion - GCD
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   :
 ************************************************************************/
#include "Header.h"

/**************************************************************************
 * UserInput Function
 * ________________________________________________________________________
 * This function will get users first and second integer input.
 * ________________________________________________________________________
 * PRECONDITIONS
 *   INT :
 *   firstNumber
 *   secondNumber
 * POSTCONDITIONS
 *  NULL
 ************************************************************************/
void UserInput(int &firstNumber, int &secondNumber)
{
	//INPUT - Reads in the users input for the first integer
	cout << left;
	cout << setw(26) << "Enter the first integer:";
	cin >> firstNumber;

	//INPUT - Reads in the users input for the second integer
	cout << setw(26) << "Enter the second integer:";
	cin >> secondNumber;
	cout << endl;
}

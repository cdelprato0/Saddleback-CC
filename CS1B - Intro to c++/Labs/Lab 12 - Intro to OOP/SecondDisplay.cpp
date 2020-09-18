/*************************************************************************
 * AUTHOR     : Rhader & BBC
 * LAB #12    : Intro to OOP
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/8/2015
 ************************************************************************/
#include "Header.h"

/**************************************************************************
 * FUNCTION SecondDisplay
 * ________________________________________________________________________
 * This function simply displays the second menu options to the user of
 * the program.
 * returns -> <nothing>
 * ________________________________________________________________________
 * PRECONDITIONS
 *   The selection of the first menu option
 *
 * POSTCONDITIONS
 *   <nothing>
 ************************************************************************/
void SecondDisplay()
{
	cout << "\n\n1 - Initialize Animals\n"
		 << "2 - Change Age\n"
		 << "3 - Change Value\n"
		 << "4 - Display\n"
		 << "0 - Exit\n";
}

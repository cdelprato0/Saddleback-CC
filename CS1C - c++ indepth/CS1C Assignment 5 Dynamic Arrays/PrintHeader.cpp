/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #5:Dynamic Arrays
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#include "Header.h"

/*************************************************************************
 * FUNCTION PrintHeader
 * _______________________________________________________________________
 * This function receives coder's name, the assignment name, the coder's
 * class, the assignment type, and the assignment number.
 *   - returns nothing.
 *________________________________________________________________________
 * PRE-CONDITIONS:
 *   codeName : the code name of the programmer must be previously defined
 *   asName   : the name of the assignment must be previously defined
 *   studId   : the programmer's student ID must be previously defined
 *   asType   : the type of assignment must be previously defined
 *   asNum    : the assignment number must be previously defined
 * _______________________________________________________________________
 * POST-CONDITIONS:
 *   This function will output the class header
 ************************************************************************/
void PrintHeader(string asName, char asType, int asNum)
{
	cout << left
	 	 << "********************************************************"
	 	 << "\n* PROGRAMMED BY : Chaz Del Prato"
	 	 << "\n* " << setw(14) << "Student ID" << ": 382108"
	 	 << "\n* " << setw(14) << "Class" << ": CS1C --> Mon/Wed 2:00pm"
	 	 << "\n* ";
	if(toupper(asType) == 'L')
	{
		cout << "LAB #" << setw(9);
	}
	else
	{
		cout << "ASSIGNMENT #" << setw(2);
	}
	cout << asNum << ": " << asName
	 	 << "\n********************************************************\n\n"
	 	 << right;
}

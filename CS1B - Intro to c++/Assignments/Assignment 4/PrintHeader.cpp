/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #4: Movie List
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 03-09-15
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
void PrintHeader(ofstream& OFile, string asName, char asType, int asNum)
{
	OFile << left;
	OFile << "********************************************************";
	OFile << "\n* PROGRAMMED BY : BBC";
	OFile << "\n* " << setw(14) << "Student ID" << ": 382108";
	OFile << "\n* " << setw(14) << "Class" << ": CS1B --> Mon/Wed 8:30am";
	OFile << "\n* ";
	if(toupper(asType) == 'L')
	{
		OFile << "LAB #" << setw(9);
	}
	else
	{
		OFile << "ASSIGNMENT #" << setw(2);
	}
	OFile << asNum << ": " << asName;
	OFile << "\n******************************************************\n\n";
	OFile << right;
}

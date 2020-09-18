/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #1: Functions
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 2-9-2015
 *************************************************************************/
#include "Header.h"

//PrintHeader - Determines if the program is an assignment or lab and
//				displays the programmers info in the output.
void PrintHeader(string asName, char asType, int asNum)
{
	cout << left;
	cout << "***********************************************************";
	cout << "\n* PROGRAMMED BY : BBC";
	cout << "\n* " << setw(14) << "Student ID" << ": 382108";
	cout << "\n* " << setw(14) << "Class" << ": CS1B --> Mon/Wed 8:30am";
	cout << "\n* ";
	if(toupper(asType) == 'L')
	{
		cout << "LAB #" << setw(9);
	}
	else
	{
		cout << "ASSIGNMENT #" << setw(2);
	}
	cout << asNum << ": " << asName;
	cout << "\n***********************************************************\n\n";
	cout << right;
}

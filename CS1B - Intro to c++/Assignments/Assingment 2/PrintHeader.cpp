/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #2: Parallel Arrays
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 2-11-2015
 *************************************************************************/
#include "Header.h"

//PrintHeader - Determines if the program is an assignment or lab and
//				displays the programmers info in the output.
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

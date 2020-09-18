#ifndef PRINTHEADER_H_
#define PRINTHEADER_H_
#include "classheader.h"
/************************************************************************
 *
 * FUNCTION PrintHeader
 * ______________________________________________________________________
 * This function receives and assignment name, type
 * and number then outputs the appropriate header - returns nothing.
 * ______________________________________________________________________
 * PRE-CONDITIONS
 * 		asName: Assignment Name has to be previously defined
 * 		asType: Assignment Type has to be previously defined
 * 		asNum : Assignment Number has to be previously defined
 *
 * POST-CONDITIONS
 * 		This function will output the class heading.
 *
 ************************************************************************/
void PrintHeader(string asName, // INPUT - ASSIGNMENT NAME
				 char asType, 	// INPUT - ASSIGNMENT TYPE
				 int asNum)		// INPUT - ASSIGNMENT NUMBER
{
	// OUTPUT - Class Heading
	cout << left;
	cout << "**************************************************\n";
	cout << "* Programmed by : Heretic Furby & BBC";
	cout << "\n* " << setw(14) << "Student ID" << ": 323630, 382108";
	cout << "\n* " << setw(14) << "Class" << ": CS1B --> MW - 8:30AM";
	cout << "\n* ";
	if (toupper(asType) == 'L')
	{
		cout << "LAB #" << setw(9);
	}
	else
	{
		cout << "ASSIGNMENT #" << setw(2);
	}
	cout << asNum << ": " << asName;
	cout <<	"\n**************************************************\n\n";
	cout << right;
}

#endif /* PRINTHEADER_H_ */

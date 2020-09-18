/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * LAB #6b      : Enumerated Types
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 2-11-2015
 *************************************************************************/
#include "header.h"

/**************************************************************************
 * ConvEnum2Strg Function
 * ________________________________________________________________________
 * This function is designed to convert a Enum data type into a string.
 * This function is also going to output into the console confirming
 * what day it is.
 * ________________________________________________________________________
 *************************************************************************/
void ConvEnum2Strg(Days today)
{
	//OUT - Will be printed into the console
	cout << "Today is ";

	//PROCESS - will take in the variable today and convert it into to a
	//			string that can and will be displayed into the console
	switch(today)
	{
		case SUNDAY   : cout << "SUNDAY";
			break;
		case MONDAY   : cout << "MONDAY";
			break;
		case TUESDAY  : cout << "TUESDAY";
			break;
		case WEDNESDAY: cout << "WEDNESDAY";
			break;
		case THURSDAY : cout << "THURSDAY";
			break;
		case FRIDAY   : cout << "FRIDAY";
			break;
		case SATURDAY : cout << "SATURDAY";
			break;
		default       : cout << "**** Invalid day input! ****\n\n";

	}

	//OUT - Will be printed into the console
	cout << "!" << endl << endl;
}

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
 * ConvStrg2Enum Function
 * ________________________________________________________________________
 * This function is designed to convert a string into a enum data type by
 * using a switch statement that will determine what day the user had
 * entered
 * ________________________________________________________________________
 * VARIABLES -
 * 			today - Saves the day and returns to the int main()
 *************************************************************************/
Days ConvertStrg2Enum(string& stringDays)
{
	Days today;	//Saves the day and returns to the int main()

	//This switch statement will take in the string and will take the first
	//letter and will determine the exact day it was looking for. In case
	//of words that start the same it will find the second letter and will
	//determine from there.
	switch(toupper(stringDays[0]))
	{
	case 'S': if(toupper(stringDays[1]) == 'A')
					today = SATURDAY;
				else
					today = SUNDAY;
				break;
	case 'M': today = MONDAY;
				break;
	case 'T': if(toupper(stringDays[1]) == 'H')
					today = THURSDAY;
				else
					today = TUESDAY;
				break;
	case 'W': today = WEDNESDAY;
				break;
	case 'F': today = FRIDAY;
				break;
	default : cout << "**** Invalid day input! ****";


	}

	return today;
}

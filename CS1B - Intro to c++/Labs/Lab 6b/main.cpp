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
 * Enumerated Types
 * ________________________________________________________________________
 * This program is designed to first read in a day as a string input and
 * then convert it to the Days type, and then convert it back to a string
 * and output the value.
 * ________________________________________________________________________
 * INPUT -
 * 			stringDays - User's input for what day it is
 * 			today - Saves the day and returns to the int main()
 *************************************************************************/
int main()
{
	string stringDays; //INPUT - User's input for what day it is
	Days today;		   //Saves the day and returns to the int main()

	//Will print the header into the console
	PrintHeader("Enumerated Types", 'L', 6);

	//INPUT - Prompting the user to enter what day it is - Initialize the LCV
	cout << "What day is today? ";
	cin >> stringDays;
	cin.ignore(10000, '\n');

	//Will convert the days as long as they are valid - Checks the LCV
	while(stringDays != "No")
	{
		//Converts a string to the data type Days and is assigned to today
		today = ConvertStrg2Enum(stringDays);

		//Converts the data type Days into a string so it can be displayed
		//into the console
		ConvEnum2Strg(today);

		//Changes the LCV
		cout << "What day is today? ";
		cin >> stringDays;
		cin.ignore(10000, '\n');
	}

	//Outputs to the console
	cout << "**** Invalid day input! ****" << endl << endl;
	cout << "Today is INVALID!";
	return 0;
}

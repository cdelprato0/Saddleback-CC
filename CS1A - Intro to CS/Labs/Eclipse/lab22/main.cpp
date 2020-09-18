/*
 * main.cpp
 *
 *  Created on: Nov 24, 2014
 *      Author: mrobison5
 */

#include"header.h"

/*************************************************************************
* OUTPUT - Number of times a name is found in a user inputed array
* ------------------------------------------------------------------------
*
* This program receives user inputed names and searches for a name
* within that list and counts how many times that name appears.
*
* ------------------------------------------------------------------------
* INPUT - Names of people to be searched for and assigns the inputs to
* 			a string array.
*
* 			nameList // Names to be searched
* 			search   // Name being looked for
*
* ------------------------------------------------------------------------
* OUTPUT - Number of times a particular name is found
*
* 			amount   // Number of times name found
*
**************************************************************************/

int main()
{

	// Declaring of variables that are going to be used for passing to functions

	const int NUM_NAMES = 10;  // CONST INT for number of elements in array
	string nameList[10];       // INPUT & OUTPUT the names being input for array
	string search;             // INPUT & CALC name being searched in list
	int amount;                // CALC & OUTPUT the number of times name found

	// FUNCTION - Call header function to display assignment information

	PrintHeader("Functions - ARRAYS", 'L', 22);

	// FUNCTION - to gather information regarding names to place in file

	NameFile(nameList, NUM_NAMES);

	do
	{

		amount = 0;

		// FUNCTION - search the amount of times name found in array

		cout << endl;
		cout << "Who do you want to search for (enter done to exit)? ";
		getline(cin, search);
		amount = NameSearching(nameList, NUM_NAMES, search);

		// OUTPUT - the number of times the name is found

		if (amount != 0)
		{

			cout << "There are " << amount << " instances of the name ";
			cout << search << "." << endl;

		}

		else if (search != "done" && search != "Done")
		{

			cout << search << "\'s name does not exist in this list." << endl;

		}


	}while(search != "done" && search != "Done");

	cout << endl;

	cout << "Thank you for using my program." << endl;

	return 0;
}



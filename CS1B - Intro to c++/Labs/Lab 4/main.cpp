#include "header.h"

int main()
{

	// Declaring of variables that are going to be used for passing to functions

	const int NUM_NAMES = 10;  // CONST INT for number of elements in array
	string nameList[10];       // INPUT & OUTPUT the names being input for array
	string search;             // INPUT & CALC name being searched in list
	int amount;                // CALC & OUTPUT the number of times name found
	// FUNCTION - Call header function to display assignment information

	PrintHeader("Introduction to Arrays", 'L', 4);

	EnterName(nameList, NUM_NAMES);

	do
	{

		amount = 0;

		// FUNCTION - search the amount of times name found in array

		cout << endl;
		cout << "Who do you want to search for (enter done to exit)? ";
		getline(cin, search);

		amount = SearchName(nameList, NUM_NAMES, search);

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

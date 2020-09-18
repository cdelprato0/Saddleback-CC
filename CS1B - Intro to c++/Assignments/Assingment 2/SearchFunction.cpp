/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #2: Parallel Arrays
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 2-11-2015
 *************************************************************************/
#include "header.h"

/**************************************************************************
 * NameSearching Function
 * ________________________________________________________________________
 * This function, when called, will take in the user input for the person
 * searched. Then will search the array files to see if the name is in
 * the database and if it is, it will output found or if not will say not
 * found.
 * ________________________________________________________________________
 * INPUTS -
 * 		index - The number of the spot the array is in
 * 		searchName - The name that is being searched for in the database
 *
 * 	OUTPUT -
 * 		found - Will determine if the name that was requested is found or
 * 				not
 *		balance - Will keep a running total sum of the balances due on the
 *			      people that were found
 *************************************************************************/

bool NameSearching(ofstream& OFile, string NAMES_AR[], const int AR_SIZE,
		string searchName, int IDS_AR[], float BAL_AR[], float& balance)
{
	int index;		//INPUT - The number of the spot the array is in
	bool found;		//OUTPUT - Will keep a running total sum of the
					//balances due on the people that were found

	//Initializes the necessary variables to zero or false to enter the loop
	index = 0;
	found = false;


	//PROCESSING - Determines if the name was found in the search or not
	while(index < AR_SIZE && !found)
	{
		if(NAMES_AR[index] == searchName)
		{
			found = true;

			OFile << IDS_AR[index] << "\t" << left << setw(24) <<
					searchName << left << "$" <<setprecision(2) << fixed <<
					right << setw(10) << BAL_AR[index] << endl;

			balance = balance + BAL_AR[index];
		}
		else
		{
			index++;
		}
	}
	return found;
}

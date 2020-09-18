/**************************************************************************
 * AUTHOR     : Bacon Pancakes & BBC
 * STUDENT ID : 951436 & 382108
 * LAB #5     : Array Train
 * CLASS      : CS1B
 * SECTION    : MW 8:30am
 * DUE DATE   : 2/11/2015
 *************************************************************************/
#include "MyHeader.h"

/**************************************************************************
 * SearchString Function
 * ________________________________________________________________________
 * This function will take in a string to search for within an array.The
 * user has been prompted to enter a name they would like to find from the
 * input file. This function will be able to find one instance of a name.
 * Once that name is found it will return the index of that name in the
 * array.
 * ________________________________________________________________________
 *VARIABLE -
 *			index - This is the number in the array that is being looked at
 *			found - Used to determine if the name is found in the array or
 *					not
 *************************************************************************/
int SearchString(const int AR_LIST, const string STRING_AR[],
				 string searchString)
{
	int index;		//This is the number in the array that is being looked at
	bool found;		//Used to determine if the name is found in the array or
					//not.

	//Initializing index to zero and found to false so it can start the loop
	index = 0;
	found = false;

	//The loop searches through the input file and looks for the string
	//that matches the search string and will return true when found.
	while(!found && index < AR_LIST)
	{
		if(searchString == STRING_AR[index])
		{
			found = true;
		}
		else
		{
			index++;
		}
	}

	return index;
}

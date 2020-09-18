/**************************************************************************
 * AUTHOR     : Cabbage & BBC
 * STUDENT ID : 386273 & 382108
 * LAB #7     : Binary Search
 * CLASS      : CS1B
 * SECTION    : MW 8:30am
 * DUE DATE   : 2/18/2015
 *************************************************************************/
#include "header.h"

/**************************************************************************
 * SequentialSearch Function
 * ________________________________________________________________________
 * This function searches for the search values index by using sequential
 * search and outputs the index
 *
 * ________________________________________________________________________
 *VARIABLE -
 *			index - number in the array that is being looked at
 *			found - Flag whether the search value is found or not
 *			key   - The number that is being searched by the user
 *
 *************************************************************************/

int SequentialSearch(int intAr[],		//CALC - array that contains ints
					 const int AR_SIZE) //CALC - Array size
{
	int key;	//IN & OUT - The number that is being searched by the user
	int index;	//CALC 	   - number in the array that is being looked at
	bool found;	//CALC     - Flag whether the search value is found or not


	for(int counter = 0; counter < 4; counter++)
	{
		//INITIALIZE
		found = false;
		index = 0;

		//INPUT - prompts the user to input the search value
		cout << "\nEnter an integer to search for: ";
		cin  >> key;

		//PROCESSING - Searches within the array to find value
		while(!found && index < AR_SIZE)
		{
			if(intAr[index] == key)
			{
				found = true;
			}
			else
			{
				index++;
			}//end IF

		}//end WHILE

		if(!found)
		{
			cout << key << " was not found!\n";
		}
		else
		{
			cout << "The integer " << key << " was found in index #"
				 << index << endl;
		}//end IF


	}//end FOR



	return index;
}

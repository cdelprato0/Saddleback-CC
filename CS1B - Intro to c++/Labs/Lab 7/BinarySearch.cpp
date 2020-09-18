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
 * BinarySearch Function
 * ________________________________________________________________________
 * This function is designed to take in an user's search number and
 * determine through a binary search.
 * ________________________________________________________________________
 *VARIABLE -
 *			index - number in the array that is being looked at
 *			bott  - Bottom of the are(index 0)
 *			top   - Top of the array (highest index)
 *			mid   - In the middle of the bottom and the top
 *			found - Flag whether the search value is found or not
 *			key   - The number that is being searched by the user
 *
 *************************************************************************/
int BinarySearch(int intAr[],		//CALC - array that contains ints
				 const int AR_SIZE) //CALC - array size
{
	int key;	//IN & OUT - The number that is being searched by the user
	int bott;	//CALC	   - Bottom of the are(index 0)
	int top;	//CALC     - Top of the array (highest index)
	int mid;	//CALC     - In the middle of the bottom and the top
	bool found;	//CALC     - Flag whether the search value is found or not
	int index;	//CALC     - number in the array that is being looked at

	//PROCESSING - loops section of code four times
	for(int counter = 0; counter < 4; counter++)
	{
		//INITIALIZE
		bott = 0;
		top = AR_SIZE - 1;
		found = false;

		//INPUT - Prompts the user to enter the number they want to search
		cout << "\nEnter an integer to search for: ";
		cin  >> key;

		//PROCESSING - searches for the inputed number's index
		while(!found && bott <= top)
		{
			mid = (bott + top) / 2;

			if(intAr[mid] == key)
			{
				found = true;
				index = mid;
			}
			else if(intAr[mid] < key)
			{
				bott = mid + 1;
			}
			else
			{
				top = mid - 1;
			}//end IF

		}//end WHILE

		//OUTPUT - Outputs if the value was found or not.
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

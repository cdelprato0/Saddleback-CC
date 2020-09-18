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
 * NumInstance Function
 * ________________________________________________________________________
 * This function will take in the search item and will determine the number
 * of instances the age appears in the input file.
 * ________________________________________________________________________
 *VARIABLE -
 *			index - This is the number in the array that is being looked at
 *			instance - The number of times the age appeared in the input file
 *************************************************************************/
int NumInstance(const int AR_LIST, const int INT_AR[], int searchItem)
{
	int index;		//This is the number in the array that is being looked at
	int instance;	//The number of times the age appeared in the input file

	//Initializing the instance to zero
	instance = 0;

	//Determines how many times a search item appears in an input file
	for(index = 0; index < AR_LIST; index++)
	{
		if(searchItem == INT_AR[index])
		{
			instance++;
		}
	}

	return instance;
}

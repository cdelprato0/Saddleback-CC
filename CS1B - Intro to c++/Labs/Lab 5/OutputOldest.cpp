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
 * OutputOldest Function
 * ________________________________________________________________________
 * This function will be able to determine the oldest age in an input file
 * by searching for the highest number of age in the file. The person's
 * index in the array will be returned to int main()
 * ________________________________________________________________________
 *VARIABLE -
 *			index - This is the number in the array that is being looked at
 *			oldest- The index of the oldest person from the input file
 *************************************************************************/
int OutputOldest(const int AR_LIST, const int INT_AR[])
{
	int index;	//This is the number in the array that is being looked at
	int oldest;	//The index of the oldest person from the input file

	//Initializing the variable to zero
	oldest = 0;

	//The loop that will be searching for the oldest person from an input
	//file and will return it when it is found
	for(index = 0; index < AR_LIST; index++)
	{
		if(INT_AR[index] > INT_AR[oldest])
		{
			oldest = index;
		}
	}

	return oldest;
}



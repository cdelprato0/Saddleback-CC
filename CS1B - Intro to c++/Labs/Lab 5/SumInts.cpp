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
 * SumInts Function
 * ________________________________________________________________________
 * This function will add up and accumulate all of the ages in the array
 * and will return the sum of all the ages.
 * ________________________________________________________________________
 *VARIABLE -
 *			index - This is the number in the array that is being looked at
 *			sum   - Accumulates all the ages in the array(intAr[])
 *************************************************************************/
int	SumInts(const int AR_SIZE, const int INT_AR[])
{
	int index;	//This is the number in the array that is being looked at
	int sum;	//Accumulates all the ages in the input file

	//Initializing index and sum to zero
	index = 0;
	sum = 0;

	//The loop goes through the array and adds up all the ages in the array
	//and returns the sum of them all
	while(-1 != INT_AR[index] && index < AR_SIZE)
	{
		sum = sum + INT_AR[index];
		index++;
	}

	return sum;


}

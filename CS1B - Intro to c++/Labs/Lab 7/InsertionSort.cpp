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
 * InsertionSort Function
 * ________________________________________________________________________
 * This function will sort out the array in order and output it to the
 * console.
 * ________________________________________________________________________
 *VARIABLE -
 *			index - number in the array that is being looked at
 *			temp  - The place holder for the highest value
 *			j     - The current value that the computer is looking at
 *************************************************************************/
void InsertionSort(int intAr[],		  //CALC - array that contains ints
				   const int AR_SIZE) //CALC - array size
{
	int temp;	//CALC - The place holder for the highest value
	int j;		//CALC - The current value that the computer is looking at

	//PROCESSING - loops section of code four times
	for(int counter = 0; counter < 4; counter++)
	{
		//PROCESSING - Finds the largest value
		for(int i = 1; i < AR_SIZE; ++i)
		{
			temp = intAr[i];
			j = i -1;

			while(j >= 0 && intAr[j] > temp)
			{
				intAr[j+1] = intAr[j];
				j = j - 1;

			}//end WHILE
			intAr[j + 1] = temp;
		}//end FOR
	}//end FOR
}



/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #1:Random Number Generator
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#include "Header.h"

/**************************************************************************
 * InsertionSort Function
 * ________________________________________________________________________
 * This function will sort out the array in order and output it to the
 * console.
 * ________________________________________________________________________
 *VARIABLE -
 *			i     - number in the array that is being looked at
 *			temp  - The place holder for the highest value
 *			j     - The current value that the computer is looking at
 *************************************************************************/
void InsertionSort(int numberAr[], int arraySize)
{
	int temp;	//CALC - The place holder for the highest value
	int j;		//CALC - The current value that the computer is looking at

	//PROCESSING - loops section of code four times
	for(int counter = 0; counter < 4; counter++)
	{
		//PROCESSING - Finds the largest value
		for(int i = 1; i < arraySize; ++i)
		{
			temp = numberAr[i];
			j = i -1;

			while(j >= 0 && numberAr[j] > temp)
			{
				numberAr[j+1] = numberAr[j];
				j = j - 1;

			}//end WHILE

			numberAr[j + 1] = temp;

		}//end FOR
	}//end FOR
}

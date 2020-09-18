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
 * Output Function
 * ________________________________________________________________________
 * This function is designed to output the elements of the array before and
 * after they are sorted accordingly.
 * ________________________________________________________________________
 *VARIABLE -
 *			index - number in the array that is being looked at
 *************************************************************************/
void OutputFunction(const int intAr[],
					const int AR_SIZE)
{
	int index; //CALC-number in the array that is being looked at

	//OUTPUT - Outputs array
	for(index = 0; index < AR_SIZE; index++)
		{
			cout << "Index #" << index << ": " << intAr[index] << endl;


		}//end FOR
}

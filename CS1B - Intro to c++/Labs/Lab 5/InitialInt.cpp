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
 * InitialInt Function
 * ________________________________________________________________________
 * This function is initializing the array "intAR[]", which in our case is
 * the user's age, to zero.
 * ________________________________________________________________________
 *VARIABLE -
 *			index - This is the number in the array that is being looked at
 *************************************************************************/
void InitialInt(const int AR_SIZE, int intAr[])
{
	int index;	//CALC - The number in the array that is being looked at

	//PROCESSING - Initializing the array "int Ar[]" to zero
	for(index = 0; index < AR_SIZE; index++)
	{
		intAr[index] = -1;
	}

}

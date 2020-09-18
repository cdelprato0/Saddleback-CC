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
 * InitialStrg Function
 * ________________________________________________________________________
 * This function is initializing the array "strgAr[]", which in our case is
 * the user's name, to zero.
 * ________________________________________________________________________
 *VARIABLE -
 *			index - This is the number in the array that is being looked at
 *************************************************************************/
void InitialStrg(const int AR_SIZE, string strgAr[])
{
	int index;	//CALC - The number in the array that is being looked at

	//PROCESSING - Initializing the array "strgAr[]" equal to zero
	for(index = 0; index < AR_SIZE; index++)
	{
		strgAr[index].clear();
	}

}

/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #1:Random Number Generator
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#include "Header.h"

/**************************************************************************
 * OutputArray Function
 * ________________________________________________________________________
 * This function is designed to output the elements of the array after it
 * has been sorted. It will also output to an output file.
 * ________________________________________________________________________
 *VARIABLE -
 *			index - number in the array that is being looked at
 *************************************************************************/
void OutputArray(ofstream& oFile, const int numberAr[], int arraySize)
{
	int index; //CALC-number in the array that is being looked at

	//OUTPUT - Outputs array to output file
	for(index = 0; index < arraySize; index++)
		{
			oFile << numberAr[index] << endl;

		}//end FOR
}

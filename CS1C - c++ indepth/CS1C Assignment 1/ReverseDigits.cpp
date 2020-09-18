/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #1:Random Number Generator
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#include "Header.h"

/**************************************************************************
 * ReverseDigits Function
 * ________________________________________________________________________
 * This function is taking the random number that has been created and
 * reversing the three digits.
 * Ex. 123 - Reversed 321
 * ________________________________________________________________________
 * VARIABLE -
 *			reverse - the variable that holds the newly reversed digits
  *************************************************************************/
void ReverseDigits(int randNum)
{
	int reverse; //CALC&OUT - used to calculate the reversed digits and
				 //				used to output what they are

	//Initializing the reverse to zero
	reverse = 0;

	//PROCRESSING - The FOR loop is taking each individual digit and changing
	//				the formation
	for( ; randNum != 0 ;)
	{
		reverse = reverse * 10;
		reverse = reverse + randNum % 10;
		randNum = randNum / 10;
	}//END FOR LOOP

	//OUT- Outputs the reversed digits
	cout << "The new order of the three digits is :" << reverse
		 << endl << endl;
}

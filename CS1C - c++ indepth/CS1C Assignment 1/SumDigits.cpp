/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #1:Random Number Generator
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#include "Header.h"

/**************************************************************************
 * SumDigits Function
 * ________________________________________________________________________
 * This function is taking the random number that has been created and
 * adding each of the digits to equal a sum of all three.
 * EX. 123 - 1+2+3=6
 * ________________________________________________________________________
 * VARIABLE -
 *			count - keeps track of how many digits are in the whole number
 *			sum - Holds the sum of all three digits
  ************************************************************************/
void SumDigits(int randNum)
{
	int count; //CALC - Used in FOR loop to keep count of digits
	int sum;   //CALC - Used in FOR loop to keep a running sum of the three
			   //       digits

	//Initializing the sum to zero
	sum = 0;

	//PROCESSING - The FOR loop is taking the random number and adding each
	//				digit of the number to itself so i can make the sum of
	//				the three
	for(count = 1; count <= 3; count++)
	{
		sum = sum + randNum % 10;
		randNum = randNum / 10;
	}//END FOR LOOP

	//OUT - Outputs the sum to the console
	cout << "The sum of the three digits is: " << sum;
	cout << endl << endl;
}

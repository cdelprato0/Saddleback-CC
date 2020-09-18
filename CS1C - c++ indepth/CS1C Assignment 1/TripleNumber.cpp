/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #1:Random Number Generator
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#include "Header.h"

/**************************************************************************
 * TripleNumber Function
 * ________________________________________________________________________
 * This function is taking the random number and simply just tripling it
 * Ex. 10 * 3 = 30
 * ________________________________________________________________________
 * VARIABLE -
 *			triple - the variable that holds the tripled valve
  ************************************************************************/
void TripleNumber(int randNum)
{
	int triple; //CALC - used to hold the value of the tripled number

	//Initializing the triple value to zero
	triple = 0;

	//PROCESSING - Multiplying the given random number by 3 and storing
	//				that value
	triple = randNum * 3;

	//Outputting the triple value to the console
	cout << "Tripling the Random Number gives you: " << triple
		 << endl << endl;
}

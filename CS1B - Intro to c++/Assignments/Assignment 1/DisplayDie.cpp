/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #1: Functions
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 2-9-2015
 *************************************************************************/
#include "Header.h"

/***************************************************************************
 * Functions - DisplayDie
 * -------------------------------------------------------------------------
 * This functions holds the values of each die and holds a character
 * generated picture of each dice from 1 to 6. Once determined the number
 * of the die it will return the picture.
 * -------------------------------------------------------------------------
 * CONSTANTS -
 * 			DIE_ONE
 * 			DIE_TWO
 * 			DIE_THREE
 * 			DIE_FOUR
 * 			DIE_FIVE
 * 			DIE_SIX
 ****************************************************************************/
void DisplayDie(int die)
{
	//Assigning each die to a constant and assigning the picture that goes
	//with it
	const string DIE_ONE =   "-----------\n"
						     "+         +\n"
						     "+         +\n"
						     "+    O    +\n"
						     "+         +\n"
						     "+         +\n"
						     "-----------\n";
	const string DIE_TWO =   "-----------\n"
						     "+         +\n"
						     "+  O      +\n"
					  	     "+         +\n"
				  		     "+       O +\n"
						     "+         +\n"
						     "-----------\n";
	const string DIE_THREE = "-----------\n"
						     "+ O       +\n"
						     "+         +\n"
						     "+    O    +\n"
						     "+         +\n"
						     "+       O +\n"
						     "-----------\n";
	const string DIE_FOUR =  "-----------\n"
						     "+         +\n"
						     "+  O   O  +\n"
						     "+         +\n"
						     "+  O   O  +\n"
						     "+         +\n"
						     "-----------\n";
	const string DIE_FIVE =  "-----------\n"
						     "+         +\n"
						     "+  O   O  +\n"
						     "+    O    +\n"
						     "+  O   O  +\n"
						     "+         +\n"
						     "-----------\n";
	const string DIE_SIX =   "-----------\n"
						     "+  O   O  +\n"
						     "+         +\n"
						     "+  O   O  +\n"
						     "+         +\n"
						     "+  O   O  +\n"
						     "-----------\n";

	//Switch statement that outputs the correct picture or if an invalid
	//number has been entered
	switch(die)
	{
	case 1: cout << DIE_ONE;
				break;
	case 2: cout << DIE_TWO;
				break;
	case 3: cout << DIE_THREE;
				break;
	case 4: cout << DIE_FOUR;
				break;
	case 5: cout << DIE_FIVE;
				break;
	case 6: cout << DIE_SIX;
				break;
	default: cout << "***** ERROR _ INVALID DIE VALUE *****\n";

	}

}

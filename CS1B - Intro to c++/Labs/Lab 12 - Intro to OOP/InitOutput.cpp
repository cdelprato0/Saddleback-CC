/*************************************************************************
 * AUTHOR     : Rhader & BBC
 * LAB #12    : Intro to OOP
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/8/2015
 ************************************************************************/
#include "Header.h"

/*************************************************************************
 * FUNCTION Output
 * ________________________________________________________________________
 * This function will simply display; in proper format, the values of each
 * animal.
 *
 * returns -> default values of each animal
 * ________________________________________________________________________
 * PRECONDITIONS
 *   GetValue : The actual value of the animals, either the default or user
 *   			input.
 *   GetAge	  : The age of the animals, either the default or the user
 *   			input.
 *
 *
 * POSTCONDITIONS
 *   the values will be displayed in proper format.
 *************************************************************************/
void Output(Sheep fluffy, Pig babe, Sheep maa)
{
	//OUTPUT - Outputs a display menu to the console that display the name
	//			of the animal and what their age and value is
	cout << left << setw(11) <<"ANIMAL" << setw(15) << "NAME" << setw(7) << "AGE" << "VALUE\n";
	cout << setw(11) << "----------" << setw(15) << "--------------" << setw(4) << "---" << "-----------\n";

	cout << setw(11) << "Sheep" << setw(17) << fluffy.GetName() << setw(5) << fluffy.GetAge()
		 << setprecision(2) << fixed << fluffy.GetValue();

	cout << setw(12) << "\nSheep" << setw(17) << maa.GetName() << setw(5) << maa.GetAge()
		 << maa.GetValue();

	cout << setw(12) << "\nPig" << setw(17) << babe.GetName() << setw(5) << babe.GetAge()
		 << babe.GetValue();
	cout << endl << endl;
}

/*************************************************************************
 * AUTHOR     : Rhader & BBC
 * LAB #12    : Intro to OOP
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/8/2015
 ************************************************************************/
#include "Header.h"

/*************************************************************************
 * FUNCTION Init
 * ________________________________________________________________________
 * This function will set default values for each animal.
 * returns -> default values of each animal
 * ________________________________________________________________________
 * PRECONDITIONS
 *   <nothing>
 *
 * POSTCONDITIONS
 *   default values will be returned to the program.
 *************************************************************************/
void Init(Sheep &fluffy, Sheep &maa, Pig &babe)
{
	//PROCESSING - Assigns all the information into each object such as
	//				the age, name and value of the animals
	fluffy.SetAge(1);
	fluffy.SetName("Fluffy");
	fluffy.SetValue(15000.00);

	maa.SetAge(3);
	maa.SetName("Maa");
	maa.SetValue(16520.35);

	babe.SetAge(2);
	babe.SetName("Babe");
	babe.SetValue(10240.67);

}

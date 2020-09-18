/*************************************************************************
 * AUTHOR     : Druox 2.0 & BBC
 * LAB #15    : Arrays & Linked Lists of Sheep
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/13/15
 ************************************************************************/
#include "Header.h"

//Class Constructor
Sheep::Sheep()
{
	name = ' ';
	age = -1;
}


//Class Destructor
Sheep::~Sheep()
{

}


/*************************************************************************
 * FUNCTION GetAge
 * ________________________________________________________________________
 * This function simply allows the code to retrieve the age of any animal.
 *
 * returns -> age
 * ________________________________________________________________________
 * PRECONDITIONS
 *   GetCommandTwo : user selection
 *
 * POSTCONDITIONS
 *   returns the value of the age
 ************************************************************************/
int Sheep::GetAge()const
{
	return age;
}


/*************************************************************************
 * FUNCTION GetName
 * ________________________________________________________________________
 * This function simply allows the code to retrieve the name of any animal.
 *
 * returns -> name
 * ________________________________________________________________________
 * PRECONDITIONS
 *   GetCommandTwo : user selection
 *
 * POSTCONDITIONS
 *   returns the name of the animal
 ************************************************************************/
string Sheep::GetName()const
{
	return name;
}
/*************************************************************************
 * FUNCTION SetAge
 * ________________________________________________________________________
 * This function will allow the user to set the age of any animal. age
 * is private.
 *
 * returns -> age
 * ________________________________________________________________________
 * PRECONDITIONS
 *   AddSheep : allows the code to set the values of the animals.
 *
 * POSTCONDITIONS
 *   the new age will be returned to the program.
 ************************************************************************/
void Sheep::SetAge(int sheepAge)
{

	age = sheepAge;

}

/*************************************************************************
 * FUNCTION SetName
 * ________________________________________________________________________
 * This function will allow the user to set the name of any animal. Name
 * is private.
 *
 * returns -> name
 * ________________________________________________________________________
 * PRECONDITIONS
 *   AddSheep : allows the code to set the values of the animals.
 *
 * POSTCONDITIONS
 *   the new value will be returned to the program.
 ************************************************************************/
void Sheep::SetName(string newName)
{
	name = newName;
}

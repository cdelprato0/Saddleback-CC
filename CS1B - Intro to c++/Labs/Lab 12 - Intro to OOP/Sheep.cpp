/*************************************************************************
 * AUTHOR     : Rhader & BBC
 * LAB #12    : Intro to OOP
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/8/2015
 ************************************************************************/
#include "Header.h"

//Constructor
Sheep::Sheep()
{
	age = -1;
	value = -1;
	name = "";
}

//De-structor
Sheep::~Sheep()
{
	age = -1;
	value = -1;
	name = "";
}


/*************************************************************************
 * FUNCTION ChangeAge
 * ________________________________________________________________________
 * This function will allow the user to change the value of age & return
 * the new value. Age is private.
 *
 * returns -> age
 * ________________________________________________________________________
 * PRECONDITIONS
 *   userCommand : the command entered by the user must be previously
 *   			   defined
 *
 * POSTCONDITIONS
 *   the new age will be returned to the program.
 ************************************************************************/
int Sheep::ChangeAge(int newAge)
{

	age = newAge;

	return age;
}


/*************************************************************************
 * FUNCTION ChangeValue
 * ________________________________________________________________________
 * This function will allow the user to change the value of value & return
 * the new value. Value is private.
 *
 * returns -> value
 * ________________________________________________________________________
 * PRECONDITIONS
 *   userCommand : the command entered by the user must be previously
 *   			   defined
 *
 * POSTCONDITIONS
 *   the new value will be returned to the program.
 ************************************************************************/
float Sheep::ChangeValue(float newValue)
{
	value = newValue;

	return value;
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
 *   Init : allows the code to set the values of the animals.
 *
 * POSTCONDITIONS
 *   the new value will be returned to the program.
 ************************************************************************/
void Sheep::SetName(string newName)
{
	name = newName;
}


/*************************************************************************
 * FUNCTION SetValue
 * ________________________________________________________________________
 * This function will allow the user to set the value of any animal. value
 * is private.
 *
 * returns -> value
 * ________________________________________________________________________
 * PRECONDITIONS
 *   Init : allows the code to set the values of the animals.
 *
 * POSTCONDITIONS
 *   the new value will be returned to the program.
 ************************************************************************/
void Sheep::SetValue(float newValue)
{
	value = newValue;
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
 *   Init : allows the code to set the values of the animals.
 *
 * POSTCONDITIONS
 *   the new age will be returned to the program.
 ************************************************************************/
void Sheep::SetAge(int sheepAge)
{

	age = sheepAge;
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
int Sheep::GetAge()
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
string Sheep::GetName()
{
	return name;
}


/*************************************************************************
 * FUNCTION GetValue
 * ________________________________________________________________________
 * This function simply allows the code to retrieve the value of any
 * animal.
 *
 * returns -> value
 * ________________________________________________________________________
 * PRECONDITIONS
 *   GetCommandTwo : user selection
 *
 * POSTCONDITIONS
 *   returns the value of the animal
 ************************************************************************/
float Sheep::GetValue()
{
	return value;
}

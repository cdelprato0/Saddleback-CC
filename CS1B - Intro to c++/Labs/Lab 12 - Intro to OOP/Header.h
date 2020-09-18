/*************************************************************************
 * AUTHOR     : Rhader & BBC
 * LAB #12    : Intro to OOP
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/8/2015
 ************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

//PRE PROCESSOR DIRECTIVES
#include <iomanip>
#include <iostream>
#include <string>
#include <limits>
#include <ios>

#include "ClassSheep.h"
#include "Pig.h"
using namespace std;

enum FirstRunMenu
{
	EXIT,
	INITIALIZE
};

enum MainMenu
{
	MAIN_EXIT,
	MAIN_INITIALIZE,
	AGE,
	VALUE,
	DISPLAY
};

/*************************************************************************
* PrintHeader:
* 	Simply prints the class header.
*
* RETURNS: the class header
**************************************************************************/
void PrintHeader(string codeName,   // IN - the programmer's code name
                 string asName,     // IN - the assignment name
                 string classF,     // IN - the programmer's class
                 char   asType,     // IN - the assignment type
                                    //      (LAB or ASSIGNMENT)
                 int    asNum);     // IN - the assignment number


/*************************************************************************
* GetCommand:
* 	Allows the user to make a selection to the first menu displayed.
*
* RETURNS: the users first menu selection.
**************************************************************************/
void GetCommand(int &commandF);


/*************************************************************************
* GetCommandTwo:
* 	Allows the user to make a selection to the second menu displayed.
*
* RETURNS: the users second menu selection.
**************************************************************************/
void GetCommandTwo(int &commandF);


/*************************************************************************
* SecondDisplay:
* 	Simply displays the second menu options to the users.
*
* RETURNS: <nothing>
**************************************************************************/
void SecondDisplay();


/*************************************************************************
* FirstDisplay:
* 	Simply displays the first menu options to the users.
*
* RETURNS: <nothing>
**************************************************************************/
void FirstDisplay();


/*************************************************************************
* Init:
* 	This function initializes all the animals to their default values.
*
* RETURNS: all the animal values as default values.
**************************************************************************/
void Init(Sheep &fluffy, Sheep &maa, Pig &babe);


/*************************************************************************
* Output:
* 	This function simply outputs whatever values may be attributed to the
* 	animals (age, name, value).
*
* RETURNS: all values of the animals (age, name, value).
**************************************************************************/
void Output(Sheep fluffy, Pig babe, Sheep maa);


/*************************************************************************
* ChangeAge:
* 	This function allows the user to choose an animal they wish to change
* 	the age of & make the change permanently.
*
* RETURNS: the permanent age change of the selected animal
**************************************************************************/
void ChangeAge(Sheep& fluffy, Pig& babe, Sheep& maa, int& newAge);


/*************************************************************************
* ChangeValue:
* 	This function allows the user to choose an animal they wish to change
* 	the value of & make the change permanently.
*
* RETURNS: the permanent value change of the selected animal
**************************************************************************/
void ChangeValue(Sheep& fluffy, Pig& babe, Sheep& maa, float& newValue);


#endif /* HEADER_H_ */

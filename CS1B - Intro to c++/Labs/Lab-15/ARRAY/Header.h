/*************************************************************************
 * AUTHOR     : Druox 2.0 & BBC
 * LAB #15    : Arrays & Linked Lists of Sheep
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/13/15
 ************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

//PRE PROCESSOR DIRECTIVES
#include <iomanip>
#include <iostream>
#include <string>
#include <limits>
#include <ios>

#include "SheepClass.h"
#include "Sheep.h"
using namespace std;

enum Menu
{
	EXIT,
	ADD,
	FIRST_SHEEP,
	FIND,
	SIZE,
	OUTPUT,
	CLEAR_LIST
};

void PrintHeader(string codeName,   // IN - the programmer's code name
                 string asName,     // IN - the assignment name
                 string classF,     // IN - the programmer's class
                 char   asType,     // IN - the assignment type
                                    //      (LAB or ASSIGNMENT)
                 int    asNum);      // IN - the assignment number

void DisplayMenu();

void GetCommand(int &commandF);		//PROC - command entered from user

void AddSheep(Sheep& sheepInfo, 	 //PROC - Calls the header with the sheep info
			SheepClass& sheepList);  //PROC - Calls the array header

void ListSize(SheepClass sheepList); //OUT - Helps output the amount in the array

#endif /* HEADER_H_ */

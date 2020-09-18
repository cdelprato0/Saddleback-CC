/*************************************************************************
 * AUTHOR     : Druox 2.0 & BBC
 * LAB #15    : Arrays & Linked Lists of Sheep
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/13/15
 ************************************************************************/
#include "Header.h"

/*************************************************************************
 * FUNCTION ListSize
 * ________________________________________________________________________
 * This function checks to see if the array is empty or not. It will display
 * how many sheep are in the stack
 * ________________________________________________________________________
 * PRECONDITIONS
 *   <Nothing>
 *
 * POSTCONDITIONS
 *   <Nothing>
 ************************************************************************/
void ListSize(SheepClass sheepList)
{

	//PROCESSING - If the list is empty it will output so and if the list
	//				has members it will output how many
	if(sheepList.ListSize() != 0)
	{
		cout << "There are " << sheepList.ListSize() << " sheep in the list!\n\n";
	}
	else
	{
		cout << "The list is empty!\n\n";
	}

}

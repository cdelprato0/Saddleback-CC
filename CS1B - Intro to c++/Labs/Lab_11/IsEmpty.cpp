/*************************************************************************
 * AUTHOR     : Zeta & BBC
 * LAB #11    : Creating an Ordered List
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/1/15
 ************************************************************************/
#include "Header.h"

/**************************************************************************
 * FUNCTION IsEmpty
 * ________________________________________________________________________
 * This function is designed to determine if the linked list is empty or
 * not. It will test to see if the head of the linked list is equal to NULL
 * returns nothing. -> determines whether the queue is empty or not
 * ________________________________________________________________________
 * PRECONDITIONS
 *   head : It must be previously defined
 *
 * POSTCONDITIONS
 *   This function determines if the list is empty.
 ************************************************************************/
void IsEmpty(PersonNode *head) //PROC - Head points to the top of list
							   //Pass by value into the function
{

	//PROC - IF ELSE statement outputs appropriate prompt if condition is met
	if(head == NULL)
	{
		//OUTPUT - It will output the list is empty.
		cout << "Yes, the list is empty.\n\n";
	}
	else
	{
		//OUTPUT - It will output the list is not empty.
		cout << "No, The list is NOT empty.\n\n";

	}//End of IF ELSE statement
}

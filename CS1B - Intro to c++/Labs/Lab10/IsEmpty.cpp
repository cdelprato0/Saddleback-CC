/*************************************************************************
 * AUTHOR     : Myrmidon & BBC
 * LAB #10    : Implementing a Queue
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 3/18/15
 ************************************************************************/
#include "Header.h"

/**************************************************************************
 * IsEmpty Function
 * ________________________________________________________________________
 * This function is designed to determine if the linked list is empty or
 * not. It will test to see if the head of the linked list is equal to NULL
 *   returns nothing. -> determines whether the queue is empty or not
 * ________________________________________________________________________
 * PRECONDITIONS
 *   head : the head of the queue must be previously defined
 * POSTCONDITIONS
 *   <none>
 ************************************************************************/
void IsEmpty(PersonNode *head)
{

	//PROCESSING - Head is the top of the linked list and Null is at the
	//			   bottom of the list. If head is equal to NULL then it
	//			   it will have nothing in the linked list and will output
	//			   so. Else it will output the queue is not empty.
	if(head == NULL)
	{
		cout << "Yes, the QUEUE is empty.\n\n\n";
	}
	else
	{
		cout << "The QUEUE is NOT empty.\n\n\n";
	}
}

/*************************************************************************
 * AUTHOR     : Myrmidon & BBC
 * LAB #10    : Implementing a Queue
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 3/18/15
 ************************************************************************/
#include "Header.h"

/**************************************************************************
 * Size Function
 * ________________________________________________________________________
 * This function will receive the head of the queue and determine the size
 * of the queue by counting each node
 *  returns size of the stack
 * ________________________________________________________________________
 * PRECONDITIONS
 *   head : the head of the queue must be previously defined
 * POSTCONDITIONS
 *   <none>
 ************************************************************************/
int Size(PersonNode* head)
{
	int 	   sizecheck;	 // PROC - the size of the queue
	PersonNode *perPtr;  // PROC - the pointer that indexes the nodes

	// INITIALIZE - the size of the queue to 0
	sizecheck = 0;

	// PROC - pointing to the first node on in queue
	perPtr = head;

	// PROC - if there is a node in queue, then it will count
	while(perPtr != NULL)
	{
		sizecheck++;

		// PROC - moves on to the next node that will be counted
		perPtr = perPtr->next;
	}

	return sizecheck;
}

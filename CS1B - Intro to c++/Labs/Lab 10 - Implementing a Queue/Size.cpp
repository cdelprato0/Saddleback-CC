/*************************************************************************
 * AUTHOR     : Myrmidon & BBC
 * LAB #10    : Implementing a Queue
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 3/18/15
 ************************************************************************/
#include "Header.h"

int Size(PersonNode* head)
{
	int 	   size;	 // PROC - the size of the queue
	PersonNode *perPtr;  // PROC - the pointer that indexes the nodes

	// INITIALIZE - the size of the queue to 0
	size = 0;

	// PROC - pointing to the first node on in queue
	perPtr = head;

	// PROC - if there is a node in queue, then it will count
	while(perPtr != NULL)
	{
		size++;

		// PROC - moves on to the next node that will be counted
		perPtr = perPtr->next;
	}

	return size;
}

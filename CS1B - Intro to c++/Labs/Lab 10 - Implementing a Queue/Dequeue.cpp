/*************************************************************************
 * AUTHOR     : Myrmidon & BBC
 * LAB #10    : Implementing a Queue
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 3/18/15
 ************************************************************************/
#include "Header.h"

PersonNode* Dequeue(PersonNode *head)
{
	PersonNode *perPtr;

	// Allocates memory for a new node
	perPtr = new PersonNode;

	// INITIALIZE - places the perPtr at the first node
	perPtr = head;

	if(perPtr != NULL)
	{
		// OUTPUT - the node that was popped from queue
		cout << "DEQUEUEING\n";

		cout << left;
		cout << setw(8) << "Name:"   << perPtr->name   << endl;
		cout << setw(8) << "Gender:" << perPtr->gender << endl;
		cout << setw(8) << "Age:"    << perPtr->age    << endl;
		cout << right;

		// PROC - since a node was removed from queue, the head must
		//		  be set to the next node in queue
		head = perPtr->next;

		// deallocates the node that was used to remove the node
		delete perPtr;
		perPtr = NULL; // set back to null for safety
	}
	else
	{
		// OUT - outputs if queue was initially empty
		cout << "Can't DEQUEUE from an empty stack!\n";
	}
	return head;
}

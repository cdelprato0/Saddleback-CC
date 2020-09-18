/*************************************************************************
* AUTHOR     : Myrmidon & BBC
* LAB #10    : Implementing a Queue
* CLASS      : CS1B
* SECTION    : MW 8:30am-12:20p
* DUE DATE   : 3/18/15
************************************************************************/
#include "header.h"

/**************************************************************************
 * ClearQueue Function
 * ________________________________________________________________________
 * This function will clear all the nodes that are part of the linked list
 * returns nothing. -> deletes all the nodes
 * ________________________________________________________________________
 * PRECONDITIONS
 *   head : the head of the queue must be previously defined
 ************************************************************************/
void ClearQueue(PersonNode *&head, int &size)
{

	if(head != NULL)
	{
		// OUTPUT - the node that was popped from queue
		cout << "CLEARING...\n";

		while(head!=NULL)
		{
			cout << left;
			cout << setw(8) << "Name:" << head->name << endl;

			// PROC - since a node was removed from queue, the head must
			//		  be set to the next node in queue
			head = head->next;
			size--;
		}

		cout << endl << endl;
		cout << "The queue has been CLEARED!\n\n\n";
		// deallocates the node that was used to remove the node
		delete head;
		head = NULL; // set back to null for safety
	}
	else
	{
		// OUT - outputs if queue was initially empty
		cout << "The QUEUE is ALREADY clear!\n\n\n";
	}
	size=0;
}

/*************************************************************************
 * AUTHOR     : Myrmidon & BBC
 * LAB #10    : Implementing a Queue
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 3/18/15
 ************************************************************************/
#include "Header.h"

void IsEmpty(PersonNode *head)
{
	if(head == NULL)
	{
		cout << "Yes, the QUEUE is empty.\n";
	}
	else
	{
		cout << "The QUEUE is NOT empty.\n";
	}
}

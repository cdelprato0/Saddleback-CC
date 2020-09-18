/*************************************************************************
 * AUTHOR     : Myrmidon & BBC
 * LAB #10    : Implementing a Queue
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 3/18/15
 ************************************************************************/
#include "Header.h"

void Front(PersonNode *head)
{
	PersonNode *perPtr;//PROC - Temp variable that takes the place of head

	//Initializes the temp variable to head
	perPtr = head;

	//PROC - It will check to see if the list is empty or not by
	//       checking if the temp variable is equal to NULL
	if(perPtr!=NULL)
	{
		//OUTPUT - Will output to the console with the person node that
		//         is at the top of the list
		cout << left;
		cout << "The first person in the queue is:\n";
		cout << setw(8) << "Name:"   << perPtr->name << endl;
		cout << setw(8) << "Gender:" << perPtr->gender << endl;
		cout << setw(8) << "Age:"    << perPtr->age << endl;
		cout << right;

	}
	else
	{
		//OUTPUT - If the linked list is empty, it will output as so
		cout << "Nobody in FRONT, the queue is empty!!\n";
	}
}

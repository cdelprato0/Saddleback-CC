/*************************************************************************
 * AUTHOR     : Zeta & BBC
 * LAB #11    : Creating an Ordered List
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/1/15
 ************************************************************************/
#include "Header.h"

/**************************************************************************
 *
 * FUNCTION ClearList
 * _______________________________________________________________________
 * This function will clear the entire list using a while loop and a selection
 * statement. It will return head for further use in main.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *  head : It will be previously defined.
 *
 * POST-CONDITIONS
 * 	This function will clear the entire list and returns head for further use.
 *
 *************************************************************************/
PersonNode* ClearList(PersonNode *&head) //PROC - Head points to the top of list
										 //Pass by reference IN & OUT of the function
{
	PersonNode *perPtr;     //PROC - pointer that points to the current position

	perPtr = head;          //Initialize perPtr to point head

	cout << left;

	//PROC - IF ELSE statement outputs appropriate prompt if condition is met
	if(head == NULL)
	{
		//OUTPUT - Outputs that the list is already clear.
		cout << "The list has been cleared!\n\n";
	}
	else
	{

		cout << "CLEARING LIST:\n";

		//PROC - WHILE LOOP - Clears the list
		while (head != NULL)
		{
			cout << "Removing " << head->name;
			perPtr = head;
			head = head -> next;

			perPtr -> next = NULL;
			cout << endl;

			//PROC - Deletes perPtr
			delete perPtr;
			perPtr = NULL;
		}

		//OUTPUT - Outputs that list has been cleared
		cout << endl << "The list has been cleared!\n\n";
	}

	return head;
}

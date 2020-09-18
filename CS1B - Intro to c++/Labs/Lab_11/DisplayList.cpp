/*************************************************************************
 * AUTHOR     : Zeta & BBC
 * LAB #11    : Creating an Ordered List
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/1/15
 ************************************************************************/
#include "Header.h"

/*******************************************************************
 *
 * FUNCTION DisplayList
 *_________________________________________________________________
 * This function outputs the entire list using a While Loop.
 *_________________________________________________________________
 * PRE-CONDITIONS
 *  head : It will be previously defined.
 *
 * POST-CONDITIONS
 *  This function Outputs the entire list.
 *******************************************************************/
void DisplayList(PersonNode *head)//PROC - Head points to the top of list
								  //Pass by value into the function
{

	PersonNode* perPtr;  //PROC - perPtr pointer variable.
	int instances;       //PROC - instances counter

	instances = 0;       //Initialize instancfes to zero
	perPtr = head;       //Initialize perPTR to point head

	//PROC - IF ELSE statement outputs appropriate prompt if condition is met
	if(head == NULL)
	{
		//OUTPUT - user's prompt indicating that the list is empty
		cout << "Can\'t display an empty list.\n\n";
	}
	else
	{
		//OUTPUT - Upper part of the output list
		cout << setw(4) << "#" << "    "
			 << left << setw(28) << "NAME" << "GENDER   AGE" << endl;
		cout << right << setfill('-') << setw(8) << ' '
			 << setw(27) << "  " << setw(9) << ' ' << setw(6) << ' '
			 << setfill(' ') << endl;

		//PROC - WHILE LOOP runs until perPtr point to NULL
		while(perPtr != NULL)
		{
			//OUTPUT - Outputs the information stored in the node
			instances = instances + 1;
			cout << right;
			cout << setw(4) << instances << "    ";
			cout << left << setw(30) << perPtr-> name
				 << setw(7) << perPtr-> gender << perPtr->age << endl;

			//PROC - moves to the next node
			perPtr= perPtr-> next;

		}//END of WHILE loop

		cout << endl;
	}//END of IF ELSE statement

}

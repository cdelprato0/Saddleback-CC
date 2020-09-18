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
 * FUNCTION SearchName
 *_________________________________________________________________
 * This function searches for a name in the linked list using a while
 * loop and a selection statement. If it finds the name it will output
 * the name, age and gender of the node found.
 *_________________________________________________________________
 * PRE-CONDITIONS
 *  head : It will be previously defined.
 *
 * POST-CONDITIONS
 *  This function Outputs the information of the node if it was found
 *  or a prompt message indicating that the person was not found.
 *******************************************************************/

void SearchName(PersonNode* head)//PROC - Head points to the top of list
								 //Pass by value into the function
{
	PersonNode *currentNode; //PROC     - pointer that points to the current position
	string nameKey;          //IN & OUT - Name to search for
	bool found;              //PROC     - Boolean variable

	found = false;			 //Initialize found to the false state
	currentNode = head;		 //Initialize currentNode to point head

	if(head == NULL)
	{
		cout << "Can\'t search from an empty list!\n\n";
	}
	else
	{
		//OUTPUT - prompt the user for a name to search
		cout << "Who would you like to search for? ";
		getline(cin, nameKey);
		cout << endl;

		cout << "Searching for " << nameKey << "...\n";

		//PROC - WHILE LOOP runs until a name is found
		while(!found && currentNode != NULL)
		{
			if(currentNode-> name == nameKey)
			{
				found = true;
			}
			else
			{
				currentNode = currentNode-> next;
			}
		}//End of WHILE LOOP

		//PROC - IF ELSE statement outputs appropriate prompt if condition is met
		if(currentNode != NULL)
		{
			//OUTPUT - Outputs the information stored in the node found
			cout << endl     << left
				 << setw(10) << "Name:"   << currentNode->name   << endl
				 << setw(10) << "Gender:" << currentNode->gender << endl
				 << setw(10) << "Age:"    << currentNode->age    << endl;
			cout << right;
		}
		else
		{
			//OUTPUT - User's prompt indicating that the name was not found
			cout << "I\'m sorry, \"" << nameKey << "\" was NOT found!\n\n";
		}//END of IF ELSE statement
	}

}

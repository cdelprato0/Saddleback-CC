/*************************************************************************
 * AUTHOR     : Zeta & BBC
 * LAB #11    : Creating an Ordered List
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/1/15
 ************************************************************************/
#include "Header.h"

/************************************************************************
*
* 				 SEARCHING CREATING AN ORDERED LIST
*________________________________________________________________________
* This program will implement a linked-list which it will be created in
* alphabetical order. The program will present options to the user such as
*
* CREATELIST : 1 - Creates the list in alphabetical order.
* DISPLAYLIST: 2 - Displays the entire list.
* ISEMPTY    : 3 - Checks to see of the list is empty.
* SEARCHNAME : 4 - Allow the user to search for a name in the list.
* REMOVENODE : 5 - Allow the user to remove a node form the list.
* CLEARLIST  : 6 - Deletes all nodes in the linked list.
* EXIT:      : 0 - Exists the program.
*
* All of the options will be executed using well-defined functions to
* implement each tasks.
*_______________________________________________________________________
* INPUTS:
* command    : User's menu selection.
* nameKey    : The name to search in the list.
*
* OUTPUTS:
* name       : Person's name read from a file.
* gender     : Person's gender read from a file.
* age        : Person's age read from a file.
*
***********************************************************************/

int main()
{

	//VARIABLES
	PersonNode *head; //PROC      - Head points to the top of the list
	PersonNode *tail; //PROC      - Tail points to the bottom of the list
	int command;      //IN & PROC - User's input command

	head = NULL;      //Initialize head to NULL
	tail = NULL;      //Initialize tail to NULL

	//PrintHeader - This function will print the header to the console
	PrintHeader("BBC & Zeta", "Creating an Ordered List", "CS1B", 'L', 11);

	//DisplayMenu - This function Outputs the menu list
	DisplayMenu();

	//GetCommand - This function will error check for a valid entry
	GetCommand(command);

	//PROC - WHILE LOOP runs until zero is entered
	while(command != EXIT)
	{
		//PROC - SWITCH statement matches the command with its predefined procedure
		switch(command)
		{
		//PROC - CREATELIST
		case CREATELIST: //CreateList - this function creates the list
						 CreateList(head, tail);
						 break;

		//PROC - DISPLAYLIST
		case DISPLAYLIST://DisplayList - This function Outputs the entire list.
						 DisplayList(head);
						 break;

		//PROC - ISEMPTY
		case ISEMPTY  :  //IsEmpty - This function determines if the list is empty.
						 IsEmpty(head);
						 break;

		//PROC - SEARCHNAME
		case SEARCHNAME: //SearchName - This function searches for a name in the linked list
						 SearchName(head);
				 		 break;

		//PROC - REMOVENODE
		case REMOVENODE: //RemovingNode - This function removes a node from the list
						 RemovingNode(head, tail);
					     break;

		//PROC - CREATELIST
		case CLEARLIST:  //ClearList - This function will clear the entire list
					     ClearList(head);
						 break;

		}//END of SWITCH statement

		//DisplayMenu - This function Outputs the menu list
		DisplayMenu();

		//GetCommand - This function will error check for a valid entry
		GetCommand(command);

	}//END of WHILE LOOP

	return 0;
}




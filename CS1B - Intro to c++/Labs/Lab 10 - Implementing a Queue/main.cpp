/*************************************************************************
 * AUTHOR     : Myrmidon & BBC
 * LAB #10    : Implementing a Queue
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 3/18/15
 ************************************************************************/
#include "Header.h"

int main()
{

	PersonNode *head;		// PROC - top of the linked list
	int        command;	    // IN   - user's input to access menu options
	int 	   size;		// PROC - size of the list


	PrintHeader("BBC & ", "Implementing a Queue", "CS1B", 'L', 10);

	DisplayMenu();

	GetCommand(command);

	while(command != EXIT)
	{

		// PROC - depending on the user's command, the respective functions
		//		  will execute
		switch(command)
		{
						/*************************************************
						 * Push - function allows the user to enter in a
						 * 		  name, gender, and age into a node
						 ************************************************/
			case ENQUEUE  : head = Enqueue(head);
					   	   break;


						/*************************************************
						 *
						 ************************************************/
			case DEQUEUE  : head = Dequeue(head);
					       break;


						  /*************************************************
						   * IsEmpty - function checks if the list is
						   * 			empty by checking if the head ==
						   * 			NULL
						   ************************************************/
			case ISEMPTY  : IsEmpty(head);
						   break;

						  /*************************************************
						   * Peek - function will show the user who is at
						   * 		the top of the stack
					       ************************************************/
			case FRONT    : Front(head);
						   break;


					    /*************************************************
					     * Size - function will tell the user how many
					     * 		  people are on the list
					     ************************************************/
			case SIZE    : size = Size(head);


						   // OUT - will properly display the amount of
						   //       people on the stack
						   if(size > 1)
						   {
							   cout << "There are " << size <<
									   " people on the queue.\n";
						   }
						   else if (size == 1)
						   {
							   cout << "There is one person "
									   "on the queue.\n";
						   }
						   else if (size == 0)
						   {
							   cout << "Nobody is on the queue!\n";
						   }

					       break;

						 /*************************************************
						  *
						  ************************************************/
//			case CLEARQUEUE   : ClearQueue(head);
//					       break;
		}

		/*****************************************************************
		 * DisplayMenu - function displays the menu for the user to use
		 ****************************************************************/
		DisplayMenu();

		/*****************************************************************
		 * GetCommand - function obtains user input and error checks that
		 * 				their command is within bounds (0 - 6)
		 ****************************************************************/
		GetCommand(command);
	}
	return 0;
}

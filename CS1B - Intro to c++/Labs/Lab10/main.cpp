/*************************************************************************
 * AUTHOR     : Myrmidon & BBC
 * LAB #10    : Implementing a Queue
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 3/18/15
 ************************************************************************/
#include "Header.h"

/***********************************************************************
 * Implementing a Queue
 * _______________________________________________________________________
 * This function emulates a Queue. It will prompt the user with a menu and
 * each number has its own function. The user will gradually create a Queue
 * by the enqueue function, the user can also remove from the Queue using the
 * dequeue function, the user will also be able to determine if the Queue is
 * empty or not using the IsEmpty function, the user can check and see who
 * is at the front of the Queue by using the Front function, and check the
 * size of the stack by using the Size function. The user will exit the
 * program by entering 0.
 * _______________________________________________________________________
 * INPUT:
 *   command : the command the user enters to access the menu
 *
 * OUTPUT:
 *   size : the size of the stack
 ************************************************************************/
int main()
{

	PersonNode *head;		// PROC - top of the linked list
	PersonNode *tail;		// PROC - end of the linked list
	int        command;	    // IN   - user's input to access menu options
	int 	   size;		// OUT - size of the list

	// INTIALIZATIONS
	tail = NULL;
	size = 0;

	// PrintHeader - prints class header to the console
	PrintHeader("BBC & Myrmidon", "Implementing a Queue", "CS1B", 'L', 10);

	/*********************************************************************
	 * DisplayMenu - function displays the menu for the user to use
	 ********************************************************************/
	DisplayMenu();

	/*********************************************************************
	 * GetCommand - function obtains user input and error checks that their
	 * 				command is within bounds (0 - 6)
	 ********************************************************************/
	GetCommand(command);

	while(command != EXIT)
	{

		// PROC - depending on the user's command, the respective functions
		//		  will execute
		switch(command)
		{

						/*************************************************
						 * Enqueue - function allows the user to enter in a
						 * 		  name, gender, and age into a node
						 ************************************************/
			case ENQUEUE  : head = Enqueue(head, tail, size);
					   	   break;


							/*************************************************
							 * Dequeue - function will deallocate the node that
							 *       was at the front of the queue
							 ************************************************/
			case DEQUEUE  : head = Dequeue(head, size);
					       break;


						  /*************************************************
						   * IsEmpty - function checks if the list is
						   * 			empty by checking if the head ==
						   * 			NULL
						   ************************************************/
			case ISEMPTY  : IsEmpty(head);
						   break;

						  /*************************************************
						   * Front - function will show the user who is at
						   * 		the front of the queue
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
									   " people on the queue.\n\n\n";
						   }
						   else if (size == 1)
						   {
							   cout << "There is one person "
									   "on the queue.\n\n\n";
						   }
						   else if (size == 0)
						   {
							   cout << "Nobody is on the queue!\n\n\n";
						   }

					       break;

						 /*************************************************
						  * ClearQueue - Will clear all the nodes of the
						  * 			linked list
						  ************************************************/
		case CLEARQUEUE   : ClearQueue(head, size);
					       break;
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

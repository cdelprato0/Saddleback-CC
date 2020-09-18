/*************************************************************************
 * AUTHOR     : & BBC
 * LAB #10    : Implementing a Queue
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 3/11/15
 ************************************************************************/
#include "Header.h"

/**************************************************************************
 * DisplayMenu Function
 * ________________________________________________________________________
 * This function is only used to display the menu for the user to see for
 * reference
 * ________________________________________________________________________
 *************************************************************************/
void DisplayMenu()
{
	cout << "STACK MENU:\n"
		 << "1 - ENQUEUE (Add a person)\n"
		 << "2 - DEQUEUE (Remove a person)\n"
		 << "3 - ISEMPTY (Is the queue empty?)\n"
		 << "4 - FRONT   (Who is in front?)\n"
		 << "5 - SIZE    (How many people are there?)\n"
		 << "6 - Clear the Queue\n"
		 << "0 - Exit\n";
}

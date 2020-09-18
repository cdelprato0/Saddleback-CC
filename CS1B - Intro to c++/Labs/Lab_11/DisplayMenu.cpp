/*************************************************************************
 * AUTHOR     : Zeta & BBC
 * LAB #11    : Creating an Ordered List
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/1/15
 ************************************************************************/
#include"Header.h"

/*******************************************************************
 *
 * FUNCTION DisplayMenu
 *_________________________________________________________________
 * This function outputs the menu list allowing the user to make a
 * selection.
 *_________________________________________________________________
 * PRE-CONDITIONS
 *  None
 *
 * POST-CONDITIONS
 *  This function Outputs the menu list
 *******************************************************************/
void DisplayMenu()
{
	cout << "\nLIST MENU:\n"
		 << "1 - Create List\n"
		 << "2 - Display List\n"
		 << "3 - Is the stack empty?\n"
		 << "4 - Search by Name\n"
		 << "5 - Remove Node\n"
		 << "6 - Clear List\n"
		 << "0 - to Exit\n";
}

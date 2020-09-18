/*************************************************************************
 * AUTHOR     : Druox 2.0 & BBC
 * LAB #15    : Arrays & Linked Lists of Sheep
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/13/15
 ************************************************************************/
#include "Header.h"

/*************************************************************************
 * FUNCTION DisplayMenu
 * ________________________________________________________________________
 * This function outputs to the console a display menu that shows the user
 * the option this program provides
 * ________________________________________________________________________
 * PRECONDITIONS
 *   <Nothing>
 *
 * POSTCONDITIONS
 *   <Nothing>
 ************************************************************************/
void DisplayMenu()
{
	//OUTPUT - Outputs to the console the display menu
	cout << "SHEEP LIST MANAGER\n"
		 << "1 - Add Sheep\n"
		 << "2 - Output 1st Sheep\n"
		 << "3 - Find Sheep\n"
		 << "4 - List Size\n"
		 << "5 - Output List\n"
		 << "6 - Clear List\n"
		 << "0 - Exit\n";
}

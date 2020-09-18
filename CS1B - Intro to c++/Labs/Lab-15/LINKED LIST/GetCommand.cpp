/*************************************************************************
 * AUTHOR     : Druox 2.0 & BBC
 * LAB #15    : Arrays & Linked Lists of Sheep
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/13/15
 ************************************************************************/
#include "Header.h"

/**************************************************************************
 * FUNCTION GetCommand
 * ________________________________________________________________________
 * This function will receive the user input and error check if their
 * entry is valid. If not, the user will be prompted to enter a valid
 * response.
 * returns -> valid response
 * ________________________________________________________________________
 * PRECONDITIONS
 *   commandF : the command entered by the user must be previously defined
 *
 * POSTCONDITIONS
 *   commandF : the command entered by the user will be returned to the
 *   			calling function
 ************************************************************************/
void GetCommand(int &commandF) //OUT - the command entered by user
                               //Pass by reference In & OUT of function
{
	bool invalid;	// PROC - the invalid condition for error checking
					//		  user input

	//PROC - DO WHILE LOOP use for error checking
	do
	{

		invalid = false;  //Initialize invalid to the false state

		cout << "Enter a command: ";

		// PROC - will check if the user entered a character for a variable
		//		  that must only receive a number.
		if(!(cin >> commandF))
		{
			cout << "\n**** Please input a number "
			    	"between 0 and 6 ****\n\n";

			// PROC - clears the fail state so program does not crash
			cin.clear();

			// PROC - clears all characters from the input buffer
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			invalid = true;
		}
		else if (commandF < 0 || commandF > 6)
		{
			// OUTPUT - if the command is out of bounds, the user will be
			//		 re-prompted
			cout << left;
			cout << "\n**** The number " << commandF << setw(25)
				 << " is an invalid entry" << "****"
			     << "\n**** Please input a number "
			    	"between 0 and 6 ****\n\n";
			cout << right;
			invalid = true;

		}

		// PROC - if the user enters a valid response, the input buffer
		//		  must be cleared
		if(!invalid)
		{
			cin.ignore(100,'\n');
		}

	}while(invalid);//END of DO WHILE LOOP

	cout << endl;
}

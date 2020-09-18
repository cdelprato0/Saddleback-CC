/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #1:Random Number Generator
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#include "Header.h"

/**************************************************************************
 * GetCommand Function
 * ________________________________________________________________________
 * This function will receive the user input and error check if their
 * entry is valid. If not, the user will be prompted to enter a valid
 * response.
 * returns -> valid response
 * ________________________________________________________________________
 * PRECONDITIONS
 *   commandF : the command entered by the user must be previously defined
 * POSTCONDITIONS
 *   commandF : the command entered by the user will be returned to the
 *   			calling function
 ************************************************************************/
void GetCommand(int &commandF)
{
	bool invalid;	// PROC - the invalid condition for error checking
					//		  user input
	do
	{
		// INITIALIZE - the invalid condition to false
		invalid = false;

		//Prompts the User the Menu to choose from
		cout << "\nPlease choose from the following menu:\n"
				"1 - SUM of the random digits.\n"
				"2 - TRIPLE the random digits.\n"
				"3 - REVERSE the random digits.\n"
				"4 - STORE and SORT random numbers into an output FILE.\n"
				"5 - READ IN from an input file and PRINT to console.\n"
				"0 - EXIT the program.\n"
				"Enter your command: ";

		// PROC - will check if the user entered a character for a variable
		//		  that must only receive a number.
		if(!(cin >> commandF))
		{
			cout << "\n**** Please input a number "
			    	"between 0 and 5 ****\n\n";

			// PROC - clears the fail state so program does not crash
			cin.clear();

			// PROC - clears all characters from the input buffer
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			invalid = true;
		}//END IF

		else if (commandF < 0 || commandF > 5)
		{
			// OUT - if the command is out of bounds, the user will be
			//		 re-prompted
			cout << left;
			cout << "\n**** The number " << commandF << setw(25)
				 << " is an invalid entry" << "****"
			     << "\n**** Please input a number "
			    	"between 0 and 5 ****\n\n";
			cout << right;

			invalid = true;
		}//END ELSE IF

		// PROC - if the user enters a valid response, the input buffer
		//		  must be cleared
		if(!invalid)
		{
			cin.ignore(100,'\n');
		}//END IF

	}while(invalid);//END OF DO-WHILE

	cout << endl;

}

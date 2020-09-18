/*************************************************************************
 * AUTHOR     : Rhader & BBC
 * LAB #12    : Intro to OOP
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/8/2015
 ************************************************************************/
#include "Header.h"

/*************************************************************************
 * FUNCTION ChangeAge
 * ________________________________________________________________________
 *  This function definition allows the user to change the age of any of
 *  the animals. It also error checks the users selection in regards to
 *  which animal the user wishes to change the age of.
 * returns -> newAge
 * ________________________________________________________________________
 * PRECONDITIONS
 *   userCommand : The command entered by the user
 *
 * POSTCONDITIONS
 *   the command entered by the user will make a change to the animals
 *   value
 *************************************************************************/
void ChangeAge(Sheep& fluffy, Pig& babe, Sheep& maa, int& newAge)
{
	int userCommand;//INPUT - Stores the users choice.
	bool invalid;	// PROC - the invalid condition for error checking
					//		  user input

	//PROC - DO WHILE LOOP use for error checking
	do
	{
		invalid = false;  //Initialize invalid to the false state

		cout << "CHANGE AGE:\n" << "1 - Fluffy\n" << "2 - Maa\n" << "3 - Babe\n"
			 << "Select the animal you\'d like to change: ";

		// PROC - will check if the user entered a character for a variable
		//		  that must only receive a number.
		if(!(cin >> userCommand))
		{
			cout << "\n**** Please input a number "
					"between 1 and 3  ****\n\n";

			// PROC - clears the fail state so program does not crash
			cin.clear();

			// PROC - clears all characters from the input buffer
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			invalid = true;
		}
		else if (userCommand < 1 || userCommand > 3)
		{
			// OUTPUT - if the command is out of bounds, the user will be
			//		 re-prompted
			cout << left;
			cout << "\n**** The number " << userCommand << setw(25)
				 << " is an invalid entry" << "****"
				 << "\n**** Please input a number "
					"between 1 and 3 ****\n\n";
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


	do
	{

		invalid = false;  //Initialize invalid to the false state

		cout << "\nNEW AGE: ";

		// PROC - will check if the user entered a character for a variable
		//		  that must only receive a number.
		if(!(cin >> newAge))
		{
			cout << "\n**** Please input a number "
					"between 0 and 10 ****\n";

			// PROC - clears the fail state so program does not crash
			cin.clear();

			// PROC - clears all characters from the input buffer
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			invalid = true;
		}
		else if (newAge < 0 || newAge > 10)
		{
			// OUTPUT - if the command is out of bounds, the user will be
			//		 re-prompted
			cout << left;
			cout << "\n**** The number " << newAge << setw(25)
				 << " is an invalid entry" << "****"
				 << "\n**** Please input a number "
					"between 0 and 10 ****\n";
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


	//Changing the correct animal name according to the user selection
	if(userCommand == 1)
	{
		//OUTPUT - outputs to the console the name of the animal that is
		//			being changed
		cout << "\nChanging Fluffy\'s age to " << newAge << " ...";
		fluffy.ChangeAge(newAge);

	}
	else if(userCommand == 2)
	{
		//OUTPUT - outputs to the console the name of the animal that is
		//			being changed
		cout << "\nChanging Maa\'s age to " << newAge << " ...";
		maa.ChangeAge(newAge);
	}
	else
	{
		//OUTPUT - outputs to the console the name of the animal that is
		//			being changed
		cout << "\nChanging Babe\'s age to " << newAge << " ...";
		babe.ChangeAge(newAge);
	}

}

/*************************************************************************
 * AUTHOR     : Druox 2.0 & BBC
 * LAB #15    : Arrays & Linked Lists of Sheep
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/13/15
 ************************************************************************/
#include "Header.h"

/*************************************************************************
 * FUNCTION AddSheep
 * ________________________________________________________________________
 * This function is designed to add an instance of a sheep a linked list.
 * Loads to the tail of the list. The function will prompt the user to enter
 * the sheep's name and age and will error check the age to make sure it is
 * within bounds. It will add the name and age to the head or the tail if
 * there is more than two
 * ________________________________________________________________________
 * PRECONDITIONS
 *   GetCommand : user selection
 *
 * POSTCONDITIONS
 *   <Nothing>
 ************************************************************************/
void AddSheep(Sheep& sheepNameAge, SheepLinkedList& sheepList)
{
	string sheepName;     //IN - Users input for the sheep's name
	int    sheepAge;	  //IN - Users input for the sheep's age
	bool   invalid;	      //PROC - the invalid condition for error checking
					      //		user input

	//INPUT - The users is prompted to enter the sheep's name that they
	//			would like to add
	cout << "Sheep Name: ";
	getline(cin, sheepName);

	//PROC - DO WHILE LOOP use for error checking
	do
	{

		invalid = false;  //Initialize invalid to the false state

		cout << "Sheep Age:  ";

		// PROC - will check if the user entered a character for a variable
		//		  that must only receive a number.
		if(!(cin >> sheepAge))
		{
			cout << "\n**** Please input a number "
					"between 0 and 9 ****\n\n";

			// PROC - clears the fail state so program does not crash
			cin.clear();

			// PROC - clears all characters from the input buffer
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			invalid = true;
		}
		else if (sheepAge < 0 || sheepAge > 9)
		{
			// OUTPUT - if the command is out of bounds, the user will be
			//		 re-prompted
			cout << left;
			cout << "\n**** The number " << sheepAge << setw(25)
				 << " is an invalid entry" << "****"
				 << "\n**** Please input a number "
					"between 0 and 9 ****\n\n";
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

	//PROCESSING -  Sets the name and the age of the sheep using the methods
	//				declared in the Sheep header
	sheepNameAge.SetName(sheepName);
	sheepNameAge.SetAge(sheepAge);

	//PROCESSING - Adds the new information about the sheep into the linked list
	sheepList.AddSheep(sheepNameAge);

	cout << endl;

	//OUTPUTS - Outputs to the console the name and age of the sheep that is being added
	cout << "The sheep..\n"
		 << "Sheep Name: " << sheepNameAge.GetName() << endl
		 << "Sheep Age:  " << sheepNameAge.GetAge()  << endl
		 << "Has been added!\n\n";
}

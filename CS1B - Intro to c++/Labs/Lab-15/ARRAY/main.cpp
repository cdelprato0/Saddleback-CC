/*************************************************************************
 * AUTHOR     : Druox 2.0 & BBC
 * LAB #15    : Arrays & Linked Lists of Sheep
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/13/15
 ************************************************************************/
#include "Header.h"

/*************************************************************************
 * Sheep List Manager
 * ________________________________________________________________________
 * This program will be able to have a database of sheep that holds their
 * name and age. The sheep list manager will be able to add a sheep, output
 * the first sheep that was entered, it can find one instance of a sheep by
 * name, it can tell you how many sheep are in the list, it will output the
 * list of sheep to a table format, and it can clear all the current sheep
 * out of the list. If the list is already empty it will state so in the
 * console.
 * ________________________________________________________________________
 *
 ************************************************************************/
int main()
{
	SheepClass sheepList; //Access to the array
	Sheep sheepInfo;	  //Access to the sheeps name and age
	string searchName;	  //The name that is being searched
	int command;		  //The command the user enters

	//Simply prints the class header.
	PrintHeader("BBC & Druox 2.0" , "Arrays & Linked Lists of Sheep", "CS1B", 'L', 15);

	//OUTPUT - Outputs the program header
	cout << "*************************************\n"
		 << "* WELCOME TO THE SHEEP LIST MANAGER *\n"
		 << "*************************************\n\n\n";

	//DisplayMenu - Displays the menu that the user can choose from
	DisplayMenu();

	//GetCommand - Get the command from the user and error checks it
	GetCommand(command);

	//PROCESSING - Takes in the user input and determines which function
	//				they are attempting to call
	while(command != EXIT)
	{
		switch(command)
		{

		//AddSheep - Adds the sheep information into an array
		case ADD 		: AddSheep(sheepInfo, sheepList);
				break;

		//OutputFirst - Outputs the first sheep in the array
		case FIRST_SHEEP: sheepInfo = sheepList.OutputFirst();

						  //PROC - Checks to see if the list is empty
						  if(sheepList.ListSize() == 0)
						  {
							  cout << "Nobody is in front - the list is empty!\n\n";
						  }
						  //PROC - IF not it will output their name and age
						  else
						  {
							  cout << left
								   << setw(15) << "NAME" << "AGE" << endl
							  	   << "-------------- ---"        << endl;
							cout << setw(16) << sheepInfo.GetName()
								 << sheepInfo.GetAge() << endl << endl;
							cout << "Is at the front of the list.\n\n";
						  }
				break;

		//Find - Searches the array for a sheep name
		case FIND		: if(sheepList.ListSize() != 0)
						  {
							cout << "Who are you looking for? ";
							getline(cin, searchName);
						  }
						//PROC - Searches through the array for the given name
						  sheepList.FindSheepName(searchName);
				break;

		//ListSize - Outputs the size of the array and if it is empty
		case SIZE		: ListSize(sheepList);
				break;

		//Output - Outputs the list of the sheep with their name and age
		case OUTPUT		: sheepList.OutputList();
				break;

		//ClearList - Clears the entire array
		case CLEAR_LIST : sheepList.ClearList();
				break;
		}

		//DisplayMenu - Displays the menu that the user can choose from
		DisplayMenu();

		//GetCommand - Get the command from the user and error checks it
		GetCommand(command);
	}

	return 0;
}

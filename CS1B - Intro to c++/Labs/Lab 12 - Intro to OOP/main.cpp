/*************************************************************************
 * AUTHOR     : Rhader & BBC
 * LAB #12    : Intro to OOP
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/8/2015
 ************************************************************************/
#include "Header.h"
#include "ClassSheep.h"
#include "Pig.h"

/**************************************************************************
 * Intro to OOP
 * ________________________________________________________________________
 * This program is designed to keep track of an animals name, age, and its
 * value using object oriented programming (OOP). This program uses two
 * classes, one for the sheep and one for the pig, in each having their own
 * public and private data.The program will prompt a menu for the user to
 * keep as a reference when choosing a specific task. The users have the
 * option to initialize the animals , change their age and/or value, and a
 * display that shows all the current info. If the user enter a wrong
 * command, age, or value the program will prompt the user to change their
 * response.
 * ________________________________________________________________________
 *
 ************************************************************************/
int main()
{
	Sheep fluffy;	//OBJECT 	   - of class sheep. Used to hold values of
					//			     the class.
	Sheep maa;		//OBJECT 	   - of class sheep. Used to hold values of
					//			     the class.
	Pig babe;		//OBJECT 	   - of class sheep. Used to hold values of
					//			     the class.
	int command;	//INPUT & CALC - used as an LCV to control the main
					//				 while loop.
	int newAge;		//INPUT & CALC - used to change the private data age
	string newName;	//INPUT & CALC - used to change the private data value
	float newValue; //INPUT & CALC - used to change the private data value
	int commandTwo; //INPUT & CALC - used as an LCV to control the main
					//				 while loop.
	char reInt;		//CALC		   - used to re-initialize all values for
					//				 the animals.
	bool invalid;	//CALC		   - used to control varies do-while loops.

	//Function call to set default values to all the animals.
	Init(fluffy, maa, babe);

	//Simply prints the class header.
	PrintHeader("BBC & RHADER" , "Intro to OOP", "CS1B", 'L', 12);

	//Displays the fist menu options
	FirstDisplay();
	//Retrieves the user choice from the first command options
	GetCommand(command);

	//Main while loop
	while(command != EXIT)
	{
		switch(command)
		{
		case INITIALIZE: Init(fluffy, maa, babe);
							cout << "Initializing Fluffy, Maa, & Babe...";

							//Displays the second menu options
							SecondDisplay();
							//Retrieves the user choice from the second command options
							GetCommandTwo(commandTwo);

							//Nested while loop
							while(commandTwo != MAIN_EXIT)
							{
								switch(commandTwo)
								{
								case MAIN_INITIALIZE:

								do
								{
									invalid = false;
									cout << "Are you sure you want to reinitialize (Y/N)? ";
											cin.get(reInt);
											reInt = toupper(reInt);
											cin.ignore(1000, '\n');

											if(reInt != 'N' && reInt != 'Y')
											{
												cout << "**** " << reInt << " is an invalid entry ****\n"
													 << "**** Please input Y or N   ****\n\n";
												invalid = true;
											}

								}while(reInt != 'N' && reInt != 'Y' && invalid);

								//If the user wants to re-initialize the
								//values of the animals.
								if(reInt == 'Y')
								{
									Init(fluffy, maa, babe);
									cout << "Initializing Fluffy, Maa, & Babe...\n";
								}
								else
								{
									cout << "Animals have not been re-initialized!\n";
								}

								break;
								case AGE : ChangeAge(fluffy, babe, maa, newAge);
								break;
								case VALUE: ChangeValue(fluffy, babe, maa, newValue);
								break;
								case DISPLAY: Output(fluffy, babe, maa);
								break;

								}
								//Displays the second menu options
								SecondDisplay();
								//Changing the LCV for the nested while loop
								GetCommandTwo(commandTwo);

							}//END OF NESTED WHILE LOOP

							if(commandTwo == MAIN_EXIT)
							{
								//If the user wants to exit from the second
								//menu choice, just exit the entire program
								command = EXIT;
							}
							else
							{
								//Displays the fist menu options
								FirstDisplay();
								//Changing the LCV for the main while loop
								GetCommand(command);
							}
		break;

		}//END OF MAIN WHILE LOOP
	}
	return 0;
}

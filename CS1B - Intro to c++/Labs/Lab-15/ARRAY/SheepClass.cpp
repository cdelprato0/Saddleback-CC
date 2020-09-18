/*************************************************************************
 * AUTHOR     : Druox 2.0 & BBC
 * LAB #15    : Arrays & Linked Lists of Sheep
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/13/15
 ************************************************************************/
#include "Header.h"

//Class Constructor
SheepClass::SheepClass()
{
	sheepCount = 0;
}

//Class Destructor
SheepClass::~SheepClass()
{

}

/*************************************************************************
 * FUNCTION AddSheep
 * ________________________________________________________________________
 * This function is designed to add an instance of a sheep into an array.
 * Loads to the end of the array.
 * ________________________________________________________________________
 * PRECONDITIONS
 *   GetCommand : user selection
 *
 * POSTCONDITIONS
 *   <Nothing
 ************************************************************************/
void SheepClass::AddSheep(Sheep newSheep)
{
	//PROCESSING - Loads the content of newSheep into a spot on the array
	if(sheepCount < AR_SIZE)
	{
		sheepArray[sheepCount] = newSheep;
		sheepCount ++;
	}
	else
	{
		//OUTPUTS - Outputs if the array is full
		cout << "Error : Array is full!!\n\n";
	}

}

/*************************************************************************
 * FUNCTION ListSize
 * ________________________________________________________________________
 * This function returns the number of sheep in the array.
 *
 * returns -> sheepCount
 * ________________________________________________________________________
 * PRECONDITIONS
 *   GetCommand : user selection
 *
 * POSTCONDITIONS
 *   returns the number of sheep
 ************************************************************************/
int SheepClass::ListSize()const
{

	return sheepCount;
}

/*************************************************************************
 * FUNCTION OutputList
 * ________________________________________________________________________
 * This function outputs to the console a table that has the name and ages
 * of all the sheep. It will determine if the array is empty. It will also
 * display how many sheep are in the array.
 * ________________________________________________________________________
 * PRECONDITIONS
 *   GetCommand : user selection
 *
 * POSTCONDITIONS
 *   <Nothing>
 ************************************************************************/
void SheepClass::OutputList()const
{
	int index;		//CALC - Used to determine the instance the array is looking at

	//Initializing index to zero
	index = 0;

	//PROCESSING - If the array is not empty it will output a table to the
	//				console that has the sheeps' name and age and will tell
	//				you how many sheep are in the array
	if(sheepCount != 0)
	{
		cout << left
			 << setw(15) << "NAME" << "AGE" << endl
			 << "-------------- ---"        << endl;
		while(sheepArray[index].GetAge() != 0 && index < AR_SIZE)
		{
			if(sheepArray[index].GetAge() != -1)
			{
				cout << setw(16) << sheepArray[index].GetName()
					 << sheepArray[index].GetAge() << endl;
			}

			index = index + 1;
		}
		cout << "\nThere are " << sheepCount << " sheep in the list!\n";
	}

	//PROCESSING - If the array is empty it will output so
	else
	{
		cout << "The list is empty!\n";
	}
	cout << endl;
}

/*************************************************************************
 * FUNCTION OutputFirst
 * ________________________________________________________________________
 * This function returns the values that are stored in the first index of
 * the array
 *
 * returns -> sheepArray[0] - the first index
 * ________________________________________________________________________
 * PRECONDITIONS
 *   GetCommand : user selection
 *
 * POSTCONDITIONS
 *   returns the first index of an array
 ************************************************************************/
Sheep SheepClass::OutputFirst()const
{
	return sheepArray[0];
}

/*************************************************************************
 * FUNCTION FindSheepName
 * ________________________________________________________________________
 * This function will be able to search an array for one instance of a
 * sheeps name. It will output whether if it was found or not and if found
 * it will out put a table that has the sheeps name in it
 * ________________________________________________________________________
 * PRECONDITIONS
 *   GetCommand : user selection
 *
 * POSTCONDITIONS
 *   <nothing>
 ************************************************************************/
void SheepClass::FindSheepName(string sheepName)const
{
	int index;  //CALC - Used to determine the instance the array is looking at
	bool found;	//CALC - Used to determine if something is found or not

	//Initializing found to false and index to zero
	found = false;
	index = 0;

	//PROCESSING - If the array is empty it will output so
	if(sheepCount == 0)
	{
		cout << "There are no sheep to be found!\n\n";
	}

	//PROCESSING - This code will search through a whole array to find one
	//				instance of a certain named sheep. Once it is found it
	//				will output a table with the sheeps name and age.
	else
	{
		while(!found && index < AR_SIZE)
		{
			if(sheepName == sheepArray[index].GetName())
			{
				found = true;
				cout << left
					 << setw(16) << "\nNAME" << "AGE" << endl
				  	 << "-------------- ---"        << endl;

				cout << setw(16) << sheepArray[index].GetName()
					 << sheepArray[index].GetAge() << endl << endl;

				cout << "Has been found.\n\n";
			}
			else
			{
				index ++;
			}
		}
	}

}

/*************************************************************************
 * FUNCTION ClearList
 * ________________________________________________________________________
 * This function will clear all the values that have been stored in  the
 * current array
 * ________________________________________________________________________
 * PRECONDITIONS
 *   GetCommand : user selection
 *
 * POSTCONDITIONS
 *   <nothing>
 ************************************************************************/
void SheepClass::ClearList()
{
	int index; //CALC - Used to determine the instance the array is looking at

	//PROCESSING - It will clear all of the values that have been stored in the array
	for(index = 0; index < AR_SIZE; index ++)
	{
		sheepArray[index].SetName("");
		sheepArray[index].SetAge(0);
	}

	//OUTPUT - Outputs to the console when the list is cleared or is the
	//			list was already cleared
	if(sheepCount == 0)
	{
		cout << "The list is empty!\n\n";
	}
	else
	{
		cout << "The list has been cleared!\n\n";
		sheepCount = 0;
	}
}

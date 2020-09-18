/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #2: Parallel Arrays
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 2-11-2015
 *************************************************************************/
#include "header.h"

/**************************************************************************
 * InputFunction
 * ________________________________________________________________________
 * This function will upload the information in the input file(database)
 * so that the names in there can be searched.
 * ________________________________________________________________________
 * INPUTS -
 * 		index - The number of the spot the array is in
 * 		InFile - The text file that all the info is saved into
 *************************************************************************/
void InputFunction(ifstream& InFile, string NAMES_AR[],int IDS_AR[],
		float BAL_AR[], const int AR_SIZE)
{
	int index;		//INPUT - The number of the spot the array is in

	//Initializes the necessary variables to zero
	index = 0;

	//The loop is loading all the information from the input file in to the
	//selected arrays
	while(InFile && index < AR_SIZE)
	{
		getline(InFile, NAMES_AR[index]);
		InFile >> IDS_AR[index];
		InFile >> BAL_AR[index];
		InFile.ignore(1000, '\n');
		index++;
	}
}

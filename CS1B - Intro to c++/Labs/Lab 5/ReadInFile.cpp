/**************************************************************************
 * AUTHOR     : Bacon Pancakes & BBC
 * STUDENT ID : 951436 & 382108
 * LAB #5     : Array Train
 * CLASS      : CS1B
 * SECTION    : MW 8:30am
 * DUE DATE   : 2/11/2015
 *************************************************************************/
#include "MyHeader.h"

/**************************************************************************
 * ReadInputFile Function
 * ________________________________________________________________________
 * This function reads the two arrays (strgAr[] and intAr[]) from the input
 * file and stores them. The input file is opened and closed only in this
 * file.
 * ________________________________________________________________________
 *VARIABLE -
 *			index - This is the number in the array that is being looked at
 *			inFile- The input file that has the user's names and ages
 *************************************************************************/
void ReadInputFile(const int AR_SIZE, int intAr[], string strgAr[])
{
	ifstream inFile; //The input file that has the user's names and ages
	int index;		 //This is the number in the array that is being looked at

	//Initializing the index to zero
	index = 0;

	//Opening the input file
	inFile.open("InFile.txt");

	//This loop goes through the input file and files in the arrays with
	//their appropriate information (names and ages) from the users.
	while(inFile && index < AR_SIZE)
	{
		getline(inFile, strgAr[index]);
		inFile >> intAr[index];
		inFile.ignore(100,'\n');
		inFile.ignore(100,'\n');
		index++;
	}

	//Closing the input file
	inFile.close();

}

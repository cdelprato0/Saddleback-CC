/**************************************************************************
 * AUTHOR     : singmusic & BBC
 * LAB #6     : Structs
 * CLASS      : CS1B
 * SECTION    : MW 8:30am
 * DUE DATE   : 2/25/2015
 *************************************************************************/
#include "Header.h"
/**************************************************************************
 * Input Function
 * ________________________________________________________________________
 * This function, when called, will read in a set of values from a
 * specified input file into an array of structs.
 * ________________________________________________________________________
 * INPUTS -
 * 		inFile 		: Input file stream
 * 		memberAr	: Array of structs containing user info
 * 		AR_SIZE		: number of elements in the array
 *
 * 	OUTPUT -
 * 		This function does not return a value. It initializes the array
 * 		with values from an input file.
 *************************************************************************/
void InputFunction(ifstream& inFile,		 //IN - input file stream var.
				   MemberAccount memberAr[], //OUT- array of structs
				   const int AR_SIZE) 		 //IN - size of array
{
	int index;		//PROC - index of current element in array

	//PROC - Reads values from the input file into corresponding fields
	//		 in an array of structs
	index = 0;
	while(inFile && index < AR_SIZE)
	{
		getline(inFile, memberAr[index].name);
		inFile >> memberAr[index].id;
		inFile >> memberAr[index].balance;
		inFile.ignore(1000, '\n');
		index++;
	}
}

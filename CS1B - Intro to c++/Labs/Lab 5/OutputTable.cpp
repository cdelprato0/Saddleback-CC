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
 * OutputTable Function
 * ________________________________________________________________________
 * This function will take in the arrays for the age and names and will
 * display a table format that will show up in the output file.
 * ________________________________________________________________________
 *VARIABLE -
 *			index - This is the number in the array that is being looked at
 *			outFile- The output file that the table will be printed to
 *************************************************************************/
void OutputTable(const int AR_SIZE, const int INT_AR[],
					   const string STRG_AR[])
{
	ofstream outFile; //The output file that this table will be displayed to
	int index;		  //This is the number in the array that is being looked at

	//Opens the output text file
	outFile.open("OFile.txt");

	//The code that forms the table format which has the names and ages
	//of all the people in the input file
	outFile << left;
	outFile << setw(10)<< "INDEX" << setw(10) << "NAME" << "AGE" << endl;
	outFile << setw(10)<< "-----" << setw(10) << "----" << "---" << endl;

	//The loop that will fill in the correct information for each person
	for(index = 0; index < AR_SIZE; index++)
	{
		outFile << setw(10)<< index << setw(10) << STRG_AR[index]
		                  		                << INT_AR[index];
		outFile << endl;
	}
	outFile << right;

	//Closing the output text file
	outFile.close();

}

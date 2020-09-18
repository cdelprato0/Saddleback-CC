/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #1:Random Number Generator
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#include "Header.h"

/**************************************************************************
 * ReadInFileAndOutput Function
 * ________________________________________________________________________
 * This function reads the array fileAr[] from the input
 * file and stores the values inside the file to the inside of the array.
 * The input file is opened and closed only in this file. This function
 * will also display the array into the console.
 * ________________________________________________________________________
 * CONSTANT -
 * 			AR_SIZE - The size of the array that is never to change
 * VARIABLE -
 *			index - This is the number in the array that is being looked at
 *			inFile- The input file that has the user's names and ages
 * ARRAY -
 * 			fileAr[] - The array that is created from the reading of the
 * 						input file
 *************************************************************************/
void ReadInFileAndOutput()
{
	const int AR_SIZE = 10;//The constant size of the array

	ifstream inFile; //The input file that has the user's names and ages
	int index;		 //This is the number in the array that is being looked at
	int fileAr[AR_SIZE];//The array that holds the values of the input file

	//Initializing the index to zero
	index = 0;

	//Opening the input file
	inFile.open("InputFile.txt");

	cout << "Reading values from the Input File... \n";

	//This loop goes through the input file and files in the arrays with
	//their appropriate information from the users.
	while(inFile && index < AR_SIZE)
	{
		inFile >> fileAr[index];
		inFile.ignore(100,'\n');
		index++;
	}//END WHILE LOOP

	//PROCESSING - The for loop is designed to output the given array to
	//				the console so that the user will know what is being
	//				read in.
	for(index = 0; index < AR_SIZE; index++)
	{
		//OUTPUT- output the contents of the array to the console.
		cout << fileAr[index] << endl;

	}//END FOR

	cout << "Reading and Output Complete.\n\n";

	//Closing the input file
	inFile.close();
}

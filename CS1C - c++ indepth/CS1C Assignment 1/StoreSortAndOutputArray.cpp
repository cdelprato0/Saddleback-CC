/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #1:Random Number Generator
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#include "Header.h"

/**************************************************************************
 * StoreSortAndOutputArray Function
 * ________________________________________________________________________
 * This function is taking in the user input for the size of the array.
 * Once in the function it will open an external output file. This function
 * will be able to allocate random numbers to be stored into the array.
 * Once they are stored in the array, insertion sort will take place and
 * order the number from least to greatest. All at the same time outputting
 * to an external file.
 * ________________________________________________________________________
 * VARIABLE -
 *			oFile - variable used to open and close the output external file
 *			index - place holder for a spot on the array
 *			randomNum - holds the three digit random value
 * ARRAY -
 * 			numberAr[] - the array that holds the random numbers
  *************************************************************************/
void StoreSortAndOutputArray(int arraySize)
{
	ofstream oFile; //OUT-used to open and close external output file
	int index; //CALC-place holder for a certain spot in the array
	int numberAr[arraySize]; //CALC-the array that holds the random numbers
	int randomNum; //CALC-the variable that holds the created random #

	//PROCESSING - Opens the external output file called "OutputFile.txt"
	oFile.open("OutputFile.txt");

	//Initializing the proper variables to zero
	randomNum = 0;
	index = 0;

	cout << "\nOutputting to the designated Output File...\n\n";

	//PREOCESSING - Used here to be able to create a new random number for
	//				each index of the array
	srand(time(NULL));

	//PROCESSING - This WHILE loop will create the array by generating a
	//				random number, then storing it into a certain index,
	//				and repeating until the array is full
	while(index < arraySize)
	{

		//Random Number generator
		randomNum = rand() % 899 + 101;

		//Loading the random number into the array
		numberAr[index] = randomNum;

		//The Change of the LCV
		index++;
	}

	//PROCESSING - This function takes the current array size and the newly
	//				made array and sorts the numbers inside the array from
	//				lowest on top and greatest on bottom
	InsertionSort(numberAr, arraySize);

	//OUTPUT - This function takes the newly sorted array and outputs all
	//			the random numbers to an external output file
	OutputArray(oFile, numberAr, arraySize);

	cout << "Output File Complete!\n\n";

	//Closes the external output file
	oFile.close();
}

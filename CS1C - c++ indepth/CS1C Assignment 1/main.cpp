/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #1:Random Number Generator
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#include "Header.h"

/**************************************************************************
 * Assignment One - Random Number Generator
 * ________________________________________________________________________
 * This program has five different random number options. This program is
 * designed to use a random number generator that creates a three digit
 * number. With One random number the program will generate it and the user
 * will be asked what operation they would like to use. They have the
 * options of adding up the three digits to accumulate a sum, and/or they
 * can triple the random number, and/or they can reverse the three digits.
 * The program is also capable of creating an array that the user can set
 * the size of how many random number they want the array to store. From
 * there the program will automatically sort through the random numbers
 * and output them to an external output file in order from least to
 * greatest. The last option this program has in the capability to read
 * input from an external input file and store the values read in, into an
 * array. Once they have been read in, the program will output all the
 * numbers into the console.
 * ________________________________________________________________________
 * INPUTS -
 * 		command - takes in the users command from the menu choice
 * 		arraySize - takes the User's request for how big the array is
 *
 * OUTPUTS -
 * 		randNum - Outputs to the console what your random number is
 *************************************************************************/
int main()
{

	int randomNum; //CALC&OUT- variable used to store the random number
	int command;  //IN- the input from the users selection from the menu
	int arraySize; //IN- the users wanted size for the array

	//Initializing the the random number to zero
	randomNum = 0;

	cout << "Welcome to the Random Number Generator!\n";

	//PROCESSING - This function is used to retrieve the users input for
	//				what option they want to use with the program. The
	//				function will be able to check for incorrect entries
	GetCommand(command);

	//PROCESSING - If the user wants to just have one random number, then
	//				it will keep the same number throughout these options
	if(command == SUM || command == TRIPLE || command == REVERSE)
	{
		//Creates the random number
		srand(time(NULL));

		randomNum = rand() % 899 + 101;

		//Outputs what the random number is
		cout << "Your Random Number is: " << randomNum;
		cout << endl << endl;
	}//END IF

	//PROCESSING - This WHILE loop will end the program if the user wants
	//				to exit
	while(command != EXIT)
	{

		//PROCESSING - This SWITCH statement will take in the users input
		//				and determine the correct operation to perform.
		switch(command)
		{
		//PROCESSING - This function is designed to take the random number
		//				and add each digit to itself to accumulate a sum
		case SUM: SumDigits(randomNum);
			break;

		//PROCESSING - This function is made to take in the random number
		//				and triple it and then output it to the console
		case TRIPLE: TripleNumber(randomNum);
			break;

		//PROCESSING - This functions purpose is to reverse the order of
		//				the random three digit number and output what it
		//				looks like
		case REVERSE: ReverseDigits(randomNum);
			break;

		//PROCESSING - This function is designed to take in the users
		//				request of how big the array is and store all of
		//				those numbers to external output file, while at the
		//				same time sorting the numbers in numeric order
		case STORE:	cout << "How many numbers would you like to store? ";
					cin >> arraySize;
					StoreSortAndOutputArray(arraySize);
			break;

		//PROCESSING - This Function is made to read in from an external
		//				input file and load the numbers into a new array
		//				that will output to the console with its contents
		case READIN: ReadInFileAndOutput();
			break;
		}//END SWITCH

		//PROCESSING - This function is used to retrieve the users input for
		//				what option they want to use with the program.
		//				Changes the LCV
		GetCommand(command);

	}//END WHILE LOOP

	return 0;
}//END OF PROGRAM

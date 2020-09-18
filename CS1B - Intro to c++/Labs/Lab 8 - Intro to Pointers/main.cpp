/*************************************************************************
 * AUTHOR	      : Heretic Furby, BBC
 * STUDENT ID     : 323630, 382108
 * Lab #8  		  : Intro to Pointers
 * CLASS	      : M-W 8:30 AM
 * SECTION	      : CS1B
 * DUE DATE	      : 04/03/2015
 *************************************************************************/

// Header file containing all preprocessor directives and prototypes
#include "classheader.h"

// Header file to print the class header detailing assignment information
// to console
#include "PrintHeader.h"

/***************************************************************************
 * Intro to Pointers
 * -------------------------------------------------------------------------
 * This program will be able to accept two integers form a user's input
 * and will be able to accumulate a sum of the two and the product of the two.
 * The program will terminate when the user enters exactly -999. It is
 * composed of three variables that include a dynamically allocated pointer,
 * a pointer variable, and a static variable.
 * -------------------------------------------------------------------------
 * INPUT -
 * 		*newVarPtr   - The first player to enter their name and is pointing
 * 						 to the actual value
 * 		*newVarPtr2  - The second player to enter their name and is pointing
 * 						 to the actual value
 *
 * OUTPUT -
 * 		No variables are declared for the output. Arithmetic is done with
 * 		the input values
 ****************************************************************************/

int main()
{
	int newVar;
	int *newVarPtr;		//IN - User input for the first integer
	int *newVarPtr2;	//IN - User input for the second integer

	//PROCESSING - Initializing the necessary variables to zero and
	//				initializing NULL to the addresses of the user's inputs
	//  			so that they are "empty".
	newVar = 0;
	newVarPtr = NULL;
	newVarPtr2 = NULL;

	//PROCESSING - Dynamically allocating a space in memory for the first
	//				user's input and assigning the static variables address
	//				to the second user's input.
	newVarPtr = new int;
	newVarPtr2 = &newVar;

	//PrintHeader - Outputs the header of the project in the console.
	PrintHeader("Intro to Pointers", 'L', 8);

	//INPUT - Gathering the first integer from the user and is pointing at
	//			the actual value not the address. INITALIZE LCV
	cout << left;
	cout << setw(PROMPT_WIDTH) << "Input the first value (enter -999 to exit): ";
	cin  >> *newVarPtr;

	//PROCESSING - A while loop that is checking to make sure the user did
	//				not enter the exit command (-999) and is also checking
	//				to see if the first integer input is equal to NULL.
	//				CHECK LCV
	while (*newVarPtr != EXIT && newVarPtr != NULL)
	{
		//INPUT - Prompting for the user to enter a second number and is
		//			pointing to the actual value not the address
		cout << setw(PROMPT_WIDTH) << "Input the second value: ";
		cin  >> *newVarPtr2;

		//OUTPUT - Outputting the sum and the product of the two entered
		//			integers using arithmetic
		cout << endl;
		cout << setw(RESULT_WIDTH)       << "The sum is: "
			 << *newVarPtr + *newVarPtr2 << endl;
		cout << setw(RESULT_WIDTH)       << "The product is: "
			 << *newVarPtr * *newVarPtr2 << endl << endl;

		//INPUT - Gathering the first integer from the user and is pointing
		//			at the actual value not the address. CHANGE LCV
		cout << setw(PROMPT_WIDTH) << "Input the first value (enter -999 to exit): ";
		cin  >> *newVarPtr;
	}

	//PROCESSING - Error check to see if the first input is equal to NULL
	//     			and if so will output the prompt of no memory
	if (newVarPtr == NULL)
	{
		cout << "\nOut of Memory!";
	}

	cout << "\n\nThank you for using this program.";
	cout << right;

	//PROCESSING - Deleting or deallocating the memory that was found
	delete newVarPtr;

	return 0;

}

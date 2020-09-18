/*************************************************************************
 * AUTHOR     : Professor X & BBC
 * LAB #16    : Intro to Recursion - GCD
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   :
 ************************************************************************/
#include "Header.h"

int main()
{
	// Declaration
	ofstream oFile;		// OUT        - Outputs the output file.
	int firstNumber;	// IN         - Inputs the first integer.
	int secondNumber;	// IN         - Inputs the second integer.
	int gcd;			// CALC & OUT - Calcs the greatest common divisor.
	int count;			// CALC       -  Loop control variable.

	// Initialization
	firstNumber = 0;
	secondNumber   = 0;

	//Opens the output file
	oFile.open("OutputFile.txt");

	// prints the header the function.
	PrintHeader("BBC & Professor X" , "Intro to Recursion", "CS1B", 'L',
			     16, oFile);

// Runs the calculations and output 4 times.
	for(count = 0; count < 4; count++)
	{
		// reads in users input.
		UserInput(firstNumber, secondNumber);
		// returns the greatest common divisor.
		gcd = Euclidean(firstNumber, secondNumber);
		// outputs the output file.
		Output(oFile, firstNumber, secondNumber, gcd);
	}

	//Closes the output file
	oFile.close();

	return 0;
}

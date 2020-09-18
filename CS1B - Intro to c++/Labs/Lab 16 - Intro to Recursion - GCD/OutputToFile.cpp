/*************************************************************************
 * AUTHOR     : Professor X & BBC
 * LAB #16    : Intro to Recursion - GCD
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   :
 ************************************************************************/
#include "Header.h"

/**************************************************************************
 * Output Function
 * ________________________________________________________________________
 * This function will output to oFile file users first and second integer
 * input followed by the greatest common divisor.
 * ________________________________________________________________________
 * PRECONDITIONS\
 * 	ofstream:
 * 	Ofile
 *   INT :
 *   first
 *   second
 *   gcd
 * POSTCONDITIONS
 *  outputs to file.
 ************************************************************************/
void Output(ofstream &oFile, int firstNumber, int secondNumber, int gcd)
{
	//OUTPUT - outputs to the out file
	oFile << "The GCD for " << firstNumber << " & " << secondNumber << " = ";

	//PROCESSING - Determines if the number is undefined or if it is equal
	//				to zero
	if(firstNumber == 0 || (firstNumber == 0 && secondNumber == 0))
	{
		//OUTPUTS - outputs to file
		oFile << "Undefined!";
	}
	else if(secondNumber == 0)
	{
		//OUTPUTS - Outputs the greatest common divisor
		oFile << gcd;
	}
	else
	{
		//OUTPUTS - Outputs the greatest common divisor
		oFile << gcd;
	}

	oFile << endl;
}

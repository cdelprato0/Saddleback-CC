/*************************************************************************
 * AUTHOR     : Professor X & BBC
 * LAB #16    : Intro to Recursion - GCD
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   :
 ************************************************************************/
#include "Header.h"

/**************************************************************************
 * Euclidean Function
 * ________________________________________________________________________
 * This function will get users first and second integer input. Then uses
 * recursion to find the greatest common divisor.
 * ________________________________________________________________________
 * PRECONDITIONS
 *   INT :
 *   first
 *   second
 * POSTCONDITIONS
 *  returns the divisor.
 ************************************************************************/
int Euclidean(int first, int second)
{

	//PROCESSING - Checks to see if one of the integers is equal to zero
	if(first != 0 && second != 0)
	{
		//PROCESSING - If the remainder of the first and second value is
		//				equal to zero it will return the greatest common
		//				divisor
		if(first % second == 0)
		{
			return second;
		}
		//PROCESSING - If the two numbers are not divisible by the same
		//				greatest common divisor it will run the function
		//				again to determine the greatest common divisor of
		//				the remainder
		else
		{
			return Euclidean(second, (first % second));
		}
	}
	else
		return 0;
}

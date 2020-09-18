/**************************************************************************
 * AUTHOR     : Cabbage & BBC
 * STUDENT ID : 386273 & 382108
 * LAB #7     : Binary Search
 * CLASS      : CS1B
 * SECTION    : MW 8:30am
 * DUE DATE   : 2/18/2015
 *************************************************************************/
#include "header.h"

/**************************************************************************
 * LAB #5: Binary Search
 * ________________________________________________________________________
 * This program shows the pre-sorted values in the array and prompts the
 * to enter what number they are searching for. It then outputs the index
 * of the inputed value. The program repeats it self but in this run, the
 * array will be sorted from smallest to largest.
 * ________________________________________________________________________
 *CONSTANTS -
 *			AR_SIZE - The never changing size of the arrays
 *INPUTS -
 *			intAr[]  - array that contains ints
 *
 *OUTPUTS -
 *
 *************************************************************************/

int main()
{
	const int AR_SIZE  = 8; //The never changing size of the arrays
	int intAr[AR_SIZE] = {4,
						  1,
						  7,
						  12,
						  8,
						  13,
						  9,
						  21}; //INPUT - array that contains ints

	//PrintHeader - This will output the heading into the console
	PrintHeader();

	/*************************************************************
	 * OUTPUT - Int array
	 *************************************************************/
	OutputFunction(intAr, AR_SIZE);

	/*************************************************************
	 * INPUT  - user is prompted to enter a value to be searched
	 * OUTPUT - outputs value's index if it was found or not
	 *************************************************************/
	SequentialSearch(intAr, AR_SIZE);

	cout << "\n\nPerforming Insertion Sort!\n\n";

	/*************************************************************
	 * PROCESSING - Sorts all the values in the array from
	 * 				smallest to largest
	 *************************************************************/
	InsertionSort(intAr, AR_SIZE);


	/*************************************************************
	 * OUTPUT - Int array
	 *************************************************************/
	OutputFunction(intAr, AR_SIZE);

	/*************************************************************
	 * INPUT  - user is prompted to enter a value to be searched
	 * OUTPUT - outputs value's index if it was found or not
	 *************************************************************/
	BinarySearch(intAr, AR_SIZE);

	return 0;
}

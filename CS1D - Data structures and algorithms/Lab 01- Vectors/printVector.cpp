/************************************************************************
 * AUTHOR     : Anna Kolev & Chaz Del Prato
 * LAB        : #1
 * CLASS      : CS1D
 * SECTION    : M/W 3:00PM
 * DUE DATE   : Jan 18, 2017
 ************************************************************************/

#include "header.h"

/************************************************************************
 * printVector
 * This function prints the contents of a vector.
 *
 * - returns nothing --> prints the vector to console
 ************************************************************************/
void printVector(vector<int> myVector)
{
	for(int i = 0; i < 20; i++)
	{
		cout << setfill ('0') << setw(3) << right << myVector[i];

		if(i < 19)
		{
			cout << ", ";
		}
	}
	cout << setfill (' ') << left << endl;

}

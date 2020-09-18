/************************************************************************
 * AUTHOR     : Anna Kolev & Chaz Del Prato
 * LAB        : #1
 * CLASS      : CS1D
 * SECTION    : M/W 3:00PM
 * DUE DATE   : Jan 18, 2017
 ************************************************************************/

#include "header.h"

/*************************************************************************
 * Vectors
 * _______________________________________________________________________
 * This program uses a random number generator to generate 20 three digit
 * integers. It will then perform the following operations:
 *
 * 		- Sort the random numbers
 * 		- Store the sorted random numbers in a vector
 * 		- Reverse the digits of the of the random numbers
 * 		- Store the reversed digits in another vector
 * 		- Sum the digits of the random numbers
 * 		- Store the sums in another vector
 * 		- Print all three vectors
 *
 * **********************************************************************/

int main()
{
	/********************************************************************
	 * CONSTANTS
	 * ------------------------------------------------------------------
	 * STRING_OUTPUT 		:  aligns the output
	 * ******************************************************************/

	const int STRING_OUTPUT = 36;

	vector <int> randoms;  	//declare a vector to store random integers
	vector <int> reverse;	//declare a vector to store reversed ints
	vector <int> sums;		//declare a vector to store digit sums

	srand(time(NULL));		//creates seed for random numbers

	cout << left; //sets output results to left justify

	cout << "Anna Kolev and Chaz Del Prato\n\n"
		 <<	"Vectors \n"
		 << "This program uses a random number generator to generate 20 three \n"
		 << "digit integers. It will then perform the following operations: \n"
		 << "\n"
		 << " 	- Sort the random numbers\n"
		 << "	- Store the sorted random numbers in a vector\n"
		 << "	- Reverse the digits of the of the random numbers\n"
		 << "	- Store the reversed digits in another vector\n"
		 << "	- Sum the digits of the random numbers\n"
		 << " 	- Store the sums in another vector\n"
		 << "	- Print all three vectors\n\n";

	//PROCESSING- stores 20 random two-digit integers in vector
	for(int i = 0; i < 20; i++)
	{
		randoms.push_back (rand() % 899 + 100);
	}


	//OUTPUT - outputs the vector
	cout << setw(STRING_OUTPUT) << "The randomized vector is: ";
	printVector(randoms);


	//PROCESSING- sorts integers in vector into ascending order
	sort (randoms.begin(), randoms.end());


	//OUTPUT- outputs the vector
	cout << setw(STRING_OUTPUT) << "The sorted vector is: ";
	printVector(randoms);


	//PROCESSING- reverses digits of numbers and stores in new vector
	for(int i = 0; i < 20; i++)
	{
		reverse.push_back((randoms[i]/100) + ((randoms[i]/10)%10)*10 + (randoms[i]%10)*100);
	}


	//OUTPUT- outputs the vector with reversed digits
	cout << setw(STRING_OUTPUT) << "The vector with digits reversed is: ";
	printVector(reverse);


	//PROCESSING- sums digits of numbers and stores in new vector
	for(int i = 0; i < 20; i++)
	{
		sums.push_back((randoms[i]/100) + ((randoms[i]/10)%10) + (randoms[i]%10));
	}


	//OUTPUT- outputs the vector with reversed digits
	cout << endl;
	for(int i = 0; i < 20; i++)
	{
		cout << "The sum of the digits of " << randoms[i] << " is ";

		cout << right << sums[i];

		if(i < 19)
		{
			cout << endl;
		}
	}
	cout << setfill (' ') << left << endl;

	cout << right; //sets output to default settings

	return 0;
}

/*
 * functions.cpp
 *
 *  Created on: Nov 24, 2014
 *      Author: mrobison5
 */

#include"header.h"

// FUNCTION - Call header function to display assignment information

void PrintHeader(string aName, char aType, int aNum)
{
	cout << left;
	cout << "********************************************";
	cout << "\n* PROGRAMMED BY : Mark Robison & Chaz Delprato";
	cout << "\n* " << setw(14) << "DUE DATE      : 11/24/2014";
	cout << "\n* " << setw(14) << "CLASS"  << ": CS1A --> Mon/Wed 9:30am";
	cout << "\n* ";
	  	  if(toupper(aType) == 'L')
		  {
			  cout << "LAB #" << setw(9);
		  }
		  else
		  {
			  cout << "ASIGNMENT # " << setw(2);
		  }
    cout << aNum << ":" << aName;
    cout << "\n********************************************\n\n";
    cout << right;
}

// FUNCTION - gather the information from user of names to be inputed

void NameFile(string fileNames[], const int NUM_N)
{

	int input;

	for (input = 0; input < NUM_N; input++)
	{
		cout << "Enter name #" << input + 1 << ": ";
		cin >> fileNames[input];
	}
	cin.ignore(100, '\n');


}

// FUNCTION - search for name that is in the list of the array and return value

int NameSearching(string fileNames[], int NUM_N, string inquiry)
{

	int index;
	int found;

	found = 0;

	// CALC - the number of times the name is found in array

	for(index = 0; index < 10; index++)
	{

		if(fileNames[index] == inquiry)
		{
			found = found +1;

		}

		else
		{

		}

	}



	return found;

}



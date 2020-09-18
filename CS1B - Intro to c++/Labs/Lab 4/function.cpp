#include "header.h"

//This function will display the header
void PrintHeader(string aName, char aType, int aNum)
{
	cout << left;
	cout << "********************************************";
	cout << "\n* PROGRAMMED BY : FSC & BBC";
	cout << "\n* " << setw(14) << "DUE DATE      :2/9/15 ";
	cout << "\n* " << setw(14) << "CLASS"  << ": CS1B --> Mon/Wed 8:30am";
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

/**************************************************************************
 * EnterName Function
 * ________________________________________________________________________
 * This function will prompt for the user's name and will load the name
 * into the array. Also keeps count of the number of people entered
 * ________________________________________________________________________
 *VARIABLE -
 *			count - Counter for the number of students
 *************************************************************************/
void EnterName(string fileNames[], const int NUM_N)
{
	int count;		//Counter for the number of students

	for (count = 0; count < NUM_N; count++)
	{
		cout << "Enter name #" << count + 1 << ": ";
		cin >> fileNames[count];
	}
	cin.ignore(100, '\n');
}

/**************************************************************************
 * SearchName Function
 * ________________________________________________________________________
 * This function will search for a name in the array and will determine
 * how many instances the name came up in the array
 * ________________________________________________________________________
 *VARIABLE -
 *			index - element on the array
 *			found - if the name is found during the search
 *************************************************************************/
int SearchName(string fileNames[], int NUM_N, string inquiry)
{

	int index;		//element on the array
	int found;		//if the name is found during the search

	found = 0;

	// CALC - the number of times the name is found in array

	for(index = 0; index < 10; index++)
	{
		if(fileNames[index] == inquiry)
			found = found +1;
	}

	return found;

}

#include "header.h"


//PrintHeader - Determines if the program is an assignment or lab and
//				displays the programmers info in the output.
void PrintHeader(ofstream& OFile, string asName, char asType, int asNum)
{
	OFile << left;
	OFile << "********************************************************";
	OFile << "\n* PROGRAMMED BY : BBC";
	OFile << "\n* " << setw(14) << "Student ID" << ": 382108";
	OFile << "\n* " << setw(14) << "Class" << ": CS1A --> Mon/Wed 9:30am";
	OFile << "\n* ";
	if(toupper(asType) == 'L')
	{
		OFile << "LAB #" << setw(9);
	}
	else
	{
		OFile << "ASSIGNMENT #" << setw(2);
	}
	OFile << asNum << ": " << asName;
	OFile << "\n******************************************************\n\n";
	OFile << right;
}

/**************************************************************************
 * InputFunction
 * ________________________________________________________________________
 * This function will upload the information in the input file(database)
 * so that the names in there can be searched.
 * ________________________________________________________________________
 * INPUTS -
 * 		index - The number of the spot the array is in
 * 		InFile - The text file that all the info is saved into
 *************************************************************************/
void InputFunction(ifstream& InFile, string NAMES_AR[],int IDS_AR[],
		float BAL_AR[], const int AR_SIZE)
{
	int index;		//INPUT - The number of the spot the array is in

	//Initializes the necessary variables to zero
	index = 0;


	while(InFile && index < AR_SIZE)
	{
		getline(InFile, NAMES_AR[index]);
		InFile >> IDS_AR[index];
		InFile >> BAL_AR[index];
		InFile.ignore(1000, '\n');
		index++;
	}
}

/**************************************************************************
 * NameSearching
 * ________________________________________________________________________
 * This function, when called, will take in the user input for the person
 * searched. Then will search the InFile file to see if the name is in
 * the database and if it is, it will output found or if not will say not
 * found.
 * ________________________________________________________________________
 * INPUTS -
 * 		index - The number of the spot the array is in
 * 		searchName - The name that is being searched for in the database
 *
 * 	OUTPUT -
 * 		found - Will determine if the name that was requested is found or
 * 				not
 *		balance - Will keep a running total sum of the balances due on the
 *			      people that were found
 *************************************************************************/

bool NameSearching(ofstream& OFile, string NAMES_AR[], const int AR_SIZE,
		string searchName, int IDS_AR[], float BAL_AR[], float& balance)
{
	int index;		//INPUT - The number of the spot the array is in
	bool found;		//OUTPUT - Will keep a running total sum of the
					//balances due on the people that were found

	//Initializes the necessary variables to zero
	index = 0;
	found = false;


	//PROCESSING - Determines if the name was found the the search or not
	while(index < AR_SIZE && !found)
	{
		if(NAMES_AR[index] == searchName)
		{
			found = true;

			OFile << IDS_AR[index] << "\t" << left << setw(24) <<
					searchName << left << "$" <<setprecision(2) << fixed <<
					right << setw(10) << BAL_AR[index] << endl;

			balance = balance + BAL_AR[index];
		}
		else
		{
			index++;
		}
	}
	return found;
}


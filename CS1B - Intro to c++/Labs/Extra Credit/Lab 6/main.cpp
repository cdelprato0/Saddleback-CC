/**************************************************************************
 * AUTHOR     : singmusic & BBC
 * LAB #6     : Structs
 * CLASS      : CS1B
 * SECTION    : MW 8:30am
 * DUE DATE   : 2/25/2015
 *************************************************************************/
#include "Header.h"

/**************************************************************************
 * Structs - Account Balance Program
 * ________________________________________________________________________
 * This program will be able to search for a name, in a database, which
 * holds their name, id, and balance due. The Program will ask you what
 * input and output file you want to use, and then will prompt for a name
 * to search and will determine if that name is in the database. Then it
 * will output the searched id, name and balance due. It will also
 * calculate and output the total of all balances for the found names.
 * ________________________________________________________________________
 * INPUTS -
 * 		searchName - The name that is being searched for in the database
 * 		inFile     - The text file that all the info is saved into
 *
 * STRUCTS - ARRAY
 * 		MemberAccount - Stores the values for the users name, id and balance
 * 		memberAr[]    - The array for the above struct
 *
 * OUTPUTS -
 * 		found - Will determine if the name that was requested is found or
 * 				not
 *		oFile - The output file that displays the header and the balance
 *				  due
 *		totalBalance - The grand total of the people that have balance due
 *
 *
 *************************************************************************/
int main()
{
	/*********************************************************************
	 *	CONSTANTS
	 * ___________________________________________________________________
	 * 	AR_SIZE    - PROC - The amount of names in the arrays
	 * 	EXIT_VAR   - PROC - The string that is used to end the search loop
	 * 	INPUT_SIZE - OUT - The size set for the setw when asking for file
	 * 						names
	 *********************************************************************/
	const int    AR_SIZE = 10;
	const string EXIT_VAR = "done";
	const int    INPUT_SIZE = 40;

	MemberAccount memberAr[AR_SIZE];//IN & OUT - Stores the values for the
									//users name, id and balance

ifstream inFile;			//INPUT - The text file that all the info is
							//			saved into
	ofstream oFile;			//OUTPUTS - The output file that displays the
							//			header and the balance due

	string inFileName;		//INPUT - Checks to see which file should be
							//			open
	string outFileName;		//INPUT - Checks to see which file should be
							//			open
	string searchName;		//INPUT - The name that is being searched for
							//			in the database

	int    index;			//The number of the spot the array is in
	float totalBalance;		//OUTPUTS -Keeps track of all the money that is
							//	owed from all the customers


	//INPUT - Prompts the user for the input and output file that they
	//		  want to choose
	cout << left;
	cout << setw(INPUT_SIZE) << "What input file would you like to use?";
	getline(cin, inFileName);

	cout << setw(INPUT_SIZE) << "What output file would you like to use?";
	getline(cin, outFileName);
	cout << endl;

	//Opens the .txt files
	inFile.open(inFileName.c_str());
	oFile.open(outFileName.c_str());

	//Calls the function PrintHeader and will output to the output file
	PrintHeader(oFile);

	//Calls the function InputFunction and reads in the info from the input
	//file
	InputFunction(inFile, memberAr, AR_SIZE);

	//Prompts the user to enter a name to search and to type in done if the
	//user wants the exit the program
	cout << "Who do you want to search for (enter done to exit): ";
	getline(cin, searchName);

	//OUTPUT - Displays in the output file
	oFile << "ID #\t" << left << setw(20) << "NAME" << "\t" <<
			"BALANCE DUE" << endl;
	oFile << "----\t" << "--------------------\t" <<
			"-----------\n";

	//Initializes the necessary variables to zero
	totalBalance = 0;

	while(searchName != EXIT_VAR)
	{
		//Call the function NameSearching and assigns it to the variable
		//found
		index = SearchArray(oFile, memberAr, AR_SIZE, searchName,
				            totalBalance);

		//Outputs if the found variable is set true and increments
		//foundCount
		if(index == AR_SIZE)
		{
			cout << searchName << " was not found.\n";
		}
		else
		{
			cout << "Found.\n";
		}

		cout << "\nWho do you want to search for (enter done to exit): ";
		getline(cin, searchName);
	}

	//Displays in the output file
	oFile << endl << right << setw(33) << "Total Balance Due: $" <<
			setw(10) << totalBalance;

	cout << "\nThank you for using my program.";

	//Closes the input and output .txt files
	inFile.close();
	oFile.close();

	return 0;
}

/**************************************************************************
 * AUTHORS       : BBC
 * STUDENT IDs   : 382108
 * ASSIGNMENT #10: Parallel Arrays
 * CLASS	 	 : CS1A
 * SECTION		 : MW 9:30a
 * DUE DATE      : 12-8-14
 *************************************************************************/

#include "header.h"

/**************************************************************************
 * Account Balance Program
 * ________________________________________________________________________
 * This program will be able to search for a name, in a database, which
 * holds their name, id, and balance due. The Program will ask you what
 * input and output file you want to use, and then will prompt for a name
 * to search and will determine if that name is in the database. Then it
 * will output the searched id, name and balance due.
 * ________________________________________________________________________
 * CONSTANTS -
 * 		AR_SIZE - The amount of names in the arrays
 *
 * INPUTS -
 * 		index - The number of the spot the array is in
 * 		search - The name that is being searched for in the database
 * 		InFile - The text file that all the info is saved into
 *
 * ARRAYS -
 * 		Names[AR_SIZE] - The array that has the names of the customers
 * 		Ids[AR_SIZE] - The array that has the id numbers of the customers
 * 		Balance[AR_SIZE] - The array that has the balances of the customers
 *
 * OUTPUTS -
 * 		found - Will determine if the name that was requested is found or
 * 				not
 *		balance - Will keep a running total sum of the balances due on the
 *			      people that were found
 *		OutFile - The output file that displays the header and the balance
 *				  due
 *		foundCount - Keeps track of the number of people found for the
 *					 average
 *		average - The average of the amount that all the customers owe
 *		totBalance - Keeps track of all the money that is owed from all the
 *					 customers and is used to find the average
 *
 *************************************************************************/

int main()
{
	const int AR_SIZE = 10; //The amount of names in the arrays
	ifstream InFile;		//INPUT - The text file that all the info is
							//			saved into
	ofstream OutFile;		//OUTPUTS - The output file that displays the
							//			header and the balancedue
	string inputFile;		//INPUT - Checks to see which file should be
							//			open
	string outputFile;		//INPUT - Checks to see which file should be
							//			open
	string Names[AR_SIZE];	//ARRAYS -The array that has the names of the
							//			customers
	int Ids[AR_SIZE];		//ARRAYS -The array that has the id numbers of
							//			the customers
	float Balance[AR_SIZE]; //ARRAYS -The array that has the balances of
							//			the customers
	bool found;				//OUTPUTS -Will determine if the name that was
							//			requested is found or not
	string search;			//INPUT - The name that is being searched for
							//			in the database
	int foundCount;			//OUTPUTS -Keeps track of the number of people
							//			found for the average
	float average;			//OUTPUTS -The average of the amount that all
							//			the customers owe
	float totBalance;		//OUTPUTS -Keeps track of all the money that is
							//	owed from all the customers and is used to
							//	find the average

	//Initializes the necessary variables to zero
	foundCount = 0;

	//INPUT - Prompts the user for the input and output file that they
	//		  want to choose
	cout << left;
	cout << setw(40) << "What input file would you like to use?";
	getline(cin, inputFile);
	cout << setw(40) << "What output file would you like to use?";
	getline(cin, outputFile);
	cout << endl;

	//Opens the .txt files
	InFile.open(inputFile.c_str());
	OutFile.open(outputFile.c_str());

	//Calls the function PrintHeader
	PrintHeader(OutFile, "Parallel Arrays", 'A', 10);

	//Calls the function InputFunction
	InputFunction(InFile, Names, Ids, Balance, AR_SIZE);

	//OUTPUT - Displays in the output file
	OutFile << "ID #\t" << left << setw(20) << "NAME" << "\t" <<
			"BALANCE DUE" << endl;
	OutFile << "----\t" << "--------------------\t" <<
			"-----------\n";
	//Prompts the user to enter a name to search and to type in done if the
	//user wants the exit the program
	do
	{
		cout << "Who do you want to search for (enter done to exit): ";
		getline(cin, search);

		//Call the function NameSearching and assigns it to the variable
		//found
		found = NameSearching(OutFile, Names, AR_SIZE, search, Ids,
				Balance, totBalance);

		//Outputs if the found variable is set true and increments
		//foundCount
		if(search != "done" && search != "Done")
		{
			if(found == true)
			{

				cout << "Found.";
				cout << endl << endl;
				foundCount++;
			}
			else
			{
				cout << search << " was not found.";
				cout << endl << endl;
			}
		}



	}while(search != "done" && search != "Done");

	cout << endl;
	cout << "Thank you for using my program." << endl;

	//CALC - Calculates the average of the total balances
	average = totBalance / foundCount;

	//Displays in the output file
	OutFile << endl << right << setw(33) << "Average Balance Due: $" <<
			setw(10) << average;

	//Closes the input and output txt files
	InFile.close();
	OutFile.close();

	return 0;
}





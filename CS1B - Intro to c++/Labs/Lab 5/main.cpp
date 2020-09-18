/**************************************************************************
 * AUTHOR     : Bacon Pancakes & BBC
 * STUDENT ID : 951436 & 382108
 * LAB #5     : Array Train
 * CLASS      : CS1B
 * SECTION    : MW 8:30am
 * DUE DATE   : 2/11/2015
 *************************************************************************/
#include "MyHeader.h"

/**************************************************************************
 * Array Train
 * ________________________________________________________________________
 * This program will begin with initializing all the arrays to zero or
 * clearing their values. Then it will read-in from an input file that has
 * users names and their ages. The program will be able to determine and
 * output the oldest person and what their age is. It will also be able to
 * search within the arrays for how many instances of an age comes up and
 * will be able search for one instance of an name. It will all be displayed
 * to an Output file in a table format and will accumulate the sum of all
 * the ages in the input file.
 * When finding the oldest person and the search for one instances in the
 * names, these will be displayed in the console not the output file.
 * ________________________________________________________________________
 *CONSTANTS -
 *			AR_SIZE - The never changing size of the arrays
 *INPUTS -
 *			ageAr[]  - Will read in the users age from the input file and
 *						store it in the array
 *			nameAr[] - Will read in the users name from the input file and
 *						store it in the array
 *OUTPUTS -
 *			oldestAge - Will determine the oldest person in the input file
 *			sum 	  - The sum of all the ages in the input file
 *			instance  - The number of instances a name came up form the
 *						 input file
 *			searchItem- The search for the number of ages in the input file
 *			searchString- The search for the one name in the input file
 *			person    - The result of the search for the one name
 *************************************************************************/
int main()
{

	const int AR_SIZE 	= 8;// The never changing size of the arrays

	int ageAr[AR_SIZE];		//INPUT - Array for the users ages
	string nameAr[AR_SIZE]; //INPUT - Array for the users names

	string searchString; //C&O - Search for the one name in the input file
	int instance;		 //C&O - The number of instances a name came up
	int searchItem;		 //C&O - Search for the instances in the input file
	int person;			 //C&O - The result of the search for the one name
	int oldestAge;		 //C&O - The oldest person in the input file
	int sum;			 //C&O - The sum of all the ages in the input file

	//Array Train - Begin

	//PrintHeader - This will output the heading into the console
	PrintHeader();

	//Initialization of the arrays ageAr[] and nameAr[]
	InitialInt(AR_SIZE, ageAr);
	InitialStrg(AR_SIZE, nameAr);

	//ReadInputFile - This will read in all the information into the arrays
	//					ageAr[] and nameAr[]
	ReadInputFile(AR_SIZE, ageAr, nameAr);

	//The index of the oldest person returns with the age and their name
	//and is assigned into oldestAge
	oldestAge = OutputOldest(AR_SIZE, ageAr);

	//The oldest age and their name is displayed into the console
	cout << nameAr[oldestAge] <<" is the oldest with an age of "
		 << ageAr[oldestAge] << "." << endl << endl;


	//Prompting the user to enter an age that they wish to see how many
	//instances that age comes up - Initializes the LCV
	cout << "What age would you like to search for? "
		 <<	"(Enter 0 to exit) ";
	cin  >> searchItem;

	//Searching for the number of instances that an age appeared in the
	//array
	while(searchItem != 0)
	{
		//This function finds and returns the number of instances an age
		//appeared inside the ageAr[] array
		instance = NumInstance(AR_SIZE, ageAr, searchItem);

		//Checks the LCV
		if(instance < AR_SIZE && instance > 0)
		{
			cout << "This age appears in " << instance << " instances.\n\n";
		}
		else
		{
			cout << "Age was not found.\n\n";

		}

		//Changes the LCV
		cout << "What age would you like to search for? "
			 <<	"(Enter 0 to exit) ";
		cin  >> searchItem;
	}

	cin.ignore(1000,'\n');

	//Prompts the user to enter the name they want to search for. It will
	//only return one instance. - Initializes the LCV
	cout << endl << endl;
	cout << "Who would you like to search for? (Enter \"done\" to exit) ";
	getline(cin, searchString);

	//Searching for the name within the array
	while(searchString != "done")
	{

		//This function searches the array to see if the name was entered
		//into the input file and returns a value that determines if it was
		//found or not
		person = SearchString(AR_SIZE, nameAr, searchString);

		//Check the LCV
		if(person < AR_SIZE)
		{
			cout << "Found.\n";
			cout << nameAr[person] << " " << ageAr[person] << endl;
		}
		else
		{
			cout << searchString << " was not found.\n";
		}

		//Changes the LCV
		cout << endl;
		cout << "Who would you like to search for? "
			 <<	"(Enter \"done\" to exit) ";
		getline(cin, searchString);

	}

	//OutputTable - Outputs all the names and ages in the arrays and puts
	//				them into a table format
	OutputTable(AR_SIZE, ageAr, nameAr);

	//SumInts - Adds up all the ages in the array and returns the sum of
	//			all the ages
	sum = SumInts(AR_SIZE, ageAr);

	//Outputs the sum of all ages into the console
	cout << "\nThe sum of all ages is " << sum << endl << endl;

	cout << endl;
	cout << "Thank you for using my program. Have a nice life.";
	return 0;
}





/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #8: Loops & Boolean Expressions
 * CLASS		: CS1A
 * SECTION		: MW 9:30a
 * DUE DATE     : 11-17-14
 *************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

/**************************************************************************
 *Military Acceptance Program
 *________________________________________________________________________
 * This program will take the user's current gender, height, and weight
 * and will determine if the candidate meets the minimum and maximum
 * requirements for the program. It will output if the user is accepted
 * or not and what they were not accepted for.
 *	______________________________________________________________________
 *	INPUT:
 *		gender			:The user's gender (m/f)
 *		height			:The user's height
 *		weight			:The user's weight
 *
 *	OUTPUT:
 *		average			:The average of candidates that are accepted
 *		accepted		:The amount of candidates that have been accepted
 *		totalCand		:The number of candidates that applied
 *	PROCESSING:
 *		heightOk		:Determines if your height qualified or not
 *		weightOk		:Determines if your weight is qualified or not
 *
 *************************************************************************/

int main()
{
	//This is the header that will display in the output

	const char PROGRAMMER[30]	= "BBC";
	const char CLASS[5]			= "CS1A";
	const char SECTION[25]		= "MW: 9:30AM";
	const char ASSIGNMENT[30]	= "Loops & Boolean Expressions";

	cout << left;
	cout << "********************************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* " << setw(14) << "ASSIGNMENT #8"  << ": " << ASSIGNMENT;
	cout << "\n******************************************************\n\n";
	cout << right;

	char gender;	//INPUT - The user's gender (m/f)
	int height;		//INPUT - The user's height
	int weight;		//INPUT - The user's weight
	int testNumber;	//CALC - The number of times the program will run
	bool heightOk;	//CALC - Determines if your height qualified or not
	bool weightOk;	//CALC - Determines if your weight is qualified or not
	int accepted;	//OUTPUT-The amount of candidates that have been accepted
	int totalCand;	//OUTPUT-The number of candidates that applied
	float average;	//OUTPUT-The average of candidates that are accepted

	//For loop that will determine how many times the program is ran
	for(testNumber = 1; testNumber <= 3; testNumber = testNumber + 1)
	{
		height = 0;
		weight = 0;
		accepted = 0;
		totalCand = 0;

		cout << "TEST RUN #" << testNumber << endl << endl << endl;

		cout << "Please enter the candidates\'s information (enter "
				"\'X\' to exit)." << endl;

		do
		{

			cout << left;
			cout << setw(9) << "Gender:";
			cin.get(gender);
			cin.ignore(1000, '\n');

			if(gender != 'm' && gender != 'M' && gender !='f' &&
					gender != 'F' && gender != 'x' && gender != 'X')
			{
				cout << "***** Invalid gender; please enter M or F"
						" *****";
				cout << endl;
			}

		}while(gender != 'm' && gender != 'M' && gender !='f' &&
				gender != 'F' && gender != 'x' && gender != 'X');

		while(gender != 'x' && gender != 'X')
		{
			heightOk = false;
			weightOk = false;
			do
			{
				cout << left;
				cout << setw(9) << "Height:";
				cin >> height;

				if(height < 24 || height > 110)
				{
					cout << "***** Invalid height; please enter a height "
							"in inches between 24 and 110. *****" << endl;
				}
			}while(height < 24 || height > 110);

			//PROCESSING - Assignment statement that determines if
			//				the user is qualified or not
			heightOk = (gender == 'm' || gender == 'M'?
						(height >= 65 && height <= 80?
						 true : false)
						: gender == 'f' || gender == 'F'?
						(height >= 62 && height <= 75?
						 true : false ): -999);

			do
			{
				cout << left;
				cout << setw(9) << "Weight:";
				cin >> weight;
				cin.ignore(1000, '\n');


				if(weight < 50 || weight > 1400)
				{
					cout << "***** Invalid weight; please enter a weight "
							"in lbs between 50 and 1400. *****" << endl;
				}
			}while(weight < 50 || weight > 1400);

			//PROCESSING - Assignment statement that determines if
			//				the user is qualified or not
			weightOk = (gender == 'm' || gender == 'M'?
						(weight >= 130 && weight <= 250?
						true : false)
					 	: gender == 'f' || gender == 'F'?
					 	(weight >= 110 && weight <= 185?
					 	true : false ): -999);

			//PROCESSING - Statement that determines if they are accepted
			//			   or tells them the requirement that they did not
			//	 			meet
			cout << endl << endl << "This candidate has been";

			if(heightOk == true && weightOk == true)
			{
				cout << " ACCEPTED!" << endl << endl << endl << endl;
				accepted = accepted + 1;
				totalCand = totalCand + 1;
			}
			else if(heightOk == true && weightOk == false)
			{
				cout << " rejected based on the WEIGHT requirement.";
				cout << endl << endl << endl << endl;
				totalCand = totalCand + 1;
			}
			else if(heightOk == false && weightOk == true)
			{
				cout << " rejected based on the HEIGHT requirement.";
				cout << endl << endl << endl << endl;
				totalCand = totalCand + 1;
			}
			else
			{
				cout << " rejected based on the HEIGHT and WEIGHT "
						"requirements.";
				cout << endl << endl << endl << endl;
				totalCand = totalCand + 1;
			}

			cout << "Please enter the candidates\'s information (enter "
					"\'X\' to exit)." << endl;
			do
			{

				cout << left;
				cout << setw(9) << "Gender:";
				cin.get(gender);
				cin.ignore(10000, '\n');


				if(gender != 'm' && gender != 'M' && gender !='f' &&
						gender != 'F' && gender != 'x' && gender != 'X')
				{
					cout << "***** Invalid gender; please enter M or F"
							" *****";
					cout << endl;


				}

			}while(gender != 'm' && gender != 'M' && gender !='f' &&
					gender != 'F' && gender != 'x' && gender != 'X');

		}
		//OUTPUT - outputs the average and the amount of candidates that
		//			were accepted
		average = float(accepted)/float(totalCand) * 100;
		if(accepted >=1)
		{
			cout << endl << endl << accepted << " candidate(s) accepted!";
			cout << endl;
			cout << "That\'s " << setprecision(2) << average
					<< "%!";
			cout << endl;
		}

	}

	return 0;
}

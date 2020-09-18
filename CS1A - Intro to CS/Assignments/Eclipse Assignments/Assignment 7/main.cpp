/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #7: Repetition & Switch Statement
 * CLASS		: CS1A
 * SECTION		: MW 9:30a
 * DUE DATE     : 11-10-14
 *************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

/**************************************************************************
 *GPA Program
 *________________________________________________________________________
 *This program receives the user's letter grades and converts the letters
 *into the correct grade points, then has a running sum of the total grade
 *points and then calculates the grade point average. This program is
 *designed to run 3 times
 *	______________________________________________________________________
 *	INPUT:
 *		grade	  	   : The user's letter grade.
 *		testNumber     : The amount of times the loop will be running
 *
 *	OUTPUT:
 *		totalGP		   : User's total Grade Points
 *		gradePA         : User's Grade Point Average

 *************************************************************************/

int main()
{
	//This is the header that will display in the output

	const char PROGRAMMER[30]	= "BBC";
	const char CLASS[5]			= "CS1A";
	const char SECTION[25]		= "MW: 9:30AM";
	const char ASSIGNMENT[30]	= "Repetition & Switch Statement";

	cout << left;
	cout << "********************************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* " << setw(14) << "ASSIGNMENT #7"  << ": " << ASSIGNMENT;
	cout << "\n******************************************************\n\n";
	cout << right;


	char grade;				//INPUT -The user's letter grade
	int totalGP;			//OUTPUT-User's total Grade Points
	float gradePA;			//OUTPUT-User's Grade Point Average
	int testNumber;			//INPUT -The amount of times the loop will run
	int gradeCount;			//CALC  -Counting the number of grades entered
	float gradePoint;		//CALC  -Holds the grade value from the letter


	for(testNumber = 1; testNumber <= 3; testNumber = testNumber + 1)
	{
		//PROCESS - Setting the counters and accumulators to zero
		totalGP = 0;
		gradePA = 0;
		gradeCount = 1;
		gradePoint = 0;

		cout << left;
		cout << "TEST CASE # " << testNumber << ":" << endl;

		//INPUT - Prompts the user for their letter grade.
		cout << left << setw(21);
		cout << "\tEnter Letter Grade #" << gradeCount << ": ";
		cin >> grade;


		while(grade != 'X')
		{
			switch(grade)
			{
			case 'A':gradePoint = 4.0;
				break;
			case 'B':gradePoint = 3.0;
				break;
			case 'C':gradePoint = 2.0;
				break;
			case 'D':gradePoint = 1.0;
				break;
			case 'F':gradePoint = 0.0;
				break;
			}
			//PROCESS - Accumulating and counting the grade count
			//			and the GPA and total grade points

			gradeCount = gradeCount + 1;
			totalGP = int(totalGP + gradePoint);
			gradePA = float(totalGP) / float(gradeCount - 1);

			//INPUT - Prompts the user for their letter grade.
			cout << left << setw(21);
			cout << "\tEnter Letter Grade #" << gradeCount << ": ";
			cin >> grade;
		}
		//OUTPUT - This will output the average and total grade points
		if(totalGP >= 1)
		{
			cout << left << setw(20);
			cout << endl << "Total Grade Points:" << totalGP << endl;

			cout << left << setw(5);
			cout << "GPA:" << setprecision(2) << fixed << gradePA;
			cout << endl << endl << endl;
		}


	}
	return 0;
}

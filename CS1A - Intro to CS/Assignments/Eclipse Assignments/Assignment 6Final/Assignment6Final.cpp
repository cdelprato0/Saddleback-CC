/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #6: Nested If - Then - Else Statements
 * CLASS		: CS1A
 * SECTION		: MW 9:30a
 * DUE DATE     : 10-29-2014
 *************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**************************************************************************
 *Largest value determiner
 *________________________________________________________________________
 *This program takes three different values and outputs the largest value
 *out of the three
 *	______________________________________________________________________
 *	INPUT:
 *		firstValue	: First number entered
 *		secondValue : Second number entered
 *		thirdValue  : Third number entered
 *
 *	OUTPUT:
 *	Will display which value was the largest and the value number
 *
 *************************************************************************/

int main()
{
	//This is the header that will display in the output

	const char PROGRAMMER[30]	= "BBC";
	const char CLASS[5]			= "CS1A";
	const char SECTION[25]		= "MW: 9:30AM";
	const char ASSIGNMENT[41]	= "Nested If - Then - Else Statements";

	cout << left;
	cout << "********************************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* " << setw(14) << "ASSIGNMENT #6"  << ": " << ASSIGNMENT;
	cout << "\n******************************************************\n\n";
	cout << right;


	float firstValue;
	float secondValue;
	float thirdValue;



	//INPUT - reads in three inputs from the user (The first, second, and
	// 		  third values)
	cout << left;
	cout << setw(9) << "Value 1:";
	cin  >> firstValue;

	cout << setw(9) << "Value 2:";
	cin  >> secondValue;

	cout << setw(9) << "Value 3:";
	cin  >> thirdValue;
	cout << endl;
	cout << right;


	/*********************************************************************
	 * PROCESSING & OUTPUT - Determines if a value is greater than another
	 * 						 value using nested if-then-else statements.
	 * 						 Once largest value is determined it will
	 * 						 display which value was the largest and the
	 * 						 value number
	 ********************************************************************/

	if(firstValue > secondValue)     //CALC - Primary If statement
	{
		if(firstValue > thirdValue)  //CALC - Secondary if statement
		{
			cout << left;
			cout << setw(36) << setprecision(2) << fixed;
			cout << "The largest value is the 1st value:";
			cout << firstValue;
			cout << endl << endl << endl;
		}
		else						 //CALC - Secondary if statement
		{
			cout << left;
			cout << setw(36) << setprecision(2) << fixed;
			cout << "The largest value is the 3rd value:";
			cout << thirdValue;
			cout << endl << endl << endl;
		}
	}
	else							 //CALC - Primary If statement
	{
		if(secondValue > thirdValue) //CALC - Secondary if statement
		{
			cout << left;
			cout << setw(36) << setprecision(2) << fixed;
			cout << "The largest value is the 2nd value:";
			cout << secondValue;
			cout << endl << endl << endl;
		}
		else						 //CALC - Secondary if statement
		{
			cout << left;
			cout << setw(36) << setprecision(2) << fixed;
			cout << "The largest value is the 3rd value:";
			cout << thirdValue;
			cout << endl << endl << endl;
		}
	}

	return 0;
}


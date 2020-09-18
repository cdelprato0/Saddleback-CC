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
 *New Salary Program
 *________________________________________________________________________
 *This program receives the user's current salary, and is able to program
 *the new salary, monthly salary, and retroactive pay if there were to be
 *a pay increase on their salary.
 *	______________________________________________________________________
 *	INPUT:
 *		name	  	   : The user's name.
 *		currentSal     : The current salary of the user
 *		payInc		   : The pay increase on the current salary
 *
 *	OUTPUT:
 *		name		   : User's Name
 *		newSal         : New salary after pay increase
 *		monthlySal     : New monthly salary after pay increase
 *		retroactivePay : The difference between the new and old salary
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



	//INPUT - reads in three inputs from the user (name, current salary,
	//		  and the pay increase)
	cout << left;
	cout << setw(9) << "Value 1:";
	cin  >> firstValue;
	cout << endl;

	cout << setw(9) << "Value 2:";
	cin  >> secondValue;
	cout << endl;

	cout << setw(9) << "Value 3:";
	cin  >> thirdValue;
	cout << endl;
	cout << right;


	//PROCESSING - Calculates the total percent increase, the new salary,
	// 			   monthly salary, and the retroactive pay.
	if(firstValue > secondValue)
	{
		if(firstValue > thirdValue)
		{
			cout << left;
			cout << setw(36) << "The largest value is the 1st value: ";
			cout << firstValue;
		}
		else
		{
			cout << setw(36) << "The largest value is the 3rd value: ";
			cout << thirdValue;
		}
	}
	else
	{
		if(secondValue > thirdValue)
		{
			cout << setw(36) << "The largest value is the 2nd value: ";
			cout << secondValue;
		}
		else
		{
			cout << setw(36) << "The largest value is the 3rd value: ";
			cout << thirdValue;
		}
	}



	//OUTPUT - Outputs the inputs and new salary, monthly salary,
	//         and retroactive pay and set to different precisions and
	//  	   fixed positions


	return 0;
}


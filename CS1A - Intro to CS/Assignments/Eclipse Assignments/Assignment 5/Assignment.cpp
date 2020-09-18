/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #5: New Salary
 * CLASS		: CS1A
 * SECTION		: MW 9:30a
 * DUE DATE     : 10-20-2014
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
	const char ASSIGNMENT[30]	= "Input & Output - New Salary";

	cout << left;
	cout << "********************************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* " << setw(14) << "ASSIGNMENT #5"  << ": " << ASSIGNMENT;
	cout << "\n******************************************************\n\n";
	cout << right;


	char  name[25];
	float currentSal;
	float payInc;
	float totalPercentInc;
	float newSal;
	float monthlySal;
	float retroactivePay;


	//INPUT - reads in three inputs from the user (name, current salary,
	//		  and the pay increase)
	cout << left << setw(29);
	cout << "What is your name?";
	cin.getline(name, 25);

	cout << setw(29);
	cout << "What is your current salary?";
	cin  >> currentSal;

	cout << setw(29);
	cout << "What is your pay increase?";
	cin  >> payInc;
	cout << endl;


	//PROCESSING - Calculates the total percent increase, the new salary,
	// 			   monthly salary, and the retroactive pay.
	totalPercentInc = payInc * currentSal	;
	newSal          = currentSal + totalPercentInc;
	monthlySal      = newSal / 12;
	retroactivePay  = (newSal - currentSal) / 2.0;


	//OUTPUT - Outputs the inputs and new salary, monthly salary,
	//         and retroactive pay and set to different precisions and
	//  	   fixed positions
	cout << name << "'s SALARY INFORMATION" << endl;
	cout << setw(10) << right << "New Salary" << setw(19);
	cout << "Monthly Salary" << setw(20) << "Retroactive Pay" << endl;
	cout << setw(10) << setprecision(2) << fixed << newSal << setw(19);
	cout << monthlySal << setw(20) << retroactivePay;
	cout << endl << endl << endl;

	return 0;
}

/**************************************************************************
 * AUTHORS      : Jebus & BBC
 * STUDENT IDs  : & 382108
 * LAB #14      : Pocket Money
 * CLASS		: CS1A
 * SECTION		: MW 9:30a
 * DUE DATE     : 10-20-2014
 *************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**************************************************************************
 *Pocket Money Program
 *________________________________________________________________________
 *This program receives the pocket money left over from the previous week
 *	and the amount spent in the current week from the user and calculates
 *	how much pocket money is remaining. Each week the user is allocated
 *	$20.00
 *	______________________________________________________________________
 *	INPUT:
 *		name	  	: The user's name.
 *		amtLeftover : Amount leftover from the previous week.
 *		spent		: Amount spent this week.
 *
 *	OUTPUT:
 *		name		: User's Name
 *		pocketMoney : Amount of pocket money remaining
 *************************************************************************/

int main()
{
	//This is the header that will display in the output

	const char PROGRAMMER[30]	= "Jebus & BBC";
	const char CLASS[5]			= "CS1A";
	const char SECTION[25]		= "MW: 9:30AM";
	const int  LAB_NUM			= 14;
	const char LAB_NAME[28]		= "Pocket Money "
			"";

	cout << left;
	cout << "***********************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* LAB#" << setw(10) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n***********************************\n\n";
	cout << right;


	char name[25];
	float amtLeftover;
	float spent;
	float pocketMoney;
	float allowance = 20.00;


	//INPUT - reads in two inputs from the user (height & base)
	cout << left << setw(33);
	cout << "What is your name?";
	cin.getline(name, 25);

	cout << setw(33);
	cout << "How much is left from last week?";
	cin  >> amtLeftover;

	cout << setw(33);
	cout << "How much have you spent?";
	cin  >> spent;
	cout << endl << endl <<endl;


	//PROCESSING - Calculates the area of triangles
	pocketMoney = (allowance + amtLeftover) - spent;


	//OUTPUT - Outputs the inputs and the Area and set this the numbers
	//		   to different precisions, fixed positions, or showpoints.
	cout << "Hello " << name << "!" << endl;
	cout << "You have $ " << showpoint << setprecision(3) << pocketMoney;
	cout << " left.";
	cout << endl << endl << endl;



	return 0;

}


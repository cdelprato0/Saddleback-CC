/**************************************************************************
 * AUTHOR	  :BBC
 * STUDENT ID :382108
 * LAB #1	  :ECLIPSE
 * CLASS	  :CS1B
 * SECTION	  :M/W 8:30
 * DUE DATE	  :01-26-2015
 *************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

//	Documentation that goes here will be discussed later
int main()
{
	/**********************************************************************
	 * CONSTANTS
	 * --------------------------------------------------------------------
	 * USED FOR CLASS HEADING - ALL WILL BE OUTPUT
	 * --------------------------------------------------------------------
	 * PROGRAMMER : Programmer's Name
	 * CLASS      : Student's Course
	 * SECTION    : Class Days and Times
	 * LAB_NUM    : Lab Number (specific to this lab
	 * LAB_NAME   : Title of the Lab
	 *********************************************************************/
	const char PROGRAMMER[30] = "BBC";
	const char CLASS[5]		 = "CS1B";
	const char SECTION[25]   = "MW : 8:30 - 11:20";
	const int  LAB_NUM		 = 1;
	const char LAB_NAME[17]  = "Eclipse";
	const int  NAME_WIDTH     = 30;

	char gender;
	char name[NAME_WIDTH];
	int age;

	// OUTPUT - Class Heading and notes exercise
	cout << left;
	cout << "*****************************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n*****************************************************\n\n";
	cout << right;

	// INPUT - User will enter their gender, name and age.
	cout << left;
	cout << "Enter your gender: ";
	cin.get(gender);
	cin.ignore(1000,'\n');

	cout << endl << setw(19) << "Enter your name: ";
	cin.getline(name, NAME_WIDTH);

	cout << endl << setw(19) << "Enter your age: ";
	cin >> age;
	cin.ignore(1000, '\n');

	return 0;

}

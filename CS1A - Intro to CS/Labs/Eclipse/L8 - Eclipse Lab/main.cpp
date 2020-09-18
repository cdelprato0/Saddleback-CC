/*
 * main.cpp
 *
 *  Created on: Oct 1, 2014
 *      Author: cdelprato0
 */
/************************************************************************
 * AUTHOR	  : Chaz Del Prato
 * STUDENT ID : 382108
 * LAB #8     : Eclipse Lab
 * CLASS      : CS1A
 * SECTION    : MW: 9:30am
 * DUE DATE   : 10/01/14
 ************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**************************************************************************
 * ECLIPSE TUTORIAL
 * ________________________________________________________________________
 * This program will output the class heading
 * ________________________________________________________________________
 * INPUT:
 * 	<There is no input for this program - output data is obtained through
 * 	the constants.>
 *
 * 	OUTPUT:
 * 	<This program will output a class heading>
 ************************************************************************/
 int main()
 {
	 /********************************************************************
	  * CONSTANTS
	  * -------------------------------------------------------------------
	  * USED FOR CLASS HEADING - ALL WILL BE OUTPUT
	  * -------------------------------------------------------------------
	  * PROGRAMMER : Programmer's Name
	  * CLASS      : Student's Course
	  * SECTION    : Class Days and Times
	  * LAB_NUM    : Lab Number (specific to this lab)
	  * LAB_NAME   : Title of the Lab
	  *******************************************************************/
	 const char PROGRAMMER[30]  = "Chaz Del Prato";
	 const char CLASS[5]       = "CS1A";
	 const char SECTION[25]    = "MW: 9:30a - 11:20a";
	 const int  LAB_NUM        = 8;
	 const char LAB_NAME[17]   = "Eclipse Tutorial";

	 //variable declarations go here

	 //OUTPUT - Class Heading
	 cout << left;
	 cout << "***********************************************************";
	 cout << "\n*  PROGRAMMED BY : " << PROGRAMMER;
	 cout << "\n*  " << setw(14) << "CLASS" << ": " << CLASS;
	 cout << "\n*  " << setw(14) << "SECTION" << ": " << SECTION;
	 cout << "\n*  LAB #" << setw(9) << LAB_NUM << ": " <<LAB_NAME;
	 cout << "\n**************************************************\n\n";
	 cout << right;

	 //INPUT - describe input here

	 //PROCESSING - describe processing here

	 //OUTPUT - describe input here

	 return 0;
 }




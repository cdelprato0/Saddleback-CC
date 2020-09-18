/*******************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #7:CS1C Overloading
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *******************************************************************************/
#include "Employee.h"
#include "Programmer.h"
#include "Header.h"

/*******************************************************************************
 * CS1C Overloading
 * _____________________________________________________________________________
 * This program will have 5 different test cases. The first test case uses a
 * friend function to check to see if an Employee's phone number is equal to a
 * Programmer's number. The second test case uses the OVERLOADED == operator to
 * check if two Employee's phone numbers are the same. The Third test uses
 * an added method to the Employee class that adds a number of years to a given
 * age. The fourth test uses the OVERLOADED + operator to add a given number of
 * years to the given age. The last test uses the OVERLOADED << operator to
 * output all the Employee's given information.
 *******************************************************************************/
int main()
{
	//The four variables that will keep the information stored for an Employee
	//Class
	Employee emp1;
	Employee emp2;
	Employee emp3;
	Employee emp4;

	//The Two variables are used to store the given information for a Programmer
	//class
	Programmer pro1;
	Programmer pro2;

	//This function will output to the console a header similar to the header at
	//the top of this program
	PrintHeader("Chaz Del Prato", "CS1C Overloading", "CS1C", 'A', 7);

	//Calls the Employee's class NON-Default Constructor to set the given
	//Variables into the private data of the class
	emp1 = Employee("Jimmy Fallon", 12345, 9495551234, 40, 'M', "Comedian", 100000);
	emp2 = Employee("Stephan Colbert", 12346, 3105555555, 51, 'M', "Comedian", 70123);
	emp3 = Employee("James Corden", 87654, 7037031234, 37, 'M', "Talk Show Host", 900000);
	emp4 = Employee("Katie Couric", 77777, 2035556789, 58, 'F', "News Reporter", 500500);

	//These use the Date NON-Default Constructor to save the hired date in to the
	//private data of the class so it can be called by the output functions
	emp1.SetDate(8, 31, 2014);
	emp2.SetDate(5, 8, 2015);
	emp3.SetDate(12, 25, 2014);
	emp4.SetDate(3, 1, 2005);

	//Calls the Programmer's class NON-Default Constructor to set the given
	//Variables into the private data of the class
	pro1 = Programmer("Sam Software", 54321, 8191234567, 21, 'M', "Programmer",
			223000, 5432122, "Joe Boss", 4.0, "Yes", "No");
	pro2 = Programmer("Mary Coder", 65432, 3105555555, 28, 'F', "Programmer",
				770123, 6543222, "Mary Leader", 7, "Yes", "Yes");

	//These use the Date NON-Default Constructor to save the hired date in to the
	//private data of the class so it can be called by the output functions
	pro1.SetDate(12, 24, 2011);
	pro2.SetDate(2, 8, 2010);

	/******************************************
	 * TESTING Employee to Programmer numbers *
	 ******************************************/
	cout << "*TEST 1*\n"
		 << "Checking to see if phone numbers are equal...\n"
		 << "---------------------------------------------\n"
		 << "Checking: " << emp1.GetName() << "\'s phone number: " << emp1.GetPhoneNumber()
		 << "\nChecking: " <<  pro1.GetName() << "\'s phone number: " << pro1.GetPhoneNumber()
		 << endl << endl;

	if(emp1 == pro1)
	{
		cout << "The phone numbers are the SAME!\n\n\n";
	}
	else
	{
		cout << "The phone numbers are NOT the same!\n\n\n";
	}

	/****************************************
	 * TESTING Employee to Employee numbers *
	 ****************************************/
	cout << "**TEST 2**\n"
		 << "Checking to see if phone numbers are equal...\n"
		 << "---------------------------------------------\n"
		 << "Checking: " << emp2.GetName() << "\'s phone number: " << emp2.GetPhoneNumber()
		 << "\nChecking: " <<  emp3.GetName() << "\'s phone number: " << emp3.GetPhoneNumber()
		 << endl << endl;

	if(emp2 == emp3)
	{
		cout << "The phone numbers are the SAME!\n\n\n";
	}
	else
	{
		cout << "The phone numbers are NOT the same!\n\n\n";
	}

	/*******************************
	 * TESTING Adding years to age *
	 *******************************/
	cout << "***TEST 3***\n"
		 << "Adding years to an Employee\'s Age...\n"
		 << "-------------------------------------\n"
		 << "This is " << emp1.GetName() << "\'s age before adding the years: "
		 << emp1.GetAge() << endl;

	emp1.AddAge(12);

	cout << emp1.GetName() << "\'s Age after adding years: " << emp1.GetAge()
		 << endl << endl << endl;

	/*********************************************************
	 * TESTING Adding years to age with OVERLOADED + operator*
	 *********************************************************/
	cout << "****TEST 4****\n"
		 << "Adding years to an Employee\'s Age using Overloaded + operator...\n"
		 << "-----------------------------------------------------------------\n"
		 << "This is " << emp2.GetName() << "\'s age before adding the years: "
		 << emp2.GetAge() << endl;

	cout << "13 years are being added to " << emp2.GetName() << "\'s age.\n\n";
	emp2 = emp2 + 13;

	cout << "Their Age after adding years: " << emp2.GetAge()
		 << endl << endl << endl;

	/*********************************
	 * TESTING OVERLOADED << operator*
	 *********************************/
	cout << "*****TEST 5*****\n"
		 << "Outputting information with OVERLOADED << operator...\n"
		 << "-----------------------------------------------------\n"
		 << emp3;
	return 0;
}

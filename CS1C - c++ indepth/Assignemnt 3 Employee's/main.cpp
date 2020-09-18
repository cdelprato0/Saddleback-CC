/*******************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #3:CS1C Corporation
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *******************************************************************************/
#include "Employee.h"
#include "Programmer.h"
#include "SWArchitect.h"
#include "Header.h"

/*******************************************************************************
 * CS1C Corporation
 * _____________________________________________________________________________
 * This program will use multiple classes to show the use of Inheritance.
 * The program will be able to take in information regarding an Employee and set
 * all the specific variables to the classes so that the can be outputted to a
 * Custom chart. The program can take a Programmer Class, which is derived from
 * the Employee Class, and create a Programmer Employee and will be able to set
 * and output all the given variables. The program will also be able to create a
 * Software Architect that is derived class from Employee, and will be able to
 * set and output information that has been given about them.
 * All output is shown in the console.
 *
 * _____________________________________________________________________________
 * INPUTS -
 * 		<none>  Users are set with Non-default Constructors
 * OUTPUTS -
 * 	 Outputs to the console in a custom chart
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

	//The Two variables are used to store the given information for a Software
	//Architect class
	SWArchitect swArch1;
	SWArchitect swArch2;

	//This function will output to the console a header similar to the header at
	//the top of this program
	PrintHeader("Chaz Del Prato", "CS1C Corporation", "CS1C", 'A', 3);

	/***************************
	 *   EMPLOYEE CLASS TEST   *
	 ***************************/
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

	//OUTPUT- Uses the output function to output a chart header that will be
	//			placed above the given information
	cout << "EMPLOYEE'S INFORMATION...\n";
	PrintOutputHeader();

	//This will call a method in the Employee class that will output all of the
	//saved given information from the private members inside the Employee class
	emp1.DisplayInfo();
	emp2.DisplayInfo();
	emp3.DisplayInfo();
	emp4.DisplayInfo();


	/***************************
	 *  PROGRAMMER CLASS TEST  *
	 ***************************/
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

	//OUTPUT- Uses the output function to output a chart header that will be
	//			placed above the given information
	cout << endl << endl
		 << "PROGRAMMER'S INFORMATION...\n";
	PrintOutputHeader();

	//This will call a method in the Employee class that will output all of the
	//saved given information from the private members inside the Employee class
	pro1.DisplayInfo();
	pro2.DisplayInfo();

	//This function will output a custom Programmer chart header that will be
	//placed above the given information
	PrintProgrammerHeader();

	//Calls a method in the Programmer class so that it can output the saved
	//information from the private members of the class
	pro1.DisplayProgrammer();
	pro2.DisplayProgrammer();


	/***************************
	 *  SWARCHITECT CLASS TEST *
	 ***************************/
	//Calls the SWArchitect class NON-Default Constructor to set the given
	//Variables into the private data of the class
	swArch1 = SWArchitect("Alex Arch", 88888, 8191234444, 31, 'M', "Architect",
				323000, 5434222, "Big Boss", 5, 4);
	swArch2 = SWArchitect("Sally Designer", 87878, 3105558888, 38, 'F', "Architect",
				870123, 6543422, "Big Boss", 8, 11);

	//These use the Date NON-Default Constructor to save the hired date in to the
	//private data of the class so it can be called by the output functions
	swArch1.SetDate(12, 24, 2009);
	swArch2.SetDate(2, 8, 2003);

	//OUTPUT- Uses the output function to output a chart header that will be
	//			placed above the given information
	cout << endl << endl
		 << "ARCHITECT'S INFORMATION...\n";
	PrintOutputHeader();

	//This will call a method in the Employee class that will output all of the
	//saved given information from the private members inside the Employee class
	swArch1.DisplayInfo();
	swArch2.DisplayInfo();

	//This function will output a custom SWArchitect chart header that will be
	//placed above the given information
	PrintSWArchitectHeader();

	//Calls a method in the SWArchitect class so that it can output the saved
	//information from the private members of the class
	swArch1.DisplaySWArchitect();
	swArch2.DisplaySWArchitect();

	return 0;
}//END OF PROGRAM

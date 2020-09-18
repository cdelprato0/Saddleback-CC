/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #3:CS1C Corporation
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#include "Header.h"

/*******************************************************************************
 * FUNCTION PrintHeader
 * _____________________________________________________________________________
 * This function receives coder's name, the assignment name, the coder's
 * class, the assignment type, and the assignment number.
 *   - returns nothing.
 *______________________________________________________________________________
 * PRE-CONDITIONS:
 *   codeName : the code name of the programmer must be previously defined
 *   asName   : the name of the assignment must be previously defined
 *   studId   : the programmer's student ID must be previously defined
 *   asType   : the type of assignment must be previously defined
 *   asNum    : the assignment number must be previously defined
 * _____________________________________________________________________________
 * POST-CONDITIONS:
 *   This function will output the class header
 *******************************************************************************/

//All parameters will be passed by value into the function
void PrintHeader(string codeName,   // IN - the programmer's code name
                 string asName,     // IN - the assignment name
                 string classF,     // IN - the programmer's class
                 char   asType,     // IN - the assignment type
                                    //      (LAB or ASSIGNMENT)
                 int    asNum)      // IN - the assignment number

{
    cout << left;
    cout << "**************************************************\n";
    cout << "* PROGRAMMED BY : " 				  << codeName    << endl;
    cout << "* " << setw(14) << "CLASS"   << ": " << classF      << endl;
    cout << "* " << setw(14) << "SECTION" << ": MW 2:00p-4:50p" << endl;
    cout << "*";

    if(toupper(asType) == 'L')
    {
        cout << " LAB #" << setw(9);
    }//END IF
    else
    {
        cout << " ASSIGNMENT #" << setw(2);
    }//END ELSE

    cout << asNum << ": " << asName;
    cout << "\n**************************************************\n\n";
    cout << right;
}//END OF FUNCTION

/*******************************************************************************
 * PrintOutputHeader Function
 * _____________________________________________________________________________
 * This function will output to the console a generic header prompt that will
 * be used to create a custom chart listing all of the employee's information
 * _____________________________________________________________________________
 * PRECONDITIONS
 *   <none>
 * POSTCONDITIONS
 * 	 Outputs to the console
 *******************************************************************************/
void PrintOutputHeader()
{
	//Manipulates the output to have a star box
	cout << left
		 << setfill('*') << setw(107) << '*' << endl
		 << setfill(' ');

	//OUTPUT - Outputs all the preset names given to match the users input
	cout << left
		 << setw(17) << "| Name" << setw(16) << "| Employee's Id" << setw(14)
		 << "| Phone" << setw(6) << "| Age" << setw(9) << "| Gender" << setw(18)
		 << "| Job Title" << setw(14) << "| Salary" << setw(16) << "| Hire Date |"
		 << endl;

	//Manipulates the output to have a star box
	cout << left
		 << setfill('*') << setw(107) << '*' << endl
		 << setfill(' ');
}//END OF FUNCTION

/*******************************************************************************
 * PrintProgrammerHeader Function
 * _____________________________________________________________________________
 * This function will output to the console a generic header prompt that will
 * be used to create a custom chart listing all of the Programmer's information
 * _____________________________________________________________________________
 * PRECONDITIONS
 *   <none>
 * POSTCONDITIONS
 * 	 Outputs to the console
 *******************************************************************************/
void PrintProgrammerHeader()
{
	//Manipulates the output to have a star box
	cout << left << endl
		 << setfill('*') << setw(92) << '*' << endl
		 << setfill(' ');

	//OUTPUT - Outputs all the preset names given to match the users input
	cout << setw(15) << "| Name" << setw(13) << "| Department" << setw(20)
		 << "| Supervisor's Name" << setw(10) << "| Raise %" << setw(16)
		 << "| C++ Knowledge" << setw(15) << "| Java Knowledge |"
		 << endl;

	//Manipulates the output to have a star box
	cout << left
		 << setfill('*') << setw(92) << '*' << endl
		 << setfill(' ');
}//END OF FUNCTION

/*******************************************************************************
 * PrintSWArchitectHeader Function
 * _____________________________________________________________________________
 * This function will output to the console a generic header prompt that will
 * be used to create a custom chart listing all of the Software Architect's
 * information
 * _____________________________________________________________________________
 * PRECONDITIONS
 *   <none>
 * POSTCONDITIONS
 * 	 Outputs to the console
 *******************************************************************************/
void PrintSWArchitectHeader()
{
	//Manipulates the output to have a star box
	cout << left << endl
		 << setfill('*') << setw(83) << '*' << endl
		 << setfill(' ');

	//OUTPUT - Outputs all the preset names given to match the users input
	cout << setw(16) << "| Name" << setw(14) << "| Department" << setw(20)
		 << "| Supervisor's Name" << setw(10) << "| Raise %" << setw(20)
		 << "| Years of Experience |"
		 << endl;

	//Manipulates the output to have a star box
	cout << left
		 << setfill('*') << setw(83) << '*' << endl
		 << setfill(' ');
}//END OF FUNCTION

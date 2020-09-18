/*******************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #7:CS1C Overloading
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *******************************************************************************/
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

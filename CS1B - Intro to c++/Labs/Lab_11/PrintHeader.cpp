/*************************************************************************
 * AUTHOR     : Zeta & BBC
 * LAB #11    : Creating an Ordered List
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/1/15
 ************************************************************************/

#include "Header.h"

/*************************************************************************
 * FUNCTION PrintHeader
 * _______________________________________________________________________
 * This function receives coder's name, the assignment name, the coder's
 * class, the assignment type, and the assignment number.
 *   - returns nothing.
 *________________________________________________________________________
 * PRE-CONDITIONS:
 *   codeName : the code name of the programmer must be previously defined
 *   asName   : the name of the assignment must be previously defined
 *   studId   : the programmer's student ID must be previously defined
 *   asType   : the type of assignment must be previously defined
 *   asNum    : the assignment number must be previously defined
 * _______________________________________________________________________
 * POST-CONDITIONS:
 *   This function will output the class header
 ************************************************************************/

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
    cout << "* " << setw(14) << "SECTION" << ": MW 8:30a-12:20p" << endl;
    cout << "*";

    if(toupper(asType) == 'L')
    {
        cout << " LAB #" << setw(9);
    }
    else
    {
        cout << " ASSIGNMENT #" << setw(2);
    }

    cout << asNum << ": " << asName;
    cout << "\n**************************************************\n\n";
    cout << right;
}

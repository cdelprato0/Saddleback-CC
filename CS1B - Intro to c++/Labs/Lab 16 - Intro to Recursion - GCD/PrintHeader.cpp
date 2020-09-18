/*************************************************************************
 * AUTHOR     : Professor X & BBC
 * LAB #16    : Intro to Recursion - GCD
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   :
 ************************************************************************/
#include "Header.h"

void PrintHeader(string codeName,   // IN - the programmer's code name
                 string asName,     // IN - the assignment name
                 string classF,     // IN - the programmer's class
                 char   asType,     // IN - the assignment type
                                    //      (LAB or ASSIGNMENT)
                 int    asNum,		// IN - the assignment number
                 ofstream &oFile)   //OUT - output file

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
{
    oFile << left;
    oFile << "**************************************************\n";
    oFile << "* PROGRAMMED BY : " 				  << codeName    << endl;
    oFile << "* " << setw(14) << "CLASS"   << ": " << classF      << endl;
    oFile << "* " << setw(14) << "SECTION" << ": MW 8:30a-12:20p" << endl;
    oFile << "*";

    if(toupper(asType) == 'L')
    {
        oFile << " LAB #" << setw(9);
    }
    else
    {
        oFile << " ASSIGNMENT #" << setw(2);
    }

    oFile << asNum << ": " << asName;
    oFile << "\n**************************************************\n\n";
    oFile << right;
}

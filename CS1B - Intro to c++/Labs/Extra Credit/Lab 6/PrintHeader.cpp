
/**************************************************************************
 * AUTHOR     : singmusic & BBC
 * LAB #6     : Structs
 * CLASS      : CS1B
 * SECTION    : MW 8:30am
 * DUE DATE   : 2/25/2015
 *************************************************************************/
#include "Header.h"
/**************************************************************************
 *
 * FUNCTION PrintHeader
 * _______________________________________________________________________
 *
 * PrintHeader
 *   This function will output the class heading predetermined by user
 *   - returns nothing - outputs class heading
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *  	<No preconditions>
 *
 * POST-CONDITIONS
 * 	   This function will output the heading for the class.
 *
 *************************************************************************/
void PrintHeader(ofstream &oFile)
{
	   oFile << left;
	   oFile << "*****************************************************\n";
	   oFile << "* Programmed by : singmusic & BBC                   *\n";
	   oFile << "* Class         : CS1B - MW 8:30a-12:20a            *\n";
	   oFile << "* Lab #6        : Structs                           *\n";
	   oFile << "*****************************************************\n\n";
	   oFile << right;

}

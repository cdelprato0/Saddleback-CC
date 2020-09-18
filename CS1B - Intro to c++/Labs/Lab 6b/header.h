/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * LAB #6b      : Enumerated Types
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 2-11-2015
 *************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

// Preprocessor directives for the program
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

//Enumerated types and typedefs go here
enum Days
{
	SUNDAY,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY
};

// Declare functions and their parameters for being called in the main
void PrintHeader(string asName, char asType, int asNum);

Days ConvertStrg2Enum(string& stringDays);

void ConvEnum2Strg(Days today);


#endif /* HEADER_H_ */

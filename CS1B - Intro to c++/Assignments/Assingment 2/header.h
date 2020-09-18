/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #2: Parallel Arrays
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 2-11-2015
 *************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

// Preprocessor directives for the program
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// Declare functions and their parameters for being called in the main
void PrintHeader(ofstream& OFile, string asName, char asType, int asNum);

void InputFunction(ifstream& InFile, string NAMES_AR[],int IDS_AR[],
		float BAL_AR[], const int AR_SIZE);

bool NameSearching(ofstream& OFile, string NAMES_AR[], const int AR_SIZE,
		string search, int IDS_AR[], float BAL_AR[], float& balance);


#endif /* HEADER_H_ */

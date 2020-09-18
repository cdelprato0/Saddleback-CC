/**************************************************************************
 * AUTHOR     : Bacon Pancakes & BBC
 * STUDENT ID : 951436 & 382108
 * LAB #5     : Array Train
 * CLASS      : CS1B
 * SECTION    : MW 8:30am
 * DUE DATE   : 2/11/2015
 *************************************************************************/
#ifndef MYHEADER_H_
#define MYHEADER_H_

// Preprocessor directives for the program
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

// Declare functions and their parameters for being called in the main
void PrintHeader();

void InitialInt(const int AR_SIZE, int intAr[]);

void InitialStrg(const int AR_SIZE, string strgAr[]);

void ReadInputFile(const int AR_SIZE, int intAr[], string strgAr[]);

int OutputOldest(const int AR_LIST, const int INT_AR[]);

int NumInstance(const int AR_LIST, const int INT_AR[], int searchItem);

int SearchString(const int AR_LIST, const string STRING_AR[],
				 string searchString);

void OutputTable(const int AR_SIZE, const int INT_AR[],
					   const string STRG_AR[]);

int	SumInts(const int AR_SIZE, const int INT_AR[]);

#endif /* MYHEADER_H_ */

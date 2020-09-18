/**************************************************************************
 * AUTHOR     : Cabbage & BBC
 * STUDENT ID : 386273 & 382108
 * LAB #7     : Binary Search
 * CLASS      : CS1B
 * SECTION    : MW 8:30am
 * DUE DATE   : 2/18/2015
 *************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

// Preprocessor directives for the program
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//PROTOTYPES
void PrintHeader();

void OutputFunction(const int intAr[],
					const int AR_SIZE);

int SequentialSearch(int intAr[],
					 const int AR_SIZE);

void InsertionSort(int intAr[],
				   const int AR_SIZE);

int BinarySearch(int intAr[],
				 const int AR_SIZE);



#endif /* HEADER_H_ */

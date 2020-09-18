/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #1:Random Number Generator
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

//Preprocessor directives for the program
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <limits>
#include <ios>
using namespace std;

enum Menu
{
	EXIT,
	SUM,
	TRIPLE,
	REVERSE,
	STORE,
	READIN,

};

//FUNCTIONS
void SumDigits(int randNum); //CALC-The random number that has been created

void TripleNumber(int randNum);//CALC-random number that has been created

void ReverseDigits(int randNum);//CALC-random number that has been created

void StoreSortAndOutputArray(int arraySize);//IN-The user's input for the array size

void InsertionSort(int numberAr[], //CALC - array that contains ints
				   int arraySize); //CALC - array size

void OutputArray(ofstream& oFile,  //OUT-Outputs to the output file
				const int numberAr[], //The array that can be outputted
				int arraySize); //CALC-The size of array

void ReadInFileAndOutput();

void GetCommand(int &commandF);//IN&CALC- user command, determines function

#endif /* HEADER_H_ */

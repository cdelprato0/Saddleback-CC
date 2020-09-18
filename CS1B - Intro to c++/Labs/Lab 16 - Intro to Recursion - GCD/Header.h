/*************************************************************************
 * AUTHOR     : Professor X & BBC
 * LAB #16    : Intro to Recursion - GCD
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   :
 ************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


void PrintHeader(string codeName,   // IN - the programmer's code name
                 string asName,     // IN - the assignment name
                 string classF,     // IN - the programmer's class
                 char   asType,     // IN - the assignment type
                                    //      (LAB or ASSIGNMENT)
                 int    asNum,      // IN - the assignment number
                 ofstream &oFile);	// OT - output file

int Euclidean(int first, 			//CALC - first integer to be divided
				int second);		//CALC - second integer to be divided

void UserInput(int &firstNumber, 	//IN - first integer value from user
				int &secondNumber);	//IN - second integer value from user

void Output(ofstream &oFile, 		//OUT  - output file
				int firstNumber, 	//IN   - first integer value from user
				int secondNumber,   //IN   - second integer value from user
				int gcd);			//CALC - Greatest common divisor


#endif /* HEADER_H_ */

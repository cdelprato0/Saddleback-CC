/*******************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #7:CS1C Overloading
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *******************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_


// Preprocessor directives for the program
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//All parameters will be passed by value into the function
void PrintHeader(string codeName,   // IN - the programmer's code name
                 string asName,     // IN - the assignment name
                 string classF,     // IN - the programmer's class
                 char   asType,     // IN - the assignment type
                                    //      (LAB or ASSIGNMENT)
                 int    asNum);      // IN - the assignment number


#endif /* HEADER_H_ */

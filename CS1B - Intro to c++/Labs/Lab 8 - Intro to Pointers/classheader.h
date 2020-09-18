#ifndef CLASSHEADER_H_
#define CLASSHEADER_H_

/*************************************************************************
 * AUTHOR	      : Heretic Furby, BBC
 * STUDENT ID     : 323630, 382108
 * Lab #8  		  : Intro to Pointers
 * CLASS	      : M-W 8:30 AM
 * SECTION	      : CS1B
 * DUE DATE	      : 04/03/2015
 *************************************************************************/

// Preprocessor directives
#include <iostream>				// Library to have input and output
#include <iomanip>				// Library to manipulate the I/O stream
using namespace std;

/**********************************************************************
 * CONSTANTS
 * --------------------------------------------------------------------
 * Set values that should not be changed throughout the whole program
 * --------------------------------------------------------------------
 * 		EXIT 		 - The value that will terminate the program when the
 * 						user is done
 * 		PROMPT_WIDTH - The setw() width for when prompting the input from
 * 						the user
 * 		RESULT_WIDTH - The setw() width for when the output is displayed
 *********************************************************************/
const int EXIT = -999;			//INPUT - User enter when they want to exit
const int PROMPT_WIDTH = 44;	//OUT	- The output manip. that sets the
								//			space for the input
const int RESULT_WIDTH = 16;	//OUT	- The output manip. that sets the
								//			space for the results

/**************************************************************************
 * This function prints the assignment/lab header to the console. The user
 * inputs the assignment name, the assignment type ('A' for Assignment or
 * 'L' for Lab) and the number for the assignment/lab. This is the first
 * function taking place after declaration statements are made in MAIN.
 * ***********************************************************************/
void PrintHeader(string asName,	//INPUT - Name of the project
				 char asType,	//INPUT - Type of project(Lab, Assignment)
				 int asNum);	//INPUT - The number for the project


#endif

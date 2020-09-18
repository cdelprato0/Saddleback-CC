/**************************************************************************
 * AUTHOR     : singmusic & BBC
 * LAB #6     : Structs
 * CLASS      : CS1B
 * SECTION    : MW 8:30am
 * DUE DATE   : 2/25/2015
 *************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

// Preprocessor directives for the program
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//Structs will be defined here
//STRUCT - MemberAccount holds the values for the user's name, id, and balance
struct MemberAccount
{
	string name;		//IN & OUT - User's name
	int id;				//IN & OUT - User's Id
	float balance;		//IN & OUT - User's balance
};

// Declare functions and their parameters for being called in the main

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
void PrintHeader(ofstream& oFile);

/**************************************************************************
 * Input Function
 * ________________________________________________________________________
 * This function, when called, will read in a set of values from a
 * specified input file into an array of structs.
 * ________________________________________________________________________
 * INPUTS -
 * 		inFile 		: Input file stream
 * 		memberAr	: Array of structs containing user info
 * 		AR_SIZE		: number of elements in the array
 *
 * 	OUTPUT -
 * 		This function does not return a value. It initializes the array
 * 		with values from an input file.
 *************************************************************************/
void InputFunction(ifstream& inFile,		 //IN - input file stream var.
				   MemberAccount memberAr[], //OUT- array of structs
				   const int AR_SIZE) ;		 //IN - size of array

/**************************************************************************
 * Search Array
 * ________________________________________________________________________
 * This function, when called, will check each element of the provided
 * array for a match with the search item entered. When found, the search
 * terminates and the index value of the match is returned.
 * ________________________________________________________________________
 *  * INPUTS -
 * 		inFile 		: Input file stream
 * 		memberAr	: Array of structs containing user info
 * 		AR_SIZE		: number of elements in the array
 * 		searchItem	: string search item -> from calling function
 * 		totBal      : total running balance of people found
 *
 * 	OUTPUT -
 *		balance - Will keep a running total sum of the balances due on the
 *			      people that were found
 *		index - will return the index number of the element in which
 *				person was found
 *************************************************************************/
int SearchArray(ofstream& oFile,			    //IN - input stream variable
				const MemberAccount memberAr[],	//IN - array of structs
				const int AR_SIZE,				//IN - size of array
				const string searchItem,		//IN - string search key
				float& totBal);					//IN&OUT - running total
												//         of balance due

#endif /* HEADER_H_ */

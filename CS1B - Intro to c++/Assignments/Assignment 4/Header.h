/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #4: Movie List
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 03-09-15
 *************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

// Preprocessor directives for the program
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//STRUCTS
struct MovieDetails{
	string title;		//IN - Holds the name of the movie
	string leadingAct;	//IN - Holds the name for the leading actor/actress
	string supportAct;	//IN - Holds the name for the supporting actor/actress
	string genre;		//IN - Holds the description of the genre
	string altGenre;	//IN - Holds the description of the other genre
	int year;			//IN - Holds the year the movie was made
	int rating;			//IN - Holds the ratings the movie got
	string synopsis;	//IN - Holds a summary of the movie
};

struct MovieNode{
	MovieDetails info;	//PROC - Refers to the MovieDetails Struct
	MovieNode *next;	//PROC - the pointer connects nodes on linked list
};

struct MovieLinkedList{
	MovieNode *head;	//IN   - The top of the linked list
	int size;			//PROC - The number of how many movies is in the
						//		 input file
};

// Declare functions and their parameters for being called in the main or
// Function.
void PrintHeader(ofstream& OFile,       // OUT- Outputs to a file
					string asName,      // IN - the assignment name
					char asType,  	    // IN - the assignment type
                             	        //      (LAB or ASSIGNMENT)
					int asNum);         // IN - the assignment number

void WordWrap(ofstream& oFile,          // OUT- Outputs to a file
				MovieNode *currentNode);// IN - the current node

void WordWrapTitle(ofstream& oFile, 		 // OUT- Outputs to a file
					MovieNode *currentNode); // IN - the current node

void CreateMovieList(ifstream& inFile,  // IN - the input file
					MovieNode *head);   // IN - The top of the linked list

void OutputMovieList(ofstream& oFile,   // OUT- Outputs to a file
					MovieNode *head);   // IN - The top of the linked list



#endif /* HEADER_H_ */





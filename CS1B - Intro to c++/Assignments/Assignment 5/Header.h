/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #5:Searching Linked Lists
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 4-1-2015
 *************************************************************************/

#ifndef HEADER_H_
#define HEADER_H_

// Preprocessor directives for the program
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <limits>
#include <ios>
using namespace std;

enum Menu
{
	EXIT,
	LIST,
	TITLESEARCH,
	GENRESEARCH,
	ACTORSEARCH,
	YEARSEARCH,
	RATINGSEARCH,
};

struct MovieDetails
{
	string title;		//IN - Holds the name of the movie
	string leadingAct;	//IN - Holds the name for the leading actor/actress
	string supportAct;	//IN - Holds the name for the supporting actor/actress
	string genre;		//IN - Holds the description of the genre
	string altGenre;	//IN - Holds the description of the other genre
	int year;			//IN - Holds the year the movie was made
	int rating;			//IN - Holds the ratings the movie got
	string synopsis;	//IN - Holds a summary of the movie
};

struct MovieNode
{
	MovieDetails info;	//PROC - Refers to the MovieDetails Struct
	MovieNode *next;	//PROC - the pointer connects nodes on linked list
};

struct MovieLinkedList
{
		//IN   - The top of the linked list
	int size;			//PROC - The number of how many movies is in the
						//		 input file
};


void InOutFiles(string& defaultIn, 	//PROC&IN - user input for files
				string& defaultOut);//PROC&IN - user input for files

void PrintHeader(ofstream& oFile,
		         string codeName,   // IN - the programmer's code name
                 string asName,     // IN - the assignment name
                 string classF,     // IN - the programmer's class
                 char   asType,     // IN - the assignment type
                                    //      (LAB or ASSIGNMENT)
                 int    asNum);     // IN - the assignment number

MovieNode* CreateNode(ifstream& inFile, //IN - using contents of input file
					MovieDetails info);	//PROC - data to be entered into node

MovieNode* CreateMovieList(ifstream& inFile,  //IN - using contents of input file
							MovieNode *&head);//PROC - head of linked list

void GetCommand(int &commandF);	//IN&PROC - user command, determines function

void DisplayMenu();

void WordWrap(ofstream& oFile, 			//OUT - outputs to output file
				MovieNode *currentNode);//PROC - pointer to current node

void OutputList(ofstream& oFile, //OUT - outputs to output file
				MovieNode *head);//PROC - head of linked list

void OutputCurrentNode(ofstream& oFile, 		//OUT - outputs to output file
						MovieNode* currentNode, //PROC - pointer to current node
						int instances);			//PROC - # of searched nodes

void OutputTitle(ofstream& oFile,//OUT - outputs to output file
				MovieNode *head);//PROC - head of linked list

bool SearchFunction(ofstream& oFile, //OUT - outputs to output file
					MovieNode *head, //PROC - head of linked list
					string key, 	 //IN - user search key
					int intKey, 	 //IN - user search key
					int command, 	//IN&PROC - user command, determines function
					int& instances);//PROC - # of searched nodes

void TitleSearch(ofstream& oFile, 	 //OUT - outputs to output file
					MovieNode* head, //PROC - head of linked list
					int command);    //IN&PROC - user command, determines function

void GenreSearch(ofstream& oFile, 	 //OUT - outputs to output file
				MovieNode* head, //PROC - head of linked list
				int command);    //IN&PROC - user command, determines function

void ActorSearch(ofstream& oFile, 	 //OUT - outputs to output file
				MovieNode* head, //PROC - head of linked list
				int command);    //IN&PROC - user command, determines function

void YearSearch(ofstream& oFile, 	 //OUT - outputs to output file
				MovieNode* head, //PROC - head of linked list
				int command);    //IN&PROC - user command, determines function

void RatingSearch(ofstream& oFile, 	 //OUT - outputs to output file
				MovieNode* head, //PROC - head of linked list
				int command);    //IN&PROC - user command, determines function

#endif /* HEADER_H_ */

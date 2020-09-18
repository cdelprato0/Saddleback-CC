/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #4: Movie List
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 03-09-15
 *************************************************************************/
#include "Header.h"

/**************************************************************************
 * OutPutMovieList
 * ________________________________________________________________________
 * This function is designed to output the whole movie list. Including the
 * title, leading actor, supporting actor, genre, alternate genre, year,
 * rating , and a short summary of the plot. It will also call the Word
 * Wrapping functions to keep the text within bounds for the output. They
 * will word wrap the title and the synopsis. After there will be a clear
 * list of all the movies and all of their information.
 * _______________________________________________________________________
 * PRECONDITIONS
 *   head  : the head of the linked list must be previously defined
 *	 oFile : The output file must be opened
 * POSTCONDITIONS
 * 	 <none>
 *************************************************************************/
void OutputMovieList(ofstream& oFile, MovieNode *head)
{
	MovieDetails info;     //PROC - Stores the info from the MoiveDetails
	MovieNode *currentNode;//PROC - pointer for the linked list
	MovieLinkedList list;  //PROC - Stores the info for the MovieLinkedList

	//Initializing the size of the linked list to zero
	list.size = 0;

	//Assigning the current node to start with the head of the linked list
	currentNode = list.head;

	//PROCESSING - The loop will keep on running until the current node
	//			   find NULL at the end of the linked list.
	while(currentNode != NULL)
	{
		//PROCESSING - WIll keep count of the movies
		list.size = list.size + 1;

		oFile << setfill('*') << setw(75)  << '*' << endl << setfill(' ');
		oFile << "MOVIE #: "  << list.size << setw(16)    << "Title:  ";

		//Calls the WordWrapTitle function to slim down the title so that
		//it will fit in the boxes made for the output file.
		WordWrapTitle(oFile, currentNode);

		oFile << setfill('-') << setw(75) << '-' << endl << setfill(' ');
		oFile << "Year: " << currentNode-> info.year << setw(16) << "Rating: "
			  << currentNode-> info.rating << endl;

		oFile << left;
		oFile << setfill('-') << setw(75) << '-' << endl << setfill(' ');
		oFile << "Leading Actor:    " << setw(26)
			  << currentNode-> info.leadingAct
			  << "Genre 1: " << currentNode-> info.genre << endl;
		oFile << "Supporting Actor: " << setw(26)
			  << currentNode-> info.supportAct
			  << "Genre 2: " << currentNode-> info.altGenre << endl;

		oFile << setfill('-') << setw(75) << '-' << endl << setfill(' ');
		oFile << "PLOT:" << endl;

		//Calls the Word Wrapping function to slim down the synopsis,
		//making it easier to read in the output file
		WordWrap(oFile, currentNode);

		oFile << setfill('*') << setw(75) << '*' << endl << endl;
		oFile << right;

		//Assigning the current node to the next node to repeat the process
		currentNode = currentNode-> next;
	}
}

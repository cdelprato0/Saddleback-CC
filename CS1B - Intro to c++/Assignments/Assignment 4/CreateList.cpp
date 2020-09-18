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
 * CreateList Function
 * ________________________________________________________________________
 * This function will pass in the input file and the head of the linked
 * list. It will start creating a new node and will load all the
 * information into the nodes and then will assign the new node to the
 * head, Making it the top of the list. This function will repeat until
 * there is nothing left in the input file or if there is no new memory
 * allocated(NULL).
 * ________________________________________________________________________
 * PRECONDITIONS
 *   head   : the head of the linked list must be previously defined
 *	 inFile : The input file must be opened before
 * POSTCONDITIONS
 * 	 <none>
 *************************************************************************/
void CreateMovieList(ifstream& inFile, MovieNode *head)
{
	MovieDetails info;		//PROC - Stores the info from the MoiveDetails
	MovieNode *currentNode;	//PROC - pointer for the linked list
	MovieLinkedList list;	//PROC - Stores the info for the MovieLinkedList

	//Initializing the top of the stack to NULL
	list.head = NULL;

	//Dynamically allocating new memory for a new node
	currentNode = new MovieNode;

	//PROCESSING - Reads from an input file and loads the information into
	//				the linked list
	while(inFile && currentNode != NULL)
	{
		//PROCESSING - Reading in all the information for the node
		getline(inFile, currentNode-> info.title);
		getline(inFile, currentNode-> info.leadingAct);
		getline(inFile, currentNode-> info.supportAct);
		getline(inFile, currentNode-> info.genre);
		getline(inFile, currentNode-> info.altGenre);

		inFile >> currentNode-> info.year;
		inFile >> currentNode-> info.rating;
		inFile.ignore(1000, '\n');

		getline(inFile, currentNode-> info.synopsis);

		//Assigning the current node to head
		currentNode-> next = list.head;
		//Assigning currentNodes content to head
		list.head = currentNode;

		//Dynamically allocating new memory for a new node
		currentNode = new MovieNode;

		//Ignores the whitespace in the input file
		inFile.ignore(1000, '\n');
	}
	//Deallocates the extra newly allocated memory
	delete currentNode;

	//Assigns the pointer to NULL for safety
	currentNode = NULL;
}


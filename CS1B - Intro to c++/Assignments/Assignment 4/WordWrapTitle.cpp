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
 * Word Wrap Title Function
 * ________________________________________________________________________
 * This function will be able to word wrap a title and will be able to turn
 * it into a slimed down version with "...". This will take in the current
 * node and will determine if the string is longer than the max length
 * allowed. Then will perform the word wrap and shorten the titles
 * ________________________________________________________________________
 * PRECONDITIONS
 *   currentNode  : current node must be defined before entering
 *	 oFile        : The output file must be opened
 *
 * POSTCONDITIONS
 * 	 currentNode  : current node will return the desired word wrapped outcome
 *************************************************************************/
void WordWrapTitle(ofstream& oFile, MovieNode *currentNode)
{
	int titleSize; //PROC - assigns the size of the whole text to
				   //		a variable

	//Initializing the size of the whole title to a variable
	titleSize = currentNode-> info.title.size();

	//PROCESSING - Determine how long the title is and shortens it if the
	//			   title is more than 45 spaces
	if(titleSize > 45)
	{
		//OUTPUT - If the title is to long out puts a "..." at the end of
		//		   the shorten title
		oFile << currentNode-> info.title.substr(0, 45) << "..." << endl;
	}
	else
	{
		//OUTPUT - If the title is shorter than the max size then it will
		//		   just output the whole title.
		oFile << currentNode-> info.title << endl;
	}
}

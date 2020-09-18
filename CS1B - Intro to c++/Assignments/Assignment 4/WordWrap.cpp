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
 * Word Wrap Function
 * ________________________________________________________________________
 * This function will be able to word wrap a long line of output and will
 * be able to turn it into a more condensed section of text. This will take
 * in the current node and will determine if the string is longer than the
 * max length allowed. Then will perform the word wrap and bring every word
 * down a line when it reaches the max length.
 * ________________________________________________________________________
 * PRECONDITIONS
 *   currentNode  : current node must be defined before entering
 *	 oFile        : The output file must be opened
 *
 * POSTCONDITIONS
 * 	 currentNode  : current node will return the desired word wrapped outcome
 *************************************************************************/
void WordWrap(ofstream& oFile, MovieNode *currentNode)
{
	//CONSTANT for the maximum length allowed for each line of words
	const int MAX_LENGTH = 75; //PROC&OUT - the max length for the output line

	string theWord; 	//PROC&OUT - the word of the string that is being
						//			 looked at.
	string theLine;		//PROC&OUT - the line that is being built word by word
	int strLength;		//PROC     - assigns the size of the whole text to
						//			 a variable
	int index;			//PROC     - where the letter number is

	//Initializing the size of the whole synopsis text to a variable
	strLength = currentNode-> info.synopsis.size();

	//PROCESSING - This is where the synopsis text will be word wrapped
	//			   into a smaller more condensed text
	for(index = 0; strLength > index; index++)
	{
		//PROCESSING - Grabbing the word that is going to be added to the line
		if(currentNode-> info.synopsis[index] != ' ')
		{
			theWord = theWord + currentNode-> info.synopsis[index];
		}
		//PROCESSING - If it is equal to a space it will add it to the line
		else
		{
			theLine = theLine + theWord;
			theLine = theLine + ' ';
			theWord.clear();
		}
		//PROCESSING - Checking to see if the word wrapped line is longer
		//			   than the max length
		if((theWord.size() + theLine.size()) > MAX_LENGTH)
		{
			oFile << theLine << endl;
			theLine.clear();
		}
	}
	//OUTPUT - Prints out the last line of the synopsis
	theLine = theLine + theWord;
	oFile << theLine << endl;
	theWord.clear();

}

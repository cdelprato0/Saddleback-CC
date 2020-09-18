/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #5:Searching Linked Lists
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 4-1-2015
 *************************************************************************/
#include "Header.h"

/**************************************************************************
 * Searching Linked Lists
 * ________________________________________________________________________
 * This program will read in from a users input the default input and output
 * file. The user will be prompted by a display menu that will have different
 * search options. The user will be able to output the entire list, search
 * for a title of a movie, search for a genre, search for an actor, search
 * for a rating, and search for year. The program then will search the
 * linked list to determine if the search key matches the specific search
 * in the linked list. If the search key is found in the linked list, then
 * it will output so either in a title box or on a list which keeps count
 * of how many movies match the search key. The user may enter invalid
 * entries and the program should be able to prompt them again to fix their
 * mistakes
 * _______________________________________________________________________
 * INPUTS -
 * 		defaultIn
 * 		defaultOut
 * OUTPUTS -
 * 	 Outputs to the console and to an output file
 *************************************************************************/
int main()
{
	ifstream inFile;	//PROC - used to open the input file
	ofstream oFile;		//PROC - used to open the output file
	string defaultIn;	//IN - User response for input file name
	string defaultOut;	//IN - User response for output file name
	int command;		//IN&PROC - user command, determines function
	MovieNode *head;	//PROC - head of linked list

	//InOutFiles - Calls this function to get the default file names and
	//				to error check the user's input of them
	InOutFiles(defaultIn, defaultOut);

	//Opening the input and output files
	inFile.open(defaultIn.c_str());
	oFile.open(defaultOut.c_str());

	//PrintHeader - Prints the head to the console and to the output file
	PrintHeader(oFile, "BBC", "Movie List", "CS1B", 'A', 5);

	//DisplayMenu - Displays the menu in the console so the user has a
	//				reference for each function
	DisplayMenu();

	//GetCommand - Prompts user for their command and error checks their
	//				input and returns the users option
	GetCommand(command);

	//CreateMovieList - Creates the linked list from an input file
	head = CreateMovieList(inFile, head);

	//PROCESSING - The program will keep on running until the user enters
	//				the exit command (0)
	while(command != EXIT)
	{
		//PROCESSING - Depending on the user's input, each case has a
		//				search task for a different search option
		//				Each search will determine if there is a match to
		//				the key that has been entered. if there is a match
		//				it will start to make an output list of all the
		//				movies that meet that search
		switch(command)
		{
		//PROCESSING - Lists all the movies in the entire linked list
		case LIST        : 	cout << "Listing all movies!\n\n\n";
							oFile << "COMPLETE MOIVE LISTING\n";
							OutputList(oFile, head);
					break;

		//PROCESSING - Searching for a title within the linked list
		case TITLESEARCH : TitleSearch(oFile, head, command);
					break;

		//PROCESSING - Searching for a genre or alternate genre within the
		//				linked list
		case GENRESEARCH : GenreSearch(oFile, head, command);
					break;

		//PROCESSING - Searching for a leading actor or supporting actor within the
		//				linked list
		case ACTORSEARCH : ActorSearch(oFile, head, command);
					break;

		//PROCESSING - Searching for a year within the linked list
		case YEARSEARCH  : YearSearch(oFile, head, command);
					break;
		//PROCESSING - Searching for a rating within the linked list
		case RATINGSEARCH: RatingSearch(oFile, head, command);
					break;
		}//END-SWITCH

		//DisplayMenu - Displays the menu in the console so the user has a
		//				reference for each function
		DisplayMenu();

		//GetCommand - Prompts user for their command and error checks their
		//				input and returns the users option
		GetCommand(command);
	}//END-WHILE

	//Closes the input and output files
	inFile.close();
	oFile.close();

	return 0;
}

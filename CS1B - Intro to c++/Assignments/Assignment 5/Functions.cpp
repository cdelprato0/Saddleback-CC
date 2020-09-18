/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #5:Searching Linked Lists
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 4-1-2015
 *************************************************************************/
#include "Header.h"

/*************************************************************************
 * FUNCTION PrintHeader
 * _______________________________________________________________________
 * This function receives coder's name, the assignment name, the coder's
 * class, the assignment type, and the assignment number.
 *   - returns nothing.
 *________________________________________________________________________
 * PRE-CONDITIONS:
 *   codeName : the code name of the programmer must be previously defined
 *   asName   : the name of the assignment must be previously defined
 *   studId   : the programmer's student ID must be previously defined
 *   asType   : the type of assignment must be previously defined
 *   asNum    : the assignment number must be previously defined
 * _______________________________________________________________________
 * POST-CONDITIONS:
 *   This function will output the class header
 ************************************************************************/
void PrintHeader(ofstream& oFile, string codeName, string asName, string classF,
                 char   asType, int    asNum)

{
	//OUPUT - Outputs the header to the output file
    oFile << left;
    oFile << "**************************************************\n";
    oFile << "* PROGRAMMED BY : " 				  << codeName    << endl;
    oFile << "* " << setw(14) << "CLASS"   << ": " << classF      << endl;
    oFile << "* " << setw(14) << "SECTION" << ": MW 8:30a-12:20p" << endl;
    oFile << "*";

    if(toupper(asType) == 'L')
    {
        oFile << " LAB #" << setw(9);
    }//END - IF
    else
    {
        oFile << " ASSIGNMENT #" << setw(2);
    }//END - ELSE

    oFile << asNum << ": " << asName;
    oFile << "\n**************************************************\n\n";
    oFile << right;


    //OUPUT - Outputs the header to the console
    cout << left;
    cout << "**************************************************\n";
    cout << "* PROGRAMMED BY : " 				  << codeName    << endl;
    cout << "* " << setw(14) << "CLASS"   << ": " << classF      << endl;
    cout << "* " << setw(14) << "SECTION" << ": MW 8:30a-12:20p" << endl;
    cout << "*";

    if(toupper(asType) == 'L')
    {
    	cout << " LAB #" << setw(9);
    }//END - IF
    else
    {
    	cout << " ASSIGNMENT #" << setw(2);
    }//END - ELSE

    cout << asNum << ": " << asName;
    cout << "\n**************************************************\n\n";
    cout << right;
}


/**************************************************************************
 * CreateNode Function
 * ________________________________________________________________________
 * This function pulls data from the input file in to one single node. It
 * only creates one node at a time. The node will receive the title,
 * genres, actors, a synopsis, rating and the year. It will then return
 * the newly created node to the function that is calling it.
 * ________________________________________________________________________
 * PRECONDITIONS
 *   info   : The info must be predefined as a struct
 *	 inFile : The input file must be opened before
 * POSTCONDITIONS
 * 	 newNode: A new node for the linked list is created
 *************************************************************************/
MovieNode* CreateNode(ifstream& inFile, MovieDetails info)
{
	MovieNode *newNode;		 //PROC - pointer that stores data and returns

	//Dynamically allocating new memory for a new node
	newNode = new MovieNode;

	//PROCESSING - Loads the node with the information from the input file
	//				and sets next to NULL so that a new node can be added.
	//				Checks to see if the new memory is equal to NULL
	if(newNode != NULL)
	{
		//PROCESSING - Reading in all the information for the node
		getline(inFile, newNode-> info.title);
		getline(inFile, newNode-> info.leadingAct);
		getline(inFile, newNode-> info.supportAct);
		getline(inFile, newNode-> info.genre);
		getline(inFile, newNode-> info.altGenre);


		inFile >> newNode-> info.year;
		inFile >> newNode-> info.rating;
		inFile.ignore(1000, '\n');

		getline(inFile, newNode-> info.synopsis);

		//Assigning the nodes next to NULL so it can add a new node later
		newNode-> next = NULL;

		//Ignores the whitespace in the input file
		inFile.ignore(1000, '\n');
	}//END - IF

	return newNode;
}


/**************************************************************************
 * CreateMovieList Function
 * ________________________________________________________________________
 * This function will pass in the input file and the head of the linked
 * list. It will start creating a new node and will load all the
 * information from the CreateNode function and then will assign the new
 * node to the head, making it the top of the list. This function will
 * repeat until there is nothing left in the input file or if there is no
 * new memory allocated(NULL).
 * ________________________________________________________________________
 * PRECONDITIONS
 *   head   : the head of the linked list must be previously defined
 *	 inFile : The input file must be opened before
 * POSTCONDITIONS
 * 	 <none>
 *************************************************************************/
MovieNode* CreateMovieList(ifstream& inFile, MovieNode *&head)
{
	MovieDetails info;		//PROC - Stores the info from the MoiveDetails
	MovieNode *currentNode;	//PROC - pointer for the linked list

	//Initializing the top of the stack to NULL
	head = NULL;

	//Dynamically allocating new memory for a new node
	currentNode = new MovieNode;

	//PROCESSING - Reads from an input file and loads the information into
	//				the linked list
	while(inFile && currentNode != NULL)
	{
		//CreateNode Function - Creates a node and loads in the information
		//						from the input file and then passes it to
		//						this function to create the linked list
		currentNode = CreateNode(inFile, info);

		//Assigning the current node to head
		currentNode-> next = head;

		//Assigning currentNodes content to head
		head = currentNode;

		//Dynamically allocating new memory for a new node
		currentNode = new MovieNode;
	}//END - WHILE - LOOP

	//Deallocates the extra newly allocated memory
	delete currentNode;

	//Assigns the pointer to NULL for safety
	currentNode = NULL;

	return head;
}


/**************************************************************************
 * InOutFiles Function
 * ________________________________________________________________________
 * This function will ask the user to enter 'd' or the default input and
 * output files. If the user enters an invalid answer it will prompt again
 * for both files. It will display in the console if the user entered an
 * invaild input. Once the default files have been entered, they are
 * converted to strings so that they can open the specific files.
 * ________________________________________________________________________
 * PRECONDITIONS
 *   <none>
 * POSTCONDITIONS
 * 	 It will determine the names of the default input and output files
 *************************************************************************/
void InOutFiles(string& defaultIn, string& defaultOut)
{
	char inputFile;		//IN - The user's response for input file
	char outputFile;	//IN - The user's response for output file

	//PROCESSING - This loop will error check, if the user enters any other
	//				characters besides 'd', the loop will prompt them again
	//				until they enter 'd' for the default files.
	do
	{
		//INPUT - Prompts the user to enter 'd' for the default input file
		cout << left;
		cout << setw(65)
			 << "What input file would you like to use(type d for default file)?";
		cin.get(inputFile);
		cin.ignore(1000, '\n');

		//INPUT - Prompts the user to enter 'd' for the default output file
		cout << setw(65)
			 << "What output file would you like to use(type d for default file)?";
		cin.get(outputFile);
		cin.ignore(1000, '\n');
		cout << endl << endl;

		//PROCESSING - If the users enter and char besides 'd' it will
		//				output an invaild message
		if(inputFile != 'd' || outputFile != 'd')
		{
			//OUPUT - outputs to the console that the user entered a wrong char
			cout << "***You have not entered a correct response. \n"
					"   PLEASE use \'d\' for the default files!***\n\n\n";
		}//END - IF

	}while(inputFile != 'd' || outputFile != 'd'); //END - DO - WHILE


	if(outputFile == 'd' && inputFile == 'd')
	{
		defaultOut = "DefaultOutputFile.txt";
		defaultIn  = "bigInputFile.txt";

	}


}


/**************************************************************************
 * DisplayMenu Function
 * ________________________________________________________________________
 * This function is only used to display the menu for the user to see for
 * reference
 * ________________________________________________________________________
 *************************************************************************/
void DisplayMenu()
{
	//OUTPUT - Outputs the menu to the console
	cout << "DVD MENU OPTIONS\n\n"
		 << "1 - Output Entire List\n"
		 << "2 - Title Search\n"
		 << "3 - Genre Search\n"
		 << "4 - Actor Search\n"
		 << "5 - Year Search\n"
		 << "6 - Rating Search (0-9)\n"
		 << "0 - EXIT\n";
}


/**************************************************************************
 * GetCommand Function
 * ________________________________________________________________________
 * This function will receive the user input and error check if their
 * entry is valid. If not, the user will be prompted to enter a valid
 * response.
 * returns -> valid response
 * ________________________________________________________________________
 * PRECONDITIONS
 *   commandF : the command entered by the user must be previously defined
 * POSTCONDITIONS
 *   commandF : the command entered by the user will be returned to the
 *   			calling function
 ************************************************************************/
void GetCommand(int &commandF) // OUT - the command entered by user
{
	bool invalid;	// PROC - the invalid condition for error checking
					//		  user input

	do
	{
		// INITIALIZE - the invalid condition to false
		invalid = false;

		//INPUT - Prompts the user for an option
		cout << "Enter an option (0 to exit): ";

		// PROC - will check if the user entered a character for a variable
		//		  that must only receive a number.
		if(!(cin >> commandF))
		{
			cout << "\n**** Please input a NUMBER "
			    	"between 0 and 6 ****\n\n\n";

			// PROC - clears the fail state so program does not crash
			cin.clear();

			// PROC - clears all characters from the input buffer
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			invalid = true;
		}//END-IF
		else if (commandF < 0 || commandF > 6)
		{
			// OUT - if the command is out of bounds, the user will be
			//		 re-prompted
			cout << left;
			cout << "\n**** The number " << commandF << setw(25)
				 << " is an invalid entry" << "****"
			     << "\n**** Please input a number "
			    	"between 0 and 6 ****\n\n\n";
			cout << right;

			invalid = true;
		}//END-ELSE-IF

		// PROC - if the user enters a valid response, the input buffer
		//		  must be cleared
		if(!invalid)
		{
			cin.ignore(100,'\n');
		}//END-IF

	}while(invalid);//END-DO-WHILE

	cout << endl;
}


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
		}//END-IF

		//PROCESSING - If it is equal to a space it will add it to the line
		else
		{
			theLine = theLine + theWord;
			theLine = theLine + ' ';
			theWord.clear();
		}//END-ELSE

		//PROCESSING - Checking to see if the word wrapped line is longer
		//			   than the max length
		if((theWord.size() + theLine.size()) > MAX_LENGTH)
		{
			oFile << theLine << endl;
			theLine.clear();
		}//END-IF
	}

	//OUTPUT - Prints out the last line of the synopsis
	theLine = theLine + theWord;
	oFile << theLine << endl;
	theWord.clear();
}


/**************************************************************************
 * OutputTitle Function
 * ________________________________________________________________________
 * This function is designed to output the whole movie list. Including the
 * title, leading actor, supporting actor, genre, alternate genre, year,
 * rating , and a short summary of the plot. It will also call the Word
 * Wrapping functions to keep the text within bounds for the output. They
 * will word wrap the title and the synopsis. After there will be a clear
 * list of the movies and of their information.
 * _______________________________________________________________________
 * PRECONDITIONS
 *   currentNode  : the pointer of the linked list must be predefined
 *	 oFile        : The output file must be opened
 * POSTCONDITIONS
 * 	 <none>
 *************************************************************************/
void OutputTitle(ofstream& oFile, MovieNode *currentNode)
{
	MovieDetails info;     //PROC - Stores the info from the MoiveDetails

	//OUPUT - Outputs to the output file a box that contains all the
	//			information about a movie and uses word wrap to make
	//			everything fit nicely.
	oFile << endl << endl << endl;
	oFile << setfill('*') << setw(75)  << '*' << endl << setfill(' ');
	oFile << "Title: " << currentNode-> info.title << endl;

	oFile << right;
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

	oFile << setfill('*') << setw(75) << '*' << setfill(' ') << endl;
	oFile << right;
}


/**************************************************************************
 * OutputList Function
 * ________________________________________________________________________
 * This function is designed to ouput the entire linked list that has been
 * created from the input file. It will display the number of movies with
 * the name , year, rating , genres, and actors. All organized in categories
 * and the title and actors have a word wrap process on them so they do not
 * overlap each other.
 * _______________________________________________________________________
 * PRECONDITIONS
 *   head  : the head of the linked list must be predefined
 *	 oFile : The output file must be opened
 * POSTCONDITIONS
 * 	 <none>
 *************************************************************************/
void OutputList(ofstream& oFile, MovieNode *head)
{

	MovieDetails info;     //PROC - Stores the info from the MoiveDetails
	MovieNode *currentNode;//PROC - pointer for the linked list
	MovieLinkedList list;  //PROC - Stores the info for the MovieLinkedList

	//Assigning the pointer to head
	currentNode = head;

	//Initializing the size of the list to zero
	list.size = 0;

	//OUTPUT - Outputs to the output file the beginning of the movie chart
	oFile << "MOVIE #  TITLE" << setw(61) << "YEAR RATING  GENRE" << setw(22)
		  << "ALT GENRE" << setw(19) << "LEAD ACTOR" << setw(27)
		  << "SUPPORTING ACTOR\n";

	oFile << setfill('-') << setw(8) << ' ' << setw(49) << ' ' << setw(5)
		  << ' ' << setw(7) << ' ' << setw(18) << ' ' << setw(18) << ' '
		  << setw(20) << ' ' << setw(20) << ' ' << setfill(' ')
		  << endl;


	//PROCESSING - This loop is going to print out every node in the linked
	//				list under the specific category it belongs to
	while(currentNode != NULL)
	{
		//Counting the number of movies that have been enter in the list
		list.size = list.size + 1;

		//OUTPUT - Outputs to the output file and starts off with the size of the list
		oFile << left;
		oFile << "   " << setw(6) << list.size << setw(48);

		//PROCESSING - Word wrapping the title so that it does not overlap,
		//				if its not necessary then just outputs the title
		if(currentNode-> info.title.size() > 47)
		{
			oFile << setw(44) << currentNode-> info.title.substr(0, 44) << "... ";
		}//END-IF
		else
		{
			oFile << currentNode-> info.title;
		}//END-ELSE

		//OUTPUT - outputs the year, rating, genre, and alt genre
		oFile << currentNode-> info.year << "   " << currentNode-> info.rating
			  << "    " << setw(18) << currentNode-> info.genre << setw(18)
			  << currentNode-> info.altGenre << setw(20);

		//PROCESSING - Word wrapping the actors so that it does not overlap,
		//				if its not necessary then just outputs the actors
		if(currentNode -> info.leadingAct.size() > 18)
		{
			oFile << setw(16) << currentNode-> info.leadingAct.substr(0,16) << "... ";
		}//END-IF
		else
		{
			oFile << currentNode-> info.leadingAct;
		}//END-ELSE

		//PROCESSING - Word wrapping the actors so that it does not overlap,
		//				if its not necessary then just outputs the actors
		if(currentNode-> info.supportAct.size() > 18)
		{
			oFile << setw(16) << currentNode-> info.supportAct.substr(0,16) << "..." << endl;
		}//END-IF
		else
		{
			oFile << setw(20) << currentNode-> info.supportAct << endl;
		}//END-ELSE

		//Has the pointer point to the next node in the linked list
		currentNode = currentNode-> next;
	}//END-WHILE
}


/**************************************************************************
 * OutputCurrentNode Function
 * ________________________________________________________________________
 * This function is designed to output one movie at a time. Used with the
 * search functions to be able to output all the movies that meet the
 * output to the output file. It will also keep track of how many movies
 * have been found
 * _______________________________________________________________________
 * PRECONDITIONS
 *   currentNode  : the pointer of the linked list must be predefined
 *	 oFile        : The output file must be opened
 * POSTCONDITIONS
 * 	 <none>
 *************************************************************************/
void OutputCurrentNode(ofstream& oFile, MovieNode* currentNode, int instances)
{
	MovieDetails info;     //PROC - Stores the info from the MoiveDetails


	//OUTPUT - Outputs to the output file and starts off with the # of nodes found
	oFile << left;
	oFile << "   " << setw(6) << instances << setw(48);

	//PROCESSING - Word wrapping the title so that it does not overlap,
	//				if its not necessary then just outputs the title
	if(currentNode-> info.title.size() > 47)
	{
		oFile << setw(44) << currentNode-> info.title.substr(0, 44) << "... ";
	}//END-IF
	else
	{
		oFile << currentNode-> info.title;
	}//END-ELSE

	//OUTPUT - outputs the year, rating, genre, and alternate genre
	oFile << currentNode-> info.year << "   " << currentNode-> info.rating
		  << "    " << setw(18) << currentNode-> info.genre << setw(18)
		  << currentNode-> info.altGenre << setw(20);

	//PROCESSING - Word wrapping the actors so that it does not overlap,
	//				if its not necessary then just outputs the actors
	if(currentNode -> info.leadingAct.size() > 18)
	{
		oFile << setw(16) << currentNode-> info.leadingAct.substr(0,16) << "... ";
	}//END-IF
	else
	{
		oFile << currentNode-> info.leadingAct;
	}//END-ELSE

	//PROCESSING - Word wrapping the actors so that it does not overlap,
	//				if its not necessary then just outputs the actors
	if(currentNode-> info.supportAct.size() > 18)
	{
		oFile << setw(16) << currentNode-> info.supportAct.substr(0,16) << "..." << endl;
	}//END-IF
	else
	{
		oFile << currentNode-> info.supportAct << endl;
	}//END-ELSE
	oFile << right;
}


/**************************************************************************
 * Search Function
 * ________________________________________________________________________
 * This function will take in the head of a linked lint, a key that is a
 * string, a key that is an integer, the command the user inputed, and the
 * number of instances a search has come up. This function is designed to
 * search for a title, actor, genre, year ,and rating through a linked list
 * Once the linked list is searched, it will output all the movies that had
 * met the search requirements or for the title it will output the title
 * box. The function returns if the object had been found in the linked
 * list or not
 * _______________________________________________________________________
 * PRECONDITIONS
 *   head      : the head of the linked list must be predefined
 *	 oFile     : The output file must be opened
 *	 stringKey : must be predefined
 *	 intKey    : must be predefined
 *	 command   : must be predefined
 * POSTCONDITIONS
 * 	 instances will change and will output the into the file
 *************************************************************************/
bool SearchFunction(ofstream& oFile, MovieNode *head, string stringKey,
					int intKey, int command, int& instances)
{
	MovieDetails info;		//PROC - Stores the info from the MoiveDetails
	MovieNode *currentNode; //PROC - pointer for the linked list
	bool found;				//PROC - checks to see if found or not

	//Assigning the pointer to head and initializing found to false and
	//instances to zero
	currentNode = head;
	found = false;
	instances = 0;


	//PROCESSING - This loop will run through the whole linked list until
	//				it reaches the end of the list
	while(currentNode != NULL)
	{
		//PROCESSING - Depending on the user's input, each case has a
		//				search task for a different search option
		//				Each search will determine if there is a match to
		//				the key that has been entered. if there is a match
		//				it will start to make an output list of all the
		//				movies that meet that search
		switch(command)
		{
		//PROCESSING - Searching for a title within the linked list
		case TITLESEARCH : if(currentNode-> info.title == stringKey)
						   {
								//Returns if there a title that matches the
								//search key
								found = true;

								//OUTPUT - outputs the title box
								OutputTitle(oFile, currentNode);
						   }//END-IF
					break;

		//PROCESSING - Searching for a genre or alternate genre within the
		//				linked list
		case GENRESEARCH : if(currentNode-> info.genre == stringKey ||
			       	   	   	  currentNode-> info.altGenre == stringKey)
			    		   {
								//Increments the instances every time an
								//instance is found
								instances = instances + 1;

								//Returns if there a title that matches the
								//search key
								found = true;

								//If it is the first time going though the
								//search it will out put the header to the
								//category list
								if(found && instances == 1)
								{
									//OUTPUT - outputs to the output file
									oFile << "\n\n\nSearching by genre for "
										  << stringKey << " found:\n";

									oFile << "MOVIE #  TITLE" << setw(61)
										  << "YEAR RATING  GENRE" << setw(22)
										  << "ALT GENRE" << setw(19)
										  << "LEAD ACTOR" << setw(27)
										  << "SUPPORTING ACTOR\n";

									oFile << setfill('-') << setw(8) << ' ' << setw(49) << ' ' << setw(5)
										  << ' ' << setw(7) << ' ' << setw(18) << ' ' << setw(18) << ' '
										  << setw(20) << ' ' << setw(20) << ' ' << setfill(' ')
										  << endl;
								}//END-IF
								//OUTPUT - Outputs each movie that is found
								OutputCurrentNode(oFile, currentNode, instances);
			    		   }//END-IF
					break;

		//PROCESSING - Searching for a leading actor or supporting actor within the
		//				linked list
		case ACTORSEARCH : if(currentNode-> info.leadingAct == stringKey ||
							 currentNode-> info.supportAct == stringKey)
						   {
								//Increments the instances every time an
								//instance is found
								instances = instances + 1;

								//Returns if there a title that matches the
								//search key
								found = true;

								//If it is the first time going though the
								//search it will out put the header to the
								//category list
								if(found && instances == 1)
								{
									//OUTPUT - outputs to the output file
									oFile << "\n\n\nSearching by actor for "
										  << stringKey << " found:\n";

									oFile << "MOVIE #  TITLE" << setw(61)
										  << "YEAR RATING  GENRE" << setw(22)
										  << "ALT GENRE" << setw(19)
										  << "LEAD ACTOR" << setw(27)
										  << "SUPPORTING ACTOR\n";

									oFile << setfill('-') << setw(8) << ' ' << setw(49) << ' ' << setw(5)
										  << ' ' << setw(7) << ' ' << setw(18) << ' ' << setw(18) << ' '
										  << setw(20) << ' ' << setw(20) << ' ' << setfill(' ')
										  << endl;
								}//END-IF

								//OUTPUT - Outputs each movie that is found
								OutputCurrentNode(oFile, currentNode, instances);
						   }//END-IF
					break;

		//PROCESSING - Searching for a year within the linked list
		case YEARSEARCH  : if(currentNode-> info.year == intKey)
						   {
								//Increments the instances every time an
								//instance is found
								instances = instances + 1;

								//Returns if there a title that matches the
								//search key
								found = true;

								//If it is the first time going though the
								//search it will out put the header to the
								//category list
								if(found && instances == 1)
								{
									//OUTPUT - outputs to the output file
									oFile << "\n\n\nSearching by year for " << intKey << " found:\n";

									oFile << "MOVIE #  TITLE" << setw(61) << "YEAR RATING  GENRE" << setw(22)
										  << "ALT GENRE" << setw(19) << "LEAD ACTOR" << setw(27)
										  << "SUPPORTING ACTOR\n";

									oFile << setfill('-') << setw(8) << ' ' << setw(49) << ' ' << setw(5)
										  << ' ' << setw(7) << ' ' << setw(18) << ' ' << setw(18) << ' '
										  << setw(20) << ' ' << setw(20) << ' ' << setfill(' ')
										  << endl;
								}//END-IF

								//OUTPUT - Outputs each movie that is found
								OutputCurrentNode(oFile, currentNode, instances);
						   }//END-IF
					break;

		//PROCESSING - Searching for a rating within the linked list
		case RATINGSEARCH: if(currentNode-> info.rating == intKey)
						   {
								//Increments the instances every time an
								//instance is found
								instances = instances + 1;

								//Returns if there a title that matches the
								//search key
								found = true;

								//If it is the first time going though the
								//search it will out put the header to the
								//category list
								if(found && instances == 1)
								{
									//OUTPUT - outputs to the output file
									oFile << "\n\n\nSearching by rating for " << intKey << " found:\n";

									oFile << "MOVIE #  TITLE" << setw(61) << "YEAR RATING  GENRE" << setw(22)
										  << "ALT GENRE" << setw(19) << "LEAD ACTOR" << setw(27)
										  << "SUPPORTING ACTOR\n";

									oFile << setfill('-') << setw(8) << ' ' << setw(49) << ' ' << setw(5)
										  << ' ' << setw(7) << ' ' << setw(18) << ' ' << setw(18) << ' '
										  << setw(20) << ' ' << setw(20) << ' ' << setfill(' ')
										  << endl;
								}//END-IF

								//OUTPUT - Outputs each movie that is found
								OutputCurrentNode(oFile, currentNode, instances);
						   }//END-IF
					break;
		}//END-SWITCH

		//Assigns the pointer to the next node in the linked list
		currentNode = currentNode-> next;
	}//END-WHILE
return found;
}


/**************************************************************************
 * ActorSearch Function
 * ________________________________________________________________________
 * This function does not do any searching. If the linked list is empty the
 * user will prompted so. This function will ask for a users input for the
 * specified search and will take that name into the search function and
 * will determine if it a part of the linked list. Once determined if the
 * search name was in the linked list, it will return true or false and the
 * output will display accordingly.
 * _______________________________________________________________________
 * PRECONDITIONS
 *   head      : the head of the linked list must be predefined
 *	 oFile     : The output file must be opened
 *	 command   : must be predefined
 * POSTCONDITIONS
 * 	 <none>
 *************************************************************************/
void ActorSearch(ofstream& oFile, MovieNode *head, int command)
{
	MovieDetails info;	//PROC - The pointer to the info stored in a node
	string actorKey;	//IN   - the input search the user gave us
	int intKey;			//IN   - the input search the user gave us
	bool found;			//PROC - will determine if it was found or not
	int instances;		//PROC - Keeps track of the number in the list

	//Initializes intKey to zero
	intKey = 0;

	//PROCESSING - checks to see if the linked list is empty
	if(head == NULL)
	{
		//OUTPUT - Outputs to the console if it is empty
		cout << "Can\'t search for an actor if the list is empty!\n\n";
	}//END-IF

	else
	{
		//INPUT - Prompts the user for the string search key that will be
		//		  sent into the search function
		cout << "Which actor are you looking for? ";
		getline(cin, actorKey);
		cout << endl;

		//OUTPUT - displays to the user that the search is starting
		cout << "Searching for the actor " << actorKey << endl;

		//SearchFunction - The search key is sent into this function to
		//					find if the search key matches anything in the
		//					linked list, if so it will return true with a
		//					number of instances. If it returns false, then
		//					the search key did not match a node in the
		//					linked list
		found = SearchFunction(oFile, head, actorKey, intKey, command, instances);

		//PROCESSING - if the search function returns true then it will
		//				output that it was found and the number of times it
		//				was found in the linked list
		if(found)
	    {
			//OUTPUT - Outputs into the console that it was found and the
			//			number of times
			cout << "Found " << instances << " movies for the actor "
				 << actorKey << "!\n\n\n";
	    }//END-IF

		else
		{
			//OUTPUT - Outputs to the console if the searchFunction returns
			//			with nothing matching the search key
			cout << "Sorry, no movies for the actor, " << actorKey
				 << " were found.\n\n\n";
		}//END-ELSE
	}//END-ELSE
}


/**************************************************************************
 * GenreSearch Function
 * ________________________________________________________________________
 * This function does not do any searching. If the linked list is empty the
 * user will be prompted so. This function will ask for a users input for the
 * specified search and will take that name into the search function and
 * will determine if it is a part of the linked list. Once determined if the
 * search name was in the linked list, it will return true or false and the
 * output will display accordingly.
 * _______________________________________________________________________
 * PRECONDITIONS
 *   head      : the head of the linked list must be predefined
 *	 oFile     : The output file must be opened
 *	 command   : must be predefined
 * POSTCONDITIONS
 * 	 <none>
 *************************************************************************/
void GenreSearch(ofstream& oFile, MovieNode *head, int command)
{
	MovieDetails info;	//PROC - The pointer to the info stored in a node
	string genreKey;	//IN   - the input search the user gave us
	int intKey;			//IN   - the input search the user gave us
	bool found;			//PROC - will determine if it was found or not
	int instances;		//PROC - Keeps track of the number in the list

	//Initializes intKey to zero
	intKey = 0;

	//PROCESSING - checks to see if the linked list is empty
	if(head == NULL)
	{
		//OUTPUT - Outputs to the console if it is empty
		cout << "Can\t search for a genre if the list is empty!\n\n";
	}//END-IF

	else
	{
		//INPUT - Prompts the user for the string search key that will be
		//		  sent into the search function
		cout << "Which genre are you looking for? ";
		getline(cin, genreKey);
		cout << endl;

		//OUTPUT - displays to the user that the search is starting
		cout << "Searching for the genre " << genreKey << endl;

		//SearchFunction - The search key is sent into this function to
		//					find if the search key matches anything in the
		//					linked list, if so it will return true with a
		//					number of instances. If it returns false, then
		//					the search key did not match a node in the
		//					linked list
		found = SearchFunction(oFile, head, genreKey, intKey, command, instances);

		//PROCESSING - if the search function returns true then it will
		//				output that it was found and the number of times it
		//				was found in the linked list
		if(found)
	    {
			//OUTPUT - Outputs into the console that it was found and the
			//			number of times
			cout << "Found " << instances << " movies for the genre "
			     << genreKey << "!\n\n\n";
	    }//END-IF
		else
		{
			//OUTPUT - Outputs to the console if the searchFunction returns
			//			with nothing matching the search key
			cout << "Sorry, no movies for the genre, " << genreKey
				    		 << " were found.\n\n\n";
		}//END-ELSE
	}//END-ELSE
}


/**************************************************************************
 * RatingSearch Function
 * ________________________________________________________________________
 * This function does not do any searching. If the linked list is empty the
 * user will prompted so. This function will ask for a users input for the
 * specified search and will take that integer into the search function and
 * will determine if it a part of the linked list. Once determined if the
 * search integer was in the linked list, it will return true or false and the
 * output will display accordingly.
 * _______________________________________________________________________
 * PRECONDITIONS
 *   head      : the head of the linked list must be predefined
 *	 oFile     : The output file must be opened
 *	 command   : must be predefined
 * POSTCONDITIONS
 * 	 <none>
 *************************************************************************/
void RatingSearch(ofstream& oFile, MovieNode *head, int command)
{
	MovieDetails info;	//PROC - The pointer to the info stored in a node
	string stringKey;	//IN   - the input search the user gave us
	int ratingKey;		//IN   - the input search the user gave us
	bool found;			//PROC - will determine if it was found or not
	int instances;		//PROC - Keeps track of the number in the list
	bool invalid;		//PROC - the invalid condition for error checking
						//		  user input

	//PROCESSING - checks to see if the linked list is empty
	if(head == NULL)
	{
		//OUTPUT - Outputs to the console if it is empty
		cout << "Can\t search for a rating if the list is empty!\n\n";
	}//END-IF

	else
	{
		//PROCESSING - Error checking the users input to make sure that a
		//				character has not been entered and if it has, it
		//				will clear the fail state and prompt the user asking
		//				for an input
		do
			{
				// INITIALIZE - the invalid condition to false
				invalid = false;

				//INPUT - Prompts the user for the input
				cout << "Which rating are you looking for? ";

				// PROC - will check if the user entered a character for a variable
				//		  that must only receive a number.
				if(!(cin >> ratingKey))
				{
					cout << "\n**** Please input a NUMBER "
							"between 0 and 9 ****\n\n\n";

					// PROC - clears the fail state so program does not crash
					cin.clear();

					// PROC - clears all characters from the input buffer
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					invalid = true;
				}//END-IF

				else if (ratingKey < 0 || ratingKey > 9)
				{
					// OUT - if the command is out of bounds, the user will be
					//		 re-prompted
					cout << left;
					cout << "\n**** The number " << ratingKey << setw(25)
						 << " is an invalid entry" << "****"
						 << "\n**** Please input a number "
							"between 0 and 9 ****\n\n\n";
					cout << right;

					invalid = true;
				}//END-ELSE-IF

				// PROC - if the user enters a valid response, the input buffer
				//		  must be cleared
				if(!invalid)
				{
					cin.ignore(100,'\n');
				}//END-IF

			}while(invalid);//END-DO-WHILE

			cout << endl;

			//OUTPUT - displays to the user that the search is starting
			cout << "Searching for the rating " << ratingKey << endl;

			//SearchFunction - The search key is sent into this function to
			//					find if the search key matches anything in the
			//					linked list, if so it will return true with a
			//					number of instances. If it returns false, then
			//					the search key did not match a node in the
			//					linked list
			found = SearchFunction(oFile, head, stringKey, ratingKey, command, instances);

			//PROCESSING - if the search function returns true then it will
			//				output that it was found and the number of times it
			//				was found in the linked list
			if(found)
			{
				//OUTPUT - Outputs into the console that it was found and the
				//			number of times
				cout << "Found " << instances << " movies for the rating "
					 << ratingKey << "!\n\n\n";
			}//END-IF

			else
			{
				//OUTPUT - Outputs to the console if the searchFunction returns
				//			with nothing matching the search key
				cout << "Sorry, no movies for the rating, " << ratingKey
					 << " were found.\n\n\n";
			}//END-ELSE
	}//END-ELSE
}


/**************************************************************************
 * TitleSearch Function
 * ________________________________________________________________________
 * This function does not do any searching. If the linked list is empty the
 * user will prompted so. This function will ask for a users input for the
 * specified search and will take that name into the search function and
 * will determine if it a part of the linked list. Once determined if the
 * search name was in the linked list, it will return true or false and the
 * output will display accordingly.
 * _______________________________________________________________________
 * PRECONDITIONS
 *   head      : the head of the linked list must be predefined
 *	 oFile     : The output file must be opened
 *	 command   : must be predefined
 * POSTCONDITIONS
 * 	 <none>
 *************************************************************************/
void TitleSearch(ofstream& oFile, MovieNode* head, int command)
{
	MovieDetails info;	//PROC - The pointer to the info stored in a node
	string titleKey;	//IN   - the input search the user gave us
	int intKey;			//IN   - the input search the user gave us
	bool found;			//PROC - will determine if it was found or not
	int instances;		//PROC - Keeps track of the number in the list

	//Initializes intKey to zero
	intKey = 0;

	//PROCESSING - checks to see if the linked list is empty
	if(head == NULL)
	{
		//OUTPUT - Outputs to the console if it is empty
		cout << "Can\t search for a title if the list is empty!\n\n";
	}//END-IF

	else
	{
		//INPUT - Prompts the user for the string search key that will be
		//		  sent into the search function
		cout << "Which title are you looking for? ";
		getline(cin, titleKey);
		cout << endl;

		//OUTPUT - displays to the user that the search is starting
		cout << "Searching for the title " << titleKey << endl;

		//SearchFunction - The search key is sent into this function to
		//					find if the search key matches anything in the
		//					linked list, if so it will return true with a
		//					number of instances. If it returns false, then
		//					the search key did not match a node in the
		//					linked list
		found = SearchFunction(oFile, head, titleKey, intKey, command, instances);

		//PROCESSING - if the search function returns true then it will
		//				output that it was found and the number of times it
		//				was found in the linked list
		if(found)
		{
			//OUTPUT - Outputs into the console that it was found and the
			//			number of times
			cout << "Found the movie " << titleKey << endl << endl << endl;
		}//END-IF

		else
		{
			//OUTPUT - Outputs to the console if the searchFunction returns
			//			with nothing matching the search key
			cout << "Sorry, the movie \"" << titleKey << "\" was not found.\n\n\n";
		}//END-ELSE
	}//END-ELSE
}


/**************************************************************************
 * YearSearch Function
 * ________________________________________________________________________
 * This function does not do any searching. If the linked list is empty the
 * user will prompted so. This function will ask for a users input for the
 * specified search and will take that integer into the search function and
 * will determine if it a part of the linked list. Once determined if the
 * search integer was in the linked list, it will return true or false and the
 * output will display accordingly.
 * _______________________________________________________________________
 * PRECONDITIONS
 *   head      : the head of the linked list must be predefined
 *	 oFile     : The output file must be opened
 *	 command   : must be predefined
 * POSTCONDITIONS
 * 	 <none>
 *************************************************************************/
void YearSearch(ofstream& oFile, MovieNode *head, int command)
{
	MovieDetails info;	//PROC - The pointer to the info stored in a node
	string stringKey;	//IN   - the input search the user gave us
	int yearKey;		//IN   - the input search the user gave us
	bool found;			//PROC - will determine if it was found or not
	int instances;		//PROC - Keeps track of the number in the list
	bool invalid;		//PROC - the invalid condition for error checking
						//		  user input

	//PROCESSING - checks to see if the linked list is empty
	if(head == NULL)
	{
		//OUTPUT - Outputs to the console if it is empty
		cout << "Can\t search for a rating if the list is empty!\n\n";
	}//END-IF

	else
	{
		//PROCESSING - Error checking the users input to make sure that a
		//				character has not been entered and if it has, it
		//				will clear the fail state and prompt the user asking
		//				for an input
		do
			{
				// INITIALIZE - the invalid condition to false
				invalid = false;

				//INPUT - Prompts the user for the input key
				cout << "Which year are you looking for? ";

				// PROC - will check if the user entered a character for a variable
				//		  that must only receive a number.
				if(!(cin >> yearKey))
				{
					cout << "\n**** Please input a NUMBER "
					    	"between 1878 and 3000 ****\n\n\n";

					// PROC - clears the fail state so program does not crash
					cin.clear();

					// PROC - clears all characters from the input buffer
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					invalid = true;
				}//END-IF

				else if (yearKey < 1878 || yearKey > 3000)
				{
					// OUT - if the command is out of bounds, the user will be
					//		 re-prompted
					cout << left;
					cout << "\n**** The number " << yearKey << setw(25)
						 << " is an invalid entry" << "****"
					     << "\n**** Please input a number "
					    	"between 1878 and 3000 ****\n\n\n";
					cout << right;

					invalid = true;
				}//END-ELSE-IF

				// PROC - if the user enters a valid response, the input buffer
				//		  must be cleared
				if(!invalid)
				{
					cin.ignore(100,'\n');
				}//END-IF

			}while(invalid);//END-DO-WHILE

			cout << endl;

			//OUTPUT - displays to the user that the search is starting
			cout << "Searching for the year " << yearKey << endl;

			//SearchFunction - The search key is sent into this function to
			//					find if the search key matches anything in the
			//					linked list, if so it will return true with a
			//					number of instances. If it returns false, then
			//					the search key did not match a node in the
			//					linked list
			found = SearchFunction(oFile, head, stringKey, yearKey, command, instances);

			//PROCESSING - if the search function returns true then it will
			//				output that it was found and the number of times it
			//				was found in the linked list
			if(found)
			{
				//OUTPUT - Outputs into the console that it was found and the
				//			number of times
				cout << "Found " << instances << " movies for the year "
					 << yearKey << "!\n\n\n";
			}//END-IF

			else
			{
				//OUTPUT - Outputs to the console if the searchFunction returns
				//			with nothing matching the search key
				cout << "Sorry, no movies for the year, " << yearKey
					 << " were found.\n\n\n";
			}//END-ELSE
	}//END-ELSE
}

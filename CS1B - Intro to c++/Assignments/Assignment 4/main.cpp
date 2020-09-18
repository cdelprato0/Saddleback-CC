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
 * Movie List - Intro to Linked Lists
 * ________________________________________________________________________
 * This program will be able to allow the user to enter in an input file
 * name and an output file name. Once those are determined the program
 * will load the information in the input file into the linked list.
 * Containing info such as the title, leading actor, supporting actor,
 * genre, alternate genre, year, rating , and a short summary of the plot.
 * The program will count how many movies there were and will output all
 * the information to the output file.
 * ________________________________________________________________________
 * CONSTANTS -
 * 		INPUT_LENGTH - The length for when prompting the user
 *
 * INPUTS -
 * 		inFile    - The text file that all the info is saved into
 * 		inputFile - User's request for the input file name
 *
 * OUTPUTS -
 * 		outputFile - User's request for the output file name
 *		OutFile    - The output file that displays the header and the balance
 *				     due
 *************************************************************************/

int main()
{
	const int INPUT_LENGTH = 40;	//OUT - Used to space the input prompt

	ifstream inFile;	//IN  - The text file that all the info is saved into
	ofstream oFile;		//OUT - he output file that displays the header
	                    //		and the balance due
	string   inputFile; //IN  - User's request for the input file name
	string outputFile;  //OUT - The output file that displays the header
						//      and the balance due
	MovieNode *head;	//PROC- Contains the head of the linked list

	//Initializes the head of the linked list to NULL
	head = NULL;

	//INPUT - Prompts the user for the name of their input file and the
	//		  name of their output file.
	cout << left;
	cout << setw(INPUT_LENGTH) << "What input file would you like to use?";
	getline(cin, inputFile);
	cout << setw(INPUT_LENGTH) << "What output file would you like to use?";
	getline(cin, outputFile);
	cout << endl;

	//PROCESSING - Opens up the input and output files
	inFile.open(inputFile.c_str());
	oFile.open(outputFile.c_str());

	//PrintHeader Function displays the programmers header in the output file
	PrintHeader(oFile, "MovieList", 'A', 4);

	//CreateMovieList Function loads the input file into the linked list
	CreateMovieList(inFile, head);

	//OutputMovieList function outputs the contents of the input file into
	//the output file.
	OutputMovieList(oFile, head);

	//Closes the input and output files
	inFile.close();
	oFile.close();

	return 0;
}

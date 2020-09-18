#include "header.h"

//This function outputs the student header
void Header()
{
	 /********************************************************************
	  * CONSTANTS
	  * ------------------------------------------------------------------
	  * USED FOR CLASS HEADING - ALL WILL BE OUTPUT
	  * ------------------------------------------------------------------
	  * PROGRAMMER:	Programmer's Name
	  * CLASS:		Student's Course
	  * SECTION:	Class Days and Times
	  * LAB_NUM:	Lab Number (specific to this lab)
	  * LAB_NAME:	Title of Lab
	  ********************************************************************/
	 const char PROGRAMMER[30]  = "FSC & BBC";
	 const char CLASS[5]		= "CS1B";
	 const char SECTION[25]		= "MW: 8:30am-12:20pm";
	 const int	LAB_NUM		 	= 3;
	 const string	LAB_NAME	= "Supplement: Coin Flip";


	 //OUTPUT - Class Heading
	 cout << left;
	 cout << "************************************************************";
	 cout << "\n*    PROGRAMMED BY : " << PROGRAMMER;
	 cout << "\n*    " << setw(14) << "CLASS" << ": " << CLASS;
	 cout << "\n*    " << setw(14) << "SECTION" << ": " << SECTION;
	 cout << "\n*    LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	 cout << "\n************************************************************\n\n";
	 cout << right;
}

/**************************************************************************
 * GetInfo Function
 * ________________________________________________________________________
 * This function will prompt for the user's name and gender and will
 * determine if their name needs a Mr. or Ms. in front of it.
 * ________________________________________________________________________
 *
 *************************************************************************/
void GetInfo(string& name, char& gender)
{
	//Prompts user for their name
	cout << left;
	cout << setw(27) << "What is your name?";
	getline(cin,name);

	//Prompts user for their gender
	cout << setw(27) << "What is your gender?(M/F)";
	cin.get(gender);
	cout << endl;
	gender=toupper(gender);
	cin.ignore(100,'\n');

	//Determines if they are a Mr. or Ms.
	if (gender=='M')
		name="Mr. " + name;
	else
		name="Ms. " + name;
}

/**************************************************************************
 * CoinFlip Function
 * ________________________________________________________________________
 * This function will randomly flip a coin from heads to tails and will
 * keep a running total of how many tosses are performed.
 * ________________________________________________________________________
 * VARIABLE -
 * 		coinFlip - Determines if it is head(1) or tales(0)
 *
 *************************************************************************/
bool CoinFlip(int& total, int& totalHeads)
{
	bool coinFlip;		//Determines if it is head(1) or tales(0)

	//Randomizes
	srand(time(NULL));

	//Only chooses from 0 to 1
	coinFlip = rand()%2;

	total = total + 1;

	//Incrementing the total tosses
	if(coinFlip == 1)
		totalHeads = totalHeads +1;

	return coinFlip;
}

/**************************************************************************
 * Total_Average Function
 * ________________________________________________________________________
 * This function will determine the average of the total number of heads
 * that flipped over the total number of tosses
 * ________________________________________________________________________
 * VARIABLE -
 * 		average - Average of heads divided by the total flips
 *
 *************************************************************************/
int Total_Average(int& total, int& totalHeads)
{
	int average;		//Average of heads divided by the total flips

	//Operation that sets the average with no decimals
	average = float(totalHeads) / total * 100;

	return average;
}

/**************************************************************************
 * Output Function
 * ________________________________________________________________________
 * This function outputs the number of tosses the user needed to do in
 * order to get heads three times in a row. Also outputs the average
 * of heads over the number of times.
 * ________________________________________________________________________
 *************************************************************************/
void Output(int average, int total)
{
	cout << endl;
	cout << "It took you " << total << " tosses to get 3 heads in a row.\n"
			"On average you flipped heads " << average << "% of the time";
}


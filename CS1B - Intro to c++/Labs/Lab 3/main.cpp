#include "header.h"


/**************************************************************************
 * Supplement: Coin Flip
 * ________________________________________________________________________
 * This program will be able to play heads or tails. It will take in the
 * user's info and it will be able to determine when heads hits 3 times in
 * a row. From there it will output the number of attempts and the average.
 * ________________________________________________________________________
 * INPUTS -
 * 		name
 * 		gender
 * OUTPUT -
 * 		headCount
 * 		average
 * 		totalHeads
 * 		total
 *************************************************************************/
int main()
{
	string name;	//INPUT - User's name
	char gender;	//INPUT - User's gender (Male/Female)
	bool coinFlip;	//PROC  - Determines if the coin flipped heads or tails
	int total;		//CALC  - Total number of coin flips
	int totalHeads; //CALC  - Number of heads that landed
	int average;	//CALC  - Average of heads divided by the total flips
	int headCount;	//CALC  - Counts the number of heads in a row

	//Initializing the counters to zero
	total = 0;
	totalHeads = 0;
	headCount = 0;

	// This function will output the header
	Header();

	cout << "Welcome to coin toss! Get 3 heads in a row to win!\n\n";

	//This function receives the user's information
	GetInfo(name, gender);

	cout << "Try to get 3 heads in a row. Good luck " << name << "!"
			<< endl << endl;

	// User presses enter to start the process
	cout << "Press <enter> to flip";
	cin.get();

	// While loop continues process until three heads in a row is met
	while(headCount != 3)
	{
		//This function determine if the coin landed heads or tails
		coinFlip = CoinFlip(total, totalHeads);

		//Increments headCount to keep track if 3 heads in a row occurs
		if(coinFlip == 1)
		{
			cout << "HEAD\n";

			headCount = headCount +1;
		}
		//Resets headCount to zero
		else
		{
			cout << "TAIL\n";
			headCount = 0;
		}

		//Once three heads in a row hits, stops prompting to continue
		if(headCount != 3)
		{
			cout << "Press <enter> to flip";
			cin.get();
		}

	}

	//This function is the calculate the average of heads over the total
	average = Total_Average(total, totalHeads);

	//This function outputs the # of tosses, and the average of heads
	Output(average, total);

	return 0;
}

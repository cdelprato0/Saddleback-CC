/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #1: Functions
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 2-9-2015
 *************************************************************************/
#include "Header.h"

/***************************************************************************
 * High Roller
 * -------------------------------------------------------------------------
 * This program will emulate the dice game "High Roller". High Roller is a
 * dice game where each p[layer rolls a die. The highest die rolled wins.
 * The program will allow each player play by hitting the <enter> key.
 * There is a random number generator that produces number 1 to 6 to ensure
 * fairness. The program will allow users to enter their name and will
 * check if they want to play the game. If so, the program will output
 * a picture of their die and whether or not if they had won or tied.
 * The program will exit once the users enter 'N' for when asked if they
 * want to play.
 * -------------------------------------------------------------------------
 * INPUT -
 * 		player1  - The first player to enter their name
 * 		player2  - The second player to enter their name
 *
 * OUTPUT -
 * 		die      - Determines the number of die and displays the picture
 * 		dieNum1  - Saves result for player one's die number to be used with
 * 					DisplayWinner
 * 		dieNum2  - Saves result for player two's die number to be used with
 * 					DisplayWinner
 * 		response - Results of the users' if they want to play the game or not
 ****************************************************************************/

int main()
{

	string player1;		//INPUT - The first player to enter their name
	string player2;		//INPUT - The second player to enter their name
	int die;			//C & O - Determines the number of die and outputs
	int dieNum1;		//C & O - Saves result for player one's die number
	int dieNum2;		//C & O - Saves result for player two's die number
	char response;		//C & O - Users' choice if they wanted to play

	//PrintHeader - Outputs the header of the project in the console
	PrintHeader("Functions", 'A', 1);

	//OutputInstructions - Displays the game rules and how-to-play into the console
	OutputInstructions();

	//GetPlayersNames - Prompts the user's for the first players name and
	//					the second player's name
	GetPlayersNames(player1, player2);

	//GetAndCheckCharResponse - Prompts the users' if they would like to
	//							play the game and checks to see if it was
	//							a valid input. Initialize the LCV
	response = GetAndCheckCharResponse();

	//While the response for the users is equal to YES, the program will
	//begin to start the game. Check the LCV
	while(response == 'Y' || response == 'y')
	{
		//PlayOneTurn - The first player's turn and returns the value of
		//				their die number
		dieNum1 = PlayOneTurn(player1, die);

		//PlayTwoTurn - The second player's turn and returns the value of
		//				their die number
		dieNum2 = PlayTwoTurn(player2, die);

		//DisplayWinner - This function takes in the users' dice numbers
		//					and determines which one wins and then outputs
		//					the results
		DisplayWinner(dieNum1, dieNum2, player1, player2);

		//Change the LCV
		response = GetAndCheckCharResponse();
	}

	//Outputs when the users are done playing the game
	cout << endl << endl;
	cout << "Thank you for playing :-)";

	return 0;
}

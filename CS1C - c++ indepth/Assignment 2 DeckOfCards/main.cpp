/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #2:Deck of Cards
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#include "Card.h"
#include "CardDeck.h"

/**************************************************************************
 * Assignment Two - Shuffling a Deck of Cards
 * ________________________________________________________________________
 * This program will use object oriented programming to hold a standard
 * deck of cards. It will be able to represent the suit and the rank of
 * the cards. The program will use methods that can initialize the deck,
 * be able to perform a perfect shuffle, print out the entire deck at any
 * time. Lastly the program will be able to compare the two decks, one
 * being the newly shuffled one and the other being the original. The
 * program will output the initial deck and then it will output the first
 * perfect shuffle and then it will output the final shuffled deck. The
 * program will also output the number of shuffles conducted in order to
 * shuffle back to the original deck.
 * ________________________________________________________________________
 * INPUTS -
 * 		current - takes in the users command from the menu choice
 * 		arraySize - takes the User's request for how big the array is
 *
 * OUTPUTS -
 * 		randNum - Outputs to the console what your random number is
 *************************************************************************/
int main()
{
	CardDeck currentDeck; //CALC-Used to call methods from the CardDeck
						  //     class

	//OUTPUT - Custom output to the console
	cout << "Welcome to the the Card Shuffling Program!\n\n";

	cout << "We will begin by Initializing the Deck of Cards...\n";

	//PROCESSING - This method will initialize the deck in correct order
	//				and will store the information into the given array
	currentDeck.IntitializeDeck();

	//OUTPUT - Custom output to the console
	cout << "Initializing Complete!\n\n";

	cout << "Here is the created deck. \n"
			"-------------------------\n";

	//OUTPUTTING - Outputs the array full of the rank and suit of the
	//				deck of cards
	currentDeck.PrintDeck();

	//PROCESSING - This method will take in the initialized array and a
	//				newly created shuffled array, and will shuffle the deck
	currentDeck.ShuffleDeck();

	//OUPUT - Custom outputting
	cout << "\nThis is the deck after one perfect shuffle\n"
			"------------------------------------------";
	cout << endl << endl;

	//OUTPUTTING - Outputs the array full of the rank and suit of the
	//				deck of cards
	currentDeck.PrintDeck();

	return 0;
}//END OF PROGRAM

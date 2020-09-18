/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #2:Deck of Cards
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#include "CardDeck.h"

//Card Deck constructor
CardDeck::CardDeck()
{
	//Assigns the arrays of strings to NULL or zero
	cardDeck = NULL;
	shuffled = NULL;
}//END METHOD

/*************************************************************************
 * METHOD IntitializeDeck
 * ________________________________________________________________________
 * This method initializes the deck by setting up the ranks and suit that
 * are available and then loads all the cards into an array of strings
 *
 * ________________________________________________________________________
 * PRECONDITIONS
 *
 *
 * POSTCONDITIONS
 *
 ************************************************************************/
void CardDeck::IntitializeDeck()
{
	int index; //Holds the index of the array

	//PORCESSING - Loads each array index with a rank or suit that will be
	//				used to create the array
	string rank[] = {"ACE", "KING", "QUEEN", "JACK", "TEN", "NINE",
				"EIGHT", "SEVEN", "SIX", "FIVE", "FOUR", "THREE", "TWO"};
	string suit[] = {"CLUBS", "DIAMONDS", "HEARTS", "SPADES"};

	//Dynamically allocating new memory for the new array
	cardDeck = new Card[DECK_SIZE];

	//PROCESSING - Loads the array with the suit of the card and the rank
	for(index = 0; index < DECK_SIZE; index++)
	{
		cardDeck[index] = Card(rank[index % 13], suit[index / 13]);
	}//END FOR LOOP

}//END METHOD

//CardDeck De-constructor
CardDeck::~CardDeck() {

}//END METHOD

/*************************************************************************
 * METHOD ShuffleDeck
 * ________________________________________________________________________
 * This method will create a new array that will keep the newly sorted
 * array stored. The method will perform a perfect shuffle by cutting the
 * deck in half and shuffling each card. After the whole deck has been
 * shuffled, the original array will load all the values that were created
 * in the new shuffled array, back into itself.
 *
 * ________________________________________________________________________
 * PRECONDITIONS
 *
 *
 * POSTCONDITIONS
 *
 ************************************************************************/
void CardDeck::ShuffleDeck()
{
	int index; //keeps track of the index of the array
	int even;  //Used to shuffle the array
	int odd;   //Used to shuffle the array

	//Initializes the variables to zero
	even = 0;
	odd = 0;

	//Dynamically allocating new memory for the new array
	shuffled = new Card[DECK_SIZE];

	//PROCESSING - This for loop is used to run through the entire array
	for(index = 0; index < DECK_SIZE ; index++)
	{
		//PROCESSING - These if-else statments are used to determine if the
		//				index is even or odd
		if(index % 2 == 0)
		{
			//PROCESSING - Loads the first shuffled into the array or if it
			//				is an even index
			if(index == 0)
			{
			shuffled[index] = cardDeck[index];
			}//END IF
			else
			{
				even++;
				shuffled[index]= cardDeck[index - even];
			}//END ELSE

		}//END IF
		else
		{
			odd++;
			shuffled[index] = cardDeck[index + 26 - odd];
		}//END ELSE

	}//END FOR LOOP

	//PROCESSING - loads the shuffled array into the original array
	for(index = 0; index < DECK_SIZE; index++)
	{
		cardDeck[index] = shuffled[index];
	}//END FOR LOOP

}//END METHOD


/*************************************************************************
 * METHOD PrintDeck
 * ________________________________________________________________________
 * This method will simply print out the current deck that has been saved
 * into the array.
 *
 * ________________________________________________________________________
 * PRECONDITIONS
 *
 *
 * POSTCONDITIONS
 *
 ************************************************************************/
void CardDeck::PrintDeck()
{
	int index; //keeps track of the index of the array

	//PROCESSING - For loop used to run through the entire array
	for(index = 0; index < DECK_SIZE ; index++)
	{
		//OUTPUT- outputs the contents that are in the array
		cout << left
			 << setw(17)
			 << cardDeck[index].CardDisplay() << "  ";

		//OUTPUT - After the fourth suit and rank prints, it will new line
		if((index + 1) % 4 == 0)
		{
			cout << endl;
		}//END IF

	}//END FOR

}//END METHOD


/*************************************************************************
 * METHOD CompareDecks
 * ________________________________________________________________________
 * This method will compare the shuffled deck with the original deck to
 * check and see if they are equal to each other.
 *
 * ______________________NOT FINISHED______________________________________
 * PRECONDITIONS
 *
 *
 * POSTCONDITIONS
 *
 ************************************************************************/
bool CardDeck::CompareDecks()
{
	bool equal;
	int index;
	equal = false;
	index = 0;

	//PROCESSING - will check the rank and suit of each deck of cards
	while(cardDeck->GetRank() == shuffled->GetRank() && cardDeck->GetSuit()
			== shuffled->GetSuit() && equal == false)
	{
		if(cardDeck->GetRank() == shuffled->GetRank() && cardDeck->GetSuit()
				== shuffled->GetSuit())
		{
			equal = true;
		}
		else
		{
			index ++;
			equal = false;
		}

	}
	return equal;
}//END METHOD

//***********NOT FINISHED************
//bool CardDeck::GetCard(Card compareCard1, Card compareCard2)
//{
//	if(compareCard1.GetRank() == compareCard2.GetRank() &&
//		compareCard1.GetSuit() == compareCard2.GetSuit())
//	{
//
//	}
//}


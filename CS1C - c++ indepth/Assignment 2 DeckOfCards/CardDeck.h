/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #2:Deck of Cards
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#ifndef CARDDECK_H_
#define CARDDECK_H_

#include "Card.h"

const int DECK_SIZE = 52;

class CardDeck {
public:

	/***************************
	 * CONSTRUCTOR * DESTRUCTOR*
	 ***************************/
	CardDeck();				//DEFAULT CONSTRUCTOR
	virtual ~CardDeck();	//NON-DEFAULT CONSTRUCTOR

	/*************
	 * ACCESSORS *
	 *************/
	void IntitializeDeck(); //Initializes the deck of cards
	void ShuffleDeck();		//Shuffles the deck perfectly in half
	bool CompareDecks();	//Used to compare the decks
	void PrintDeck();		//Prints the deck of cards
	string GetCard(Card compareCard1, Card compareCard2); //Gets the cards
														  //and compares

private:
	Card* cardDeck; //The array that holds the initialized deck
	Card* shuffled; //The array that holds the shuffled deck

};

#endif /* CARDDECK_H_ */

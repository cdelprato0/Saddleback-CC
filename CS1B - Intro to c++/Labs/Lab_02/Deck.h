#ifndef DECK_H_
#define DECK_H_

#include <iostream> //Provides cout()

#include "Card.h"

//Constant that represents the size of a deck
const int DECK_SIZE = 52;

/*************************************************************************
 * class Deck
 *
 * This class represents a deck of cards. It does this by creating an
 * array of card objects and provides methods to manipulate the array
 *
 * CONSTRUCTORS:
 *  Deck(): Default constructor with no parameters
 *
 * METHODS:
 *  PrintDeck(): Outputs deck to user
 *  CompareDeck(): Compares cardDeck to passed in deck
 *
 *  Initialize(): Resets array to default configuration
 *  Shuffle(): Does a perfect shuffle on cardDeck
 *
 *  CompareCard(): Compares one card to another card
 *  GetCard(): Returns the card at passed in index
 *
 * DATA MEMBERS:
 *  cardDeck[]: An array of cards of size DECK_SIZE as declared above
 ************************************************************************/
class Deck {
	public:
        Deck();
		
        //Accessors
        void PrintDeck() const;
        bool CompareDeck(Deck compareDeck) const;

        //Mutators
        void Initialize();
        void Shuffle();

	private:
		Card cardDeck[DECK_SIZE];

        bool CompareCard(Card compareCard1, Card compareCard2) const;
        Card GetCard(int element) const;
};

#endif //DECK_H_

/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #2:Deck of Cards
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#include "Header.h"

#ifndef CARDDECK_H_
#define CARDDECK_H_

class CardDeck
{
public:

	CardDeck();
	virtual ~CardDeck();


private:

	enum Suit{
		CLUBS,
		DIAMONDS,
		HEARTS,
		SPADES
	};

	enum Rank{
		ACE,
		KING,
		QUEEN,
		JACK,
		TEN,
		NINE,
		EIGHT,
		SEVEN,
		SIX,
		FIVE,
		FOUR,
		THREE,
		TWO
	};

	int cardArray[4][13];

};

#endif /* CARDDECK_H_ */

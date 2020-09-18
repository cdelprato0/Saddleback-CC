#ifndef CARD_H_
#define CARD_H_


//Aces are low
//Enum that represents possible card ranks
enum Rank{
	JOKER,
	ACE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
    TEN,
	JACK,
	QUEEN,
	KING
};

//Enum that represents possible card suits
enum Suit {
	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES
};

//Struct that represents the information for a card
//  cardRank: The card's rank
//  cardSuit: The card's suit
struct Card {
	 Rank cardRank;
	 Suit cardSuit;
};

#endif //CARD_H_

#include "Deck.h"

/*
 * Defualt constructor
 */
Deck::Deck() {
    Initialize();
}

/*
 * Outputs the contents of cardDeck to user
 *
 * @logic Iterate through cardDeck and output based on switch statements
 */
void Deck::PrintDeck() const{
    int index;
    
    /*********************************************************************
     * For loop iterates through array
     *
     * switch 1 outputs the card rank based on enum
     * switch 2 outputs the card suit based on enum
     ********************************************************************/
    for (index = 0; index < DECK_SIZE; index++) {

        switch (cardDeck[index].cardRank) {
            case 1: std::cout << "ACE";
                break;
            case 2: std::cout << "TWO";
                break;
            case 3: std::cout << "THREE";
                break;
            case 4: std::cout << "FOUR";
                break;
            case 5: std::cout << "FIVE";
                break;
            case 6: std::cout << "SIX";
                break;
            case 7: std::cout << "SEVEN";
                break;
            case 8: std::cout << "EIGHT";
                break;
            case 9: std::cout << "NINE";
                break;
            case 10: std::cout << "TEN";
                break;
            case 11: std::cout << "JACK";
                break;
            case 12: std::cout << "QUEEN";
                break;
            case 13: std::cout << "KING";
                break;
        }

        std::cout << " of ";

        switch (cardDeck[index].cardSuit) {
            case 0: std::cout << "CLUBS";
                break;
            case 1: std::cout << "DIAMONDS";
                break;
            case 2: std::cout << "HEARTS";
                break;
            case 3: std::cout << "SPADES";
                break;
        }

        std::cout << std::endl;
    }

}

/*
 * Compares cardDeck to passed in deck
 *
 * @params  Deck compareDeck
 * @logic   Calls method to check if cards are equal at each index
 * @returns bool whether the parameter deck is the same as the calling
 *              deck
 */
bool Deck::CompareDeck(Deck compareDeck) const
{
    bool decksAreEqual = true;
    int index = 0;

    //will iterate through myDeck and compareDeck and check if they're
    //  equal until end of array or a comparison is false
    do {
        decksAreEqual = CompareCard(cardDeck[index], compareDeck.GetCard(index));

        index++;
    } while(decksAreEqual && index < DECK_SIZE);

    return decksAreEqual;
}

/*
 * Resets array to default configuration
 *
 *
 */
void Deck::Initialize() {
    
    int index;      //Stores index for for loop
    int numRank = 1;//Stores
    int numSuit = 0;

    for (index = 0; index < DECK_SIZE; index++) {

        switch (numRank) {
            case 1: cardDeck[index].cardRank = ACE;
                break;
            case 2: cardDeck[index].cardRank = TWO;
                break;
            case 3: cardDeck[index].cardRank = THREE;
                break;
            case 4: cardDeck[index].cardRank = FOUR;
                break;
            case 5: cardDeck[index].cardRank = FIVE;
                break;
            case 6: cardDeck[index].cardRank = SIX;
                break;
            case 7: cardDeck[index].cardRank = SEVEN;
                break;
            case 8: cardDeck[index].cardRank = EIGHT;
                break;
            case 9: cardDeck[index].cardRank = NINE;
                break;
            case 10: cardDeck[index].cardRank = TEN;
                break;
            case 11: cardDeck[index].cardRank = JACK;
                break;
            case 12: cardDeck[index].cardRank = QUEEN;
                break;
            case 13: cardDeck[index].cardRank = KING;
                break;
        }

        if (index != 0 && index % 13 == 0) {
            numSuit++;
        }

        switch (numSuit) {
            case 0: cardDeck[index].cardSuit = CLUBS;
                break;
            case 1: cardDeck[index].cardSuit = DIAMONDS;
                break;
            case 2: cardDeck[index].cardSuit = HEARTS;
                break;
            case 3: cardDeck[index].cardSuit = SPADES;
                break;
        }

        (numRank >=13? numRank = 1: numRank++);

    }
}

/*************************************************************************
 * method Shuffle
 *
 * Does a perfect shuffle pn cardDeck
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS:
 *  -none
 *
 * POST-CONDITIONS:
 *  -cardDeck has had a perfect shuffle completed on it
 ************************************************************************/
void Deck::Shuffle()
{
    int index;
    int odd = 0;
    int even = 0;
    Card shuffleDeck[DECK_SIZE];

    for (index = 0; index < DECK_SIZE; index++) {

        if (index % 2 == 0) {

            if (index == 0) {
               shuffleDeck[index] = cardDeck[index];
            }
            else {
                even++;

                shuffleDeck[index] = cardDeck[index - even];
            }
        }
        else {
            odd++;

            shuffleDeck[index] = cardDeck[index + 26 - odd];
        }
    }

    for (index = 0; index < DECK_SIZE; index++) {
        cardDeck[index] = shuffleDeck[index];
    }
}

/*************************************************************************
 * const method CompareCard
 *
 * Compares one card object to another card object and returns bool
 * ----------------------------------------------------------------------
 * PRE-CONDITIONS:
 *  -compareCard1: A card object
 *  -compareCard2: A card object
 *
 * POST-CONDITIONS:
 *  -A bool is returned based on whether object data members are equal
 ************************************************************************/
bool Deck::CompareCard(Card compareCard1, Card compareCard2) const
{
    bool isSame = false;

    if (compareCard1.cardRank == compareCard2.cardRank &&
        compareCard1.cardSuit == compareCard2.cardSuit) {
        isSame = true;
    }

    return isSame;
}

/*************************************************************************
 * const method GetCard
 *
 * Returns the card object at passed in index
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS:
 *  -element: number representing which array element to return
 *
 * POST-CONDITIONS:
 *  -The element at passed in int is returned
 *
 * WARNING:
 *  This method does not check for out of bounds
 ************************************************************************/
Card Deck::GetCard(int element) const
{
    return cardDeck[element];
}

#include "Deck.h"

int main(int argc, char **argv) {
	Deck deck1;
    Deck deck2;
    int total = 1;
	
    deck1.PrintDeck();

    std::cout << std::endl;

    deck1.Shuffle();
    deck1.PrintDeck();

    while (!(deck1.CompareDeck(deck2))) {

        deck1.Shuffle();
        total++;
    }

    std::cout << "\nThe amount of shuffles to return to normal is: " << total << std::endl <<std::endl;

    deck1.PrintDeck();

	return 0;
}

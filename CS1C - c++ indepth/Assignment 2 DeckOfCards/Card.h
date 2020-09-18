/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #2:Deck of Cards
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#ifndef CARD_H_
#define CARD_H_
#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Card
{
public:

	/***************************
	 * CONSTRUCTOR * DESTRUCTOR*
	 ***************************/
	Card(); 								//DEFAULT CONSTRUCTOR
	Card(string cardRank, string cardSuit); //NON-DEFALUT CONSTRUCTOR
	virtual ~Card();					    //DEFAULT DE-CONSTRUCTOR

	/*************
	 * ACCESSORS *
	 *************/
	string GetRank();			//Gets the rank of the card
	string GetSuit();			//Gets the suit of the card
	string CardDisplay()const;  //Displays the suit and the rank of the card

private:

	string rank; //The rank of the card
	string suit; //The suit of the card
};

#endif /* CARD_H_ */

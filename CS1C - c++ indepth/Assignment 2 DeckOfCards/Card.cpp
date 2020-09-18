/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #2:Deck of Cards
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#include "Card.h"

//Card constructor
Card::Card()
{

}//END METHOD

/*************************************************************************
 * METHOD Card - NON-DEFALUT Constructor
 * ________________________________________________________________________
 * This method uses overloading to set in variables that have been entered
 * into the parameters and assigns them to the attributes
 *
 * ________________________________________________________________________
 * PRECONDITIONS
 * 		cardRank - The request for the rank
 * 		cardSuit - The request for the suit
 *
 *
 * POSTCONDITIONS
 *
 ************************************************************************/
Card::Card(string cardRank, string cardSuit)
{

	rank = cardRank;
	suit = cardSuit;
}//END METHOD


//Card De-constructor
Card::~Card()
{

}//END METHOD


/*************************************************************************
 * METHOD CardDisplay
 * ________________________________________________________________________
 * This method simply just outputs a string that has the suit and the rank
 * of the card
 *
 * ________________________________________________________________________
 * PRECONDITIONS
 *
 *
 * POSTCONDITIONS
 *		returns the string of the rank and the suit
 ************************************************************************/
string Card::CardDisplay()const
{
	return(rank + " of " + suit);
}//END METHOD


/*************************************************************************
 * METHOD GetRank
 * ________________________________________________________________________
 * This method is used to get the rank of the card out of the private class
 *
 * ________________________________________________________________________
 * PRECONDITIONS
 *
 *
 * POSTCONDITIONS
 *
 ************************************************************************/
string Card::GetRank()
{
	return rank;
}//END METHOD


/*************************************************************************
 * METHOD GetSuit
 * ________________________________________________________________________
 * This method is used to get the suit of the card out of the private class
 *
 * ________________________________________________________________________
 * PRECONDITIONS
 *
 *
 * POSTCONDITIONS
 *
 ************************************************************************/
string Card::GetSuit()
{
	return suit;
}//END METHOD

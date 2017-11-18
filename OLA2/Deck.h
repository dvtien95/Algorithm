#ifndef DK_H
#define DK_H

#include <iostream>
#include "card.h"


class Deck
{
public:

    // Constructor
	Deck();

    // Remove the top card from the deck
    // and return it.
	Card dealCard();

    // Shuffle the cards on the deck
	void Shuffle();

    // return true is no more cards on the deck,
    // otherwise return false
	bool isEmpty();
	
	// get the index of the top card
	int getIndex() const;

    //overload << operator to display the deck
    friend ostream& operator << (ostream&, const Deck&);

private:
    static const int Card_Num = 52; //Max # of cards in  a deck

	Card    theDeck[Card_Num];    // the array holding the cards
	int     topCard;              // the index of the top card on the deck
};

#endif


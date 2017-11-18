#ifndef PL_H
#define PL_H

#include <iostream>
#include <string>
#include "deck.h"
#include "card.h"

class Player
{
public:
    static const int Max_Cards = 3; //Max # of cards a player can have

    // Constructor
	Player();
	
	// Sort number of cards in hand
	void sortHand();

    // The player removes one card from his hand
    // and return it.
    // You can use whatever stratge you want here such as
    // choose a card randomly, choose the largest card,
    // choose the first card, or other more complicated algorithm
	Card playCard();

    // The player gets one card from the deck
	void drawCard(Deck& dk);

    // Add the point value of the card
    // to the score of the player
	void addScore(Card acard);

    // Return the score the player has earned so far
	int total() const;

    // return the name of the player
    std::string getName() const; 
	
	// set name of the player
	void setName(std::string aName);

    // Return true if no more cards in the player's hands,
    // otherwise false
	bool emptyHand() const;

    // overload the << operator to display all cards in player's hand
    friend std::ostream& operator << (std::ostream&, const Player&);

private:
	std::string  name;       //player's name
	int     score=0;      //score the player has earned so far
	Card    hand[Max_Cards];    //the array holding cards 
};

#endif

#include <iostream>
#include <string>
#include <ctime>
#include "Card.h"
#include "Deck.h"

using std::swap;
using std::ostream;

//Define a constructor to generate a defalut deck of card
Deck::Deck()
{
	for (int i = 0; i < Card_Num; i++)
	{
		if (i<13)
		{
			theDeck[i].SetFaceValue(i%13+1);
			theDeck[i].SetType(clubs);
		}
		else if (i<26)
		{
			theDeck[i].SetFaceValue(i%13+1);
			theDeck[i].SetType(hearts);
		}
		else if (i<39)
		{
			theDeck[i].SetFaceValue(i%13+1);
			theDeck[i].SetType(spades);
		}
		else if (i<52)
		{
			theDeck[i].SetFaceValue(i%13+1);
			theDeck[i].SetType(diamonds);
		}
	}
	topCard = 0;
}

// Deal the top card, then increse the index
Card Deck::dealCard()
{
	Card aCard = theDeck[topCard];
	topCard ++;
	return aCard;
}

// Use random to swap position of 2 cards for a number of times
void Deck::Shuffle()
{
	int rand1, rand2, curCards = Card_Num - topCard;
	for (int i = 0; i < 50; i++)
	{
		rand1 = rand() % curCards;
		rand2 = rand() % curCards;
		
		swap(theDeck[rand1],theDeck[rand2]);
	}
}

// If the index of the top card equal to the last card, the deck is empty
bool Deck::isEmpty()
{
	return topCard == Card_Num;
}

// Getor
int Deck::getIndex() const
{
	return topCard;
}

// overload << operator to display Deck
ostream& operator << (ostream& os, const Deck& aDeck)
{
	os << "The deck: " << std::endl;
	for (int i = aDeck.getIndex(); i < Deck::Card_Num; i++)
	{
		os << aDeck.theDeck[i] << std::endl;
	}
	return os;
}

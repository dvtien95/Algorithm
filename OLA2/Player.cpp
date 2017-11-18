#include <iostream>
#include <string>
#include "Card.h"
#include "Deck.h"
#include "Player.h"

// All card with face value of -1 is considered empty card
// Initialize player hands with empty card
Player::Player()
{
	for (int i=0; i<Max_Cards; i++)
		hand[i].SetFaceValue(-1);
}

// Sort the player cards in increasing order 
void Player::sortHand()
{
	Card tmpCard;
	
	// Selection sort
	for (int i = 0; i < Max_Cards; i++)
	{
		for (int j = i+1; j < Max_Cards; j++)
			if (hand[i] > hand[j])
			{
				tmpCard = hand[i];
				hand[i] = hand[j];
				hand[j] = tmpCard;
			}
	}
}

//	First sort hand, then play the largest card in 3rd position. If there is no card to play, then return empty card
Card Player::playCard()
{
	Card tmpCard;
	sortHand();
	// loop to play the card that is not empty
	for (int i=Max_Cards-1; i>-1; i--)
	{
		if (hand[i].getFaceValue() != -1)
		{
			tmpCard = hand[i];
			hand[i].SetFaceValue(-1);
			return tmpCard;		// return value of the card
		}
	}
	tmpCard.SetFaceValue(-1);
	return tmpCard;		// return empty card
}

void Player::drawCard(Deck& dk)
{
	// draw card if the card is empty and deck is not empty
	for (int i = Max_Cards-1; i > -1; i--)
	{
		if ((hand[i].getFaceValue() == -1) && (!dk.isEmpty()))
		{
			hand[i] = dk.dealCard();	// get 1 card from the top of the deck
		}
	}
}

// Add score to a player
void Player::addScore(Card acard)
{
	score += acard.getPointValue();
}

// Getor
int Player::total() const
{
	return score;
}

// Getor
std::string Player::getName() const
{
	return name;
}

// Setor
void Player::setName(std::string aName)
{
	name = aName;
}

// Empty hand if all cards in player's hand have faceValue -1
bool Player::emptyHand() const
{
	for (int i=0; i<Max_Cards; i++)
	{
		if (hand[i].getFaceValue() != -1)
			return false;
	}
	return true;
}

// overloaded <<
ostream & operator << (ostream & os, const Player& aPlayer)
{
	os << aPlayer.getName() << "'s card(s): ";
	for (int i = aPlayer.Max_Cards - 1; i > -1; i--)
	{
		if (aPlayer.hand[i].getFaceValue() != -1)
			os << aPlayer.hand[i] << "  ";
		else
			os << "empty ";
	}
	return os;
}
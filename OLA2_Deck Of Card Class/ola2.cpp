#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));
	
	Deck deck1;
	
	deck1.Shuffle();
	
	string name1, name2;
	
	cout << "Enter player1's name: ";
	cin >> name1;
	cout << "Enter player2's name: ";
	cin >> name2;
	
	cout << endl;
	
	Player p1;
	Player p2;
	p1.setName(name1);
	p2.setName(name2);
	
	// Remove the "//" to show the shuffled deck of card
	cout << deck1 << endl;
	
	// Draw first 3 cards into player's hand
	for (int i=0; i<3; i++)
	{
		p1.drawCard(deck1);
		p2.drawCard(deck1);
	}
	
	cout << "The game begins: " << endl;
	cout << endl;
	
	// Both player play all the card until their hands empty
	while (!p1.emptyHand())
	{
		cout << p1 << "		";
		Card card1 = p1.playCard();
		cout << name1 << " played: " << card1 << endl;
		
		cout << p2 << "		";
		Card card2 = p2.playCard();
		cout << name2 << " played: " << card2 << endl;
		
		// Decide who wins the round
		if (card1 > card2)
		{
			cout << name1 << " win this round " << endl;
			p1.addScore(card1);
		}
		else if (card1 < card2)
		{
			cout << name2 << " win this round " << endl;
			p2.addScore(card2);
		}
		else
		{
			cout << "Both player get points" << endl;
			p1.addScore(card1);
			p2.addScore(card2);
		}
		cout << name1 << "'s score: " << p1.total() << "		";
		cout << name2 << "'s score: " << p2.total() << "		";
		cout << endl;
		
		// After card is played, draw 1 card from top of the deck
		p1.drawCard(deck1);
		p2.drawCard(deck1);
		
		cout << endl;
	}
	
	// print out the winner
	if (p1.total() > p2.total())
		cout << name1 << " is the winner! " << endl;
	else if (p1.total() < p2.total())
		cout << name2 << " is the winner! " << endl;
	else
		cout << "Draw! " << endl;
	
	return 0;
}
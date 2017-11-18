#include <iostream>
#include <string>
#include "Card.h"

using std::string;
using std::runtime_error;

// default constructor
Card::Card()
{
	faceValue = 2;
	type = clubs;
	pointValue = 0;
}

// another constructor
Card::Card(int faceValue, suite type)
		: type (type), faceValue (faceValue)
{
	
}

// 1,2,3,4...13 refers to A,2,3,4,... J,Q,K
string PrintFaceValue(int faceValue)
{
	switch (faceValue){
		case -1: return "NO CARD";		// No Card on hand
		case 1: return "A";		// Card "A" has facevalue of 1
		case 2: return "2";
		case 3: return "3";
		case 4: return "4";
		case 5: return "5";
		case 6: return "6";
		case 7: return "7";
		case 8: return "8";
		case 9: return "9";
		case 10: return "10";
		case 11: return "J";	// Card "J" has facevalue of 11
		case 12: return "Q";	// Card "Q" has facevalue of 12
		case 13: return "K";	// Card "K" has facevalue of 13
	default: throw runtime_error ("invalid card");
	}
}

// overloaded <<
ostream& operator << (ostream& os, const Card& cd)
{
	switch (cd.type){
		case clubs: os << PrintFaceValue(cd.faceValue) << "clubs";	return os;
		case hearts: os << PrintFaceValue(cd.faceValue) << "hearts";	return os;
		case spades: os << PrintFaceValue(cd.faceValue) << "spades";	return os;
		case diamonds: os << PrintFaceValue(cd.faceValue) << "diamonds";	return os;
	default: throw runtime_error ("invalid card");
	}
}

// overloaded <
bool Card::operator < (const Card& cd) const
{
	return getPointValue() < cd.getPointValue();
}

// overloaded >
bool Card::operator > (const Card& cd) const
{
	return getPointValue() > cd.getPointValue();
}

// overloaded ==
bool Card::operator == (const Card& cd) const
{
	return getPointValue() == cd.getPointValue();
}

// get points according to the faceValue
int Card::getPointValue() const
{
	switch (faceValue){
		case -1: return -1;		// NO CARDS ON HAND
		case 1: return 15;		// "Ace" has point value of 15
		case 11: return 10;	// "Jack" has point value of 10
		case 12: return 10;	// "Queen" has point value of 10
		case 13: return 10;	// "King" has point value of 10
	default: return faceValue;
	}
}

// Getor
void Card::SetFaceValue(int value)
{
	faceValue = value;
}

// Getor
int Card::getFaceValue() const
{
	return faceValue;
}

// Setor
void Card::SetType(suite atype)
{
	type = atype;
}








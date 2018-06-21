/* Tien Dinh - CSCI3110-001 - OLA6: Hash Table
 * Practice class template hash_map/unordered_map and string operations
 * Redesign a spell check program similar to Linux utility program ispell
 * */

// This header file provides operation to check spelling of a input word,
// as long as providing a dictionary container and a list of near missed words

#ifndef WORDCHECKER_H
#define WORDCHECKER_H

#include <unordered_map>
#include <string>
#include <iostream>
#include <list>

using namespace std;

class WordChecker
{
public:
	WordChecker();	// constructor
	
	bool WordAppear(const string& word);	// Check if the word is correct or not
	
	void DeleteLetter(const string& word);	// Single-letter omissions
	
	void InsertLetter(const string& word);	// Single-letter addition
	
	void SwapNeighbor(const string& word);	// Transpositions of two neighboring letters
	
	void ReplaceLetter(const string& word);	// Substitution of one letter for another
	
	void InsertSpace(const string& word);	// Two words run together
	
	void CheckNearMisses(string temp);	// Check tempWords after performing operations
	
	void PrintNearMisses();	// Print all near missed words

	~WordChecker();	// Destructor


private:
	unordered_map<string, int> dict;	// Store words in a dictionary file
	list<string> nearMisses;	// Store all near missed words
};

#endif // WORDCHECKER_H


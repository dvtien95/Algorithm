/* Tien Dinh - CSCI3110-001 - OLA6: Hash Table
 * Practice class template hash_map/unordered_map and string operations
 * Redesign a spell check program similar to Linux utility program ispell
 * */

// Using spell checking: "Wordchecker.h", read user input and process it
#include "WordChecker.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	WordChecker a;
	
	string aWord;	// Original word
	
	cout << "Input a single word: ";
	getline(cin, aWord);	// Get input
	
	string tmpWord = aWord;	
	
	for (int i=0; i < tmpWord.length(); i++)	
		tmpWord[i] = tolower(tmpWord[i]);	// Conver all letters to lowercase
	
	// If the word is in the dictionary, the output is correct
	if (a.WordAppear(tmpWord))
		cout << endl << aWord << "  is a correct word. " << endl;
	else
	{
		a.DeleteLetter(tmpWord);		// Check single-letter omissions
		a.InsertLetter(tmpWord);		// Check single-letter addition
		a.SwapNeighbor(tmpWord);		// Check transpositions of two neighboring letters
		a.ReplaceLetter(tmpWord);		// Check substitution of one letter for another
		a.InsertSpace(tmpWord);		// Check two words run together
		
		a.PrintNearMisses();	// Print all possible near misses
	}
}
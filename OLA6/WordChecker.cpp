/* Tien Dinh - CSCI3110-001 - OLA6: Hash Table
 * Practice class template hash_map/unordered_map and string operations
 * Redesign a spell check program similar to Linux utility program ispell
 * */

// Implementation of WordChecker.h

#include "WordChecker.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <list>

using namespace std;

// Defined a constructor to read data from the external file
WordChecker::WordChecker()
{
	ifstream myIn;
	myIn.open("dict.txt");
	assert(myIn);	// Check filename
	
	string word;
	int numOfWord = 0;	// Total number of data recorded
	
	// Readin until eof
	while(myIn >> word)
	{
		for (int i=0; i < word.length(); i++)
			word[i] = tolower(word[i]);
		
		dict[word] = numOfWord;	// Insert values into the hash table
		numOfWord++;
	}
	
	cout << numOfWord << endl; 
	
	cout << dict["a"] << endl;

	
	myIn.close();
}

bool WordChecker::WordAppear(const string& word)
{
	auto t = dict.find(word);
	if (t != dict.end())
		return true;
	else
		return false;
}

// Construct strings by deleting one letter from the word (n posibilities)
void WordChecker::DeleteLetter(const string& word)
{
	cout << "Delete Letter: " << endl;
	for (int position = 0; position < word.length(); position++)
	{
		string temp = word;	// Save the value of word
		
		temp.erase(position,1);	// Delete one letter for each loop
		
		cout << temp << endl;
 		
		CheckNearMisses(temp);
	}
	//cout << endl;
}

// Construct strings by inserting any letter of the alphabet at any
// position in the string (26*(n+1)) posibilities
void WordChecker::InsertLetter(const string& word)
{
	cout << "InsertLetter: " << endl;
	// For each position
	for (int position = 0; position < word.length(); position++)
	{
		// For each letter in alphabet
		for (int letter = 97; letter < 123; letter++)
		{
			string temp = word;	// Save value of word
			
			temp.insert(position,1,char(letter));	// Insert a letter in each position
			
			cout << temp << endl;
			
			CheckNearMisses(temp);			
		}
	}
	//cout << endl;
}

// Construct strings by swapping two neighboring characters in the original one
void WordChecker::SwapNeighbor(const string& word)
{
	cout << "SwapNeighbor: " << endl;
	for (int position = 0; position < word.length()-1; position++)
	{
		string temp = word;	// Save value of word
		
		swap(temp[position], temp[position+1]);	// Swap 2 adjacent letters
		
		cout << temp << endl;
		
		CheckNearMisses(temp);
	}
	//cout << endl;
}

// Construct strings by replacing each letter in the word with letters in alphabet (26*n)
void WordChecker::ReplaceLetter(const string& word)
{
	cout << "ReplaceLetter: " << endl;
	// For each position
	for (int position = 0; position < word.length(); position++)
	{
		// For each letter in alphabet
		for (int letter = 97; letter < 123; letter ++)
		{
			string temp = word;	// Save value of word
			
			temp[position] = char(letter);	// Replace letter in word with letter in alphabet
			
			cout << temp << endl;
			
			CheckNearMisses(temp);
		}
	}
	//cout << endl;
}

// Construct pairs of strings by inserting space into the word (n-1 pairs)
void WordChecker::InsertSpace(const string& word)
{
	cout << "InsertSpace: " << endl;
	for (int position = 1; position < word.length(); position++)
	{
		string temp = word;	// Save value of word
		
		temp.insert(position,1,' ');	// Insert space to each position
		int index = temp.find(' ');	// Seperate at space into 2 words
		
		string temp1 = temp.substr(0,index);	// Word1: from beginning to space 
		string temp2 = temp.substr(index+1,temp.length());	// Word2: from space to end
		
		cout << temp1 << "  " << temp2 << endl;
		
		CheckNearMisses(temp1);
		CheckNearMisses(temp2);
	}
	//cout << endl;
}

// After operation functions on a given word, check existence in dictionary and duplication with list
// After checking condition, push the possible word in nearMisses list to output
void WordChecker::CheckNearMisses(string temp)
{
	auto t = dict.find(temp);	// Find temp in the map
	auto it = find(nearMisses.begin(), nearMisses.end(), temp);	// Find temp in the list
		
		// Check if temp is in the dictionary and not duplicated in the list, store it in the list
		if ((t != dict.end()) && (it == nearMisses.end()))
				nearMisses.push_front(temp);	// Push front is more efficient
}

// Print all the possible near missed words
void WordChecker::PrintNearMisses()
{
	nearMisses.sort();	// Sort the list of strings in alphabetic order
	if (nearMisses.empty())
		cout << endl << "Does not found any near misses" << endl;
	else
	{
		cout << endl << "All possible misses are: " << endl;
		for (list<string>::iterator it = nearMisses.begin(); it != nearMisses.end(); ++it)
			cout << *it << endl;	
	}
}

WordChecker::~WordChecker()
{
}


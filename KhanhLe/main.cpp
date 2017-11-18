#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

string checkWord(string & word);

int main()
{
	ifstream myFile;
	myFile.open("document.txt");
	
	map<string, int> m;		// Key: word, Value: frequency
	string word;
	char c;
	
	if (myFile.is_open())
	{
		while (!myFile.eof())		// Read until end of file
		{
			c = myFile.get();		// Get each character
			
			if (c != ' ')		// If reading non space character, add to a word
				word += c;
			else				// If reading space, add the word to the table, then reset word
			{
				checkWord(word);			// Check for special cases of word
				if (m.count(word) == 0)	// Case: Word not in the map
					m[word] = 1;
				else						// Case: Word in the map
					m[word] ++;
				
				word = "";					// Reset word
			}
			
		}
		// Print all words, and frequency in the map
		for (auto it = m.cbegin(); it!= m.cend(); ++it)
		{
			cout << it->first << " " << it->second << endl;
		}
	}
	else
		cout << "File is not opened! " << endl;
	
	myFile.close();
	
}

// Check for special cases of word
string checkWord(string & word)
{
	const int specialWordSize = 10;
	string specialWord[specialWordSize] = {"i.e."};		// String array of special words can be modified
	
	// If word is on special list, do nothing, return word
	for (int i = 0; i < specialWordSize; i++)
	{
		if (word == specialWord[i])
			return word;
	}
	
	// Remove all non alphabet character to form a correct word
	for (int i = 0; i < word.length(); i++)
	{
		if (!isalpha(word[i]))
		word.erase(i);
	}
	
	return word;
}

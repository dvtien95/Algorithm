#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string checkWord(string & word);
bool isSpecialWordBefore(const string & txt);

const int specialWordSize = 1;		// An arbitrary number, depends on how many special words in dictionary, can be modified
const string SPECIALWORDS[specialWordSize] = {"i.e."};		// String array of special words can be modified

int main()
{
	ifstream myFile;
	myFile.open("document3.txt");
	
	map<string, vector<pair<int,int > > > m;		// Key: word, Value: a vector of pair < sentence, frequency >
	string txt;			// txt hold each sentence
	string word;		// word hold each valid word
	char c;				// c hold value of each character read from file
	int sentence = 0;
	
	while (!myFile.eof())
	{
		c = myFile.get();		// Read each character
		txt += c;				// Add character to form a sentence

		// Condition to check if encounter end of a sentence, or end of file
		int checkEOF = myFile.peek();
		if (c == '.' && (myFile.peek() == ' ' || myFile.peek() == '\n' || myFile.peek() == '\t' || checkEOF == EOF))
		{
			if (!isSpecialWordBefore(txt))
			{
				sentence ++;		// Finish sentence 1
				
				// loop through a sentence to find each valid word, then add words to the hash table
				for (int i = 0; i < txt.length(); i++)
				{
					// if the current character is non-space and not the last character of the file
					if (txt[i] != ' ' && txt[i] != '\n' && txt[i] != '\t' && i != txt.length() -1)
						word += txt[i];
					else
					{
						// Add the last character to the word
						if (i == txt.length()-1)
							word += txt[i];
						
						checkWord(word);
						
						if (word != "")		// If word is not empty
						{
							// if word is not on the hash table, push back sentence and 1st time appeared
							if (m.count(word) == 0)
								m[word].push_back(make_pair(sentence,1));
							else
							{
								bool found = false;
								
								// if word is on the hash table, check if it the word appear in the current sentence.
								for (int j = 0; j < m[word].size(); j++)
								{
									if (m[word][j].first == sentence)
									{
										m[word][j].second ++;
										found = true;
										break;
									}
								}
								// If not in the current sentence, push back new sentence and 1st time appeared
								if (found == false)
									m[word].push_back(make_pair(sentence,1));
							}
						}
						word = "";		// reset word
					}
				}
				
				txt = "";		// reset sentence
			}
		}
	}
	
	// print
	for (auto it = m.cbegin(); it!= m.cend(); ++it)
	{
		cout << it->first << ": ";
		for (int i = 0; i < it->second.size(); i++)
		{
			cout << "at sentence "<< it->second[i].first << " ";
			cout << "appeared " << it->second[i].second << " times, ";
		}
		cout << endl;
	}
	
}

// Check for special cases of word, remove non-alphabetic characters
string checkWord(string & word)
{
	string concatenateWord;
	
	// If word is on special list, do nothing, return word
	for (int i = 0; i < word.length(); i++)
	{
		concatenateWord += word[i];
		for (int j = 0; j < specialWordSize; j++)
		{
			if (concatenateWord == SPECIALWORDS[j])
			{
				word = concatenateWord;
				return word;
			}
		}
	}
	
	// Remove all non alphabet character to form a correct word
	for (int i = 0; i < word.length(); i++)
	{
		if (!isalpha(word[i]))
			word.erase(i);
	}
	
	return word;
}

// This function is to check if special word ends with '.', then it's not the end of the sentence
bool isSpecialWordBefore(const string & txt)
{
	int i = txt.length()-1;
	string reverseWord;
	string word;
	
	while (txt[i] != ' ' && txt[i] != '\n' && txt[i] != '\t' && i > 0)
	{
		reverseWord += txt[i];
		i--;
	}
	
	for (int i = reverseWord.length()-1; i >= 0; i--)
		word += reverseWord[i];
	
	for (int i = 0; i < specialWordSize; i++)
	{
		if (word == SPECIALWORDS[i])
			return true;
	}
	return false;
}




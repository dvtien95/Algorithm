#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode
{
	struct TrieNode * children[ALPHABET_SIZE];
	
	// true if node represents end of word
	bool isEndOfWord;
};

struct TrieNode * getNode(void)
{
	TrieNode * pNode = new TrieNode;
	pNode->isEndOfWord = false;
	
	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;
		
	return pNode;
};

void insert(TrieNode * root, string key)
{
	TrieNode * pCrawl = root;
	
	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();
		
		pCrawl = pCrawl->children[index];
	}
	pCrawl->isEndOfWord = true;
}

bool search(TrieNode * root, string key)
{
	TrieNode * cur = root;
	
	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (cur->children[index])	// if cur->next is not NULL
			cur = cur->children[index];
		else
			return false;
	}
	
	return (cur != NULL && cur->isEndOfWord);
}

int main()
{
	vector<string> key; key.push_back("the"); key.push_back("a"); key.push_back("there"); key.push_back("answer");
	key.push_back("any"); key.push_back("by"); key.push_back("bye"); key.push_back("their");
	
	TrieNode * root = getNode();
	
	for (int i = 0; i < key.size(); i++)
		insert(root, key[i]);
		
	search(root, "the") ? cout << "Yes" << endl : cout << "No" << endl;
	search(root, "thee") ? cout << "Yes" << endl : cout << "No" << endl;

}

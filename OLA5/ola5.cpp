#include "BST.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <cmath>

using namespace std;

//The name of the file containing binary search trees
const string    FileName = "bst.dat";

//The value indicating the end of a binary search tree in the fileName
const int       SentinelValue = -1;

//Calculate # of nodes each time traverse through a node
//nodeCount is reset to 0 each time traversing through a new tree.
float nodeCount;
void nodeNum(int& nodeValue)
{
    nodeCount ++;
}

int main( void )
{
    ifstream myIn;
	myIn.open(FileName);
	assert(myIn);
	
	// Modify this number according to the number of trees in the file
	// or the number of tree you want to read
	int numOfTree = 5;
	
	// loop through all the trees in the file
	for (int i = 0; i < numOfTree; i++)
	{
		cout << "The Tree No. " << i + 1 << endl;
		BinarySearchTree<int> aTree;
		nodeCount = 0;
		int value;
		
		while((myIn >> value) && (value != SentinelValue))
			aTree.searchTreeInsert(value);
		
		//Calculating number of node in a tree, store value in nodeCount
		aTree.inorderTraverse(nodeNum);	// Pass in nodeNum() as function parameter
		
		cout << "# of tree node: " << nodeCount << endl;	// nodeCount holds value of # of tree nodes

		cout << "Total level of the tree: " << aTree.totalLevel() << endl;	// use totalLevel function
		
		cout << "ln(n) of the tree: " << log(nodeCount) << endl;	// cmath log()
		
		cout << "Average level: " << aTree.totalLevel()/nodeCount << endl;	// averageLv = totalLv / #ofNode
		
		cout << "Average level / log(n): " << (aTree.totalLevel()/nodeCount)/log(nodeCount) << endl; // averageLv / log(#ofNode)
		
		cout << endl;
		
		aTree = BinarySearchTree<int>();	// Destroy tree
	}
		return 0;
}
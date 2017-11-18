#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node * next;
};

struct
{
	int count;
	Node * headPtr;
};

class LinkedList
{
	public:
			LinkedList();
			~LinkedList();
			
	private:
			HeadNode head;
}

LinkedList::LinkedList()
{
	head.count = 0;
	head.headPtr = NULL;
	return;
}

LinkedList::~LinkedList()
{
	deleteAllNodes();
	return;
}
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <functional>

using namespace std;

struct node {
	int data;
	node * next;
};

struct Node {
	int data;
	Node * next;
	Node * prev;
};

class singlyLinkedList
{
public:
	node * head;
	node * tail;
	
	singlyLinkedList()
	{
		head = NULL;
		tail = NULL;
	}	
	
	void createNode(int value)
	{
		node * tmp = new node;
		tmp->data = value;
		tmp->next = NULL;
		if (head==NULL)
		{
			head = tmp;
			tail = tmp;
			tmp = NULL;
		}
		else
		{
			tail->next = tmp;
			tail = tmp;
		}
	}
	
	void displayList()
	{
		node * tmp = head;
		while (tmp!= NULL)
		{
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
		cout << endl << "-----------------------" << endl;
	}
	
	void insertEnd(int value)
	{
		node * tmp = new node;
		tmp->data = value;
		tmp->next = NULL;
		
		if (head == NULL)
		{
			head = tmp;
			tail = tmp;
			tmp = NULL;
		}
		else
		{
			tail->next = tmp;
			tail = tmp;
			tmp = NULL;
		}
	}
	
	void insertHead(int value)
	{
		node * tmp = new node;
		tmp->data = value;
		tmp->next = NULL;
		
		if (head == NULL)
		{
			head = tmp;
			tail = tmp;
			tmp = NULL;
		}
		else
		{
			tmp->next = head;
			head = tmp;
			tmp = NULL;
		}
	}
	
	void insertAtPosition(int value, int position)
	{
		node * tmp = new node;
		tmp->data = value;
		node * cur = new node;
		node * pre = new node;
		cur = head;
		
		for (int i = 0; i < position; i++)
		{
			pre = cur;
			cur = cur->next;
		}
		pre->next = tmp;
		tmp->next = cur;
		tmp = NULL;
	}
	
	void deleteAtPosition(int position)
	{
		node * pre = new node;
		node * cur = new node;
		cur = head;
		
		for (int i = 0; i < position; i++)
		{
			pre = cur;
			cur = cur->next;
		}
		
		node * tmp = cur;
		pre->next = cur->next;
		delete tmp;
	}
	
	void removeDuplicateUsingBuffer()
	{
		if (head == NULL)
			return;
			
		node * cur = head->next;
		node * pre = head;
		
		unordered_map<int, bool> m;
		m[head->data] = true;
		
		while (cur != NULL)
		{
			if (m.count(cur->data) == 0)
			{
				m[cur->data] = true;
				pre = cur;
				cur = cur->next;
			}
			else
			{
				node * tmp = cur;
				pre->next = cur->next;
				cur = cur->next;
				delete tmp;
			}
		}
		return;
	}
	
	void removeDuplicateNotUsingBuffer()
	{
		if (head == NULL) return;
		
		node * cur = head;
		
		while (cur != NULL)
		{
			node * r = cur->next;
			node * l = cur;
			
			while (r != NULL)
			{
				if (r->data == cur->data)
				{
					node * tmp = r;
					l->next = r->next;
					r = r->next;
					delete tmp;
				}
				else
				{
					l = r;
					r = r->next;
				}
			}
			cur = cur->next;
		}
	}
	
	void reorderList()
	{
		if (head == NULL || head->next == NULL || head->next->next == NULL)
			return;
		node * start = getHalfPointer();
		reverseHalf(start);
		reorderListHelper(start);
		
		start = NULL; delete start;
		return;
	}
	
	node * getHalfPointer()
	{
		node * slow = head;
		node * fast = head->next->next;

		while (fast != NULL && fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		if (fast == NULL)
			return slow;
		else
			return slow->next;
	}
	
	void reverseHalf(node * start)
	{
		node * end = start->next;
		node * cur = end->next;
		while (cur != NULL)
		{
			node * tmp = cur->next;
			cur->next = start->next;
			start->next = cur;
			end->next = tmp;
			cur = tmp;
			tmp = NULL; delete tmp;
		}
		end = NULL; cur = NULL; delete end; delete cur;
	}
	
	void reorderListHelper(node * start)
	{
		node * cur = head;
		node * tmp = start->next;
		while (cur != start)
		{
			start->next = tmp->next;
			tmp->next = cur->next;
			cur->next = tmp;
			tmp = start->next;
			cur = cur->next->next;
		}
		cur = NULL; tmp = NULL; delete cur; delete tmp;
	}
};

class doublyLinkedList
{
public:
	Node * head;
	Node * tail;
	doublyLinkedList()
	{
		head = NULL;
		tail = NULL;
	}	
	
	void createNode(int value)
	{
		Node * tmp = new Node;
		tmp->data = value;
		tmp->next = NULL;
		tmp->prev = NULL;
		
		if (head==NULL)
		{
			head = tmp;
			tail = tmp;
			tmp = NULL;
		}
		else
		{
			tail->next = tmp;
			tmp->prev = tail;
			tail = tmp;
			tmp = NULL;
			delete tmp;
		}
	}
	
	void displayFoward()
	{
		Node * cur = head;
		
		while (cur != NULL)
		{
			cout << cur->data << " ";
			cur = cur->next;
		}
		
		cout << endl << "-----------------------" << endl;
	}
	
	void displayBackward()
	{
		Node * cur = tail;
		
		while (cur != NULL)
		{
			cout << cur->data << " ";
			cur = cur->prev;
		}
		
		cout << endl << "-----------------------" << endl;
	}

		
};

bool greaterNode(node * a, node * b);
node* mergeKLists(const vector<node*>& lists);

int main()
{
	singlyLinkedList a1;
	a1.createNode(3); a1.createNode(5); a1.createNode(7);
	singlyLinkedList b1;
	b1.createNode(0); b1.createNode(6);
	singlyLinkedList c1;
	c1.createNode(0); c1.createNode(6); c1.createNode(28);
	
	node * a = a1.head; node * b = b1.head; node * c = c1.head;
	
	vector<node *> sortedLists;
	sortedLists.push_back(a); sortedLists.push_back(b); sortedLists.push_back(c);
	
	node * result = mergeKLists(sortedLists);
	
	node * cur = result;
	while (cur != NULL)
	{
		cout << cur->data << ' ';
		cur = cur->next;
	}
	
	//a.displayList();
	a1.removeDuplicateNotUsingBuffer();
	b1.removeDuplicateNotUsingBuffer();
	c1.removeDuplicateNotUsingBuffer();
	
}

class greaterNode{
    bool operator() (node * p1, node * p2){
         return p1->data > p2->data;
    }
};

struct CompareNode                                                                               
{
  bool operator()(const node* lhs, const node* rhs) const
  {
     return lhs->data > rhs->data;
  }
};

node* mergeKLists(const vector<node *> & lists)
{
	priority_queue<node*, vector<node *>, CompareNode > q;
	node * result = NULL; node * resultTail = NULL;
	
	for (int i = 0; i < lists.size(); i++)
		q.push(lists[i]);
	
	while (!q.empty())
	{
		node * tmp = q.top();
		node * newNode = new node; newNode->data = tmp->data; newNode->next = NULL;
		if (result == NULL)
		{
			result = newNode;
			resultTail = result;
		}
		else
		{
			resultTail->next = newNode;
			resultTail = resultTail->next;
		}
		node * cur = tmp->next;
		q.pop();
		if (cur != NULL)
		{
			q.push(cur);
		}
	}
	
	return result;
}
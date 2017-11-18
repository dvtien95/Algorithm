#include <iostream>
#include <string>

using namespace std;

struct node
{
	int data;
	struct node * left;
	struct node * right;
};

struct node * newNode(int data)
{
	struct node * node = new (struct node);
	
	node->data = data;
	
	node->left = NULL;
	node->right = NULL;
	
	return (node);
}

int main()
{
	// Create root
	struct node * root = newNode(3);
	
	root->left = newNode(2);
	root->right = newNode(7);
	root->left->left = newNode(4);
	root->right->left = newNode(1);
	root->right->right = newNode(5);
	root->right->right->left = newNode(9);
	root->right->right->right = newNode(6);
	
	
}
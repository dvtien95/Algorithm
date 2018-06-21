#include <iostream>
#include <math.h>
#include <queue>

using namespace std;

struct node {
	int value;
	node * left;
	node * right;
};

node * newNode(int val);
node * search(node* r, int key);
void inorder_print(node * tmp);
void preorder_print(node * tmp);
void postorder_print(node * tmp);
void destroyTree(node * r);
void depthFirstPrint(node * r);
void breathFirstPrint(node * r);
bool isBST(node * r);	vector<int> inOrderBST(node * r, vector<int> & a);
bool isBSTrecursive(node * r);
bool checkBSTsetRange(node * r, int lowBound, int highBound);
node * searchBST(node * r, int key);
node * firstKeyGreater(node * r, int key);
vector<int> findKlargestElement(node * r, int k);
void findKlargest(node * r, int k, vector<int> & res);

int main()
{
	node * root = newNode(19);
	root->left = newNode(7); root->right = newNode(43);
	root->left->left = newNode(3); root->left->right = newNode(11);
	root->left->left->left = newNode(2); root->left->left->right = newNode(5);
	root->left->right->right = newNode(17); root->left->right->right->left = newNode(13);
	root->right->left = newNode(23); root->right->right = newNode(47);
	root->right->right->right = newNode(53);
	root->right->left->right = newNode(37);
	root->right->left->right->left = newNode(29); root->right->left->right->right = newNode(41);
	root->right->left->right->left->right = newNode(31);
	
	cout << "inOrderTraversal: "; inorder_print(root); cout << endl;
	cout << "preOrderTraversal: "; preorder_print(root); cout << endl;
	cout << "postOrderTraversal: "; postorder_print(root); cout << endl;
	
	cout << "Level Print: "; breathFirstPrint(root);
	
	if (isBSTrecursive(root))
		cout << "This tree is a BST" << endl;
	else
		cout << "Not a BST" << endl;
	 
	node * tmp1 = searchBST(root, 17);
	if (tmp1)	cout << "Found node: " << tmp1->value << endl;
	else	cout << "Can't find searched node " << endl;
		
	node * tmp2 = firstKeyGreater(root, 19);
	if (tmp2)	cout << "First key greater than given value in BST is: " << tmp2->value << endl;
	else	cout << "Can't find first key greater than given value in BST" << endl;
		
	vector<int> tmp3 = findKlargestElement(root, 4); cout << "4 largest element are: ";
	for (int i = 0; i < tmp3.size(); i++)	cout << tmp3[i] << ' '; cout << endl;
	
	destroyTree(root);
}

node * newNode(int val)
{
	node * tmp = new node;
	
	tmp->value = val;
	tmp->left = NULL;
	tmp->right = NULL;
	
	return tmp;
}
	
node * search(node* r, int key)
{
	if (r != NULL)
	{
		if (r->value == key)
			return r;
		return search(r->left, key);
		return search(r->right, key);
	}
	else
		return NULL;
}
	
void inorder_print(node * tmp)
{
	if (tmp == NULL)
		return;
	inorder_print(tmp->left);
	cout << tmp->value << ' ';
	inorder_print(tmp->right);
}
	
void preorder_print(node * tmp)
{
	if (tmp == NULL)
		return;
	cout << tmp->value << ' ';
	preorder_print(tmp->left);
	preorder_print(tmp->right);
}
	
void postorder_print(node * tmp)
{
	if (tmp == NULL)
		return;
	postorder_print(tmp->left);
	postorder_print(tmp->right);
	cout << tmp->value << ' ';
}

void destroyTree(node * r)
{
	if (r != NULL)
	{
		destroyTree(r->left);
		destroyTree(r->right);
		delete r;
	}
}

void depthFirstPrint(node * r)
{
	
}

void breathFirstPrint(node * r)
{
	if (r == NULL)
		cout << "No node" << endl;
	queue<pair<node *, bool> > q;
	q.push(make_pair(r, true));
	
	while (!q.empty())
	{
		if (q.front().first->left != NULL)
			q.push(make_pair(q.front().first->left, false));
			
		if (q.front().first->right != NULL)
			q.push(make_pair(q.front().first->right, false));
			
		cout << q.front().first->value << ' ';
			
		q.pop();
	}
	cout << endl;
}

bool isBST(node * r)
{
	vector<int> a;
	a = inOrderBST(r, a);
	
	if (a.size() <= 1)
	{	
		return true;
	}
	int maxV = a[0];

	for (int i = 1; i < a.size(); i++)
	{
		if (a[i] < a[i-1] || a[i] < maxV)
			return false;
			
		maxV = a[i];
	}
	return true;
}

vector<int> inOrderBST(node * r, vector<int> & a) {
	if (r == NULL)
		return a;
	inOrderBST(r->left, a);
	a.push_back(r->value);
	inOrderBST(r->right, a);
	
	return a;
}

bool isBSTrecursive(node * r)
{
	return checkBSTsetRange(r, numeric_limits<int>::min(), numeric_limits<int>::max());
}

bool checkBSTsetRange(node * r, int lowBound, int highBound) {
	if (r == NULL)
		return true;
	
	if (r->value < lowBound || r->value > highBound)
		return false;
		
	return checkBSTsetRange(r->left, lowBound, r->value ) && checkBSTsetRange(r->right, r->value, highBound);
}

node * searchBST(node * r, int key)
{
	if (r == NULL)
		return NULL;
		
	if (r->value == key)
		return r;
	else if (r->value > key)
		return searchBST(r->left, key);
	else
		return searchBST(r->right, key);
}

node * firstKeyGreater(node * r, int key)
{
	if (r == NULL)
		return NULL;
	
	node * cur = r;
	node * tmp = NULL;
	
	while (cur && cur->value != key)
	{
		if (cur->value > key)
		{
			tmp = cur;
			cur = cur->left;
		}
		else if (cur->value < key)
			cur = cur->right;
	}
	
	
	if (cur == NULL)
		return NULL;
	else
	{
		if (cur->right)
		{
			cur = cur->right;
			while (cur->left)
				cur = cur->left;
			return cur;
		}
		else
			return tmp;
	}
}

vector<int> findKlargestElement(node * r, int k)
{
	vector<int> res;
	findKlargest(r, k, res);
	return res;
}

void findKlargest(node * r, int k, vector<int> & res)
{
	if (r == NULL)
		return;

	if (r && res.size() < k)
	{
		findKlargest(r->right, k, res);
		if (res.size() < k)
			res.push_back(r->value);
		findKlargest(r->left, k, res);
	}
}


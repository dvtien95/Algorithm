#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

struct compare
{
	bool operator()(const int & a, const int & b)
	{
		return a > b;
	}
};

int main()
{
	int myints[] = {10, 60, 50, 70, 20};
	priority_queue<int> first;
	priority_queue<int, vector<int>, greater<int> > second;
	priority_queue<int, vector<int>, compare>  third;
	
	for (int i = 0; i < 5; i++)
	{
		//first.push(myints[i]);
		//second.push(myints[i]);
		third.push(myints[i]);
	}
	cout << endl;
	
	while (!third.empty())
	{
		cout << third.top() << ' ';
		third.pop();
	}
	
	vector<vector<int > > 
}

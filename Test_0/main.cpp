#include <iostream>
#include <string>
#include <climits>
#include <vector>

using namespace std;

bool checkVector(const vector<int> & a);
void print(const vector<int> & a);

int main()
{
	vector<int> a;
	a.push_back(1); a.push_back(2); a.push_back(3);
	a.push_back(9); a.push_back(5); a.push_back(6);
	a.push_back(7); a.push_back(8); a.push_back(4);
	
	if (checkVector(a)) 
		cout << "True" << endl;
	else
		cout << "False" << endl;
}

void print(const vector<int> & a)
{
	for (int j = 0; j < a.size(); j++)
		cout << a[j] << " ";
	cout << endl;
}

bool checkVector(const vector<int> & a)
{
	int L1 = -1; int L2 = -1;
	int countL = 0;
	if (a.size() <= 1) return true;
	
	for (int i = 1; i < a.size(); i++)
	{
		if (a[i] < a[i-1])
		{
			countL++;
			if (countL == 1) 
				L1 = i;
			else if (countL == 2)
				L2 = i;
			else
				return false;
		}
	}
	
	if (countL == 2)
	{
		if (L1 - 2 < 0)
		{
			if (a[L2] < a[L1-2])
				return false;
		}
		
		if (a[L2] > a[L1]) return false;
		
		if (a[L1-1] < a[L2 - 1]) return false;
		
		if (L2 + 1 < a.size())
		{
			if (a[L1-1] > a[L2 + 1])
				return false;
		}
		
		return true;
		
	}
	else if (countL == 1)
	{
		return false;
	}
	else if (countL == 0)
		return true;
	else
		return false;
	
}

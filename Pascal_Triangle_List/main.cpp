#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getPascal(int n);

int main()
{
	int n = 3;
	vector<int> a;
	a = getPascal(n);
	for(int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << endl;
}

vector<int> getPascal(int n)
{
	vector<int> a;
	a.push_back(1);
	if (n == 0)
		return a;
	else
	{
		a.push_back(1);
		if (n == 1)
		{
			a.push_back(1);
			return a;
		}
		else
		{
			for (int i = 0; i < n - 1; i++)
			{
				int c = a[0];
				for (int j = 1; j < a.size(); j++)
				{
					int d = a[j];
					a[j] = c + d;
					c = d;
				}
				a.push_back(1);
			}
		}
	}
	
	return a;
}
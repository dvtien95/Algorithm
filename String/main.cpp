#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isUnique(string s);

int main()
{
	string s = "asdfghjk";
	cout << isUnique(s) << endl;
}

bool isUnique(string s)
{
	vector<bool> a;
	for (int i = 0; i < 256; i++)
		a.push_back(false);
	for (int i = 0; i < s.length(); i++)
	{
		if (a[s[i] - '0'] == false)
		{
			a[s[i] - '0'] = true;
		}
		else
		{
			return false;
		}
	}
	return true;
}

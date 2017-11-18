#include <iostream>
#include <string>
#include <climits>

using namespace std;

string countAndSay(int n);
string convert(string s);

struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
};

int main()
{
	int n = 6;
	
	cout << countAndSay(n) << endl;
}

string countAndSay(int n)
{
	string s = "1";
	if (n==1) return s;
	
	int cur = 2;
	
	while (cur <= n)
	{
		s = convert(s);
		cur++;
	}
	return s;
}

string convert(string s)
{
	string result; int count = 1;
	for (int i = 0; i < s.length(); i++)
	{
		if (i + 1 == s.length())
		{
			result += to_string(count) + s[i];
			s = result;
			break;
		}
		if (s[i] == s[i+1])
			count++;
		else
		{
			result += to_string(count) + s[i];
			count = 1;
		}
		
	}
	return result;
}
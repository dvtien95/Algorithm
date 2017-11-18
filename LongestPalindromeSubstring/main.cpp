#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s);

int main()
{
	string s = "abbacddd";
	cout << longestPalindrome(s) << endl;
}

string longestPalindrome(string s)
{
	if (s.length() == 0)
		return "";
	string result = s[0];
	for (int i = 0; i < s.length(); i++)
	{
		string cur = "", cur += s[i];
		if (i - 1 >= 0 && i + 1 < s.length())
		{
			int left = i - 1;
			int right = i + 1;
			int countPair = 0;
			while (s[left] == s[right])
			{
				countPair++;
				if (left - 1 >= 0 && right + 1 < s.length)
				{
					left--;
					right++;
				}
				else break;
			}
			else if (countPair*2 + 1 > result.length())
				result = s.substr(left, right - left + 1);
		}
		
		if (i + 1 < s.length())
		{
			string cur = "", cur+= s[i], cur += s[i+1];
			if (i - 1)
		}
	}
}
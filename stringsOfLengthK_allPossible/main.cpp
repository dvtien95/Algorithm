#include <iostream>
#include <string>
#include <vector>

using namespace std;

void displayList(const vector<string> & s);
vector<string> printAllstringsOfLengthK(cosnt vector<char> & a, int n);
void printStrings(const vector<char> & a, int n, vector<string> res);

int main()
{
	vector<char> a; a.push_back('a'); a.push_back('b');// a.push_back('c'); a.push_back('d');
	displayList(printAllstringsOfLengthK(a, 3));
}

void displayList(const vector<string> & s)
{
	for (int i = 0; i < s.size(); i++)
		cout << s[i] << endl;
}

vector<string> printAllstringsOfLengthK(cosnt vector<char> & a, int n)
{
	vector<string> res;
	printStrings(a, n, res);
	return res;
}

void printStrings(const vector<char> & a, int n, vector<string> res)
{
	if (n == 1)
}

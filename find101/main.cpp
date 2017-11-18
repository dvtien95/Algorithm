#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int count101(string s);

int main()
{
	string s = "10100001asdsa111001ascd1dsadas";

	int abc =  count101(s);
	
	cout << "Count101: " << abc << endl;
	
}

int count101(string s)
{
	int count = 0;
	int i = 0;
	while(i < s.length())
	{
		while ((s[i] != '1' || s[i+1] != '0') && i < s.length() - 1)
			i++;
		
		if (i >= s.length() - 2)
			return count;
		else
			i++;
		
		while(s[i] == '0' && i < s.length() - 1)
			i++;
		
		if (s[i] == '1')
			count ++;
			
	}
	return count;
}
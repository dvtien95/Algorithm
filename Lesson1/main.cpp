#include <stdio.h>
#include <iostream>
#include <string>

void reverse(string &s);

int main (int argc, char *argv[] )
{
	string s = "Toi di hoc";
	
	reverse(s);
	
	cout << s;
}

void reverse(string &s)
{
	int i = s.length();
	string r;
	int tempIndex = 0;
	while (i != 0)
	{
		r += s[i];
		
	}
	i--;
}
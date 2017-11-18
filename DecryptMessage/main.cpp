#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int giaiMa(const string & message, const string & signature);

int main()
{
	string signature = "-Your friend, Alice";
	string message = Otjvknou kskgnl, K mbxg iurtsvcnb ksgq hoz atv. Vje xcxtyqrl vt ujg smewfv vrmcxvtg rwqr ju vhm ytsf elwepuqyez. -Atvt hrqgse, Cnikg"
	
	cout << endl;
	cout << giaiMa(message, signature) << endl;
}

int giaiMa(const string & message, const string & signature)
{
	if (message.length() < signature.length())
		return "";
	if (message.length() == signature.length())
		return signature;
	
	int m = message.length();
	int s = signature.length();
	int code = 0;
	int z = 1;
	int result;
	
	// -Your friend, Alice
	for (int i = m - s + 1; i < m; i++ )
	{
		if (isalpha(signature[i]) && isalpha(message[z]))
		{
			int x = signature[i] - message[z];
		
			if (x < 0)
			{
				
			}
		
		}
	}
	
}


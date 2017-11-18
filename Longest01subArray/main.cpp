/* Find longest subarray that numbers of 0,1 are equal*/

#include <iostream>
#include <vector>

using namespace std;

int findMaxLength(const vector<int> & a);

int main()
{
	vector<int> a; a.push_back(0); a.push_back(0); a.push_back(1); a.push_back(1);
					a.push_back(1); a.push_back(0); a.push_back(1); a.push_back(1);
					
	cout << findMaxLength(a) << endl;
}

int findMaxLength(const vector<int> & a)
{
	if (a.size() == 0) return 0;
	if (a.size() == 1) return 1;
	
	int i = 1, count0 = 0, count1 = 0, maxLength;
	if (a[0] == 0) count0++;
	else count1++;
	
	bool found = false;
	while (i < a.size())
	{
		if (a[i] == 0) count0++;
		else count1++;
		
		if (count0 == count1){
			maxLength = i + 1;
			found = true;
		}
		i++;
	}
	if (found == false)
	{
		if (count1 > count0)
			return count0;
		else return count1;
	}
	else
		return maxLength;
}
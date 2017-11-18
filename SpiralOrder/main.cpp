#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(const vector<vector<int> > & arr);

int main()
{
	vector<int> a; a.push_back(1); a.push_back(2); a.push_back(3); a.push_back(4);
	vector<int> b; b.push_back(4); b.push_back(5); b.push_back(6); b.push_back(8);
	vector<int> c; c.push_back(7); c.push_back(8); c.push_back(9); c.push_back(12);
	vector<int> a1; a1.push_back(1);// a1.push_back(2);
	vector<int> a2; a2.push_back(3);// a2.push_back(4);
	vector<int> a3; a3.push_back(5);// a3.push_back(6);
	vector<int> a4; a4.push_back(7);// a4.push_back(8);
	vector<int> a5; a5.push_back(9);// a5.push_back(10);
	
	vector<vector<int> > arr; arr.push_back(a); arr.push_back(b); arr.push_back(c);// arr.push_back(a4); arr.push_back(a5);
	
	vector<int> result = spiralOrder(arr);
	
	for(int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	cout << endl;
}

vector<int> spiralOrder(const vector<vector<int> > & arr)
{
	int m = arr[0].size() * arr.size();
	int a1 = arr[0].size();
	int a2 = arr.size();
	int a3 = 0; int a4 = 0;
	vector<int> result;
	
	while (result.size() < m)
	{
		int i = a3; int j = a4;
		while (i < a1 && result.size() < m)
		{
			result.push_back(arr[j][i]);
			i++;
		}
		i--;
		j++;
		while (j < a2 && result.size() < m)
		{
			result.push_back(arr[j][i]);
			j++;
		}
		j--;
		i--;
		while (i >= a3 && result.size() < m) 
		{
			result.push_back(arr[j][i]);
			i--;
		}
		i++;
		j--;
		while (j > a4 && result.size() < m)
		{
			result.push_back(arr[j][i]);
			j--;
		}
		a1--; a2--; a3++; a4++;
	}
	return result;
}
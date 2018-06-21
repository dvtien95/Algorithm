#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int maxV(int a, int b);

int main()
{
	vector<pair<int,int> >a; int weight = 7; //int max = 0;
	
	a.push_back(make_pair(1,1)); a.push_back(make_pair(3,4)); a.push_back(make_pair(4,5)); a.push_back(make_pair(5,7));
	int row = a.size(); int col = weight + 1;
	
	vector<vector<int> > w(row,  vector<int> (col, 0));
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (j == 0)
				w[i][j] = 0;
			else
			{
				if (i - 1 < 0)
				{
					w[i][j] = a[i].second;
				}
				else
				{
					if (j < a[i].first)	
						w[i][j] = w[i-1][j];
					else
						w[i][j] = maxV(a[i].second + w[i-1][j-a[i].first], w[i-1][j]);
				}
			}
		}
	}
	
	for(int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << w[i][j] << " ";
		cout << endl;
	}
	
	
}

int maxV(int a, int b)
{
	if (a > b) return a;
	else return b;
}
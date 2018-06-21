#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;
int numIslands(const vector<vector<char> >& a);
void findIsland(const vector<vector<char> > & a, int i, int j, vector<vector<char> > & s);

int main()
{
	vector<vector<char> > a;
	//{{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
	vector<char> b; b.push_back('1'); b.push_back('1'); b.push_back('0'); b.push_back('0'); b.push_back('0');
	vector<char> c; c.push_back('1'); c.push_back('1'); c.push_back('0'); c.push_back('0'); c.push_back('0');
	vector<char> d; d.push_back('0'); d.push_back('0'); d.push_back('1'); d.push_back('0'); d.push_back('0');
	vector<char> e; e.push_back('0'); e.push_back('0'); e.push_back('0'); e.push_back('1'); e.push_back('1');
	vector<char> f; f.push_back('1'); f.push_back('1'); f.push_back('1'); f.push_back('1'); f.push_back('0');
	a.push_back(b); a.push_back(c); a.push_back(d); a.push_back(e);

	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[i].size(); j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
	cout << "Number of island: " << numIslands(a) << endl;
}

int numIslands(const vector<vector<char> >& a)
{
	vector<vector<char> > s; int count = 0;
	
	for (int i = 0; i < a.size(); i++)
	{
		vector<char> tmp;
		for (int j = 0; j < a[i].size(); j++)
		{
			tmp.push_back('0');
		}
		s.push_back(tmp);
	}
	
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[i].size(); j++)
		{
			// if a[i][j] == 0(is water) or in set(is island), which mean found island, do nothing 
			// if a[i][j] not in set and == 1, BFS island, put all piece to set, increase count
			if (a[i][j] == '1' && s[i][j] == '0')
			{
				findIsland(a, i, j, s);
				count ++;
			}
		}
	}
	return count;
}

void findIsland(const vector<vector<char> > & a, int i, int j, vector<vector<char> > & s)
{
	queue<pair<int, int> > q; q.push(make_pair(i,j)); s[i][j] = '1';
	while (!q.empty())
	{
		int r = q.front().first; int c = q.front().second;
		if (r + 1 < a.size() && a[r+1][c] == '1' && s[r+1][c] == '0')
		{
			q.push(make_pair(r+1, c));
			s[r+1][c] = '1';
		}
		if (r - 1 >= 0 && a[r-1][c] == '1' && s[r-1][c] == '0')
		{
			q.push(make_pair(r-1, c));
			s[r-1][c] = '1';
		}
		if (c + 1 < a[r].size() && a[r][c+1] == '1' && s[r][c+1] == '0')
		{
			q.push(make_pair(r, c+1));
			s[r][c+1] = '1';
		}
		if (cs - 1 >= 0 && a[r][c-1] == '1' && s[r][c-1] == '0')
		{
			q.push(make_pair(r, c-1));
			s[r][c-1] = '1';
		}
		q.pop();
	}
	return;
}

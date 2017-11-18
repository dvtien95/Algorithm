#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void print (const vector < vector < char > > & mBoard);
vector<int> createRealBoard (vector<vector<char> > & realBoard, int mines, char & decision);
int countMines (const vector<vector<char > > & realBoard, int x, int y);
int countFlags (const vector<vector<char> > & playBoard, int x, int y);
void traceBlanks (vector<vector<char> >& realBoard, vector<vector<char> >& playBoard, int x, int y);
bool isWin (const vector<vector<char> > & realBoard, const vector<vector<char> > & playBoard);
string startGame(vector<vector<char> > & realBoard, vector<vector<char> > & playBoard, vector<int> & startOrigin, char & decision);
string updateBoard (vector<vector<char> >& realBoard, vector<vector<char> >& playBoard, int x, int y);


int main()
{
	srand(time(0));
	int row = 5, col = 5, mines = 3;
	vector< vector < char > > realBoard(row, vector<char> (col, 'e'));
	vector< vector < char > > playBoard(row, vector<char> (col, 'e'));
	vector<int> startOrigin(2);
	char decision = ' ';
	
	time_t start = time(0);
	
	startOrigin = createRealBoard(realBoard, mines, decision);
	cout << endl << startGame(realBoard, playBoard, startOrigin, decision) << "in ";
	
	double elapsed_secs = difftime( time(0), start);
	cout << elapsed_secs << " seconds" << endl;
	
}

void print(const vector < vector < char > > & mBoard)
{
	cout << "x/y ";
	for (int j = 0; j < mBoard.size(); j++)
		cout << j << ' ';
	cout << endl;
	for (int i = 0; i < mBoard.size(); i++)
	{
		cout << ' ' << i << "  ";
		for (int j = 0; j < mBoard.size(); j++)
			cout << mBoard[i][j] << " ";
		cout << endl;
	}
}

vector<int> createRealBoard(vector<vector<char> > & realBoard, int mines, char & decision)
{
	int minesTMP = mines;
	print(realBoard);
	char dec;
	do {
		cout << "Type p/d/f/u respectively to pick, double click, flag, or remove flag: ";
		cin >> dec;
	}	while (dec != 'f' && dec != 'p' && dec != 'P' && dec != 'F' && 
			dec != 'd' && dec != 'D' && dec != 'u' && dec != 'U');
			
	char xTMP, yTMP;
	do {
		cout << "Choose your x co-ordinate: ";
		cin >> xTMP;
		cout << "Choose your y co-ordinate: ";
		cin >> yTMP;
	}	while (xTMP - '0' < 0 || xTMP - '0' >= realBoard.size() || yTMP - '0' < 0 || yTMP - '0' >= realBoard[0].size());
	
	int x = xTMP - '0', y = yTMP - '0';
	vector<int> result; result.push_back(x); result.push_back(y);
	decision = dec;
	
	while (minesTMP > 0)
	{
		for (int r = 0; r < realBoard.size(); r++)
		{
			for (int c = 0; c < realBoard[0].size(); c++)
			{
				int x = rand() % 10;
				if (x == 0)
				{
					if (minesTMP > 0 && (r != x || c != y))
					{
						minesTMP--;
						realBoard[r][c] = 'M';
					}
					else break;
				}
			}
		}
	}
	
	for (int r = 0; r < realBoard.size(); r++)
	{
		for (int c = 0; c < realBoard[0].size(); c++)
		{
			int minesNum = countMines(realBoard, r, c);
			if (realBoard[r][c] == 'e')
			{
				if (minesNum > 0)
					realBoard[r][c] = minesNum + '0';
				else
					realBoard[r][c] = 'B';
			}
		}
	}
	return result;
}

int countMines(const vector<vector<char> > & realBoard, int x, int y)
{
	int count = 0;
	for (int i = x-1; i <= x+1; i++) {
		for (int j = y-1; j <= y+1; j++) {
			if ((i != x || j != y) && (i >= 0 || j >= 0) && i < realBoard.size() && j < realBoard[0].size() 
					&& realBoard[i][j] == 'M')
				count++; } }
	return count;
}

int countFlags(const vector<vector<char> > & playBoard, int x, int y)
{
	int count = 0;
	for (int i = x-1; i <= x+1; i++) {
		for (int j = y-1; j <= y+1; j++) {
			if ((i != x || j != y) && (i >= 0 || j >= 0) && i < playBoard.size() && j < playBoard[0].size() 
					&& playBoard[i][j] == 'F')
				count++; } }
	return count;
}

void traceBlanks(vector<vector<char> >& realBoard, vector<vector<char> >& playBoard, int x, int y)
{
	queue<pair<int,int> > q; q.push(make_pair(x,y)); playBoard[x][y] = 'B';
	while (!q.empty())
	{
		for (int i = q.front().first - 1; i <= q.front().first + 1; i++)
		{
			for (int j = q.front().second - 1; j <= q.front().second + 1; j++)
			{
				if ((i != q.front().first || j != q.front().second) && (i >= 0 || j >= 0) && 
						i < realBoard.size() && j < realBoard[0].size())
				{
					if (realBoard[i][j] == 'B')
					{
						realBoard[i][j] = 'b';
						playBoard[i][j] = 'B';
						q.push(make_pair(i,j));
					}
					else if (isdigit(realBoard[i][j]))
						playBoard[i][j] = realBoard[i][j];
				}
			}
		}
		q.pop();
	}
	return;
}

bool isWin(const vector<vector<char> > & realBoard, const vector<vector<char> > & playBoard)
{
	for (int i = 0; i < playBoard.size(); i++)
	{
		for (int j = 0; j < playBoard.size(); j++)
		{
			if (playBoard[i][j] == 'E')
				return false;
			if (realBoard[i][j] != 'M')
			{
				if (isdigit(realBoard[i][j]) && realBoard[i][j] != playBoard[i][j])
					return false;
				if (!isdigit(realBoard[i][j]))
				{
					if (realBoard[i][j] == 'b' && playBoard[i][j] != 'B')
						return false;
				}
			}
		}
	}
	return true;
}

string startGame(vector<vector<char> > & realBoard, vector<vector<char> > & playBoard, vector<int> & startOrigin, char & decision)
{
	string condition = ""; int x = startOrigin[0]; int y = startOrigin[1]; char dec = decision;
	do {
		if (dec == 'p' || dec == 'P')
			condition = updateBoard(realBoard, playBoard, x, y);
		else if (dec == 'f' || dec == 'F')
		{
			if (playBoard[x][y] == 'e')
				playBoard[x][y] = 'F'; 
		}
		else if (dec == 'u' || dec == 'U')
		{
			if (playBoard[x][y] == 'F')
				playBoard[x][y] = 'e';
		}
		else //if(dec is double click)
		{
			if (isdigit(playBoard[x][y]) && playBoard[x][y] - '0' == countFlags(playBoard,x,y))
			{
				for (int i = x-1; i <= x+1; i++)
				{
					for (int j = y-1; j <= y+1; j++)
					{
						if ((i != x || j != y) && (i >= 0 || j >= 0) && i < realBoard.size() && j < realBoard[0].size())
							condition = updateBoard(realBoard, playBoard, i, j);
					}
				}
			}
		}
		print(playBoard);
		
		if (condition == "Lose")
			break;
		else if (isWin(realBoard, playBoard))
		{
			condition = "Win";
			break;
		}
		
		do {
			cout << "Type p/d/f/u respectively to pick, double click, flag, or remove flag: ";
			cin >> dec;
		}	while (dec != 'f' && dec != 'p' && dec != 'P' && dec != 'F' && 
				dec != 'd' && dec != 'D' && dec != 'u' && dec != 'U');
				
		char xTMP, yTMP;
		do {
			cout << "Choose your x co-ordinate: ";
			cin >> xTMP;
			cout << "Choose your y co-ordinate: ";
			cin >> yTMP;
		}	while (xTMP - '0' < 0 || xTMP - '0' >= realBoard.size() || yTMP - '0' < 0 || yTMP - '0' >= realBoard[0].size());
		
		x = xTMP - '0';
		y = yTMP - '0';
		
	}	while (condition != "Win" && condition != "Lose");
		
	return condition;
}

string updateBoard (vector<vector<char> >& realBoard, vector<vector<char> >& playBoard, int x, int y)
{
	if (playBoard[x][y] != 'F')
	{
		char selected = realBoard[x][y];
		if (isdigit(selected))
			playBoard[x][y] = selected;
		else if (selected == 'M')
		{
			playBoard[x][y] = 'M';
			return "Lose";
		}
		else if (selected == 'B' || selected == 'b')
			traceBlanks(realBoard, playBoard, x, y);
	}
	return "";
}
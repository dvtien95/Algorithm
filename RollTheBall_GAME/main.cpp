#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void printWallBoard(const vector<vector<char> > & board);
vector<vector<char> > createBoard(vector<int> & a, vector<int> & b);
void GoAllTheWayUp(vector<vector<char> > & playBoard, int & x, int & y, int & score, bool & winCondition);
void GoAllTheWayLeft(vector<vector<char> > & playBoard, int & x, int & y, int & score, bool & winCondition);
void GoAllTheWayDown(vector<vector<char> > & playBoard, int & x, int & y, int & score, bool & winCondition);
void GoAllTheWayRight(vector<vector<char> > & playBoard, int & x, int & y, int & score, bool & winCondition);
int startGame(vector<vector<char> > & playBoard, vector<int> startPosition);

int main()
{
	vector<int> startPosition;
	vector<int> endPosition;
	vector<vector<char> > playBoard = createBoard(startPosition, endPosition);
	
	int score = startGame(playBoard, startPosition);
	cout << "Finishing score: " << score << endl;
}

void printWallBoard(const vector<vector<char> > & board)
{
	cout << "Play Board: " << endl;
	cout << "W ";
	for (int j = 0; j <= board[0].size(); j++)
		cout << "W ";
	cout << endl;
	for (int i = 0; i < board.size(); i++)
	{
		cout << "W ";
		for (int j = 0; j < board[0].size(); j++)
			cout << board[i][j] << ' ';
		cout << "W " << endl;
	}
	cout << "W ";
	for (int j = 0; j <= board[0].size(); j++)
		cout << "W ";
	cout << endl;
}

vector<vector<char> > createBoard(vector<int> & a, vector<int> & b)
{
	vector<vector<char> > playBoard;
	ifstream myFile;
	char s;
	
	do {
		cout << "Which stage do you want to play: ";
		cin >> s;
	} while (cin.fail() && !isdigit(s));
	
	string fileName = "Stage .txt";
	fileName[5] = s;
	
	myFile.open(fileName);
	
	if (myFile.is_open())
	{
		int row = 0, col = 0;
		while (!myFile.eof())
		{
			string line; getline(myFile, line);
			if (line == "") break;
			vector<char> tmpVector;
			for (int i = 0; i < line.length(); i += 2)
			{
				if (line[i] == 'B') {
					a.push_back(row);
					a.push_back(col);
				}
				else if (line[i] == 'E') {
					b.push_back(row);
					b.push_back(col);
				}
				tmpVector.push_back(line[i]);
				col++;
			}
			playBoard.push_back(tmpVector);
			row ++;
			col = 0;
		}
		if (a.empty() || b.empty())
		{
			cout << "Stage is not finished! " << endl;
			exit(-1);
		}
	}
	else
	{
		cout << "File is not opened! " << endl;
		exit(-1);
	}
	
	return playBoard;
}

char askWayToGo()
{
	char dec;
	do {
		cout << "Type w/a/s/d then enter to go all the way up, left, down, right: ";
		cin >> dec;
		cout << endl;
	} while (dec != 'w' && dec != 'a' && dec != 's' && dec != 'd');
	return dec;
}

void GoAllTheWayUp(vector<vector<char> > & playBoard, int & x, int & y, int & score, bool & winCondition)
{
	playBoard[x][y] = '-';
	while (x >= 0 && playBoard[x][y] != 'W') {
		x--;
		score++;
		if (x >= 0 && playBoard[x][y] == 'E')
		{
			winCondition = true;
			playBoard[x][y] = 'B';
			printWallBoard(playBoard);
			return;
		}
	}
	x++; score--;
	playBoard[x][y] = 'B';
	printWallBoard(playBoard);
	return;
}

void GoAllTheWayLeft(vector<vector<char> > & playBoard, int & x, int & y, int & score, bool & winCondition)
{
	playBoard[x][y] = '-';
	while (y >= 0 && playBoard[x][y] != 'W') {
		y--;
		score++;
		if (y >= 0 && playBoard[x][y] == 'E')
		{
			winCondition = true;
			playBoard[x][y] = 'B';
			printWallBoard(playBoard);
			return;
		}
	}
	y++; score--;
	playBoard[x][y] = 'B';
	printWallBoard(playBoard);
	return;
}

void GoAllTheWayDown(vector<vector<char> > & playBoard, int & x, int & y, int & score, bool & winCondition)
{
	playBoard[x][y] = '-';
	while (x < playBoard.size() && playBoard[x][y] != 'W') {
		x++;
		score++;
		if (x < playBoard.size () && playBoard[x][y] == 'E')
		{
			winCondition = true;
			playBoard[x][y] = 'B';
			printWallBoard(playBoard);
			return;
		}
	}
	x--; score--;
	playBoard[x][y] = 'B';
	printWallBoard(playBoard);
	return;
}

void GoAllTheWayRight(vector<vector<char> > & playBoard, int & x, int & y, int & score, bool & winCondition)
{
	playBoard[x][y] = '-';
	while (y < playBoard[0].size() && playBoard[x][y] != 'W') {
		y++;
		score++;
		if (y < playBoard[0].size() && playBoard[x][y] == 'E')
		{
			winCondition = true;
			playBoard[x][y] = 'B';
			printWallBoard(playBoard);
			return;
		}
	}
	y--; score--;
	playBoard[x][y] = 'B';
	printWallBoard(playBoard);
	return;
}

int startGame(vector<vector<char> > & playBoard, vector<int> startPosition)
{
	printWallBoard(playBoard);
	int xCur = startPosition[0], yCur = startPosition[1];
	int score = 0;
	bool winCondition = false;
	
	while (!winCondition)
	{
		char decision = askWayToGo();
		switch (decision)
		{
			case 'w': GoAllTheWayUp(playBoard, xCur, yCur, score, winCondition); break;
			case 'a': GoAllTheWayLeft(playBoard, xCur, yCur, score, winCondition); break;
			case 's': GoAllTheWayDown(playBoard, xCur, yCur, score, winCondition); break;
			case 'd': GoAllTheWayRight(playBoard, xCur, yCur, score, winCondition); break;
			default: break;
		}
	}
	return score;
}

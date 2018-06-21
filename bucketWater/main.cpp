#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

/*BUCKETWATER
Chúng ta có n thùng, 1 ≤ n ≤ 4. Lúc đầu tất cả chúng đều đầy nước. Sức chứa (đơn vị lít) của thùng chứa thứ i là số tự
nhiên oi thỏa mãn: 1 ≤ oi ≤ 49.
Có 3 kiểu thao tác sau:
1. Đổ toàn bộ nước trong một thùng sang thùng khác. Thao tác này chỉ có thể được thực hiện nếu thùng thứ hai
đủ sức chứa.
2. Đổ đầy một thùng chứa với lượng nước từ thùng khác.
3. Đổ bỏ toàn bộ nước trong một thùng.
Viết chương trình: Đọc số lượng n thùng, sức chứa của mỗi thùng và lượng nước mong muốn trong mỗi thùng chứa.
Xác minh xem liệu có tồn tại một loạt các thao tác dẫn đến một trạng thái cuối nào đó không, và nếu có, tính số thao
tác tối thiểu dẫn đến trạng thái được yêu cầu.
INPUT
Dòng đầu tiên là một số nguyên dương n ( n ≤ 4), là số lượng thùng chứa. Dòng thứ 2 chứa n số nguyên dương đây là
sức chứa của các thùng (số nguyên thứ i - oi là sức chứa của thùng thứ i với 1 ≤ oi ≤ 49. Dòng thứ ba có n số là khối
lượng nước được yêu cầu chứa trong n thùng chứa (số nguyên thứ i - wi là lượng nước trong thùng thứ i với 1 ≤ wi ≤
oi ). Các số nguyên cách nhau một khoảng trắng.
OUTPUT
Nếu không có dãy thao tác, in ra NO. Nếu có in ra số thao tác tối thiểu.*/

void displayVectorOfPair(const vector<pair<int, int> > & a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i].first << ' ' << a[i].second << endl;
	cout << endl;
}

void resetStats(vector<pair<int , int> > & a)
{
	for (int i = 0; i < a.size(); i++)
		a[i].second = a[i].first;
}

int do4bucket(vector<pair<int, int> > status, const vector<pair<int, int> > & requirement);
int do3bucket(vector<pair<int, int> > status, const vector<pair<int, int> > & requirement);
int do2bucket(vector<pair<int, int> > status, const vector<pair<int, int> > & requirement);
int do1bucket(vector<pair<int, int> > status, const vector<pair<int, int> > & requirement);

int main()
{
	char c; string word; int result;
	vector<pair<int, int> > requirement;
	vector<pair<int, int> > status;
	
	ifstream myFile;
	myFile.open("bucket.txt");
	
	int n = myFile.get() - '0';
	myFile.get();
	cout << "n = " << n << endl;
	
	for (int i = 0; i < n; i++)
	{
		c = myFile.get();
		word += c;
		while (c != ' ' && c != '\n')
		{
			c = myFile.get();
			word += c;
		}
		requirement.push_back(make_pair(stoi(word),0));
		status.push_back(make_pair(stoi(word),0));
		word = "";
	}
	
	for (int i = 0; i < n; i++)
	{
		c = myFile.get();
		word += c;
		while (c != ' ' && c != '\n' && !myFile.eof())
		{
			c = myFile.get();
			word += c;
		}
		requirement[i].second = stoi(word);
		status[i].second = stoi(word);
		word = "";
	}
	
	sort(requirement.begin(), requirement.end()); sort(status.begin(), status.end());
	displayVectorOfPair(requirement);
	cout << endl;
	resetStats(status);
	
	if (n == 4)
	{
		result = do4bucket(status, requirement);
	}
	else if (n == 3)
	{
		result = do3bucket(status, requirement);
	}
	else if (n == 2)
	{
		result = do2bucket(status, requirement);
	}
	else
	{
		result = do1bucket(status, requirement);
	}
	
	if (result == -1)
		cout << "NO" << endl;
	else
		cout << result << " thao tac " << endl;
}

int do4bucket(vector<pair<int, int> > status, const vector<pair<int, int> > & requirement)	// n = 4
{
	int currentMinResult = INT_MAX;
	int target = requirement[3].second;
	
	if (target == status[3].first)
		return do3bucket(status, requirement);
	else if (target == 0)
	{
		return 1 + do3bucket(status, requirement);
	}
		
	vector<int> listOfThree;
	int currentMinStep = INT_MAX;
	
	for (int a = 0; a <= target/status[0].first; a++)
	{
		for (int b = 0; b <= target/status[1].first; b++)
		{
			for (int c = 0; c <= target/status[2].first; c++)
			{
				if (status[0].first*a + status[1].first*b + status[2].first*c == target)
				{
					int tmpStep = a + b + c;
					if (listOfThree.empty() || tmpStep == currentMinStep)
					{
						listOfThree.push_back(a); listOfThree.push_back(b); listOfThree.push_back(c);
						currentMinStep = tmpStep;
					}
					else
					{
						if (tmpStep < currentMinStep)
						{
							listOfThree.clear();
							listOfThree.push_back(a); listOfThree.push_back(b); listOfThree.push_back(c);
							currentMinStep = tmpStep;
						}
					}
				}
			}
		}
	}
	
	//cout << "List 3: " << endl; for (int i = 0; i < listOfThree.size(); i+= 3) cout << listOfThree[i] << ' ' << listOfThree[i+1] << ' ' << listOfThree[i+2] << endl;
	
	if (listOfThree.size() == 0)
		return -1;

	int a = status[0].second; int b = status[1].second; int c = status[2].second;
	for (int i = 0; i < listOfThree.size(); i += 3)
	{
		int steps = 0;
		//cout << listOfThree[i] << ' ' << listOfThree[i+1] << ' ' << listOfThree[i+2] << endl;
		for (int j = i; j < i + 3; j++)
		{
			if (listOfThree[j] != 0)
			{
				if (status[j%3].second == status[j%3].first) // if full tank
				{
					steps += listOfThree[j]*2 - 1;
					status[j%3].second = 0;
				}
				else
				{
					steps += listOfThree[j]*2;
					status[j%3].second = 0;
				}
			}
		}

		status[3].second = target;

		if (status[3].second != 0)
		{
			int tmp3 = do3bucket(status, requirement);
			if (tmp3 == -1)
				return -1;
			else
				steps = steps + 1 + tmp3;
		}
		else
		{
			int tmp3 = do3bucket(status, requirement);
			if (tmp3 == -1)
				return -1;
			else
				steps = steps + tmp3;
		}
			
		if (currentMinResult > steps)
			currentMinResult = steps;
		
		// Reset status
		status[0].second = a; status[1].second = b; status[2].second = c;
	}
	
	
	return currentMinResult;
}

int do3bucket(vector<pair<int, int> > status, const vector<pair<int, int> > & requirement)	// n = 3
{
	int currentMinResult = INT_MAX;
	int target = requirement[2].second;
	
	
	if ( (target == status[2].first && status[2].second == status[2].first ) || (target == 0 && status[2].second == 0) ) 
		return do2bucket(status, requirement);
	else if ( (target == 0 && status[2].second == status[2].first ) || (target == status[2].first && status[2].second == 0) )
	{
		return 1 + do2bucket(status, requirement);
	}
		
	vector<int> listOfTwo;
	int currentMinStep = INT_MAX;
	
	for (int a = 0; a <= target/status[0].first; a++)
	{
		for (int b = 0; b <= target/status[1].first; b++)
		{
			if (status[0].first*a + status[1].first*b == target)
			{
				int tmpStep = a + b;
				if (listOfTwo.empty() || tmpStep == currentMinStep)
				{
					listOfTwo.push_back(a); listOfTwo.push_back(b);
					currentMinStep = tmpStep;
				}
				else
				{
					if (tmpStep < currentMinStep)
					{
						listOfTwo.clear();
						listOfTwo.push_back(a); listOfTwo.push_back(b);
						currentMinStep = tmpStep;
					}
				}
			}
		}
	}
	
	
	//cout << "List 2: " << endl; for (int i = 0; i < listOfTwo.size(); i+= 2) cout << listOfTwo[i] << ' ' << listOfTwo[i+1] << endl;
	
	if (listOfTwo.size() == 0)
		return -1;
		
	int a = status[0].second; int b = status[1].second;
	for (int i = 0; i < listOfTwo.size(); i += 2)
	{
		int steps = 0;
		//cout << listOfTwo[i] << ' ' << listOfTwo[i+1] << endl;
		for (int j = i; j < i + 2; j++)
		{
			if (listOfTwo[j] != 0)
			{
				if (status[j%2].second == status[j%2].first) // if full tank
				{
					steps += listOfTwo[j]*2 - 1;
					status[j%2].second = 0;
				}
				else
				{
					steps += listOfTwo[j]*2;
					status[j%2].second = 0;
				}
			}
		}
		
		if (status[2].second != 0)
		{
			int tmp2 = do2bucket(status, requirement);
			if (tmp2 == -1)
				return -1;
			else
			{
				steps = steps + 1 + tmp2;
			}
		}
		else
		{
			int tmp2 = do2bucket(status, requirement);
			if (tmp2 == -1)
				return -1;
			else
				steps = steps + tmp2;
		}
			
		if (currentMinResult > steps)
			currentMinResult = steps;

		// Reset status
		status[0].second = a; status[1].second = b;
	}
	
	return currentMinResult;
}

int do2bucket(vector<pair<int, int> > status, const vector<pair<int, int> > & requirement)	// n = 2
{
	int currentMinResult = INT_MAX;
	int target = requirement[1].second;
	
	if ( (target == status[1].first && status[1].second == status[1].first ) || (target == 0 && status[1].second == 0) ) 
	{
		return do1bucket(status, requirement);
	}
	else if ( (target == 0 && status[1].second == status[1].first ) || (target == status[1].first && status[1].second == 0) )
	{
		return 1 + do1bucket(status, requirement);
	}
		
	vector<int> listOfOne;
	int currentMinStep = INT_MAX;
	
	for (int a = 0; a <= target/status[0].first; a++)
	{
		if (status[0].first*a == target)
		{
			int tmpStep = a;
			if (listOfOne.empty() || tmpStep == currentMinStep)
			{
				listOfOne.push_back(a);
				currentMinStep = tmpStep;
			}
			else
			{
				if (tmpStep < currentMinStep)
				{
					listOfOne.clear();
					listOfOne.push_back(a);
					currentMinStep = tmpStep;
				}
			}
		}
	}
	
	
	//cout << "List 1: " << endl; for (int i = 0; i < listOfOne.size(); i+= 1) cout << listOfOne[i] << endl;
	
	if (listOfOne.size() == 0)
		return -1;
		
	int a = status[0].second;
	for (int i = 0; i < listOfOne.size(); i += 1)
	{
		int steps = 0;
		//cout << listOfOne[i] << endl;
		for (int j = i; j < i + 1; j++)
		{
			if (listOfOne[j] != 0)
			{
				if (status[j%1].second == status[j%1].first) // if full tank
				{
					steps += listOfOne[j]*2 - 1;
					status[j%1].second = 0;
				}
				else
				{
					steps += listOfOne[j]*2;
					status[j%1].second = 0;
				}
			}
		}
		
		status[1].second = target;
		
		if (status[1].second != 0)
		{
			int tmp1 = do1bucket(status, requirement);
			if (tmp1 == -1)
				return -1;
			else
				steps = steps + 1 + tmp1;
		}
		else
		{
			int tmp1 = do1bucket(status, requirement);
			if (tmp1 == -1)
				return -1;
			else
				steps = steps + tmp1;
		}
			
		if (currentMinResult > steps)
			currentMinResult = steps;

		// Reset status
		status[0].second = a;
	}
	
	
	return currentMinResult;
}

int do1bucket(vector<pair<int, int> > status, const vector<pair<int, int> > & requirement)	// n = 1
{
	int target = requirement[0].second;
	
	if ( (target == status[0].first && status[0].second == status[0].first ) || (target == 0 && status[0].second == 0) ) 
		return 0;
	else if ( (target == 0 && status[0].second == status[0].first ) || (target == status[0].first && status[0].second == 0) )
	{
		return 1;
	}
	else
		return -1;
}
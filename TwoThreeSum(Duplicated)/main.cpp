#include <iostream>
#include <string>
#include <vector>

using namespace std;

int factorial(int n);
int TwoSum(const vector<int> & a, int begin, int target);
int ThreeSum(const vector<int> & a, int begin, int target);
int FourSum(const vector<int> & a, int begin, int target);
void printValueInAVector(const vector<int> & a);

int main()
{
	vector<int> a;
	a.push_back(0); a.push_back(3); a.push_back(5); a.push_back(6), a.push_back(7); a.push_back(9); a.push_back(10);
	a.push_back(12); a.push_back(14); a.push_back(15); a.push_back(18);
	
	printValueInAVector(a);
	
	//int TwoSum(const vector<int> & a, int begin, int target)
	//cout << "TwoSum with target 8: " << TwoSum(a, 0, 8) << endl;
	
	cout << "ThreeSumCount target 6: " << ThreeSum(a, 0, 19) << endl;
	
	//cout << "FourSumCount target 12: " << FourSum(a,0,1) << endl;
}

int factorial(int n)
{
	if (n == 0)
		return 0;
	int num = 1;
	for (int i = 1; i <= n; i++)
		num *= i;
	
	return num;
}

int TwoSum(const vector<int> & a, int begin, int target)
{
	int end = a.size() - 1;
	int count = 0;
	while (begin < end)
	{
		if (a[begin] + a[end] < target)
			begin ++;
		else if (a[begin] + a[end] > target)
			end --;
		else
		{
			if (a[begin] != a[end])
			{
				cout << a[begin] << ' ' << a[end] ;
				int x = 1, y = 1;
				while (a[begin] == a[begin+1] && begin < end)
				{
					begin++;
					x++;
				}
				while (a[end] == a[end-1] && begin < end)
				{
					end--;
					y++;
				}
				count += x*y;
				begin ++;
				end --;
			}
			else
			{
				count += factorial(begin + end - 1) / (factorial(2) * factorial(begin + end - 1 - 2));
				break;
			}
 		}
	}
	return count;
}

int ThreeSum(const vector<int> & a, int begin, int target)
{
	int count = 0;
	
	for (; begin < a.size() - 2; begin ++)
	{
		cout << a[begin] << "is ";
		int c = TwoSum(a, begin + 1, target - a[begin]);
		cout << endl;
		count += c;
	}
	
	return count;
}

int FourSum(const vector<int> & a, int begin, int target)
{
	int count = 0;
	
	for (; begin < a.size() - 2; begin ++)
		count += ThreeSum(a, begin + 1, target - a[begin]);
	
	return count;
}

void printValueInAVector(const vector<int> & a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << endl;
}


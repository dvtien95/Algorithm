#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> list;
	int num; cin >> num;
	while(num!=0)
	{
		list.push_back(num);
		cin >> num;
	}

	sort(list.begin(),list.end());

	if(list.size()<3)
	{
		cout << "NO";
		return 0;
	}

	for(int i=2;i<list.size();i++)
	{
		if(list[i-1]+list[i-2]>list[i])
		{
			cout << list[i] << ' ' << list[i+1] << ' ' << list[i+2];
			return 0;
		}
	}
	
	cout << "NO" << endl;
	return 0;
}


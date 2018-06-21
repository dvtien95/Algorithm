#include <vector>
#include <iostream>

using namespace std;

void displayVector(const vector<int> & a);
int binarySearchIterative(const vector<int> & a, int l, int r, int target);
int binarySearchRecursive(const vector<int> & a, int l, int r, int target);
void insertionSort(vector<int> & a);
void bubleSort(vector<int> & a);
void mergeSort(vector<int> & a, int l, int r);
void mergeArray(vector<int> & a, int l, int m, int r)

int main()
{
	vector<int> a; a.push_back(4); a.push_back(3); a.push_back(2); a.push_back(10); a.push_back(12);
	a.push_back(1); a.push_back(5); a.push_back(6);
	
	bubleSort(a); displayVector(a);
	
	
}

void displayVector(const vector<int> & a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << endl;
}

int binarySearchIterative(const vector<int> & a, int l, int r, int target)
{
	if (a.size() == 0)
		return -1;
	while (l <= r)
	{
		int mid = l + (r - l)/2;
		if (a[mid] < target)
			l = mid + 1;
		else if (a[mid] == target)
			return mid;
		else
			r = mid - 1;
	}
	return -1;
}

int binarySearchRecursive(const vector<int> & a, int l, int r, int target)
{
	if (a.size() == 0)
		return -1;
	int mid = (l + r)/2;
	if (a[mid] == target)
		return mid;
	else if (target > a[mid])
		return binarySearchRecursive(a, mid + 1, r, target);
	else
		return binarySearchRecursive(a, l, mid-1, target);
}

void insertionSort(vector<int> & a)
{
	for (int i = 1; i < a.size(); i ++)
	{
		int key = a[i];
		int j = i - 1;
		while (j >=  0 && a[j] > key)
		{
			a[j+1] = a[j];
			j = j - 1;
		}
		a[j+1] = key;
	}
}

void bubleSort(vector<int> & arr)
{
   int i, j;
   bool swapped;
   for (i = 0; i < arr.size(); i++)
   {
     swapped = false;
     for (j = 0; j < arr.size()-i; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(arr[j], arr[j+1]);
           swapped = true;
        }
     }
 
     // IF no two elements were swapped by inner loop, then break
     if (swapped == false)
        break;
   }
}

void mergeArray(vector<int> & a, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    vector<int> leftArray;
	vector<int> rightArray;
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < m && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> & a, int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m+1, r);
		mergeArray(a, l, m, r);
	}
}






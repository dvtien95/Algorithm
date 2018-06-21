#include "Algorithm.h"
#include "Windows.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));
	
	const int numOfTest = 15;
	int sizeSelection[numOfTest] = {10,50,100,200,300,400,500,1000,2000,3000,4000,5000,10000,50000,100000};
	
	int size;
	int theArray[size];
	
	Algorithm a;
	
	cout << "Test cases on random data " << endl;
	cout << "Arraysize" << "	" << "Bubble" << "	" << "Insertion" << "	" << "MergeSort" << "	" << "Quicksort" << endl;
	for (int i=0; i<numOfTest; i++)
	{
		int BubbleSortTime, InsertionSortTime, MergeSortTime, QuickSortTime;
		size = sizeSelection[i];
		for (int i = 0; i < size; i++)
			theArray[i] = rand()%size;
		DWORD begin, end;
		
		begin = GetTickCount();
		a.bubbleSort(theArray,size);
		end = GetTickCount();
		BubbleSortTime = end - begin;
		
		begin = GetTickCount();
		a.insertionSort(theArray, size);
		end = GetTickCount();
		InsertionSortTime = end - begin;
		
		begin = GetTickCount();
		a.mergesort(theArray, 0, size-1);
		end = GetTickCount();
		MergeSortTime = end - begin;
		
		begin = GetTickCount();
		a.quicksort(theArray, 0, size -1);
		end = GetTickCount();
		QuickSortTime = end - begin;
		
		cout << "size	" << "	" << BubbleSortTime << "	" << InsertionSortTime << "	"
			<< MergeSortTime << "	" << QuickSortTime << endl;
	}
	
	return 0;
}
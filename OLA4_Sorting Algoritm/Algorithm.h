#ifndef ALGORITHM_H
#define ALGORITHM_H

typedef int DataType;

class Algorithm
{
public:
	Algorithm();
	
	void bubbleSort(DataType theArray[], int n);
	
	void insertionSort(DataType theArray[], int n);
	
	void mergesort(DataType theArray[], int first, int n);
	
	void quicksort(DataType theArray[], int first, int n);
	
	~Algorithm();

};

#endif // ALGORITHM_H

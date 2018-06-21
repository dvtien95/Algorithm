#include "Algorithm.h"

Algorithm::Algorithm()
{
}

void swap(DataType& x, DataType& y)
// ---------------------------------------------------
// Swaps two items.
// Precondition: x and y are the items to be swapped.
// Postcondition: Contents of actual locations that x 
// and y represent are swapped.
// ---------------------------------------------------
{
   DataType temp = x;
   x = y;
   y = temp;
}

void Algorithm::bubbleSort(DataType theArray[], int n)
// ---------------------------------------------------
// Sorts the items in an array into ascending order.
// Precondition: theArray is an array of n items.
// Postcondition: theArray is sorted into ascending
// order; n is unchanged.
// Calls: swap.
// ---------------------------------------------------
{
   bool sorted = false;  // false when swaps occur

   for (int pass = 1; (pass < n) && !sorted; ++pass)
   {  // Invariant: theArray[n+1-pass..n-1] is sorted
      //            and > theArray[0..n-pass]
      sorted = true;  // assume sorted
      for (int index = 0; index < n-pass; ++index)
      {  // Invariant: theArray[0..index-1] <= 
         // theArray[index]
         int nextIndex = index + 1;
         if (theArray[index] > theArray[nextIndex])
         {  // exchange items
            swap(theArray[index], theArray[nextIndex]);
            sorted = false;  // signal exchange
         }  // end if
      }  // end for

      // Assertion: theArray[0..n-pass-1] < 
      // theArray[n-pass]
   }  // end for
}  // end bubbleSort


void Algorithm::insertionSort(DataType theArray[], int n)
// ---------------------------------------------------
// Sorts the items in an array into ascending order.
// Precondition: theArray is an array of n items.
// Postcondition: theArray is sorted into ascending
// order; n is unchanged.
// ---------------------------------------------------
{
   // unsorted = first index of the unsorted region, 
   // loc = index of insertion in the sorted region, 
   // nextItem = next item in the unsorted region

   // initially, sorted region is theArray[0], 
   //            unsorted region is theArray[1..n-1];
   // in general, sorted region is 
   //             theArray[0..unsorted-1], 
   // unsorted region is theArray[unsorted..n-1]

   for (int unsorted = 1; unsorted < n; ++unsorted)
   {  // Invariant: theArray[0..unsorted-1] is sorted

      // find the right position (loc) in 
      // theArray[0..unsorted] for theArray[unsorted], 
      // which is the first item in the unsorted 
      // region; shift, if necessary, to make room
      DataType nextItem = theArray[unsorted];
      int loc = unsorted;

      for (;(loc > 0) && (theArray[loc-1 ]> nextItem);
            --loc)
         // shift theArray[loc-1] to the right
         theArray[loc] = theArray[loc-1];

      // Assertion: theArray[loc] is where nextItem 
      // belongs

      // insert nextItem into Sorted region
      theArray[loc] = nextItem;
   }  // end for
}  // end insertionSort


const int MAX_SIZE = 10;

void merge(DataType theArray[], 
           int first, int mid, int last)
// ---------------------------------------------------------
// Merges two sorted array segments theArray[first..mid] and 
// theArray[mid+1..last] into one sorted array.
// Precondition: first <= mid <= last. The subarrays 
// theArray[first..mid] and theArray[mid+1..last] are each 
// sorted in increasing order.
// Postcondition: theArray[first..last] is sorted.
// Implementation note: This function merges the two
// subarrays into a temporary array and copies the result
// into the original array theArray.
// ---------------------------------------------------------
{
   DataType tempArray[MAX_SIZE];    // temporary array

   // initialize the local indexes to indicate the subarrays
   int first1 = first;       // beginning of first subarray
   int last1  = mid;         // end of first subarray
   int first2 = mid + 1;     // beginning of second subarray
   int last2  = last;        // end of second subarray

   // while both subarrays are not empty, copy the
   // smaller item into the temporary array
   int index = first1;    // next available location in 
                          // tempArray
   for (; (first1 <= last1) && (first2 <= last2); ++index)
   {  // Invariant: tempArray[first1..index-1] is in order
      if (theArray[first1] < theArray[first2])
      {  tempArray[index] = theArray[first1];
         ++first1;
      }
      else
      {  tempArray[index] = theArray[first2];
         ++first2;
      }  // end if
   }  // end for

   // finish off the nonempty subarray

   // finish off the first subarray, if necessary
   for (; first1 <= last1; ++first1, ++index)
      // Invariant: tempArray[first1..index-1] is in order
      tempArray[index] = theArray[first1];

   // finish off the second subarray, if necessary
   for (; first2 <= last2; ++first2, ++index)
      // Invariant: tempArray[first1..index-1] is in order
      tempArray[index] = theArray[first2];

   // copy the result back into the original array
   for (index = first; index <= last; ++index)
      theArray[index] = tempArray[index];
}  // end merge


void Algorithm::mergesort(DataType theArray[], int first, int last)
// ---------------------------------------------------------
// Sorts the items in an array into ascending order. 
// Precondition: theArray[first..last] is an array.
// Postcondition: theArray[first..last] is sorted in 
// ascending order.
// Calls: merge.
// ---------------------------------------------------------
{
   if (first < last)
   {  // sort each half
      int mid = (first + last)/2;    // index of midpoint
      // sort left half theArray[first..mid]
      mergesort(theArray, first, mid);
      // sort right half theArray[mid+1..last]
      mergesort(theArray, mid+1, last);

      // merge the two halves
      merge(theArray, first, mid, last);
   }  // end if
}  // end mergesort


void choosePivot(DataType theArray[], int first, int last)
// ---------------------------------------------------------
// Chooses a pivot for quicksortÕs partition algorithm and 
// swaps it with the first item in an array.
// Precondition: theArray[first..last] is an array; 
// first <= last.
// Postcondition: theArray[first] is the pivot.
// ---------------------------------------------------------
// Implementation left as an exercise.
{
	int index = (first + last) / 2;
	swap(theArray[first],theArray[index]);
}

void partition(DataType theArray[], int first, int last, int& pivotIndex)
// ---------------------------------------------------------
// Partitions an array for quicksort.
// Precondition: theArray[first..last] is an array; 
// first <= last.
// Postcondition: Partitions theArray[first..last] such 
// that:
//    S1 = theArray[first..pivotIndex-1] <  pivot
//         theArray[pivotIndex]          == pivot
//    S2 = theArray[pivotIndex+1..last]  >= pivot
// Calls: choosePivot and swap.
// ---------------------------------------------------------
{
   // place pivot in theArray[first]
   choosePivot(theArray, first, last);
   DataType pivot = theArray[first];     // copy pivot

   // initially, everything but pivot is in unknown
   int lastS1 = first;           // index of last item in S1
   int firstUnknown = first + 1; // index of first item in 
                                 // unknown

   // move one item at a time until unknown region is empty
   for (; firstUnknown <= last; ++firstUnknown)
   {  // Invariant: theArray[first+1..lastS1] < pivot
      //         theArray[lastS1+1..firstUnknown-1] >= pivot

      // move item from unknown to proper region
      if (theArray[firstUnknown] < pivot)
      {  // item from unknown belongs in S1
         ++lastS1;
         swap(theArray[firstUnknown], theArray[lastS1]);
      }  // end if

      // else item from unknown belongs in S2
   }  // end for

   // place pivot in proper position and mark its location
   swap(theArray[first], theArray[lastS1]);
   pivotIndex = lastS1;
}  // end partition

void Algorithm::quicksort(DataType theArray[], int first, int last)
// ---------------------------------------------------------
// Sorts the items in an array into ascending order.
// Precondition: theArray[first..last] is an array.
// Postcondition: theArray[first..last] is sorted.
// Calls: partition.
// ---------------------------------------------------------
{
   int pivotIndex;

   if (first < last)
   {  // create the partition: S1, pivot, S2
      partition(theArray, first, last, pivotIndex);

      // sort regions S1 and S2
      quicksort(theArray, first, pivotIndex-1);
      quicksort(theArray, pivotIndex+1, last);
   }  // end if
}  // end quicksort


Algorithm::~Algorithm()
{
}
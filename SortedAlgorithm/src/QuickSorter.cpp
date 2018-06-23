#include <iostream>
#include "QuickSorter.h"
using namespace std;

QuickSorter::QuickSorter(string name) : VectorSorter(name) {}

QuickSorter::~QuickSorter() {}

void QuickSorter::run_sort_algorithm() throw (string)
												{
	quicksort(0, size-1);
												}

void QuickSorter::quicksort(const int left, const int right)
{
	// Continue the recursive calls until the indexes cross.
	if (left <= right)
	{
		// Choose the pivot and partition this subrange.
		Element& pivot = choose_pivot(left, right);
		int p = partition(left, right, pivot);

		quicksort(left, p-1);  // Sort elements <  pivot
		quicksort(p+1, right); // Sort elements >= pivot
	}
}

Element& QuickSorter::choose_pivot(const int left, const int right)
{
	return choose_pivot_strategy(left, right);
}



int QuickSorter::partition(const int left, const int right, const Element& pivot)
{
	/***** Complete this member function. *****/
	//Reference-:http://www.algolist.net/Algorithms/Sorting/Quicksort

	int i,j;
	i= left-1;  // moves to the right
	j = right;   // moves to the left.

	while (i < j) {

		do
		{
			i++;
			compare_count++;   // Move i to right

		} while ((i <= right) && (data[i] < pivot));

		do
		{
			j--;
			compare_count++;   // Move j to left

		} while ((j >= left) && (data[j] > pivot));

		if (i < j)
		{
			swap(i, j);  // Swap only if necessary
		}
	}

	swap(i, right);  // restore the pivot
	return i;
}

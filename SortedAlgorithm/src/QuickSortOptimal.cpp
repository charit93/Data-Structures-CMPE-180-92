#include "QuickSortOptimal.h"

QuickSortOptimal::QuickSortOptimal() : QuickSorter("Quicksort optimal") {} // Constructor

QuickSortOptimal::~QuickSortOptimal() {} // Destructor

Element& QuickSortOptimal::choose_pivot_strategy(const int left, const int right)
{
	// Reference - https://stackoverflow.com/questions/10714207/c-quicksort-pivot-optimization
	int middle = (left + right)/2;

	// Order the left, center, and right elements.
	if (data[middle] < data[left])
	{
		swap(left, middle);
	}
	if (data[right]  < data[left])
	{
		swap(left, right);
	}
	if (data[right]  < data[middle]){
		swap(middle, right);
	}
	compare_count += 3;

	swap(middle, right);  // Swapping to rightmost position temporarily

	return data[right];
}

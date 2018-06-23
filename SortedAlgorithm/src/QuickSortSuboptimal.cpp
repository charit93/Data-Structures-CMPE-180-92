#include "QuickSortSuboptimal.h"

QuickSortSuboptimal::QuickSortSuboptimal() : QuickSorter("Quicksort suboptimal") {} // constructor

QuickSortSuboptimal::~QuickSortSuboptimal() {} // Destructor


Element& QuickSortSuboptimal::choose_pivot_strategy(const int left, const int right)
{

	swap(left, right);  // Swapping to rightmost position for temporary

	return data[right];
}

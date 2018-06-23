#include "ShellSortSuboptimal.h"


ShellSortSuboptimal::ShellSortSuboptimal() : VectorSorter("Shellsort suboptimal") {} // constructor

ShellSortSuboptimal::~ShellSortSuboptimal() {} // Destructor


void ShellSortSuboptimal::run_sort_algorithm()
{
	//Reference: http://www.sanfoundry.com/cplusplus-program-implement-shell-sort/
	for (int h = size/2; h >= 1; h /= 2)  // Reducing Vector size by 2
	{

		for (int insert = h; insert < size; insert++) // Insertion sort
		{
			Element elmnt = data[insert];  // next data element to check
			int j = insert;

			while ((j >= h) && (elmnt < data[j-h])) // Comparing Elements that are h apart
			{
				data[j] = data[j-h];
				move_count++;
				compare_count++;
				j -= h;
			}

			if (j >= h)
			{
				compare_count++;
			}

			if (insert != j)    // Moving element in its prpoer place
			{
				data[j] = elmnt;
				move_count++;
			}
		}
	}
}

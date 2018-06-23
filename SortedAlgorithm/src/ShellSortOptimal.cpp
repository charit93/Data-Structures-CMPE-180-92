#include "ShellSortOptimal.h"

ShellSortOptimal::ShellSortOptimal() :VectorSorter("Shellsort optimal") {} // constructor

ShellSortOptimal::~ShellSortOptimal() {} // Destructor

//Run the optimal shellsort algorithm.
//According to Don Knuth:
//h = 3*i + 1 for i = 0, 1, 2, ... used in reverse.


void ShellSortOptimal::run_sort_algorithm()
{
	//REF: Malik Textbook
	//Reference: ftp://ftp.cs.princeton.edu/pub/cs226/linksort/shellsort.c

	int h = 1,j,insert;
	while (h < size) h = 3*h + 1;

	// For each value of h ...
	for (h = (h-1)/3; h >= 1; h = (h-1)/3)
	{
		for (insert = h; insert < size; insert++)  // Performing insertion sort
		{
			Element tmp = data[insert];  // next data element to check
			j = insert;

			while ((j >= h) && (tmp < data[j-h]))   // Next data element drifts into its proper place
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
			if (insert != j)   // Moving next element to proper place
			{
				data[j] = tmp;
				move_count++;
			}
		}
	}
}

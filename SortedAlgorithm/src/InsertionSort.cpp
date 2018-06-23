#include "InsertionSort.h"


InsertionSort::InsertionSort() : VectorSorter("Insertion sort") {} // Constructor

InsertionSort::~InsertionSort() {} // Destructor.

void InsertionSort::run_sort_algorithm() // insertion sort algorithm.
{
	//https://codereview.stackexchange.com/questions/110793/insertion-sort-in-c
	int i,j;

	for (i = 1; i < data.size(); i++) {
		j = i;
		Element tmp = data[j];
		while (j > 0 && data[j - 1] > data[j]) {
			compare_count++;
			move_count++;
			data[j]= data[j-1];
			data[j-1] = tmp;
			j--;
		}
		if(j!=0)
		{
			compare_count++;
		}


	}

}

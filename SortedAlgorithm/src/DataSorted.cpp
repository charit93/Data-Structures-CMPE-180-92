#include "DataSorted.h"


DataSorted::DataSorted() : DataGenerator("Already sorted") {} // constructor.

DataSorted:: ~DataSorted() {} // Destructor.



void DataSorted::generate_data(vector<Element>& data, int size) // Generate already sorted values (low to high) to fill a vector.
{
	for (long i = 0; i < size; i++) data.push_back(Element(i));
}

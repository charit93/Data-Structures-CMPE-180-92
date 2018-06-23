#include "DataReverseSorted.h"

DataReverseSorted::DataReverseSorted() : DataGenerator("Reverse sorted") {} //  constructor.

DataReverseSorted:: ~DataReverseSorted() {} // Destructor

void DataReverseSorted::generate_data(vector<Element>& data, int size) // reverse sorted values from high to low
{
	for (long i = 0; i < size; i++) data.push_back(Element(size - i));
}

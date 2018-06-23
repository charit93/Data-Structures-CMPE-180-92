#include "DataAllZeros.h"

DataAllZeros::DataAllZeros() : DataGenerator("All zeroes") {} // Constructor

DataAllZeros::~DataAllZeros() {}  //Destructor.

void DataAllZeros::generate_data(vector<Element>& data, int size) // Filling data vector so generating all zeros
{
	for (int i = 0; i < size; i++) data.push_back(Element(0));
}

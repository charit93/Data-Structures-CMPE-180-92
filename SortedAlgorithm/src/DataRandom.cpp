#include <stdlib.h>
#include <time.h>
#include "DataRandom.h"
#include "Element.h"


DataRandom::DataRandom() : DataGenerator("Unsorted random") {} //Default constructor.

DataRandom::~DataRandom() {} //Destructor.


void DataRandom::generate_data(vector<Element>& data, int size) // Reuse previous generated data
{
	data.clear();

	if (random_data.size() == size)
	{
		data = random_data;
	}

	else
	{
		random_data.clear();
		srand(time(NULL));  // seed the random number generator

		for (int i = 0; i < size; i++)
		{
			long r = rand()%size;
			Element elmt(r);
			random_data.push_back(elmt);
			data.push_back(elmt);
		}
	}
}

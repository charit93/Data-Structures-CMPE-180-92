#include <iostream>
#include <vector>
#include <string>
#include "WordVector.h"

using namespace std;

WordVector::WordVector()
{
}

WordVector::~WordVector()
{
	data.clear();

}
int WordVector::size()
{
	return data.size();
}

Word WordVector::operator [](const int index)
{
	return data[index];
}

int WordVector::get_count(const string text) const
{
	/***** Complete this function. *****/
	int index = find(text, 0, data.size()-1);
	return index >= 0 ? data[index].get_count() : -1;

}

void WordVector::insert(const string text)
{
	/***** Complete this function. *****/
	steady_clock::time_point start = steady_clock().now(); // Start Timer
	vector<Word>::iterator begin,end;
	begin = data.begin();
	end = data.end();
	int index = find(text,0,data.size()-1);
	if(index<0){
		Word x(text);

		index = (-1) * index;
		data.insert(data.begin() + index - 1, x);
	}else{
		(*(begin+index)).increment_count();
	}
	steady_clock::time_point end_time = steady_clock().now();// end timer
	increment_elapsed_time(start,end_time);                  // Elapsed Time


}

vector<Word>::iterator WordVector::search(const string text)
{
	/***** Complete this function. *****/

	steady_clock::time_point start = steady_clock().now();  // Start Timer
	int index = find(text,0,data.size()-1);
	steady_clock::time_point end = steady_clock().now();  // end timer
	increment_elapsed_time(start,end);                  // Elapsed Time

	return index >= 0 ? data.begin() + index : data.end(); 


}

int WordVector::find(const string text, int low, int high) const
{
	/***** Complete this function. *****/

	if(low<=high)
	{
		int mid = (low+high)/2;
		if(data[mid].get_text() == text){
			return mid;
		}else if(data[mid].get_text() < text)
		{
			high = mid-1;
			return find(text,low,mid-1);
		}else{
			low = mid+1;
			return find(text,mid+1,high);
		}
	}else{
		return -(low+1);
	}

}

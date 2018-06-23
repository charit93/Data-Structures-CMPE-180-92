#include <map>
#include <string>
#include<iostream>
#include "WordMap.h"

using namespace std;

WordMap::WordMap() {}

WordMap::~WordMap() {}

map<string, Word>& WordMap::get_data() { return data; }

int WordMap::get_count(const string text) const
{
	/***** Complete this function. *****/
	map<string, Word>::const_iterator it = data.find(text);
	return it != data.end() ? (it->second).get_count() : -1;
}

void WordMap::insert(const string text)
{
	/***** Complete this function. *****/

	steady_clock::time_point start = steady_clock::now();  // start timer
	map<string, Word>::iterator it = data.find(text); // word in the map

	if (it == data.end())  // Entering the word
	{
		data[text] = Word(text);
	}
	else
	{
		(it->second).increment_count();  // increment word count
	}
	steady_clock::time_point end = steady_clock::now(); // count end time
	increment_elapsed_time(start,end); // total elapsed time
}


map<string, Word>::iterator WordMap::search(const string text)
{
	/***** Complete this function. *****/

	steady_clock::time_point start = steady_clock().now(); // start timer
	map<string, Word>::iterator it=data.find(text);  // word in the map
	steady_clock::time_point end_time = steady_clock().now(); // count end time
	increment_elapsed_time(start,end_time); // total elapsed time
	return it;
}

int WordMap::size(){
	return data.size();
}

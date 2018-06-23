#include <iostream>
#include <iterator>
#include "SortedVector.h"

using namespace std;


SortedVector::SortedVector()
{
    Node::reset();
}

SortedVector::~SortedVector()
{
    Node::reset();
}


int SortedVector::size() const { return data.size(); }

bool SortedVector::check() const
{
    if (data.size() == 0) return true;

    vector<Node>::const_iterator it = data.begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it >= *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}
bool SortedVector::check_reversed() const
{
    if (size() == 0) return true;

    vector<Node>::const_iterator it = begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is less than or equal to the previous node.
    while ((it != end()) && (*it <= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}

void SortedVector::prepend(const long value)
{
	Node pr(value);
    data.insert(data.begin(), pr);
}

void SortedVector::append(const long value)
{
	Node ap(value);
	data.push_back(ap);
}


void SortedVector::remove(const int index)
{
    data.erase(data.begin() + index);
}

void SortedVector::reverse()
{
	vector<Node>::iterator start = data.begin();
	vector<Node>::iterator end = data.end();
	while((start != end))
	{
		start++;
		data.insert(data.begin(), *start);
		start = data.erase(start);
	}
}


void SortedVector::insert(const long value)
{
    vector<Node>::const_iterator it = data.begin();
    Node in(value);
    // Look for the appropriate position to insert.
    while ((it != data.end()) && (value > it->get_value())) it++;
    data.insert(it,in);
}

Node& SortedVector::at(const int index)
{
    return data[index];
}

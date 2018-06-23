#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;


SortedList::SortedList()
{
	Node::reset();
}

SortedList::~SortedList()
{
	Node::reset();
}


int SortedList::size() const
{
	return data.size();
}

/**
 * Check that the data is sorted.
 * @return true if sorted, false if not.
 */
bool SortedList::check() const
{
	if (size() == 0) return true;

	list<Node>::const_iterator it = begin();
	list<Node>::const_iterator prev = it;

	it++;

	// Ensure that each node is greater than or equal the previous node.
	while ((it != end()) && (*it >= *prev))
	{
		prev = it;
		it++;
	}

	return it == end();  // Good if reached the end.
}

bool SortedList::check_reversed() const
{
	if (size() == 0) return true;

	list<Node>::const_iterator it = begin();
	list<Node>::const_iterator prev = it;

	it++;

	// Ensure that each node is less than or equal to the previous node.
	while ((it != end()) && (*it <= *prev))
	{
		prev = it;
		it++;
	}

	return it == end();  // Good if reached the end.
}
/**
 * Insert a new node at the beginning of the data list.
 */
void SortedList::prepend(const long value)
{
	Node pr(value);
	list<Node>::iterator it = data.begin();
	data.insert(it,pr);
}

/**
 * Append a new node at the end of the data list.
 */
void SortedList::append(const long value)
{
	Node ap(value);
	data.push_back(ap);
}

/**
 * Remove a node.
 */
void SortedList::remove(const int index)
{
	   if (index <= data.size() / 2)
	   {
	      list<Node>::iterator it = data.begin();
	      advance(it, index);
	      data.erase (it );
	      return;
	   }
	   else
	   {
	      list<Node>::reverse_iterator rit = data.rbegin();
	      advance(rit, (data.size() - index - 1));
	      data.erase ((++rit).base());
	      return;
	   }
}

/**
 * Insert a new node into the data list at the
 */
void SortedList::insert(const long value)
{
	int inserted = 0;
	Node in(value);
	for (list<Node>::iterator it = data.begin(); it != data.end(); it++)
	{
		if ( it->get_value() > value )
		{
			data.insert ( it ,in);
			inserted = 1;
			break;
		}
	}

	if ( inserted == 0)
		data.push_back (in);
}

/**
 * Reverse in place the order of the nodes of the list.
 */

void SortedList::reverse()
{
	list<Node>::iterator start = data.begin();
	list<Node>::iterator end = data.end();
	while((start != end))
	{
		start++;
		data.insert(data.begin(), *start);
		start = data.erase(start);
	}
}
/**
 * Return the data node at the indexed position.
 */

Node& SortedList::operator[](const int index)
{
	if (index <= data.size() / 2)
	   {
	      list<Node>::iterator it = data.begin();
	      advance(it, index);
	      return *it;
	   }
	   else
	   {
	      list<Node>::reverse_iterator rit = data.rbegin();
	      advance(rit, (data.size() - index - 1));
	      return *((++rit).base());
	   }
}

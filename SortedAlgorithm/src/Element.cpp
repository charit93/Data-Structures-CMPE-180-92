#include <iostream>
#include "Element.h"

using namespace std;

// Static member variables, which are global to the class.
long Element::copy_count;
long Element::destructor_count;


Element::Element() : value(0) {} // Constructor

Element::Element(long val) : value(val) {}  // Elements Value

Element::Element(const Element& other)  // other element to be copied
{
	value = other.value;
	copy_count++;
}

Element::~Element() // Destructor
{
	destructor_count++;
}

long Element::get_value() const
{
	return value;
} // Returns the value

long Element::get_copy_count()
{
	return copy_count;
} // Returns the global count

long Element::get_destructor_count()
{
	return destructor_count;
} // Returns destructors_cound

/**
 * Reset the values of the global counters.
 */
void Element::reset()
{
	copy_count = destructor_count = 0;
}

bool operator ==(const Element& element1, const Element& element2) // Overload Operator ==
		{
	if(element1.value == element2.value)
		return true;
	else
		return false;
		}

bool operator <(const Element& element1, const Element& element2)  // Overload operator <
{
	if(element1.value < element2.value)
		return true;
	else
		return false;
}


bool operator >(const Element& element1, const Element& element2)
{
	if(element1.value > element2.value)
		return true;
	else
		return false;
}

ostream& operator <<(ostream& outs, const Element& element) //Overloaded << operator.
{
	outs << element.get_value();
	return outs;
}

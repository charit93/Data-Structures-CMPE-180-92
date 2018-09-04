#include <math.h>
#include <iomanip>
#include "Node.h"


Node:: Node()      //default constructor creating node
{
	name = " ";
	state = " ";
	row = 0;
	col = 0;
	next = nullptr;
}

Node::Node(Coordinate coordinate) // Constructor for a geogrphic coordinate
{
	convert_coordinate(coordinate);
	next=nullptr;
	name="";
	state="";
}

Node::Node(City city)   // Constructor for a city
{
	convert_coordinate(city.get_coordinate());
	next=nullptr;
	name=city.get_name();
	state=city.get_state();

}

Node::~Node() //Destructor.
{

}

Node *Node::get_next() const // Returns the pointer to next node
{
	return next;
}

int Node::get_row() const // Getter function to return the row
{
	return row;
}

int Node::get_col() const // Getter function to return the col
{
	return col;
}

string Node::get_name() const // Getter function to return the city's name
{
	return name;
}

string Node::get_state() const // Getter function to return the city's state
{
	return state;
}

void Node::convert_coordinate(const Coordinate& coordinate)
{
	//Convert coordinate's latitude and longitude in row and columns
	row = round(2*(Coordinate::MAX_LATITUDE - coordinate.get_latitude()));
	col = round(2*(coordinate.get_longitude() - Coordinate::MIN_LONGITUDE));
}

/**
 * Overloaded > operator used to determine
 * where to insert a node into the linked list.
 * The list is sorted first by row and then by column.
 */
bool Node::operator >(const Node &other)
{

	if (row < other.row)
		return false;
	else
		if (row > other.row)
			return true;

	if (row == other.row)
	{
		if (col > other.col)
			return true;
		else
			return false;
	}
    return    (row > other.row)
           || ((row == other.row) && (col > other.col));
}

ostream& operator <<(ostream& outs, const Node& node) // Overloaded stream output insertion operator.
{
	// Boundary node: Output a #

	if(node.name=="")
	{
		outs << "#";
	}

	else
		// City node: Output a * with the city's name and state.
		if (node.name.length() > 0)
		{
			outs << "*" << node.name << " " << node.state;
		}

	return outs;
}

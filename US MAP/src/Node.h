#ifndef NODE_H_
#define NODE_H_

#include "City.h"
#include "Coordinate.h"

/**
 * A linked list node.
 */
class Node
{
public:
    // Constructors
    Node();

    Node(Coordinate coordinate); // Initializing the coordinate
    Node(City city);             // Initializing the city

    // Destructor.
    ~Node();

    // Getters.
    Node *get_next() const;

    //function to get name
    string get_name() const;

    //function to get state
    string get_state() const;

    //function to get row
    int get_row() const;

    //function to get column
    int get_col() const;


    // Public pointer to the next node in the list.
    Node *next;

    // Overloaded > operator.
    bool operator >(const Node& other);

    // Overloaded stream output insertion operator.
    friend ostream& operator <<(ostream& outs, const Node& node);

private:
    string name;   // city name,
    string state;  // city state
    int row;       // print row
    int col;       // print column

    void convert_coordinate(const Coordinate& coordinate);
};

#endif /* NODE_H_ */

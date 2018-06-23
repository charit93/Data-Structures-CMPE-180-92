#include "Node.h"
#include "Element.h"

Node::Node() : next(nullptr) {} //constructor

Node::Node(const Element elmt) : element(elmt), next(nullptr) {} // element contained in this node.

Node::~Node() {}; //Destructor.

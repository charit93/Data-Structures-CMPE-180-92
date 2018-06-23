#include <string>
#include <vector>
#include "DataGenerator.h"

using namespace std;


DataGenerator::DataGenerator(string name) : name(name) {} // Constructor.

DataGenerator:: ~DataGenerator() {} //Destructor.

string DataGenerator::get_name() { return name; } // Getter to return the name of this generator

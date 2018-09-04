#include "Coordinate.h"

/**
 * Maximum latitude and minimum longitude for this app's input data.
 */
const double Coordinate::MAX_LATITUDE  =   49.373112;
const double Coordinate::MIN_LONGITUDE = -124.769867;

/**
 * Default constructor.
 */
Coordinate::Coordinate() : latitude(0), longitude(0)
{
}

/**
 * Destructor.
 */
Coordinate::~Coordinate()
{
}

double Coordinate::get_latitude()  const // getter function that returns latitude
{
	return latitude;
}


double Coordinate::get_longitude() const // getter function that returns longitude
{
	return longitude;
}

/**
 * Overloaded input stream extraction operator.
 * Read a coordinate from a CSV file.
 * @param istream the input stream.
 * @param coordinate the coordinate to input.
 * @return the input stream.
 */
istream& operator >>(istream& ins, Coordinate& coordinate)
{
    string str;

    // Latitude
    getline(ins, str, ',');
    coordinate.latitude = stod(str);

    //longitude
    getline(ins, str);
    coordinate.longitude = stod(str);

    return ins;
}

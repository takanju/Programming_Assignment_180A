/*
 * Coordinate.h
 *
 *  Created on: Oct 14, 2020
 *      Author: swapnanjali
 */

#ifndef COORDINATE_H_
#define COORDINATE_H_

#include <iostream>
#include <string>
using namespace std;

/**
 * A geographic coordinate.
 */
class Coordinate {
public:

	/***** Commplete this class. *****/

	//To get  latitude values
	//@return latitude the type double
	double get_latitude() const;

	//To get row values
	//@return longitude the type double
	double get_longitude() const;

	/**
	 * @param lat the type double.
	 * set value of latitude
	 */
	void set_lat(double lat);

	/**
	 * @param lat the type double.
	 * set value of longitude
	 */
	void set_long(double longi);

	/**
	 * Overloaded input stream extraction operator
	 * to read a coordinate from an input stream.
	 * @param ins the input stream.
	 * @param coordinate the coordinate to read.
	 * @return the input stream.
	 */

	friend istream& operator >>(istream &ins, Coordinate &coordinate);

	friend ostream& operator <<(ostream &outs, const Coordinate &coordinate);

	// Constants for this app's input data.
	static const double MAX_LATITUDE;
	static const double MIN_LONGITUDE;

private:
	double latitude;
	double longitude;
};

#endif /* COORDINATE_H_ */

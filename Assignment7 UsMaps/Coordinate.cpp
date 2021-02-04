/*
 * Coordinate.cpp
 *
 *  Created on: Oct 14, 2020
 *      Author: swapnanjali
 */

#include "Coordinate.h"
#include "string"

/**
 * Maximum latitude and minimum longitude for this app's input data.
 */
const double Coordinate::MAX_LATITUDE = 49.373112;
const double Coordinate::MIN_LONGITUDE = -124.769867;

/***** Complete this class. *****/

double Coordinate::get_longitude() const {
	return longitude;
}
double Coordinate::get_latitude() const {
	return latitude;
}

void Coordinate::set_lat(double lat) {
	latitude = lat;

}

void Coordinate::set_long(double longi) {
	longitude = longi;
}

istream& operator >>(istream &ins, Coordinate &coordinate) {

	string x, y;

	getline(ins, x, ',');
	getline(ins, y);

	string::size_type sz;
	coordinate.latitude = stod(x, &sz);
	coordinate.longitude = stod(y, &sz);

	return ins;
}

ostream& operator <<(ostream &outs, const Coordinate &coordinate) {

	outs << coordinate.latitude << " " << coordinate.longitude;
	outs<< coordinate.get_longitude(), coordinate.get_latitude();

	return outs;
}


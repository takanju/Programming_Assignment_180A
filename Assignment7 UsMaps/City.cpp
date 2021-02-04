/*
 * City.cpp
 *
 *  Created on: Oct 14, 2020
 *      Author: swapnanjali
 */

#include "City.h"

/***** Complete this class. *****/
void City::set_cord(Coordinate cord) {
	coordinate = cord;
}

void City::set_name(string nam) {
	name = nam;

}

void City::set_state(string sta) {
	state = sta;

}

istream& operator >>(istream &ins, City &city) {
	string x, y;
	Coordinate coordinate;
	string name1, state1;
	getline(ins, name1, ',');
	getline(ins, state1, ',');
	city.name = name1;
	city.state = state1;

	getline(ins, x, ',');
	getline(ins, y);

	string::size_type sz;
	coordinate.set_lat(stod(x, &sz));
	coordinate.set_long(stod(y, &sz));
	city.coordinate = coordinate;

	return ins;
}

ostream& operator <<(ostream &outs, const City &city) {
	return outs;
}
;

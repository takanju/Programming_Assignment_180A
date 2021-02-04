/*
 * Node.cpp
 *
 *  Created on: Oct 14, 2020
 *      Author: swapnanjali
 */

#include <math.h>
#include "Node.h"
#include <cmath>

/***** Complete this class. *****/

void Node::convert_coordinate(const Coordinate &coordinate) {

	row = round(2 * (Coordinate::MAX_LATITUDE - coordinate.get_latitude()));
	col = round(2 * (coordinate.get_longitude() - Coordinate::MIN_LONGITUDE));

}

Node::Node(Coordinate coord) {
	convert_coordinate(coord);
	this->next = NULL;
	this->cord = coord;
	this->name = "";
	this->state = "";
}

Node::Node(City city) {
	string state, name;
	this->name = city.get_name();
	this->state = city.get_state();
	this->cord = city.get_coord();
	convert_coordinate(this->cord);

}

double Node::get_row() const {
	return row;
}

double Node::get_col() const {
	return col;
}

int Node::get_size_of_city_and_state() {
	if( this->name == "") {
		return 0;
	}
	string city_and_state = this->name + " " + this->state;
	return city_and_state.length();
}

bool Node::operator >(const Node &other) {
	if (this->row > other.row) {
		return true;
	} else if (this->row == other.row && this->col > other.col) {
		return true;
	} else if (this-> row == other.row && this->col == other.col && this->name == "") {
		return true;
	}

	return false;
}

ostream& operator <<(ostream &outs, const Node &node) {


	if (node.name != "") {
		outs << "*" << node.name << " " << node.state;
	} else {
		outs <<  "#";
	}

	return outs;

}


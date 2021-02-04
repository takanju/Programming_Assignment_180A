/*
 * Node.h
 *
 *  Created on: Oct 14, 2020
 *      Author: swapnanjali
 */

#ifndef NODE_H_
#define NODE_H_

#include "City.h"
#include "Coordinate.h"

/**
 * A node of a linked list.
 */
class Node
{
public:

    /***** Complete this class. *****/

    Node *next;  // pointer to the next node in the list

    //Overloaded constrctor to set class Coordinate values
    //@param coord the type Coordinate
    Node(Coordinate coord);



    //Overloaded constructor to set class City values
    //@param city the type City
    Node(City city);

    //Destructor
    ~Node(){};

    //To get row values
    //@return row the type double
    double get_row() const;

    //To get column values
    //@return col the type double
    double get_col() const;

    int get_size_of_city_and_state();

    /**
     * Overloaded > operator to compare two nodes.
     */
    bool operator >(const Node& other);

    /**
     * Overloaded stream output insertion operator
     * to output a node to the output stream.
     * @param outs the output stream.
     * @param node the node to output.
     * @return the output stream.
     */
 friend ostream& operator <<(ostream& outs, const Node& node);

private:
    string name;   // city name,  or the empty string for a border location
    string state;  // city state, or the empty string for a border location
    double row;       // print row
    double col;       // print column
 Coordinate cord;
    /**
     * Convert a coordinate to a row and a column.
     * @param coordinate the coordinate to convert.
     */
    void convert_coordinate(const Coordinate& coordinate);
};

#endif /* NODE_H_ */

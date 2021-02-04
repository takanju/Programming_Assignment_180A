/*
 * City.h
 *
 *  Created on: Oct 14, 2020
 *      Author: swapnanjali
 */

#ifndef CITY_H_
#define CITY_H_

#include <iostream>
#include <string>

#include "Coordinate.h"

using namespace std;

/**
 * City data.
 */
class City
{
public:

	/***** Complete this class. *****/


	/**
      * @param cord the type Coordinate.
	  * set value of coordinate
      */
   void set_cord(Coordinate cord);

   /**
     * @param nam the type string.
   	 * set value of name
     */
   void set_name(string nam);

   /**
     * @param sta the type string.
     * set value of state
     */
   void set_state(string sta);

   string get_name() {
	   return name;
   }

     /**
       * @param sta the type string.
       * set value of state
       */
     string get_state() {
    	 return state;
     }

     Coordinate get_coord() {
        	 return coordinate;
         }


    /**
     * Overloaded input stream operator to read a city
     * from an input stream.
     * @param ins the input stream.
     * @param city the city to read.
     * @return the input stream.
     */
    friend istream& operator >>(istream& ins, City& city);

    /**
     * Overloaded output stream operator to output a city
     * to an output stream.
     * @param outs the output stream.
     * @param city the city to output.
     * @return the output stream.
     */
    friend ostream& operator <<(ostream& outs, const City& city);

private:
    string name;
    string state;
    Coordinate coordinate;
};




#endif /* CITY_H_ */

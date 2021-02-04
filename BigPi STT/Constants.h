#ifndef CONSTANTS_H_
#define CONSTANTS_H_

//  5 iterations to compute 1,000 decimal places.
// 10 iterations to compute 1,000,000 decimal places.

const int MAX_ITERATIONS = 10;
const int PLACES         = 1000000;          // desired decimal places
const int PRECISION      = PLACES + 1;    // +1 for the digit 3 before the decimal

const int BASE       = 10;                // base 10 numbers
const int BIT_COUNT  = 8;                 // bits per machine word

const int BLOCK_SIZE = 10;                // print digits in blocks
const int LINE_SIZE  = 100;               // digits to print per line
const int LINE_COUNT = PLACES/LINE_SIZE;  // lines to print
const int GROUP_SIZE = 5;                 // line grouping size

#endif /* CONSTANTS_H_ */

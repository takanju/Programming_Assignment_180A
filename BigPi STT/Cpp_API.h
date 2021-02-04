/*
 * Cpp_API.h
 *
 *  Created on: Oct 27, 2020
 *      Author: swapnanjali
 */

#ifndef CPP_API_H_
#define CPP_API_H_

#include <mpirxx.h>

/**
 * C++ API: Compute pi and print pi.
 */
void compute_and_print_pi_cpp();

/**
 * C++ API: Compute pi.
 * Time the calculation.
 * @param pi
 */
void compute_pi_cpp(mpf_class& pi);

/**
 * C++ API: Compute the 4th root of a multiple-precision number x.
 * @param root4 the computed multiple-precision 4th root of x.
 * @param x the multiple-precision number.
 */
mpf_class& root4(mpf_class& root4, const mpf_class& x);

/**
 * C++ API: Compute the 4th power of a multiple-precision number x.
 * @param xxxx the computed multiple-precision 4th power of x.
 * @param x the multiple-precision number.
 */
mpf_class& power4(mpf_class& xxxx, const mpf_class& x);

#endif /* CPP_API_H_ */

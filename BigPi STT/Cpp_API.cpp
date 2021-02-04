/*
 * Cpp_API.cpp
 *
 *  Created on: Oct 27, 2020
 *      Author: swapnanjali
 */

#include <iostream>
#include <mpirxx.h>

#include "Constants.h"
#include "Timer.h"
#include "Cpp_API.h"

using namespace std;

void compute_and_print_pi_cpp()
{
    cout << "C++ API: pi to " << " 1 million places:" << endl;

    // Time the computation of pi.
    mpf_class pi;
    long ns = Timer::time_it(compute_pi_cpp, pi);

    cout<<" Total elapsed time: "<< ns/(1000000000) <<" seconds"endl;

    // Convert the number to a string for printing.
//    mp_exp_t exp;      // exponent (not used)
//    char *str = NULL;
//    char *s = mpf_get_str(str, &exp, BASE, PRECISION, pi.get_mpf_t());
//
//    print(s, ns);
}

void compute_pi_cpp(mpf_class& pi)
{
    mpf_set_default_prec(BIT_COUNT*PRECISION/2);

    const mpf_class ONE(1), TWO(2), FOUR(4), SIX(6);
    const mpf_class SQRT2 = sqrt(TWO);

    mpf_class y, a, y4, yRoot4, aTerm;

    mpf_class y_prev = SQRT2 - ONE;
    mpf_class a_prev = SIX - FOUR*SQRT2;
    mpf_class powers2 = 2;

    for (int i = 1; i <= MAX_ITERATIONS; i++)
    {
        y4 = power4(y4, y_prev);
        yRoot4 = root4(yRoot4, ONE - y4);
        y = (ONE - yRoot4)/(ONE + yRoot4);

        mpf_class temp;
        aTerm = a_prev*power4(temp, ONE + y);
        powers2 = FOUR*powers2;
        a = aTerm - powers2*y*(ONE + y + y*y);

        a_prev = a;
        y_prev = y;
    }

    pi = ONE/a;
}

mpf_class& root4(mpf_class& root4, const mpf_class& x)
{
    root4 = sqrt(sqrt(x));
    return root4;
}

mpf_class& power4(mpf_class& xxxx, const mpf_class& x)
{
    mpf_class xx = x*x;
    xxxx = xx*xx;
    return xxxx;
}




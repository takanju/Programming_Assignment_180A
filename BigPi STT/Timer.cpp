/*
 * Timer.cpp
 *
 *  Created on: Oct 28, 2020
 *      Author: swapnanjali
 */

/*
 * Timer.h
 *
 *  Created on: Oct 27, 2020
 *      Author: swapnanjali
 */

#include <chrono>
#include "Timer.h"

using namespace std;
using namespace std::chrono;

//long Timer::time_it(void f(mpf_t&), mpf_t& pi)
//{
//    steady_clock::time_point start_time = steady_clock::now();
//
//    f(pi);
//
//    steady_clock::time_point end_time = steady_clock::now();
//    long ns = duration_cast<nanoseconds>(end_time - start_time).count();
//
//    return ns;
//}

long Timer::time_it(void f(mpf_class&), mpf_class& pi)
{
    steady_clock::time_point start_time = steady_clock::now();

    f(pi);

    steady_clock::time_point end_time = steady_clock::now();
    long ns = duration_cast<nanoseconds>(end_time - start_time).count();

    return ns;
}




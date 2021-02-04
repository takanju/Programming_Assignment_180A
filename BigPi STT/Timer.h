#ifndef TIMER_H_
#define TIMER_H_

#include <mpir.h>
#include <mpirxx.h>

using namespace std;
using namespace std::chrono;

class Timer
{
public:
    /**
     * Time a call to function f with argument mpf_t pi.
     * @param f the function.
     * @param pi function f's argument
     * @return the execution time in nanoseconds.
     */
   // static long time_it(void f(mpf_t&), mpf_t& pi);

    /**
     * Time a call to function f with argument mpf_class pi.
     * @param f the function.
     * @param pi function f's argument
     * @return the execution time in nanoseconds.
     */
    static long time_it(void f(mpf_class&), mpf_class& pi);
};

#endif /* TIMER_H_ */

/*
 * TimeVector2.cpp
 *
 *  Created on: Oct 20, 2020
 *      Author: swapnanjali
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

/**
 * Time how long it takes to initialize a vector of size n.
 * @param v the vector to initialize.
 * @param n the vector size.
 * @return the elapsed time in milliseconds.
 */
long time_vector_initialization(vector<int>& v, const int n);

/**
 * Convert a long integer to a string with commas.
 * @param i the integer.
 * @return the string with commas.
 */
string commafy(const long i);

int main()
{
    vector<int> v;

    for (long n = 10000; n <= 100000000; n *= 10)
    {
        long elapsed_time = time_vector_initialization(v, n);

        cout << "Elapsed_time for " << setw(11) << commafy(n) << " : "
             << setw(5) << commafy(elapsed_time) << " ms" << endl;
    }

    cout << endl << "Done!";
    return 0;
}

long time_vector_initialization(vector<int>& v, const int n)
{
    auto start_time = steady_clock::now();

    // Do the work that we're timing.
    v.clear();
    for (int i = 0; i < n; i++) v.push_back(i);

    decltype(start_time) end_time = steady_clock::now();

    // Other options include: nanoseconds, microseconds
    long elapsed_time =
            duration_cast<milliseconds>(end_time - start_time).count();

    return elapsed_time;
}

string commafy(long i)
{
    string str = to_string(i);
    int pos = str.length() - 3;

    while (pos > 0)
    {
        str.insert(pos, ",");
        pos -= 3;
    }

    return str;
}



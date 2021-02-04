/*
 * Fibonnaci3.cpp
 *
 *  Created on: Oct 20, 2020
 *      Author: swapnanjali
 */




#include <iostream>
#include <iomanip>
using namespace std;

long fibonacci(int n);

int main()
{
    fibonacci(6);
}

long fibonacci(int n)
{
    cout << "Called fibonacci(" << n << ")" << endl;

    long f;
    if (n <= 2) f = 1;
    else        f = fibonacci(n-2) + fibonacci(n-1);

    cout << "Returning fibonacci(" << n << ") = " << f << endl;
    return f;
}

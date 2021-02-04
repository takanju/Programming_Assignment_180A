/*
 * Fibonacci2.cpp
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
    for (int i = 1; i <= 50; i++) {
        cout << "fibonacci(" << setw(2) << i << ") = "
        	 << setw(11) << fibonacci(i) << endl;
    }
}

long fibonacci(int n)
{
    if (n <= 2) return 1;
    else        return fibonacci(n-2) + fibonacci(n-1);
}

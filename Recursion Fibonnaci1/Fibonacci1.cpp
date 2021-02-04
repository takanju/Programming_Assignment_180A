/*
 * Fibonacci1.cpp
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
    else {
        long older = 1;
        long old   = 1;
        long next  = 1;
    	//int var=1, var2=2, result=0;

        for (int i = 3; i <= n; i++) {
            next = older + old;
            older = old;
            old   = next;
        	//result = result+var+var2;
        }

        return next;
    }
}




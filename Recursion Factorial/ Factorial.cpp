/*
 *  Factorial.cpp
 *
 *  Created on: Oct 27, 2020
 *      Author: swapnanjali
 */


#include <iostream>
#include <iomanip>

using namespace std;

int fact(int n);

int main()
{
    for (int n = 1; n <= 10; n++)
    {
        cout << setw(2) << n << "! = " << setw(7) <<  fact(n) << endl;
    }
}

int fact(int n)
{
    if (n <= 1) return 1;
    else        return n*fact(n-1);
}


/*
 * TemplateExchange.cpp
 *
 *  Created on: Oct 20, 2020
 *      Author: swapnanjali
 */



#include <iostream>
#include <string>
using namespace std;

template <typename T>
void exchange(T& first, T& second);

template <typename T>
void print(T first, T second);

int main()
{
    int i = 5, j = 7;
    print(i, j);
    exchange(i, j);
    print(i, j);

    cout << endl;

    double pi = 3.14, e = 2.72;
    print(pi, e);
    exchange(pi, e);
    print(pi, e);

    cout << endl;

    string a = "alpha", b = "beta";
    print(a, b);
    exchange(a, b);
    print(a, b);
}

template <typename T>
void exchange(T& first, T& second)
{
    T temp = first;
    first = second;
    second = temp;
}

template <typename T>
void print(T first, T second)
{
    cout << first << " " << second << endl;
}

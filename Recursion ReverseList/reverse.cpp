/*
 * reverse.cpp
 *
 *  Created on: Oct 20, 2020
 *      Author: swapnanjali
 */



#include <iostream>
#include <list>
using namespace std;

void print(const list<int>& alist);
void reverse(list<int>& alist);

int main()
{
    list<int> alist;
    for (int i = 1; i <= 9; i++) alist.push_back(10*i);

    print(alist);
    reverse(alist);
    print(alist);
}

void print(const list<int>& alist)
{
    for (list<int>::const_iterator it = alist.begin(); it != alist.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void reverse(list<int>& alist)
{
    if (alist.size() <= 1) return;

    int first = alist.front();
    alist.erase(alist.begin());  // remove the first element

    reverse(alist);          // reverse the rest of the list
    alist.push_back(first);  // append the first element at the end
}

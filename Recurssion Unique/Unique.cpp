/*
 * Unique.cpp
 *
 *  Created on: Oct 20, 2020
 *      Author: swapnanjali
 */




#include <iostream>
#include <list>
using namespace std;

void print(const list<int>& alist);
bool member_of(const int value, const list<int>& alist,
               list<int>::const_iterator it);
void unique(list<int>& alist);

int main()
{
    list<int> alist;
    alist.push_back(30);
    alist.push_back(10);
    alist.push_back(50);
    alist.push_back(80);
    alist.push_back(50);
    alist.push_back(10);
    alist.push_back(40);
    alist.push_back(10);
    alist.push_back(70);

    print(alist);
    unique(alist);
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

bool member_of(const int value, const list<int>& alist,
               list<int>::const_iterator it)
{
    if (it == alist.end()) return false;

    return (*it == value) || member_of(value, alist, ++it);
}

void unique(list<int>& alist)
{
    if (alist.size() <= 1) return;

    int first = alist.front();
    alist.erase(alist.begin());  // remove the first element

    unique(alist);  // make the rest of the list unique

    if (!member_of(first, alist, alist.begin()))
    {
        alist.push_front(first);  // put back the first element
    }
}

/*
 * MemberOf.cpp
 *
 *  Created on: Oct 20, 2020
 *      Author: swapnanjali
 */

#include <iostream>
#include <list>
using namespace std;

bool member_of(const int value, const list<int>& alist,
               list<int>::const_iterator it);
void test(const int value, const list<int>& alist);

int main()
{
    list<int> alist;
    alist.push_back(30);
    alist.push_back(10);
    alist.push_back(50);
    alist.push_back(80);
    alist.push_back(60);
    alist.push_back(90);
    alist.push_back(40);
    alist.push_back(20);
    alist.push_back(70);

    for (list<int>::const_iterator it = alist.begin(); it != alist.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl << endl;

    test(50, alist);
    test(75, alist);
}

void test(const int value, const list<int>& alist)
{
    cout << value << " is";
    bool found = member_of(value, alist, alist.begin());
    if (!found) cout << " not";
    cout << " in the list." << endl;
}

bool member_of(const int value, const list<int>& alist,
               list<int>::const_iterator it)
{
    if (it == alist.end()) return false;

    return (*it == value) || member_of(value, alist, ++it);
}



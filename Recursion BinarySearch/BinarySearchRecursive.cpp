/*
 * BinarySearchRecursive.cpp
 *
 *  Created on: Oct 28, 2020
 *      Author: swapnanjali
 */


#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void search(int value, vector<int> v);
int  search(int value, vector<int> v, int low, int high);

int main()
{
    vector<int> v;
    v.push_back(4);
    v.push_back(8);
    v.push_back(19);
    v.push_back(25);
    v.push_back(34);
    v.push_back(39);
    v.push_back(45);
    v.push_back(48);
    v.push_back(66);
    v.push_back(75);
    v.push_back(89);
    v.push_back(95);

    search(89, v);
    search(34, v);
    search(22, v);
}

void search(int value, vector<int> v)
{
    cout << endl << "Searching for " << value << endl;

    int index = search(value, v, 0, v.size());
    if (index >= 0)
    {
        cout << "Value " << value << " found at index " << index << endl;
    }
    else
    {
        cout << "Value " << value << " not found" << endl;
    }
}


int search(int value, vector<int> v, int low, int high)
{
    if (low <= high) {
        int mid = (low + high)/2;


        cout << " low " << setw(2) << low << " mid " << setw(2) << mid
             << " high " << setw(2) << high << endl;


        if (value == v[mid]) {
            return mid;
        }
        else if (value < v[mid]) {
            return search(value, v, low, mid-1);
        }
        else {
            return search(value, v, mid+1, high);
        }
    }

    return -1;
}


/*
 * QuickSortOptimal.cpp
 *
 *  Created on: Nov 17, 2020
 *      Author: swapnanjali
 */




#include "QuickSortOptimal.h"

Element& QuickSortOptimal::choose_pivot_strategy(const int left, const int right)
{
    int middle = (left+right)/2;
  if (data[middle] < data[left])
    {
        swap(left,middle);
    }
    if (data[right] < data[left])
    {
        swap(left, right);
    }
    if (data[right] < data[middle])
    {
        swap(middle, right);
    }
    compare_count += 3;
  swap(middle, right);
    return data[right];
}

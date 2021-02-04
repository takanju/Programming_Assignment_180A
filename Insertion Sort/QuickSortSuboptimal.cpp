/*
 * QuickSortSuboptimal.cpp
 *
 *  Created on: Nov 17, 2020
 *      Author: swapnanjali
 */




#include "QuickSortSuboptimal.h"

Element& QuickSortSuboptimalRight::choose_pivot_strategy(const int left, const int right)
{
    return data[right];
}

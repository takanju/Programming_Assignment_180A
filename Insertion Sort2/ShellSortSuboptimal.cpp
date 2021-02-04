/*
 * QuickSortSuboptimal.cpp
 *
 *  Created on: Nov 17, 2020
 *      Author: swapnanjali
 */




#include "ShellSortSuboptimal.h"

//https://www.geeksforgeeks.org/shellsort/

void ShellSortSuboptimal::run_sort_algorithm() throw (string)
{
    for (int gap = size/2; gap > 0; gap /= 2)
    {
       for (int i = gap; i < size; i += 1)
        {
         Element temp = data[i];
            int j;
            for (j = i; j >= gap; j -= gap) {
				compare_count++;
				if (data[j - gap] > temp) {
					data[j] = data[j - gap];
					move_count++;
				}
				else
				{	break;}
			}
            data[j] = temp;
        }
    }
}

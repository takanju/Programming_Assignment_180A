/*
 * QuickSortSuboptimal.cpp
 *
 *  Created on: Nov 17, 2020
 *      Author: swapnanjali
 */




#include "ShellSortOptimal.h"

/**
     * Run the optimal shellsort algorithm.
     * According to Don Knuth:
     * h = 3*i + 1 for i = 0, 1, 2, ... used in reverse.
     * @throws an exception if an error occurred.
     */

   //https://www.geeksforgeeks.org/shellsort/

void ShellSortOptimal::run_sort_algorithm() throw (string)
{
  int h = 0;
	while (h < (size/3))
		h = h * 3 + 1;
	while (h > 0) {
		for (int i = h; i < size; i++) {
			Element temp = data[i];
			int j;
			for (j = i; j >= h; j -= h) {
				compare_count++;
				if (data[j - h] > temp) {
					data[j] = data[j - h];
					move_count++;
				} else
					break;
			}
			data[j] = temp;
		}
		h = (h - 1) / 3;
	}


   }



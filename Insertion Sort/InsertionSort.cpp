/*
 * InsertionSort.h
 *
 *  Created on: Nov 17, 2020
 *      Author: swapnanjali
 */




#include "InsertionSort.h"


void InsertionSort::run_sort_algorithm() throw (string)
{

 //https://www.tutorialspoint.com/cplusplus-program-to-implement-insertion-sort

 Element temp;
 int j=0;
   for(int i = 1; i<size; i++) {
       temp = data[i];
      j = i;
      while(j > 0 && data[j-1]>temp) {
         compare_count++;
         data[j] = data[j-1];
         j--;
         move_count++;
      }
      data[j] = temp;   //insert in right place
   }
}

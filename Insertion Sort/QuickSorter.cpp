#include <iostream>
#include "QuickSorter.h"
using namespace std;

void QuickSorter::run_sort_algorithm() throw (string)
{
    quicksort(0, size-1);
}

void QuickSorter::quicksort(const int left, const int right)
{
    // Continue the recursive calls until the indexes cross.
    if (left < right)
    {
        // Choose the pivot and partition this subrange.
        Element& pivot = choose_pivot(left, right);
        int p = partition(left, right, pivot);
        quicksort(left, p-1);
        quicksort(p+1, right);
    }
}

Element& QuickSorter::choose_pivot(const int left, const int right)
{
    return choose_pivot_strategy(left, right);
}


//https://www.youtube.com/watch?v=7h1s2SojIRw&t=325s

int QuickSorter::partition(const int left, const int right, const Element& pivot)
{

 int i = left; int j = right;
 while(i<j){
    if(data[i].get_value()<=pivot.get_value()) {
       i++;
       continue;
    }
    if(data[j].get_value()>pivot.get_value()) {
       j--;
       continue;
    }
    if(i<j){
       swap(i, j);
    }
 }
    swap(i, right);
    return i;

    }


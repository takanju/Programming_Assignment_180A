/*
 * MergeSort.cpp
 *
 *  Created on: Nov 17, 2020
 *      Author: swapnanjali
 */




#include <string>
#include "MergeSort.h"

void MergeSort::run_sort_algorithm()
    throw (string)
{
    // Defensive programming: Make sure we end up
    // with the same size list after sorting.
    int size_before = data.get_size();

    mergesort(data);

    // Check sizes.
    int size_after = data.get_size();
    if (size_before != size_after)
    {
        string message = "***** Size mismatch: before " +
                         to_string(size_before) + ", size after " +
                         to_string(size_after);
        throw message;
    }
}


/**
     * The mergesort algorithm recursively splits and merges data lists.
     * @param list the list of data to sort.
     */
void MergeSort::mergesort(LinkedList& list)
{
    int listSize = list.get_size();
    if(listSize >1){
       LinkedList list1, list2;
       list.split(list1, list2);
       move_count=move_count+2;
       mergesort(list1);
       mergesort(list2);
       list.reset();
       merge(list, list1, list2);
    }
}


//https://gist.github.com/mycodeschool/9678029

void MergeSort::merge(LinkedList& list,
                      LinkedList& sublist1, LinkedList& sublist2)
{
   Node* i = sublist1.get_head();
   Node* j = sublist2.get_head();
   Node* k;

   while(i != nullptr && j != nullptr) {
		if(i->element.get_value()  <= j->element.get_value()) {
		   list.add(sublist1.remove_head());
		   i = sublist1.get_head();
		   }
		else {
		   list.add(sublist2.remove_head());
		   j = sublist2.get_head();}
	}
	compare_count++;
	move_count++;
	if(i !=nullptr ) {
	   list.concatenate(sublist1);
        move_count++;
	}
	if(j != nullptr) {
	   list.concatenate(sublist2);
        move_count++;
	   }

}

void MergeSort::clear() { data.clear(); }



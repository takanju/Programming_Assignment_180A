/*
 * LinkedList.cpp
 *
 *  Created on: Nov 17, 2020
 *      Author: swapnanjali
 */




#include <iostream>
#include "LinkedList.h"
using namespace std;

Node *LinkedList::remove_head()
{
    if (head == nullptr) return nullptr;

    Node *removed_head = head;
    head = head->next;

    // Is the list now empty?
    if (head == nullptr) tail = nullptr;

    size--;
    return removed_head;
}

void LinkedList::add(const Element& elmt)
{
    Node *node = new Node(elmt);
    add(node);
}

void LinkedList::add(Node *node)
{
    // First node.
    if (head == nullptr)
    {
        head = tail = node;
    }

    // Subsequent node.
    else
    {
        tail->next = node;
        tail = node;

    }

    node->next = nullptr;
    size++;
}

void LinkedList::clear()
{
    // Repeatedly delete the head node until the list is empty.
    while (head != nullptr)
    {
        Node *next = head->next;
        delete head;
        head = next;
    }

    tail = nullptr;
    size = 0;
}

void LinkedList::print() const
{
    for (Node *ptr = head; ptr != nullptr; ptr = ptr->next)
    {
        cout << " " << ptr->element.get_value();
    }
    cout << endl;
}

void LinkedList::split(LinkedList& list1, LinkedList& list2)
{
    int firstSize = size/2;
   Node* mid_point = head;
   Node* prev_mid_point = head;
   for(int i=0; i<firstSize; i++){
      prev_mid_point = mid_point;
      mid_point=mid_point->next;
   }
   list1.set(head, prev_mid_point, firstSize);
   int secondSize=0;
   if(size%2==0){
      secondSize = firstSize;
   }
   else{
      secondSize = firstSize+1;
   }
   list2.set(mid_point, tail, secondSize);
}

void LinkedList::concatenate(LinkedList& other_list)
{
   tail->next=other_list.head;
	set(head,other_list.get_tail(),size+other_list.size);
	other_list.reset();

}

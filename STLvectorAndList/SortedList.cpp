/*
 * SortedList.cpp
 *
 *  Created on: Oct 30, 2020
 *      Author: swapnanjali
 */


#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
    Node::reset();
}

SortedList::~SortedList()
{
    Node::reset();
}

void SortedList::prepend(const long value)
{
    list<Node>::insert(begin(), Node(value));
}

void SortedList::append(const long value)
{
    push_back(Node(value));
}

void SortedList::insert(const long value)
{
    list<Node>::const_iterator it = begin();

    // Look for the appropriate position to insert.
    while ((it != end()) && (value > it->get_value())) it++;
    list<Node>::insert(it, Node(value));
}

void SortedList::remove(const int index)
{
    list<Node>::iterator ite;
    for(ite = list<Node>::begin(); ite!=list<Node>::end();ite++){
       erase(ite);
    }
}

void SortedList::reverse()
{
    list<Node>::const_iterator it = begin();
    ++it;

    while (it != end())
    {
        list<Node>::insert(begin(), *it);
        it = erase(it);
    }
}


bool SortedList::check() const
{
    if (size() == 0) return true;

    list<Node>::const_iterator it = begin();
    list<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than or equal the previous node.
    while ((it != end()) && (*it >= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}

bool SortedList::check_reversed() const
{
    if (size() == 0) return true;

    list<Node>::const_iterator it = begin();
    list<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is less than or equal to the previous node.
    while ((it != end()) && (*it <= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}


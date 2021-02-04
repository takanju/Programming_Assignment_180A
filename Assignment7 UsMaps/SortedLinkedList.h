/*
 * SortedLinkedList.cpp
 *
 *  Created on: Oct 14, 2020
 *      Author: swapnanjali
 */

#ifndef SORTEDLINKEDLIST_CPP_
#define SORTEDLINKEDLIST_CPP_

#include "Node.h"

/**
 * A singly-linked list of Node objects that is sorted
 * by the nodes' rows and columns.
 */
class SortedLinkedList {
public:

	/***** Complete this class. *****/

	SortedLinkedList() {
		head = NULL;
	}

	~SortedLinkedList() {
	}
	;
	/**
	 * Insert a node into the linked list at the correct position
	 * to maintain sort order.
	 * @param node the node to insert.
	 */
	void insert(Node *node);

	/**
	 * Overloaded stream output insertion operator
	 * to output the entire sorted linked list.
	 * @param outs the output stream.
	 * @param list the sorted linked list to output.
	 * @return the output stream.
	 */
	friend ostream& operator <<(ostream &outs, const SortedLinkedList &list);

private:
	Node *head;  // pointer to the head of the linked list

	void printToCoordinates(int x, int y, string text);
};

#endif /* SORTEDLINKEDLIST_CPP_ */

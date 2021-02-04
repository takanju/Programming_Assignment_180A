/*
 * SortedLinkedList.cpp
 *
 *  Created on: Oct 14, 2020
 *      Author: swapnanjali
 */

#include "SortedLinkedList.h"

/***** Complete this class. *****/

void SortedLinkedList::insert(Node *node) {

	if (head == NULL) {
		head = node;
		return;

	}
	Node *temp = head;

	if (*temp > *node) {
		node->next = head;
		head = node;

		return;
	}

	while (temp->next != NULL && *node > *(temp->next)) {

		temp = temp->next;

	}

	Node *temp1;
	temp1 = temp->next;

	temp->next = node;
	node->next = temp1;
}

ostream& operator <<(ostream &outs, const SortedLinkedList &list) {
	Node *temp;
	temp = list.head;

	while (temp != NULL) {
		Node *prevNode = NULL;
		int previous = 0;

		while (temp  != NULL && (prevNode == NULL || prevNode->get_row() == temp->get_row())) {

			int current = temp->get_col();

			if(previous > current) {
				prevNode = temp;
				temp = temp->next;
				continue;
			}
			if (previous != 0 && previous == current) {
				prevNode = temp;
				temp = temp->next;
				continue;
			}

			int start = (prevNode == NULL ? previous : previous + 1);

			for (int i = start; i < current; i++) {
				outs << " ";
			}

			outs << *temp;
			previous = current + temp->get_size_of_city_and_state();
			//previous = current;
			prevNode = temp;
			temp = temp->next;
		}

		if (temp != NULL && prevNode != NULL) {

			for (int i = 0; i < temp->get_row() - prevNode->get_row(); i++) {
				outs << "\n";

			}
		}
	//	cout << "hello" << endl;

	}

	//cout << "I am here" << endl;

	return outs;
}

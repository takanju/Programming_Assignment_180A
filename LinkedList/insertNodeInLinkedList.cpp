#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* link;
	};

void insert(Node *afterme, int  number){
	Node* tempPointer;
	tempPointer = new Node;
	tempPointer->data = number;
	tempPointer->link = afterme->link;
	afterme->link = tempPointer;
}

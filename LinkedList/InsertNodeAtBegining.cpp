/*
 * codeSchool1.cpp
 *
 *  Created on: Oct 18, 2020
 *      Author: swapnanjali
 */




#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* link;
};

//Node* head;

Node* insert(int x, Node* &head){
	Node* temp = new Node;
	temp->data = x;
	temp->link = head;
	head = temp;
	return head;

}

void print(Node* head){

	//Node* temp = head;
	cout<< "list is: ";
	while(head!=NULL){
		cout<< head->data << " ";
		head=head->link;

	}
	cout<<endl;

}

int main(){

	Node* head;

	head=NULL;

	cout<<"how many numbers";
	int n,i,x;

	cin>>n;

	for(int i=0;i<n;i++){
		cout<<"enter the number";
		cin>>x;
		head = insert(x, head);
		print(head);
	}






//	Node* p = NULL;
//	Node* temp = new Node;
//	temp->data = 2;
//	temp->link = NULL;
//	p = temp;
//
//	Node* temp = new Node;
//	temp->data =4;
//	temp->link = NULL;
//	//temp->link = temp2;
//
//	Node* temp = new Node;
//	temp->data = 5;
//	temp->link = NULL;
//	//temp->link = temp3;
//
//	Node* temp = p;
//
//	while(temp->link != NULL){
//		temp = temp->link;
//
//
//
//	}
}

#include <iostream>
#include "Node.h"

using namespace std;


//Declared globally
long Node::constructor_count;
 long Node::copy_count;
 long Node::assign_count;
 long Node::destructor_count;


Node::Node(const long the_value){
	value = the_value;
	constructor_count++;
}

Node::Node(const Node& other){
	value = other.value;
	copy_count++;
}

Node& Node::operator =(const Node& rhs){
	value = rhs.value;
	assign_count++;
	return *this;
}

Node::~Node(){
	destructor_count++;
}



long Node::get_value() const{
	return value;
}

long::Node::get_constructor_count() {
	return constructor_count;
}

long Node::get_copy_count(){
	return copy_count;
}

long Node::get_assign_count(){
	return assign_count;
}

long Node::get_destructor_count(){
	return destructor_count;
}

void Node::reset(){
	constructor_count = 0;
	copy_count = 0;
	assign_count = 0;
	destructor_count = 0;
}





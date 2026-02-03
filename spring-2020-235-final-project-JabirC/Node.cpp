
#include <iostream>
#include "Node.h"

//REUSED CODE FROM PREVIOUS ASSIGNMENT
//slightly modified to incorporate person class

Node::Node() : next(nullptr){
}

Node::Node(person p){
 this->per = p;
 this->next = nullptr;
}


Node::Node(person p, Node *next){
 this->per = p;
 this->next = next;
}

void Node::setData(person p){
 this->per = p;
}

void Node::setNext(Node *next){
 this->next = next;
}

person  Node::getData(){
 return per;
}

Node* Node::getNext(){
 return next;
}

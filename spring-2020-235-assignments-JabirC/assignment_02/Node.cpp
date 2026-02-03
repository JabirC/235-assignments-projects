#include <iostream>

#include "Node.h"

Node::Node() : next(nullptr)
{
}

Node::Node(std::string data){
  this->data = data;
  this->next = nullptr;
  this->previous = nullptr;
}


Node::Node(std::string data, Node *next){
  this->data = data;
  this->next = next;
  this->previous = nullptr;
}

Node::Node(std::string data, Node *next, Node *previous){
  this->data = data;
  this->next = next;
  this->previous = previous;
}

void Node::setData(std::string data){
  this->data = data;
}

void Node::setNext(Node *next){
  this->next = next;
}

void Node::setPrevious(Node *previous){
  this->previous = previous;
}

std::string Node::getData(){
  return data;
}

Node* Node::getNext(){
  return next;
}

Node* Node::getPrevious(){
  return previous;
}

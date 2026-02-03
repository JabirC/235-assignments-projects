#include <iostream>
#include <string>
#include "List.h"
#include "Node.h"

List::List(){
  current = nullptr;
  len=0;
}

List::~List(){

  std::cout << "In the destructor\n";
  if(current != nullptr){
    Node *t;
    while (current->getPrevious() != nullptr){
      current=current->getPrevious();
    }

    while (current != nullptr){
      t = current;
      current=current->getNext();
      delete t;
    }
    len = 0;
  }
}
void List::insert(std::string data){
  // make the new node
  Node *t = new Node(data);

  Node *cur = current;

  if(cur!= nullptr){ // if list is not empty
    while(cur->getPrevious() != nullptr){
      cur = cur->getPrevious();        //traverse to the front node
    }
    cur->setPrevious(t);           //redirect pointers
    t->setNext(cur);
  }
  else{
    current =t; //if list is empty
  }
  // update the length
  len++;
}

std::string List::getDebugString(){
  Node *cur;
  cur = current;
  std::string result="";
  if(cur !=  nullptr){
    while (cur->getPrevious() != nullptr){
      cur = cur->getPrevious();
    }
    while (cur != nullptr){
      result = result + cur->getData() + "-->";
      cur = cur->getNext();
    }
  }

  result = result + "null";
  return result;
}

int List::length(){
  return len;
}

void List::pushback(std::string s){
  Node *t = new Node(s); // Create the new node
  Node *cur = current;
  //traverse through linked list until the last element
  if(cur!=nullptr){ //if list is not empty
    while (cur->getNext()!=nullptr){
      cur=cur->getNext();
    }
    cur->setNext(t); //set the Next of last element to the new node
    t->setPrevious(cur);
  }
  else{
    current = t; //if list is empty
  }
  len++; //length increases by 1
}

void List::remove(int i){
  if(i>=len || i<0)return; // if i is invalid
  Node *cur = current;

  while(cur->getPrevious() != nullptr){  // traverse to the front node
    cur = cur->getPrevious();
  }

  int l = 0;
  //traverse through linked list until the element i
  while (l < i ){
    cur=cur->getNext();
    l++;
  }

  if(cur->getPrevious() == nullptr){ // if cur is the front node
    if(cur->getNext()== nullptr){ // if cur is the only node
      delete cur;
      current = nullptr;
    }
    else{ // if cur is the front node with atleast one other node after it
      (cur->getNext())->setPrevious(nullptr);
      if(cur == current){
        current = cur->getNext();
      }
      delete cur;
    }
  }
  else{ // if cur is not the front node
    if(cur->getNext() == nullptr){   // if cur is the last node
      (cur->getPrevious())->setNext(nullptr);
      if(cur == current){
        current = cur->getPrevious();
      }
      delete cur;
    }
    else{ // if cur is somewhere between two other nodes
      (cur->getNext())->setPrevious(cur->getPrevious());
      (cur->getPrevious())->setNext(cur->getNext());
      if(cur == current){
        current= cur->getPrevious();
      }
      delete cur;
    }
  }
  len--; // length decreases by 1
}

static std::string ret; // For string to be referenced after function call
std::string& List::operator[](int n){
  ret = "";
  if(n>=len || n<0)return ret; // if n is invalid
  else{
    Node *cur = current;

    while(cur->getPrevious() != nullptr){
      cur = cur->getPrevious(); // traverse to the front node
    }

    int l = 0;
    //traverse through linked list until the element i
    while (l < n ){
      cur=cur->getNext();
      l++;
    }
    ret= cur->getData();
    return ret;
  }
}

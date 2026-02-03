#include <iostream>
#include <string>
#include "List.h"
#include "Node.h"

List::List(){
  head = nullptr;
  len=0;
}

List::~List(){

  std::cout << "In the destructor\n";
  Node *t;
  while (head != nullptr){
    t = head;
    head=head->getNext();
    delete t;
    }
}
void List::insert(std::string data){
  // make the new node
  Node *t = new Node(data);

  // insert it into the list
  t->setNext(head);
  head = t;
  // update the length
  len++;
}

std::string List::getDebugString(){
  Node *t;
  t = head;
  std::string result="";
  while (t != nullptr){
    result = result + t->getData() + "-->";
    t = t->getNext();
  }
  result = result + "null";

  return result;
}

int List::length(){
  // Node *t = head;
  // int l = 0;
  // while (t!=nullptr){
  //   t=t->getNext();
  //   l++;
  // }
  // return l;
  return len;
}

void List::pushback(std::string s){
  Node *t = new Node(s); // Create the new node
  Node *k = head;
  //traverse through linked list until the last element
  while (k->getNext()!=nullptr){
    k=k->getNext();
  }
  k->setNext(t); //set the Next of last element to the new node
  len++; //length increases by 1
}

void List::remove(int i){
  if(i>=len || i<0)return; // if i is invalid
  Node *t = head;
  if(i == 0){ // if removing the head
    head = t->getNext();
    delete t;
  }
  else{
    int l = 0;
    //traverse through linked list until the element before i
    while (l < i - 1){
      t=t->getNext();
      l++;
    }
    Node *k = t->getNext(); //Node after i
    t->setNext(k->getNext());// set Next of node before i to the node after i
    delete k;
  }
  len--; // length decreases by 1
}

static std::string ret; // For string to be referenced after function call
std::string& List::operator[](int n){
  ret = "";
  if(n>=len || n<0)return ret; // if n is invalid
  else{
    Node *t = head;
    //traverse through linked list until the nth element
    for(int i = 0; i < n; i++){
      t = t->getNext();
    }
    ret= t->getData();
    return ret;
  }
}

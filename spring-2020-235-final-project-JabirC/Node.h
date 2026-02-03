#pragma once
#include <string>
#include "Person.h"

//REUSED CODE FROM PREVIOUS ASSIGNMENT
//slightly modified to incorporate person class

class Node{
 private:
  person per; // Node holds data of an instance of class person
  Node *next;
 public:
  Node();
  Node(person p);
  Node(person p, Node* next);

  void setData(person p); 
  void setNext(Node *next);
  person getData();
  Node *getNext();

};

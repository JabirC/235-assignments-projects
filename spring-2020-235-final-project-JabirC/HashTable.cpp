#include <iostream>
#include "HashTable.h"


hash_table::hash_table(){
  size = 10; // number of entries in the array table
  table = new Node*[size]; // allocating memory for array of Node pointers (lined lists) with given size
  for(int i =0; i < size; i++){
    table[i] = nullptr; // intiializing all entries to nullptr
  }
}

hash_table::~hash_table(){
  //first deallocates all nodes from each linked list
  for(int i =0; i < size; i++){
    Node *head = table[i];
    Node *temp;
    while (head != nullptr){
      temp = head;
      head=head->getNext();
      delete temp;
    }
  }
  delete []table; // deallocates memory from table
}


// Hash function, returns the (lenght of first name + length of last name) mod size of array table
int hash_table::hash(person p){
  return ((p.last).length() + (p.first).length())%size;
}

//Inserts Node with data of person p at the index given by the hash function
//If the entry is empty, the node becomes the 'head' or the Node pointer which is stored in the array
//If the entry is not empty, the node is attached to the front of the linked list and becomes the new 'head'
void hash_table::insert(person p){
  Node *n = new Node(p);
  int index = hash(p);
  if(table[index] == nullptr){ // the linked list is empty
    table[index] = n;
  }
  else{
    n->setNext(table[index]); // a non-empty linked list is already there
    table[index] = n;
  }
}

// Looks for the Node with data of person p at the index given by the hash function
// If person p is found, the node carrying the data is deleted from the linked list at the index
void hash_table::deleter(person p){
  int index = hash(p);
  Node *head = table[index];
  if(head == nullptr) return; // the linked list is empty

  // the head is the Node carrying data of person p
  else if((head->getData()).first == p.first &&  (head->getData()).last == p.last){
    table[index] = head->getNext();
    delete head;
  }

  // the Node carrying data of person p is not the head, so traverse through the linked list
  else{
    Node *temp = head;
    while(temp->getNext() != nullptr){
      if(((temp->getNext())->getData()).first == p.first &&  ((temp->getNext())->getData()).last == p.last){
        Node *del = temp->getNext();
        temp->setNext(del->getNext());
        delete del;
        return; // Node is found
      }
      else{
        temp = temp->getNext();
      }
    }
    return; // Node not found
  }
}

//Looks for the Node carrying data of person p,
// if found, returns the full data of person p which includes title and salary
// if not found, returns the original argument passed to the funciton
person hash_table::retrieve(person p){
  int index = hash(p);
  Node *head = table[index];
  while(head != nullptr){
    if((head->getData()).first == p.first &&  (head->getData()).last == p.last){
      return (head->getData());
    }
    head = head->getNext();
  }
  return p;
}


// Used for testing, returns a string version of
// the linked list in the given index of the table
std::string hash_table::debug_string(int ind){
  std::string str = "";
  Node * head = table[ind];
  while(head != nullptr){
    str+= "|" + (head->getData()).last + ", " + (head->getData()).first + ", " + (head->getData()).title + ", " + std::to_string((head->getData()).salary) + "|" + "-->";
    head = head->getNext();
  }
  str+= "NULL";
  return str;
}

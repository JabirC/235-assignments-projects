#pragma once
#include <string>
#include "Node.h"

class hash_table{
 private:
  Node **table; // An array of linked lists, each entry holds a 'head' of a linked list
  int size; // number of entries in the array table
 public:
  hash_table();
  ~hash_table();

  int hash(person p);// hash function which returns an int based on the last and first names of person p
  void insert(person p); // inserts a Node with the data of person p into the table given person p
  void deleter(person p); // Looks for Node carrying data of person p in the table and removes it from the associated linked list and deletes it
  person retrieve(person p); // Looks for Node carrying data of person p in the table and returns the full information of person p if found

  std::string debug_string(int ind); // Used for testing, returns a string version of the linked list in the given index of the table
};

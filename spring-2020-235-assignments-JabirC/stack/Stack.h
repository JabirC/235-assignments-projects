#pragma once
#include <vector>
#include "List.h"


class Stack{
 private:
  List *llist;

 public:
  Stack();
  void push(int); // add an item to the top of the stack
  int pop(); // remove and return an item from the top of the stack
  int top(); // returns element at the top (most recently added)
  bool is_empty(); // return true if the stack is empty;
  std::vector<int> get_vector(); //<-- returns a vector with all the elements in the stack
  void initialize(std::vector<int> a); // <– adds all the elements in a to the stack
  void swap(); // <– swaps the top two elements of the stack.
};

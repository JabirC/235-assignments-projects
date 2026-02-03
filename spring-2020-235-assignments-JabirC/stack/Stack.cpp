#include "Stack.h"

Stack::Stack(){
  llist = new List();
}


void Stack::push(int data){
  llist->insert(data);
} // add an item to the top of the stack


int Stack::pop(){
  if(llist->length() == 0)return -1;
  int ret = (*llist)[0];
  llist->remove(0);
  return ret;
}; // remove and return an item from the top of the stack


int Stack::top(){
  if(llist->length() == 0)return -1;
  int ret = (*llist)[0];
  return ret;
}; // returns element at the top (most recently added)


bool Stack::is_empty(){
  if(llist->length() == 0) return true;
  return false;
}; // return true if the stack is empty;

std::vector<int> Stack::get_vector(){
  std::vector<int> ret;
  int len = llist->length();
  for(int i =0; i < len; i++){
    ret.push_back((*llist)[i]);
  }
  return ret;
}; //<-- returns a vector with all the elements in the stack


void Stack::initialize(std::vector<int> a){
  int len = a.size();
  for(int i = len -1; i >= 0; i--){
    push(a[i]);
  }
}; // <– adds all the elements in a to the stack


void Stack::swap(){
  if(llist->length() < 2)return;
  int a = pop();
  int b = pop();
  push(a);
  push(b);
}; // <– swaps the top two elements of the stack.

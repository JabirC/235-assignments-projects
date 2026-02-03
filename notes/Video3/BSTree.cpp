#include "BSTree.h"
#include "Node.h"
#include <iostream>

BSTree::BSTree(){
  root = nullptr;
}

void BSTree::insert(int d){

}


std::string BSTree::get_debug_string(){
  return get_debug_string_helper(root);
}

std::string BSTree::get_debug_string_helper(Node * r){
  if(r == nullptr) return "";
  else {
    return std::to_string(r->getData()) + " " + get_debug_string_helper(r->getLeft()) +get_debug_string_helper(r->getRight());
  }
}

void BSTree::setup(){
  Node *n = new Node(10);
  root = n;
  n = new Node(20);
  root->setLeft(n);
  n = new Node(30);
  root->setRight(n);
  n = new Node(40);
  root->getLeft()->setLeft(n);
}

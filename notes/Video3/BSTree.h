#pragma once
#include "Node.h"
#include <string>


class BSTree{
  private:
    Node *root;
  public:
    BSTree();
    std::string get_debug_string();
    std::string get_debug_string_helper(Node * r);
    void insert(int data);
    void setup();
};

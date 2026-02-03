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
    void insert_helper(Node * r, int data);
    void deleter(int data);
    Node * delete_helper(Node * r, int data);
    Node * minNode(Node* node);
    void setup();

    Node * getRoot();
    int num_nodes(Node * n);
    int sum_nodes(Node * n);
    int num_leaves(Node * n);
    int tree_height(Node * n);
    int sum_at_level(Node * n, int level);
    int rootleaf(Node * n);
};

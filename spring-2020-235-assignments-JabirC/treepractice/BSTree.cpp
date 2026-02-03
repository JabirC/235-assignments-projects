#include "BSTree.h"
#include "Node.h"
#include <iostream>

BSTree::BSTree(){
  root = nullptr;
}

void BSTree::insert(int data){
  if(root == nullptr){
    root = new Node(data);
  }
  else insert_helper(root, data);
}

void BSTree::insert_helper(Node * r, int data){
  if (r->getData() > data){
    if(r->getLeft() == nullptr){
      r->setLeft(new Node(data));
      return;
    }
    insert_helper(r->getLeft(), data);
    return;
  }
  else{
    if(r->getRight() == nullptr){
      r->setRight(new Node(data));
      return;
    }
    insert_helper(r->getRight(), data);
    return;
  }
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

Node * BSTree::minNode(Node* node){
    Node * current = node;
    while (current && current->getLeft() != nullptr)
        current = current->getLeft();

    return current;
}

void BSTree::deleter(int data){
  if(root == nullptr) return;
  else root = delete_helper(root,data);
}

Node * BSTree::delete_helper(Node* r, int data){
    if (r == nullptr) return r;
    if (data < r->getData())
        r->setLeft(delete_helper(r->getLeft(), data));
    else if (data > r->getData())
        r->setRight(delete_helper(r->getRight(), data));
    else
    {
        if (r->getLeft() == nullptr)
        {
            Node *temp = r->getRight();
            delete r;
            return temp;
        }
        else if (r->getRight() == nullptr)
        {
            Node *temp = r->getLeft();
            delete r;
            return temp;
        }
        Node * temp = minNode(r->getRight());
        r->setData(temp->getData());
        r->setRight(delete_helper(r->getRight(), temp->getData()));
    }
    return r;
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


Node* BSTree::getRoot(){
  return root;
}


int BSTree::num_nodes(Node * n){
  if (n == nullptr){
    return 0;
  }
  int num_left = num_nodes(n->getLeft());
  int num_right = num_nodes(n->getRight());
  return 1 + num_left + num_right;
}

int BSTree::sum_nodes(Node * n){
  if (n == nullptr){
    return 0;
  }
  int num_left = num_nodes(n->getLeft());
  int num_right = num_nodes(n->getRight());
  return n->getData() + num_left + num_right;
}



int BSTree::num_leaves(Node * n){
  if(n == nullptr){
     return 0;
  }

  if(n->getLeft() == nullptr && n->getRight() == nullptr){
     return 1;
  }

  int left_node = num_leaves(n->getLeft());
  int right_node = num_leaves(n->getRight());
  return left_node + right_node;
}

int BSTree::tree_height(Node * n){
  if (n == nullptr){
    return 0;
  }
  int left_node = tree_height(n->getLeft());
  int right_node = tree_height(n->getRight());
  int height;

  if (left_node > right_node){
    height = left_node;
  }
  else {
    height = right_node;
  }

  return 1 + height;
}

int BSTree::sum_at_level(Node * n, int level){
  if(n == nullptr){
     return 0;
  }
  if(level == 0){
     return n->getData();
  }
  return sum_at_level(n->getLeft(), level-1) + sum_at_level(n->getRight(), level-1);
}


int BSTree::rootleaf(Node * n){
  if (n == nullptr){
    return 0;
  }

  if(n->getLeft() == nullptr && n->getRight() == nullptr){ //leaf found
   return n->getData();

  }
  int left_node = rootleaf(n->getLeft());
  int right_node = rootleaf(n->getRight());
  int greater_path;

  if (left_node > right_node){
    greater_path = left_node;
  }
  else {
    greater_path = right_node;
  }

  return n->getData() + greater_path;
}

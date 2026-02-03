#include <iostream>
#include "Node.h"
#include "BSTree.h"

int main(){
  // BSTree *t = new BSTree();
  // t->setup();
  // std::cout << t->get_debug_string() << std::endl;


  BSTree * n = new BSTree();
  n->insert(10);
  n->insert(20);
  n->insert(30);
  n->insert(5);
  n->insert(17);
  n->insert(22);
  n->insert(35);
  n->insert(40);
  n->insert(8);
  n->insert(3);
  n->insert(9);
  std::cout << n->get_debug_string() << std::endl;
  std::cout << "Should be : 10 5 3 8 9 20 17 30 22 35 40" << std::endl << std::endl;

  n->deleter(10);
  std::cout << "***Deleting 10***" << std::endl;
  std::cout << n->get_debug_string() << std::endl;
  std::cout << "Should be : 17 5 3 8 9 20 30 22 35 40" << std::endl << std::endl;

  n->deleter(5);
  std::cout << "***Deleting 5***" << std::endl;
  std::cout << n->get_debug_string() << std::endl;
  std::cout << "Should be : 17 8 3 9 20 30 22 35 40" << std::endl << std::endl;

  n->deleter(9);
  std::cout << "***Deleting 9***" << std::endl;
  std::cout << n->get_debug_string() << std::endl;
  std::cout << "Should be : 17 8 3 20 30 22 35 40" << std::endl << std::endl;

  n->deleter(20);
  std::cout << "***Deleting 20***" << std::endl;
  std::cout << n->get_debug_string() << std::endl;
  std::cout << "Should be : 17 8 3 30 22 35 40" << std::endl << std::endl;

  n->deleter(40);
  std::cout << "***Deleting 40***" << std::endl;
  std::cout << n->get_debug_string() << std::endl;
  std::cout << "Should be : 17 8 3 30 22 35" << std::endl << std::endl;
  return 0;
}

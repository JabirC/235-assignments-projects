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

  std::cout << n->get_debug_string() << std::endl << std::endl;

  std::cout << "Num Nodes: " << n->num_nodes(n->getRoot()) << std::endl;
  std::cout << "-----Should be 11-----" << std::endl << std::endl;


  std::cout << "Sum Nodes: " << n->sum_nodes(n->getRoot()) << std::endl;
  std::cout << "-----Should be 20-----" << std::endl << std::endl;


  std::cout << "Num Leaves: " << n->num_leaves(n->getRoot()) << std::endl;
  std::cout << "-----Should be 5-----" << std::endl << std::endl;

  std::cout << "Tree Height: " << n->tree_height(n->getRoot()) << std::endl;
  std::cout << "-----Should be 5-----" << std::endl << std::endl;

  std::cout << "Sum at Level 0: " << n->sum_at_level(n->getRoot(), 0) << std::endl;
  std::cout << "-----Should be 10-----" << std::endl << std::endl;
  std::cout << "Sum at Level 1: " << n->sum_at_level(n->getRoot(), 1) << std::endl;
  std::cout << "-----Should be 25-----" << std::endl << std::endl;
  std::cout << "Sum at Level 2: " << n->sum_at_level(n->getRoot(), 2) << std::endl;
  std::cout << "-----Should be 58-----" << std::endl << std::endl;
  std::cout << "Sum at Level 3: " << n->sum_at_level(n->getRoot(), 3) << std::endl;
  std::cout << "-----Should be 66-----" << std::endl << std::endl;
  std::cout << "Sum at Level 4: " << n->sum_at_level(n->getRoot(), 4) << std::endl;
  std::cout << "-----Should be 40-----" << std::endl << std::endl;

  std::cout << "rootleaf: " << n->rootleaf(n->getRoot()) << std::endl;
  std::cout << "-----Should be 135-----" << std::endl <<std::endl;





  BSTree *n2 = new BSTree();
  n2->insert(16);
  n2->insert(29);
  n2->insert(31);
  n2->insert(5);
  n2->insert(13);
  n2->insert(12);
  n2->insert(88);
  n2->insert(2);
  n2->insert(14);
  n2->insert(8);
  n2->insert(15);

  std::cout << "##########################################" <<std::endl;
  std::cout << n2->get_debug_string() << std::endl << std::endl;

  std::cout << "Num Nodes: " << n2->num_nodes(n2->getRoot()) << std::endl;
  std::cout << "-----Should be 11-----" << std::endl << std::endl;


  std::cout << "Sum Nodes: " << n2->sum_nodes(n2->getRoot()) << std::endl;
  std::cout << "-----Should be 26-----" << std::endl << std::endl;


  std::cout << "Num Leaves: " << n2->num_leaves(n2->getRoot()) << std::endl;
  std::cout << "-----Should be 4-----" << std::endl << std::endl;

  std::cout << "Tree Height: " << n2->tree_height(n2->getRoot()) << std::endl;
  std::cout << "-----Should be 5-----" << std::endl << std::endl;

  std::cout << "Sum at Level 0: " << n2->sum_at_level(n2->getRoot(), 0) << std::endl;
  std::cout << "-----Should be 16-----" << std::endl << std::endl;
  std::cout << "Sum at Level 1: " << n2->sum_at_level(n2->getRoot(), 1) << std::endl;
  std::cout << "-----Should be 34-----" << std::endl << std::endl;
  std::cout << "Sum at Level 2: " << n2->sum_at_level(n2->getRoot(), 2) << std::endl;
  std::cout << "-----Should be 46-----" << std::endl << std::endl;
  std::cout << "Sum at Level 3: " << n2->sum_at_level(n2->getRoot(), 3) << std::endl;
  std::cout << "-----Should be 114-----" << std::endl << std::endl;
  std::cout << "Sum at Level 4: " << n2->sum_at_level(n2->getRoot(), 4) << std::endl;
  std::cout << "-----Should be 23-----" << std::endl << std::endl;

  std::cout << "rootleaf: " << n2->rootleaf(n2->getRoot()) << std::endl;
  std::cout << "-----Should be 164-----" << std::endl <<std::endl;
  return 0;
}

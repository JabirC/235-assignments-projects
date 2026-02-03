#include <iostream>
#include "Node.h"


int main(){

  Node * n = new Node(10);
  Node * n1 = new Node(20);
  Node * n2 = new Node(50);
  Node * n3 = new Node(30);
  Node * n4 = new Node(40);
  Node * n5 = new Node(60);
  Node * n6 = new Node(70);

  n->setLeft(n1);
  n->setRight(n2);

  n1->setLeft(n3);
  n3->setLeft(n4);

  n2->setLeft(n5);
  n2->setRight(n6);

  std::cout << n->getData() << std::endl;
  std::cout << n->getLeft()->getData() << std::endl;
  std::cout << n->getRight()->getData() << std::endl;

  std::cout << n1->getLeft()->getData() << std::endl;

  std::cout << n3->getLeft()->getData() << std::endl;

  std::cout << n2->getLeft()->getData() << std::endl;
  std::cout << n2->getRight()->getData() << std::endl;

  return 0;
}

#define DOCTEST_CONFIG_IMPLEMENT


#include "practice.h"

#include <iostream>

int main()
{

  Node * n = new Node();
  n = nullptr;
  std::cout << (reverse(n) == nullptr) << std::endl;


  Node * m = new Node(20, nullptr);
  std::cout << getDebugString(m) << std::endl;

  Node * test = reverse(m);
  std::cout << getDebugString(test) << std::endl;

  Node * a = new Node(3, nullptr);
  Node * b = new Node(4, a);
  Node * c = new Node(7, b);
  Node * d = new Node(9, c);
  Node * e = new Node(11, d);

  std::cout << getDebugString(e) << std::endl;
  std::cout << getDebugString(reverse(e)) << std::endl;

  Node * a4 = new Node(23, nullptr);
  Node * a3 = new Node(16, a4);
  Node * a2 = new Node(13, a3);
  Node * a1 = new Node(9, a2);
  Node * a0 = new Node(5, a1);

  std::cout << getDebugString(merge(a,a0)) << std::endl; 


  std::cout << "The end\n";
  return 0;
}

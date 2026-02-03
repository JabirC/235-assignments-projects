#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "practice.h"
#include "Node.h"



TEST_CASE("reverse(node* i)"){

  Node * n = new Node();
  n = nullptr;
  std::cout << (reverse(n) == nullptr) << std::endl;


  Node * m = new Node(20, nullptr);
  CHECK(getDebugString(m) == "20--> nullptr");

  Node * test = reverse(m);
  CHECK(getDebugString(test) == "20--> nullptr");

  Node * a = new Node(3, nullptr);
  Node * b = new Node(4, a);
  Node * c = new Node(7, b);
  Node * d = new Node(9, c);
  Node * e = new Node(11, d);

  CHECK(getDebugString(e) == "11--> 9--> 7--> 4--> 3--> nullptr");
  CHECK(getDebugString(reverse(e)) == "3--> 4--> 7--> 9--> 11--> nullptr");

}

TEST_CASE("merge(Node * a, Node * b)"){

  Node * a = new Node(3, nullptr);
  Node * b = new Node(4, a);
  Node * c = new Node(7, b);
  Node * d = new Node(9, c);
  Node * e = new Node(11, d);

  reverse(e);
  Node * a4 = new Node(23, nullptr);
  Node * a3 = new Node(16, a4);
  Node * a2 = new Node(13, a3);
  Node * a1 = new Node(9, a2);
  Node * a0 = new Node(5, a1);

  CHECK(getDebugString(merge(a,a0)) == "3--> 4--> 5--> 7--> 9--> 9--> 11--> 13--> 16--> 23--> nullptr");

}

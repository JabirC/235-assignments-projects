#define DOCTEST_CONFIG_IMPLEMENT

#include "Queue.h"
#include <iostream>

int main()
{
  Queue *a = new Queue();


  // Testing is_empty()
  std::cout << a->is_empty() << std::endl;

  // Testing enqueue()
  a->enqueue(3);
  a->enqueue(2);
  a->enqueue(1);
  a->enqueue(0);

  // Testing is_empty now
  std::cout << a->is_empty() << std::endl;


  // Testing dequeue now
  std::cout << a->dequeue() << std::endl;

  // Testing resizing
  a->enqueue(5);
  a->enqueue(6);
  a->enqueue(7);
  a->enqueue(8);


  std::cout << a->getDebugString() << std::endl;
  delete a;

  std::cout << "The end\n";
  return 0;
}

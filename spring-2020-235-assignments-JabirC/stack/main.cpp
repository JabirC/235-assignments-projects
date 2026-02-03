#include <iostream>
#include "Stack.h"
int main()
{
  Stack *s = new Stack();
  s->push(1);
  s->push(2);
  std::cout << s->top() << std::endl;
  std::cout << s->pop() <<std::endl;
  std::cout << s->top() << std::endl;
   return 0;
}

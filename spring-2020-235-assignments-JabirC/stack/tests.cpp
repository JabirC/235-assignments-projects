#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "Stack.h"


TEST_CASE("push(int) + top() + get_vector()"){
   Stack *s = new Stack();
   s->push(1);
   CHECK(s->top() == 1);
   s->push(2);
   CHECK(s->top() == 2);
   s->push(3);
   CHECK(s->top() == 3);
   s->push(4);
   CHECK(s->top() == 4);
   s->push(5);
   CHECK(s->top() == 5);
   std::vector<int> v;


   v = s->get_vector();
   CHECK(v[0] == 5);
   CHECK(v[1] == 4);
   CHECK(v[2] == 3);
   CHECK(v[3] == 2);
   CHECK(v[4] == 1);

}


TEST_CASE("pop()  + top() + is_empty()"){
   Stack *s = new Stack();
   s->push(1);
   CHECK(s->top() == 1);
   s->push(2);
   CHECK(s->top() == 2);
   s->push(3);
   CHECK(s->top() == 3);
   s->push(4);
   CHECK(s->top() == 4);
   s->push(5);
   CHECK(s->top() == 5);

   int temp;

   temp = s->pop();
   CHECK(temp == 5);
   CHECK(s->top() == 4);

   temp = s->pop();
   CHECK(temp == 4);
   CHECK(s->top() == 3);

   temp = s->pop();
   CHECK(temp == 3);
   CHECK(s->top() == 2);

   temp = s->pop();
   CHECK(temp == 2);
   CHECK(s->top() == 1);

   temp = s->pop();
   CHECK(temp == 1);
   CHECK(s->top() == -1); //error check
   CHECK(s->is_empty() == true);
}


TEST_CASE("is_empty()"){
   Stack *s = new Stack();
   CHECK(s->is_empty() == true);
   s->push(1);
   CHECK(s->is_empty() == false);
   s->push(2);
   CHECK(s->is_empty() == false);
   s->push(3);
   CHECK(s->is_empty() == false);
   s->push(4);
   CHECK(s->is_empty() == false);
   s->push(5);
   CHECK(s->is_empty() == false);
   s->pop();
   s->pop();
   s->pop();
   s->pop();
   s->pop();
   CHECK(s->is_empty() == true);
   CHECK(s->pop() == -1); //error check
}

TEST_CASE("initialize()"){
   Stack *s = new Stack();
   CHECK(s->is_empty() == true);

   s->push(1);
   s->push(2);
   s->push(3);
   s->push(4);
   s->push(5);


   std::vector<int> v;
   v = s->get_vector();

   CHECK(v[0] == 5);
   CHECK(v[1] == 4);
   CHECK(v[2] == 3);
   CHECK(v[3] == 2);
   CHECK(v[4] == 1);

   s->pop();
   s->pop();
   s->pop();
   s->pop();
   s->pop();

   CHECK(s->is_empty() == true);

   s->initialize(v);

   CHECK(s->is_empty() == false);

   CHECK(s->pop() == 5);
   CHECK(s->pop() == 4);
   CHECK(s->pop() == 3);
   CHECK(s->pop() == 2);
   CHECK(s->pop() == 1);

   CHECK(s->is_empty() == true);
}



TEST_CASE("swap()"){
   Stack *s = new Stack();
   CHECK(s->is_empty() == true);
   s->swap(); // error check
   s->push(1);
   s->swap(); // error check

   CHECK(s->top() == 1);

   s->push(2);
   CHECK(s->top() == 2);

   s->swap();
   CHECK(s->top() == 1);

   CHECK(s->pop() == 1);
   CHECK(s->pop() == 2);
   CHECK(s->is_empty() == true);
}

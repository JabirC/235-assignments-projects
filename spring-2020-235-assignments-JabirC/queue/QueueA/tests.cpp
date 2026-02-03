#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "Queue.h"


TEST_CASE("IS_EMPTY()"){
  Queue *q = new Queue();

  // Testing is_empty()
  CHECK(q->is_empty() == true);

  // Testing enqueue()
  q->enqueue(9);
  q->enqueue(8);
  q->enqueue(7);
  q->enqueue(6);

  // Testing is_empty now
  CHECK(q->is_empty() == false);

  delete q;
}

TEST_CASE("ENQUEUE(data)"){
  Queue *q = new Queue();

  q->enqueue(9);
  q->enqueue(8);
  q->enqueue(7);
  q->enqueue(6);


  CHECK(q->getDebugString() == "9<-8<-7<-6");


  q->enqueue(5);
  q->enqueue(4);
  q->enqueue(3);
  q->enqueue(2);

  CHECK(q->getDebugString() == "9<-8<-7<-6<-5<-4<-3<-2");

  delete q;
}

TEST_CASE("DEQUEUE()"){
  Queue *q = new Queue();

  q->enqueue(11);
  q->enqueue(5);
  q->enqueue(8);
  q->enqueue(4);

  CHECK(q->dequeue() == 11);

  CHECK(q->getDebugString() == "5<-8<-4");

  CHECK(q->dequeue() == 5);

  CHECK(q->getDebugString() == "8<-4");

  CHECK(q->dequeue() == 8);

  CHECK(q->getDebugString() == "4");

  CHECK(q->dequeue() == 4);

  // q->dequeue(); //throws exception

  delete q;
}

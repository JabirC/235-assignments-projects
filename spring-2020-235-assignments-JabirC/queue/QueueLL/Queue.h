#pragma once

#include <string>
#include "Node.h"

#define EMPTY_QUEUE 1

class Queue{
 private:
  Node *head;
  Node *tail;
  int size;
 public:
  Queue();
  ~Queue();
  void enqueue(int data);
  int dequeue();
  bool is_empty();

  std::string getDebugString();

};

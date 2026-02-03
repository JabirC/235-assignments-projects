#pragma once
#include <iostream>
#include <string>

#define EMPTY_QUEUE 1


class Queue{
private:
   int* a;
   int head, tail, size;
public:
   Queue(); //constructor
   void enqueue(int data); //adds an item to the back of the queue
   int dequeue(); //removes and returns the item from the front of the queue
   bool is_empty();
   std::string getDebugString();
};

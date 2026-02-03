
#pragma once
#include <string>

class MinHeap {
private:
 int * minHeap;
 int size;
public:
 MinHeap();
 void insert(int val);
 int getSize();
 int getRoot();
 void removeRoot();
 void heapify(int index);
 std::string printHeap();

};

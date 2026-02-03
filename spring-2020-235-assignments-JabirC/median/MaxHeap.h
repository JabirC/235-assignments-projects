
#pragma once
#include <string>

class MaxHeap {
private:
 int * maxHeap;
 int size;
public:
 MaxHeap();
 void insert(int val);
 int getSize();
 int getRoot();
 void removeRoot();
 void heapify(int index);
 std::string printHeap();

};

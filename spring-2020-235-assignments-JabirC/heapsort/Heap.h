#pragma once
#include <string>

class Heap {
private:
 int* heap;
 int size;
public:
 Heap(int* arr, int n);

 void heapsort();
 void heapify(int index);
 int remove_min(int index);

 std::string printHeap();
};

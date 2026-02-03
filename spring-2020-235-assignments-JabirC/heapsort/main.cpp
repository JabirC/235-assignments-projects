#define DOCTEST_CONFIG_IMPLEMENT

#include <iostream>
#include "Heap.h"
#include "doctest.h"


int main(){
 int arr[9] = {65, 4, 23, 10, 54, 45, 14, 21, 30};
 Heap * h = new Heap(arr, 9);
 std::cout<< "Heapification:" <<std::endl;
 h->heapify(0);
 std::cout << h->printHeap() << std::endl;
 h->heapify(1);
 std::cout << h->printHeap() << std::endl;
 h->heapify(2);
 std::cout << h->printHeap() << std::endl;
 h->heapify(3);
 std::cout << h->printHeap() << std::endl;
 h->heapify(4);
 std::cout << h->printHeap() << std::endl;
 h->heapify(5);
 std::cout << h->printHeap() << std::endl;
 h->heapify(6);
 std::cout << h->printHeap() << std::endl;
 h->heapify(7);
 std::cout << h->printHeap() << std::endl;
 h->heapify(8);
 std::cout << h->printHeap() << std::endl;
 h->heapify(9);
 std::cout << h->printHeap() << std::endl;

 std::cout << std::endl << "Sorted:" << std::endl;
 h->heapsort();

 std::cout << h->printHeap() << std::endl; 

 delete h;
}

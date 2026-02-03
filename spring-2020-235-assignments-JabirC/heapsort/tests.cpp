#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <string>
#include <iostream>
#include "Heap.h"
#include "doctest.h"


TEST_CASE("HEAPIFY"){
  int arr[9] = {65, 4, 23, 10, 54, 45, 14, 21, 30};
  Heap * h = new Heap(arr, 9);

  h->heapify(0);
  CHECK(h->printHeap() == "65 4 23 10 54 45 14 21 30 ");

  h->heapify(1);
  CHECK(h->printHeap() == "4 65 23 10 54 45 14 21 30 ");

  h->heapify(2);
  CHECK(h->printHeap() == "4 65 23 10 54 45 14 21 30 ");

  h->heapify(3);
  CHECK(h->printHeap() == "4 10 23 65 54 45 14 21 30 ");

  h->heapify(4);
  CHECK(h->printHeap() == "4 10 23 65 54 45 14 21 30 ");

  h->heapify(5);
  CHECK(h->printHeap() == "4 10 23 65 54 45 14 21 30 ");

  h->heapify(6);
  CHECK(h->printHeap() == "4 10 14 65 54 45 23 21 30 ");

  h->heapify(7);
  CHECK(h->printHeap() == "4 10 14 21 54 45 23 65 30 ");

  h->heapify(8);
  CHECK(h->printHeap() == "4 10 14 21 54 45 23 65 30 ");

  h->heapify(9);
  CHECK(h->printHeap() == "4 10 14 21 54 45 23 65 30 ");

  delete h;
}

TEST_CASE("heapsort()"){
  int arr[9] = {50, 10, 20, 35, 30, 40, 32, 42, 47};
  Heap * h = new Heap(arr, 9);
  h->heapsort();

  CHECK(h->printHeap() == "50 47 42 40 35 32 30 20 10 ");

  delete h;
}

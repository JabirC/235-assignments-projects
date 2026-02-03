#pragma once
// Declaration
template <class T>
class myVector {
public:
  myVector();
  int get_size();
  void add_back(T elem);
  T& operator [] (int index);
private:
  T* dynamic_arr;
  void expand();
  int size;
  int capacity;
};

#include "myVector.hxx"

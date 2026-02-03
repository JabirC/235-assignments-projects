// Definition
#include "myVector.h"

template <class T>
myVector<T>::myVector(){
  dynamic_arr = new T[10];
  size =0;
  capacity = 10;
}

template <class T>
int myVector<T>::get_size(){
  return size;
}

template <class T>
void myVector<T>::add_back(T elem){
  if(size >= capacity) expand();
  dynamic_arr[size] = elem;
  size++;
}

template <class T>
T& myVector<T>::operator[](int index){
  return dynamic_arr[index];
}

template <class T>
void myVector<T>::expand(){
  capacity *= 2;
  T* temp = new T[capacity];
  for(int i =0; i < size;i++){
    temp[i] = dynamic_arr[i];
  }
  dynamic_arr = temp;
  delete[] temp;
}

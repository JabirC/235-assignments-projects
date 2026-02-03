#include <iostream>
#include <string>
#include "Heap.h"

Heap::Heap(int* arr, int n){
  heap = arr;
  size = n;
}

void Heap::heapsort(){
   int i =1;
   while(i <size){
      heapify(i);
      i++;
   }
   i=0;
   while(i <size){
      remove_min(size-i-1);
      i++;
   }
}
void Heap::heapify(int index){
   if(index<1){
      return;
   }
   else{
      int mid=(index-1)/2;
      if(heap[mid]>heap[index]){
         int temp=heap[mid];
         heap[mid]=heap[index];
         heap[index]=temp;
         heapify(mid);
      }
   }
}
int Heap::remove_min(int index){
   if(index<1){
      return 0;
   }
   else{
      int temp=heap[0];
      heap[0]=heap[index];
      heap[index]=temp;
      for(int i=1;i<index;i++){
         heapify(i);
      }
   }
}

std::string Heap::printHeap(){
  std::string str = "";
  for(int i =0; i< size; i++){
    str += std::to_string(heap[i]) + " ";
  }
  return str;

}

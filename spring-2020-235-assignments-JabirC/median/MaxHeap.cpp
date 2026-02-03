#include "MaxHeap.h"
#include <iostream>
#include <string>

MaxHeap::MaxHeap(){
  maxHeap = new int[10];
  size = 0;
}
int MaxHeap::getRoot(){
  return maxHeap[0];
}
void MaxHeap::insert(int val){
  maxHeap[size] = val;
  size++;
  int i =1;
  while(i <size){
     heapify(i);
     i++;
  }
}

void MaxHeap::heapify(int index){
   if(index<1){
      return;
   }
   else{
      int mid=(index-1)/2;
      if(maxHeap[mid]>maxHeap[index]){
         int temp=maxHeap[mid];
         maxHeap[mid]=maxHeap[index];
         maxHeap[index]=temp;
         heapify(mid);
      }
   }
}

int MaxHeap::getSize(){
  return size;
}
void MaxHeap::removeRoot(){
  int temp = maxHeap[0];
  maxHeap[0] = maxHeap[size-1];
  maxHeap[size-1] = temp;
  size--;
  int i =1;
  while(i <size){
     heapify(i);
     i++;
  }
}



std::string MaxHeap::printHeap(){
  std::string ret = "";
  for(int i =0; i< size; i++){
    ret += std::to_string(maxHeap[i]);
    ret += " ";
  }
  return ret;

}

#include <iostream>
#include "MinHeap.h"

MinHeap::MinHeap(){
  minHeap = new int[10] ;
  size = 0;
}
int MinHeap::getRoot(){
  return minHeap[0];
}
void MinHeap::insert(int val){
  minHeap[size] = val;
  size++;
  int i =1;
  while(i <size){
     heapify(i);
     i++;
  }
}

void MinHeap::heapify(int index){
   if(index<1){
      return;
   }
   else{
      int mid=(index-1)/2;
      if(minHeap[mid]<minHeap[index]){
         int temp=minHeap[mid];
         minHeap[mid]=minHeap[index];
         minHeap[index]=temp;
         heapify(mid);
      }
   }
}

int MinHeap::getSize(){
  return size;
}
void MinHeap::removeRoot(){
  int temp = minHeap[0];
  minHeap[0] = minHeap[size-1];
  minHeap[size-1] = temp;
  size--;
  int i =1;
  while(i <size){
     heapify(i);
     i++;
  }
}


std::string MinHeap::printHeap(){
  std::string ret = "";
  for(int i =0; i< size; i++){
    ret += std::to_string(minHeap[i]);
    ret += " ";
  }
  return ret;

}

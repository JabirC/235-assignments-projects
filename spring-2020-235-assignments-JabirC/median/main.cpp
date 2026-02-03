#include <iostream>
#include "MinHeap.h"
#include "MaxHeap.h"

double medCalc(int value, MaxHeap * minH, MinHeap * maxH){
  if(minH->getSize()==0|| value<minH->getRoot()){
    minH->insert(value);
  }
  else{
    maxH->insert(value);
  }
  if(minH->getSize()>maxH->getSize()){
    if(minH->getSize()-maxH->getSize()>=2){
      maxH->insert(minH->getRoot());
      minH->removeRoot();
    }
  }
  else if(maxH->getSize()>minH->getSize()){
    if(maxH->getSize()-minH->getSize()>=2){
      minH->insert(maxH->getRoot());
      maxH->removeRoot();
    }
  }
  if(minH->getSize()==maxH->getSize()){
    return (minH->getRoot()+maxH->getRoot())/2;
  }
  else if(minH->getSize()>maxH->getSize()){
    return minH->getRoot();
  }
  else if(minH->getSize()<maxH->getSize()){
    return maxH->getRoot();
  }
  return -1;
}

int main() {
  int myInputs[6]={1,5,3,4,6, 7};
  MaxHeap * minH = new MaxHeap(); //all numbers before median
  MinHeap * maxH = new MinHeap(); //all numbers after median
  std::string medians;
  for(int i = 0; i<6; i++){
    medians+=std::to_string(medCalc(myInputs[i], minH, maxH))+"  ";
  }
  std::cout<<medians<<std::endl;


  int myInputs2[6]={13,65,22,11,34,13};
  MaxHeap * minH2 = new MaxHeap(); //all numbers before median
  MinHeap * maxH2 = new MinHeap(); //all numbers after median
  std::string medians2;
  for(int i = 0; i<6; i++){
    medians2+=std::to_string(medCalc(myInputs2[i], minH2, maxH2))+"  ";
  }
  std::cout<<medians2<<std::endl;



  int myInputs3[6]={8,12,32,14,30,19};
  MaxHeap * minH3 = new MaxHeap(); //all numbers before median
  MinHeap * maxH3 = new MinHeap(); //all numbers after median
  std::string medians3;
  for(int i = 0; i<6; i++){
    medians3+=std::to_string(medCalc(myInputs3[i], minH3, maxH3))+"  ";
  }
  std::cout<<medians3<<std::endl;


  return 0;
}

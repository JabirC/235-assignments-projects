#include "Queue.h"

void Queue::enqueue(int data){
  if(tail == size){
    size = size * 2;
    int * temp = new int[size];
    for(int i =0; i < tail; i++){
      temp[i] = a[i];
    }
    delete[] a;
    a = temp;
  }
  a[tail] = data;
  tail++;
}
int Queue::dequeue(){
   if(tail == 0){
      throw EMPTY_QUEUE;
   }
   else{
     int ret = a[head];
     for(int i = 1; i < tail; i++){
       a[i - 1] = a[i];
     }
     tail--;
     return ret;
   }
}

Queue::Queue(){
    a=new int[10];
    size=10;
    head=0;
    tail=0;
}

bool Queue::is_empty(){
    return !tail;
}


std::string Queue::getDebugString(){
   std::string s="";
   for(int i = 0 ; i < tail - 1; i++){
     s+=std::to_string(a[i]) + "<-";
   }
   s+= std::to_string(a[tail -1 ]);
   return s;
}

#include "Queue.h"
#include "Node.h"

void Queue::enqueue(int data){
  Node * n = new Node(data);
  if(head == nullptr){
    head = n;
    tail = n;
  }
  else{
    tail->setNext(n);
    tail = n;
  }
}
int Queue::dequeue(){
  if(head == nullptr){
    throw EMPTY_QUEUE;
  }
  else if(head == tail && head != nullptr){
    int ret = head->getData();
    delete head;
    head = nullptr;
    tail = nullptr;
    return ret;
  }
  else{
    Node * temp = head;
    int ret = head->getData();
    head = head->getNext();
    delete temp;
    return ret;
  }
}

Queue::Queue(){
  head = nullptr;
  tail = nullptr;
}

Queue::~Queue(){
  while(head!= nullptr){
    Node * temp = head;
    head = head->getNext();
    delete temp;
  }
}

bool Queue::is_empty(){
  if(head == nullptr) return true;
  return false;
}


std::string Queue::getDebugString(){
  std::string s = "";
  Node * temp = head;
  while(temp!= nullptr){
    s+= std::to_string(temp->getData()) + "->";
    temp = temp->getNext();
  }
  s += "null";
  return s;
}

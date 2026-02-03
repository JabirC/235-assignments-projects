#include "practice.h"


Node * reverse(Node *i){

  Node * head = i;
  Node * temp = head;
  Node * prev = nullptr;
  Node * next = nullptr;

  while (temp != NULL){
    next = temp->getNext();

    temp->setNext(prev);

    prev = temp;
    temp = next;
  }

  head = prev;

  return head;

}

Node* merge(Node* a, Node* b)
{
    Node* result = nullptr;

    if (a == nullptr) return b;
    else if (b == nullptr) return a;

    if (a->getData() <= b->getData()) {
        result = a;
        result->setNext(merge(a->getNext(), b));
    }
    else {
        result = b;
        result->setNext(merge(a, b->getNext()));
    }
    return result;
}



std::string getDebugString(Node * n){
  std::string s = "";
  Node * temp = n;

  while (temp != nullptr){
    s += std::to_string(temp->getData()) + "--> ";
    temp = temp->getNext();
  }
  s += "nullptr";
  return s;
}

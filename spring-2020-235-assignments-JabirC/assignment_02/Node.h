#pragma once

class Node{
 private:
  std::string data;
  Node *next;
  Node *previous;
 public:
  Node();
  Node(std::string data);
  Node(std::string,Node* next);
  Node(std::string,Node* next, Node* previous);

  void setData(std::string data);
  void setNext(Node *next);
  void setPrevious(Node *previous);
  std::string getData();
  Node *getNext();
  Node *getPrevious();

};

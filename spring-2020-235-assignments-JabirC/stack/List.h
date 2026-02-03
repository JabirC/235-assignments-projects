
#pragma once

#include <string>
#include "Node.h"

class List{
private:
 Node *head;
 int len;
public:
 List();
 ~List();
 void insert(int data);
 std::string getDebugString();
 int length();
 void pushback(int s);
 void remove(int i);
 int& operator[] (int n);
};

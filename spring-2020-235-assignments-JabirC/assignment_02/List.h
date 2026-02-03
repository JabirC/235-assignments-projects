
#pragma once

#include <string>
#include "Node.h"

class List{
private:
 Node *current;
 int len;
public:
 List();
 ~List();
 void insert(std::string data);
 std::string getDebugString();
 int length();
 void pushback(std::string s);
 void remove(int i);
 std::string& operator[] (int n);
};

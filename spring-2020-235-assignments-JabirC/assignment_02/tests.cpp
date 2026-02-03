#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "List.h"


TEST_CASE("insert(std::string data)"){
  List *t = new List();
  t->insert("A");
  t->insert("B");
  t->insert("C");
  t->insert("D");
  CHECK(t->getDebugString()=="D-->C-->B-->A-->null");

  CHECK((*t)[0] == "D");
  CHECK((*t)[1] == "C");
  CHECK((*t)[2] == "B");
  CHECK((*t)[3] == "A");
  CHECK((*t)[10] == "");
  CHECK((*t)[-5] == "");
}

TEST_CASE("pushback(std::string s)"){
   List *t = new List();
   t->insert("A");
   t->insert("B");
   t->insert("C");
   t->insert("D");
   CHECK(t->length() == 4);
   t->pushback("E");
   CHECK(t->getDebugString()=="D-->C-->B-->A-->E-->null");
   CHECK(t->length() == 5);
   t->pushback("F");
   CHECK(t->getDebugString()=="D-->C-->B-->A-->E-->F-->null");
   CHECK(t->length() == 6);
   t->pushback("G");
   CHECK(t->getDebugString()=="D-->C-->B-->A-->E-->F-->G-->null");
   CHECK(t->length() == 7);
}
TEST_CASE("remove(int i)"){
  List *t = new List();
  t->insert("A");
  t->insert("B");
  t->insert("C");
  t->insert("D");
  t->pushback("E");
  t->pushback("F");
  t->pushback("G");
  CHECK(t->getDebugString()=="D-->C-->B-->A-->E-->F-->G-->null");

  CHECK((*t)[0] == "D");
  CHECK(t->length() == 7);

  t->remove(0);
  CHECK(t->getDebugString()=="C-->B-->A-->E-->F-->G-->null");
  CHECK(t->length() == 6);
  t->remove(2);
  CHECK(t->getDebugString()=="C-->B-->E-->F-->G-->null");
  CHECK(t->length() == 5);
  t->remove(3);
  CHECK(t->getDebugString()=="C-->B-->E-->G-->null");
  CHECK(t->length() == 4);
  t->remove(3);
  CHECK(t->getDebugString()=="C-->B-->E-->null");
  CHECK(t->length() == 3);
  t->remove(-1);
  CHECK(t->getDebugString()=="C-->B-->E-->null");
  CHECK(t->length() == 3);
  t->remove(10);
  CHECK(t->getDebugString()=="C-->B-->E-->null");
  CHECK(t->length() == 3);
}

TEST_CASE("operator[]"){
  List *t = new List();
  t->pushback("E");
  t->pushback("F");
  t->pushback("G");
  t->insert("A");
  t->insert("B");
  t->insert("C");
  t->insert("D");
  CHECK(t->getDebugString()=="D-->C-->B-->A-->E-->F-->G-->null");

  CHECK((*t)[0] == "D");
  CHECK((*t)[1] == "C");
  CHECK((*t)[2] == "B");
  CHECK((*t)[3] == "A");
  CHECK((*t)[4] == "E");
  CHECK((*t)[5] == "F");
  CHECK((*t)[6] == "G");
  CHECK((*t)[10] == "");
  CHECK((*t)[-5] == "");
}

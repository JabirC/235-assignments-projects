#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "myVector.h"


TEST_CASE("Constructor: myVector()"){
  myVector<int> vec;
  CHECK(vec.get_size() == 0);

  myVector<char> vec1;
  CHECK(vec1.get_size() == 0);

}

TEST_CASE("get_size"){
  myVector<int> vec;
  CHECK(vec.get_size() == 0);
  for(int i = 1; i < 11; i++){
    vec.add_back(i);
    CHECK(vec.get_size() == i);
  }

  myVector<char> vec1;
  CHECK(vec1.get_size() == 0);
  for(char i = 1; i < 11; i++){
    vec1.add_back(i);
    CHECK(vec1.get_size() == i);
  }
}

TEST_CASE("add_back(T elem)"){
  myVector<int> vec;
  vec.add_back(19);
  CHECK(vec[0] == 19);
  vec.add_back(23);
  CHECK(vec[1] == 23);
  vec.add_back(92);
  CHECK(vec[2] == 92);
  vec.add_back(12);
  CHECK(vec[3] == 12);

  myVector<char> vec1;
  vec1.add_back(98);
  CHECK(vec1[0] == 'b');
  vec1.add_back(100);
  CHECK(vec1[1] == 'd');
  vec1.add_back(102);
  CHECK(vec1[2] == 'f');
  vec1.add_back(104);
  CHECK(vec1[3] == 'h');
}

TEST_CASE("operator []"){
  myVector<int> vec;
  for(int i = 1; i < 11; i++){
    vec.add_back(i);
    CHECK(vec[i-1] == i);
  }

  vec[5] = vec[1] + vec[2];
  CHECK(vec[5] == 5);

  int num = vec[7] + vec[1];
  CHECK(num == 10);

  vec[0] = 1000;
  CHECK(vec[0] == 1000);

  myVector<char> vec1;
  vec1.add_back('a');
  CHECK(vec1[0] == 97);
  vec1[0] = vec1[0] + 1;
  CHECK(vec1[0] == 'b');
}

TEST_CASE("expand()"){
  myVector<int> vec;
  CHECK(vec.get_size() == 0);
  for(int i = 1; i < 15; i++){
    vec.add_back(i);
  }
  CHECK(vec[10] == 11);
  CHECK(vec[11] == 12);
  CHECK(vec[12] == 13);
  CHECK(vec[13] == 14);
}

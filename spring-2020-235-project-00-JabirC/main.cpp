#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "myVector.h"
#include <iostream>

int main(int argc, char *argv[])
{
  myVector<int> vec;
  std::cout << vec.get_size() << std::endl; //0
  std::cout << "Should be 0" << std::endl << std::endl;

  vec.add_back(9);
  std::cout << vec[0] << std::endl; //9
  std::cout << "Should be 9" << std::endl << std::endl;

  std::cout << vec.get_size() << std::endl; //1
  std::cout << "Should be 1" << std::endl << std::endl;

  vec.add_back(2);
  vec.add_back(3);

  std::cout << vec.get_size() << std::endl; //3
  std::cout << "Should be 3" << std::endl << std::endl;

  int sum = vec[0] + vec[1];
  std::cout << sum << std::endl; // 11
  std::cout << "Should be 11" << std::endl << std::endl;

  vec[2] = vec[0] + vec[1];
  std::cout << vec[2] << std::endl; // should be 11
  std::cout << "Should be 11" << std::endl << std::endl;
  return 0;
}

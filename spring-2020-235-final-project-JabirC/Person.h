#pragma once
#include <string>


class person{
public:
  std::string last; // last name
  std::string first; // first name
  std::string title; // job title
  double salary;   // job Salary
  person(); // default constructor
  person(std::string l, std::string f); // constructor given first and last name
  person(std::string l, std::string f, std::string t, double s); // constructor given all the info

};

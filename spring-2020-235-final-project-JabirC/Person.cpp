#include <iostream>
#include <string>
#include "Person.h"

// Default constructor, set everything to default value
person::person(){
  last = "";
  first = "";
  title = "";
  salary = -1.0;
}

// Set the fist and last name from the given, set title and salary to default
person::person(std::string l, std::string f){
  last = l;
  first = f;
  title = "";
  salary = -1.0;
}

// Set the fist and last name and title and salary from given
person::person(std::string l, std::string f, std::string t, double s){
  last = l;
  first = f;
  title = t;
  salary = s;
}

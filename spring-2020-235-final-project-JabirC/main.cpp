#include <iostream>
#include "HashTable.h"

int main()
{
  hash_table *t = new hash_table();

  person *p1 = new person("Smith", "Adam", "CEO" , 2000.50);
  person *p2 = new person("cmith", "Bdam", "CEO" , 9000.50);
  person *p3 = new person("Cleo", "Tom", "Secretary" , 95000.50);

  t->insert(*p1);
  t->insert(*p2);
  t->insert(*p3);

  int ind = t->hash(*p1);
  std::cout << ind<< std::endl;
  std::cout << t->debug_string(9) << std::endl;
  std::cout << t->debug_string(7) << std::endl;

  t->deleter(*p1);
  std::cout << t->debug_string(9) << std::endl;

  person *temp = new person("Cleo", "Tom");

  person p4 = t->retrieve(*temp);
  std::cout << p4.title << ", " << p4.salary << std::endl;

  return 0;

}

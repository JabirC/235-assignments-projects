#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "HashTable.h"


TEST_CASE("Testing Person Class"){
  person * p1 = new person(); //default constructor
  CHECK(p1->last == "");
  CHECK(p1->first == "");
  CHECK(p1->title == "");
  CHECK(p1->salary == -1.0);
  delete p1;

  person * p2 = new person("Smith" , "Adam");
  CHECK(p2->last == "Smith");
  CHECK(p2->first == "Adam");
  CHECK(p2->title == "");
  CHECK(p2->salary == -1.0);
  delete p2;

  person * p3 = new person("Jacobs" , "Mark", "Secretary" , 95454.50);
  CHECK(p3->last == "Jacobs");
  CHECK(p3->first == "Mark");
  CHECK(p3->title == "Secretary");
  CHECK(p3->salary == 95454.50);
  delete p3;
}


TEST_CASE("Testing Node Class"){
  person * p1 = new person("Smith" , "Adam" , "CEO" , 200000.50);
  Node * n1 = new Node(*p1);
  CHECK((n1->getData()).first == "Adam");
  CHECK((n1->getData()).last == "Smith");
  CHECK((n1->getData()).title == "CEO");
  CHECK((n1->getData()).salary == 200000.50);

  person * p2 = new person("Jacobs" , "Mark", "Chef" , 95454.50);
  Node * n2 = new Node(*p2);

  n1->setNext(n2);

  CHECK(((n1->getNext())->getData()).first == "Mark");
  CHECK(((n1->getNext())->getData()).last == "Jacobs");
  CHECK(((n1->getNext())->getData()).title == "Chef");
  CHECK(((n1->getNext())->getData()).salary == 95454.50);

  delete p1,p2;
  delete n1,n2;
}



TEST_CASE("Hash function"){
  hash_table * table = new hash_table();


  person *p1 = new person("Smith", "Adam", "CEO" , 2000.50);
  person *p2 = new person("Madison", "James", "President" , 9000.50);
  person *p3 = new person("Cleo", "Tom", "Secretary" , 95000.50);
  person *p4 = new person("Georgeorea", "Washingtonian", "General" , 300.0);


  CHECK(table->hash(*p1) == 9);
  CHECK(table->hash(*p2) == 2);
  CHECK(table->hash(*p3) == 7);
  CHECK(table->hash(*p4) == 3);

  delete p1,p2,p3,p4;
  delete table;
}


TEST_CASE("insert"){
  hash_table * table = new hash_table();


  person *p1 = new person("Smith", "Adam", "CEO" , 2000.50);
  person *p2 = new person("Madison", "James", "President" , 9000.50);
  person *p3 = new person("Cleo", "Tom", "Secretary" , 95000.50);

  table->insert(*p1);// index 9
  table->insert(*p2);// index 2
  table->insert(*p3);// index 7

  CHECK(table->debug_string(table->hash(*p1)) == "|Smith, Adam, CEO, 2000.500000|-->NULL" );
  CHECK(table->debug_string(table->hash(*p2)) == "|Madison, James, President, 9000.500000|-->NULL" );
  CHECK(table->debug_string(table->hash(*p3)) == "|Cleo, Tom, Secretary, 95000.500000|-->NULL" );

  person *p4= new person("Scott", "Rick", "Janitor" , 1400.50);

  table->insert(*p4);// index 9

  CHECK(table->debug_string(table->hash(*p1)) == "|Scott, Rick, Janitor, 1400.500000|-->|Smith, Adam, CEO, 2000.500000|-->NULL" );

  person *p5= new person("duncan", "Tim", "Janitor" , 32000.40);

  table->insert(*p5);// index 9

  CHECK(table->debug_string(table->hash(*p1)) == "|duncan, Tim, Janitor, 32000.400000|-->|Scott, Rick, Janitor, 1400.500000|-->|Smith, Adam, CEO, 2000.500000|-->NULL" );

  CHECK(table->debug_string(table->hash(*p2)) == "|Madison, James, President, 9000.500000|-->NULL" );
  CHECK(table->debug_string(table->hash(*p3)) == "|Cleo, Tom, Secretary, 95000.500000|-->NULL" );
  CHECK(table->debug_string(table->hash(*p2)) == "|Madison, James, President, 9000.500000|-->NULL" );

  //Checking if remaining linked lists are empty
  CHECK(table->debug_string(0) == "NULL" );
  CHECK(table->debug_string(1) == "NULL" );
  CHECK(table->debug_string(3) == "NULL" );
  CHECK(table->debug_string(4) == "NULL" );
  CHECK(table->debug_string(5) == "NULL" );
  CHECK(table->debug_string(6) == "NULL" );
  CHECK(table->debug_string(8) == "NULL" );


  delete p1,p2,p3,p4,p5;
  delete table;
}


TEST_CASE("deleter"){
  hash_table * table = new hash_table();


  person *p1 = new person("Smith", "Adam", "CEO" , 2000.50);
  person *p2 = new person("Madison", "James", "President" , 9000.50);
  person *p3 = new person("Cleo", "Tom", "Secretary" , 95000.50);
  person *p4 = new person("Georgeorea", "Washingtonian", "General" , 300.0);
  person *p5= new person("duncan", "Tim", "Janitor" , 32000.40);


  table->insert(*p1); // index 9
  table->insert(*p2); // index 2
  table->insert(*p3); // index 7
  table->insert(*p4); // index 3
  table->insert(*p5); // index 9


  CHECK(table->debug_string(9) == "|duncan, Tim, Janitor, 32000.400000|-->|Smith, Adam, CEO, 2000.500000|-->NULL" );
  table->deleter(*p1);
  CHECK(table->debug_string(9) == "|duncan, Tim, Janitor, 32000.400000|-->NULL" );
  table->deleter(*p5);
  CHECK(table->debug_string(9) == "NULL" );
  table->deleter(*p5); // trying to delete an already deleted person
  CHECK(table->debug_string(9) == "NULL" );

  CHECK(table->debug_string(2) == "|Madison, James, President, 9000.500000|-->NULL" );
  table->deleter(*p2);
  CHECK(table->debug_string(2) == "NULL" );

  CHECK(table->debug_string(7) == "|Cleo, Tom, Secretary, 95000.500000|-->NULL" );
  table->deleter(*p3);
  CHECK(table->debug_string(7) == "NULL" );

  CHECK(table->debug_string(3) == "|Georgeorea, Washingtonian, General, 300.000000|-->NULL" );
  table->deleter(*p4);
  CHECK(table->debug_string(3) == "NULL" );

  //deleting already deleted person
  table->deleter(*p4);
  CHECK(table->debug_string(3) == "NULL" );

  //All persons deleted
  //Checking to see that the table is empty

  CHECK(table->debug_string(0) == "NULL" );
  CHECK(table->debug_string(1) == "NULL" );
  CHECK(table->debug_string(2) == "NULL" );
  CHECK(table->debug_string(3) == "NULL" );
  CHECK(table->debug_string(4) == "NULL" );
  CHECK(table->debug_string(5) == "NULL" );
  CHECK(table->debug_string(6) == "NULL" );
  CHECK(table->debug_string(7) == "NULL" );
  CHECK(table->debug_string(8) == "NULL" );
  CHECK(table->debug_string(9) == "NULL" );

  delete p1,p2,p3,p4,p5;
  delete table;
}


TEST_CASE("retrieve"){
  hash_table * table = new hash_table();


  person *p1 = new person("Smith", "Adam", "CEO" , 2000.50);
  person *p2 = new person("Madison", "James", "President" , 9000.50);
  person *p3 = new person("Cleo", "Tom", "Secretary" , 95000.50);
  person *p4 = new person("Duncan", "Tim", "Janitor" , 32000.40);

  table->insert(*p1); // index 9
  table->insert(*p2); // index 2
  table->insert(*p3); // index 7
  table->insert(*p4); // index 9

  person *p5 = new person("Smith", "Adam");
  person p5r = table->retrieve(*p5);
  CHECK(p5r.last == "Smith");
  CHECK(p5r.first == "Adam");
  CHECK(p5r.title == "CEO");
  CHECK(p5r.salary == 2000.50);

  person *p6 = new person("Madison", "James");
  person p6r = table->retrieve(*p6);
  CHECK(p6r.last == "Madison");
  CHECK(p6r.first == "James");
  CHECK(p6r.title == "President");
  CHECK(p6r.salary == 9000.50);

  person *p7 = new person("Cleo", "Tom");
  person p7r = table->retrieve(*p7);
  CHECK(p7r.last == "Cleo");
  CHECK(p7r.first == "Tom");
  CHECK(p7r.title == "Secretary");
  CHECK(p7r.salary == 95000.50);

  person *p8 = new person("Duncan", "Tim");
  person p8r = table->retrieve(*p8);
  CHECK(p8r.last == "Duncan");
  CHECK(p8r.first == "Tim");
  CHECK(p8r.title == "Janitor");
  CHECK(p8r.salary == 32000.40);

  //retrieving for person not in table
  person *p9 = new person("Stewart", "Bob");
  person p9r = table->retrieve(*p9);
  CHECK(p9r.last == "Stewart");
  CHECK(p9r.first == "Bob");
  CHECK(p9r.title == "");
  CHECK(p9r.salary == -1.0);



  delete p1,p2,p3,p4,p5,p6,p7,p8,p9;
  delete table;
}

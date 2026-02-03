main: main.o	Person.o Node.o HashTable.o
	g++ -o main main.o Person.o Node.o HashTable.o

tests: tests.o Person.o Node.o HashTable.o
	g++ -o tests tests.o Person.o Node.o HashTable.o

main.o: main.cpp Person.o Node.o HashTable.o

tests.o: tests.cpp Person.o Node.o HashTable.o

Person.o:	Person.cpp Person.h

Node.o:	Node.cpp Node.h Person.h

HashTable.o: HashTable.cpp HashTable.h Node.h Person.h

clean:
	rm -f main.o tests.o Person.o Node.o HashTable.o

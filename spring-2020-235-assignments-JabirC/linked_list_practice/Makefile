main: main.o practice.o Node.o
	g++ -o main main.o practice.o Node.o

tests: tests.o practice.o Node.o
	g++ -o tests tests.o practice.o Node.o

main.o: main.cpp practice.h Node.h
	g++ -c main.cpp

tests.o: tests.cpp practice.h Node.h
	g++ -c tests.cpp

practice.o: practice.cpp practice.h Node.h
	g++ -c practice.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

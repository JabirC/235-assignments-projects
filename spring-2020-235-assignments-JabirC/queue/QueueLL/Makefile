
main: main.o Queue.o Node.o
	g++ -o main main.o Queue.o Node.o

tests: tests.o Queue.o Node.o
	g++ -o tests tests.o Queue.o Node.o

main.o: main.cpp Queue.h Node.h
	g++ -c main.cpp

tests.o: tests.cpp Queue.h Node.h
	g++ -c tests.cpp

Queue.o: Queue.cpp Queue.h Node.h
	g++ -c Queue.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

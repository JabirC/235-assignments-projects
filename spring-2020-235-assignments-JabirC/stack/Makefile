main: main.o List.o Node.o Stack.o
	g++ -o main main.o List.o Node.o Stack.o

tests: tests.o List.o Node.o Stack.o
	g++ -o tests tests.o List.o Node.o Stack.o

Stack.o: Stack.cpp Stack.h List.h Node.h

main.o: main.cpp Node.h List.h Stack.h
	g++ -c main.cpp

List.o: List.cpp List.h Node.h
	g++ -c List.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

tests.o: tests.cpp List.h Node.h Stack.h
	g++ -c tests.cpp

clean:
	rm *.o

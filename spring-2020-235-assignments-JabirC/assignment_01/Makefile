main: main.o List.o Node.o
	g++ -o main main.o List.o Node.o

tests: tests.o List.o Node.o
	g++ -o tests tests.o List.o Node.o

main.o: main.cpp Node.cpp Node.h
	g++ -c main.cpp

List.o: List.cpp List.h Node.cpp Node.h
	g++ -c List.cpp

tests.o: tests.cpp List.h Node.h
	g++ -c tests.cpp

clean:
	rm List.o main.o tests.o Node.o

main: main.o Queue.o
	g++ -o main main.o Queue.o

tests: tests.o Queue.o
	g++ -o tests tests.o Queue.o

main.o: main.cpp Queue.h
	g++ -c main.cpp

Queue.o: Queue.cpp Queue.h
	g++ -c Queue.cpp

tests.o: tests.cpp Queue.h
	g++ -c tests.cpp

clean:
	rm *.o main

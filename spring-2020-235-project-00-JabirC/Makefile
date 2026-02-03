main: main.o
	g++ -o main main.o

test: test.o
	g++ -o test test.o


main.o: main.cpp myVector.h
	g++ -c main.cpp


test.o: test.cpp myVector.h
	g++ -c test.cpp

clean:
	rm  main.o test.o

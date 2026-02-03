OBJECTS = Heap.o
FLAGS = -std=c++14

main: main.o $(OBJECTS)
	g++ $(FLAGS) -o main main.o $(OBJECTS)

tests: tests.o $(OBJECTS)
	g++ $(FLAGS) -o tests tests.o $(OBJECTS)

main.o: main.cpp Heap.h
	g++ $(FLAGS) -c main.cpp

tests.o: tests.cpp Heap.h
	g++ $(FLAGS) -c tests.cpp

Heap.o: Heap.cpp Heap.h
	g++ $(FLAGS) -c Heap.cpp

clean:
	rm main tests main.o tests.o $(OBJECTS)

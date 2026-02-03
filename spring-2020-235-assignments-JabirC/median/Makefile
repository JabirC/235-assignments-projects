main: main.o MinHeap.o MaxHeap.o
	g++ -g -o main main.o MinHeap.o MaxHeap.o

main.o: main.cpp MinHeap.h MaxHeap.h

MinHeap.o: MinHeap.cpp MinHeap.h

MaxHeap.o: MaxHeap.cpp MaxHeap.h

clean:
	rm tests.o main.o

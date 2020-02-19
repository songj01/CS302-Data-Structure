
CXXFLAGS = -g -std=c++11

all: P11 p12

P11: PA03.o FlightMap1.o LinkedStack.o
	g++ $(CXXFLAGS) -o P11 PA03.o FlightMap1.o LinkedStack.o 

p12: PA03.o FlightMap2.o LinkedQueue.o
	g++ $(CXXFLAGS) PA03.o FlightMap2.o LinkedQueue.o -o P12

PA03.o: PA03.cpp MapCreate.h LinkedStack.h
	g++ $(CXXFLAGS) -c PA03.cpp -o PA03.o

FlightMap1.o:  FlightMap.v1.cpp MapCreate.h LinkedStack.h 
	g++ $(CXXFLAGS) -c FlightMap.v1.cpp -o FlightMap1.o

FlightMap2.o:  FlightMap.v2.cpp MapCreate.h LinkedQueue.h LinkedStack.h
	g++  $(CXXFLAGS) -c FlightMap.v2.cpp    -o FlightMap2.o

LinkedStack.o:   LinkedStack.cpp LinkedStack.h LinkedStackInterface.h
	g++ $(CXXFLAGS) -c  LinkedStack.cpp    -o LinkedStack.o

LinkedQueue.o:   LinkedQueue.h LinkedQueue.cpp LinkedStack.h LinkedQueueInterface.h
	g++ $(CXXFLAGS) -c  LinkedQueue.cpp      -o LinkedQueue.o

clean:
	rm *.o P11 P12


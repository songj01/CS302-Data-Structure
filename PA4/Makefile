
CXXFLAGS = -g -std=c++11


PA04: main.o Radix.o Merge.o Bubble.o 
	g++ $(CXXFLAGS) main.o Radix.o Merge.o Bubble.o -o PA04
main.o: main.cpp Radix.h Merge.h Bubble.h
	g++ $(CXXFLAGS) -c main.cpp  -o main.o
Radix.o: Radix.cpp Radix.h
	g++ $(CXXFLAGS) -c Radix.cpp  -o Radix.o
Merge.o: Merge.cpp Merge.h
	g++ $(CXXFLAGS) -c Merge.cpp  -o Merge.o
Bubble.o: Bubble.cpp Bubble.h
	g++ $(CXXFLAGS) -c Bubble.cpp  -o Bubble.o
clean:
	rm *.o PA04

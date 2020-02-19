CXXFLAGS = -g -std=c++11


PA07: PA07.o RBT.o RBTNode.o RandomData.o
	g++ $(CXXFLAGS) PA07.o RBT.o RBTNode.o RandomData.o   -o PA07
PA07.o: PA07.cpp RBT.h
	g++ $(CXXFLAGS) -c PA07.cpp -o PA07.o
RBT.o: RBT.cpp RBT.h RBTNode.h RandomData.h
	g++ $(CXXFLAGS) -c RBT.cpp  -o RBT.o
RandomData.o: RandomData.h RandomData.cpp
	g++ $(CXXFLAGS) -c RandomData.cpp  -o RandomData.o

clean:
		rm *.o PA07  *.txt

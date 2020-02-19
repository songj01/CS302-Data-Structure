CXXFLAGS = -g -std=c++11

All: PA06  PA06bonus

PA06bonus: PA06bonus.o BST1.o BST2.o RandomData.o BinaryNode.o
	g++ $(CXXFLAGS) PA06bonus.o BST1.o BST2.o RandomData.o BinaryNode.o  -o PA06bonus
PA06bonus.o: PA06bonus.cpp BST1.h BST2.h BinaryNode.h RandomData.h
	g++ $(CXXFLAGS) -c PA06bonus.cpp -o PA06bonus.o
PA06: PA06.o BST1.o BST2.o RandomData.o BinaryNode.o
	g++ $(CXXFLAGS) PA06.o BST1.o BST2.o RandomData.o BinaryNode.o  -o PA06
PA06.o: PA06.cpp BST1.h BST2.h BinaryNode.h RandomData.h
	g++ $(CXXFLAGS) -c PA06.cpp -o PA06.o
BST1.o: BST1.cpp BST1.h RandomData.h BinaryNode.h BST2.h
	g++ $(CXXFLAGS) -c BST1.cpp -o BST1.o
BST2.o: BST2.cpp BST2.h RandomData.h BinaryNode.h
	g++ $(CXXFLAGS) -c BST2.cpp -o BST2.o
RandomData.o: RandomData.h RandomData.cpp
	g++ $(CXXFLAGS) -c RandomData.cpp -o RandomData.o
BinaryNode.o: BinaryNode.cpp BinaryNode.h
	g++ $(CXXFLAGS) -c BinaryNode.cpp -o BinaryNode.o


clean:
	rm *.o PA06 PA06bonus *.txt

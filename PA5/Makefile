CXXFLAGS = -g -std=c++11

All: PA05 Bonus1  Bonus2


PA05: PA05.o banksimulation3F3.o eventListPQueue.o linkedBankQueue.o  RandomData.o banksimulation1F1.o banksimulation1F3.o
	g++ $(CXXFLAGS) PA05.o banksimulation1F1.o banksimulation1F3.o banksimulation3F3.o eventListPQueue.o linkedBankQueue.o  RandomData.o   -o PA05
PA05.o: PA05.cpp RandomData.h banksimulation3F3.h banksimulation1F1.h  banksimulation1F3.h
	g++ $(CXXFLAGS)  -c PA05.cpp   -o PA05.o
Bonus1: eventListPQueue.o linkedBankQueue.o  RandomData.o Bonus1main.o Bonus1.o
	g++ $(CXXFLAGS) eventListPQueue.o linkedBankQueue.o  RandomData.o Bonus1main.o Bonus1.o  -o Bonus1
Bonus2: eventListPQueue.o linkedBankQueue.o  RandomData.o Bonus2main.o Bonus2.o
	g++ $(CXXFLAGS) eventListPQueue.o linkedBankQueue.o  RandomData.o Bonus2main.o Bonus2.o   -o Bonus2
Bonus1main.o: Bonus1main.cpp RandomData.h Bonus1.h 
	g++ $(CXXFLAGS)  -c Bonus1main.cpp   -o Bonus1main.o
Bonus2main.o: Bonus1main.cpp RandomData.h Bonus2.h 
	g++ $(CXXFLAGS)  -c Bonus2main.cpp   -o Bonus2main.o

Bonus1.o: Bonus1.h Bonus1.cpp linkedBankQueue.h eventListPQueue.h Tellers.h
	g++ $(CXXFLAGS)  -c Bonus1.cpp   -o Bonus1.o
Bonus2.o: Bonus2.h Bonus2.cpp linkedBankQueue.h eventListPQueue.h
	g++ $(CXXFLAGS)  -c Bonus2.cpp   -o Bonus2.o


banksimulation1F1.o: banksimulation1F1.h banksimulation1F1.cpp linkedBankQueue.h eventListPQueue.h 
	g++ $(CXXFLAGS)  -c banksimulation1F1.cpp   -o banksimulation1F1.o
banksimulation1F3.o: banksimulation1F3.h banksimulation1F3.cpp linkedBankQueue.h eventListPQueue.h Tellers.h
	g++ $(CXXFLAGS)  -c banksimulation1F3.cpp   -o banksimulation1F3.o
banksimulation3F3.o: banksimulation3F3.h banksimulation3F3.cpp linkedBankQueue.h eventListPQueue.h 
	g++ $(CXXFLAGS)  -c banksimulation3F3.cpp   -o banksimulation3F3.o
eventListPQueue.o: eventListPQueue.h eventListPQueue.cpp EventListNode.h 
	g++ $(CXXFLAGS)  -c eventListPQueue.cpp   -o eventListPQueue.o
linkedBankQueue.o: linkedBankQueue.h linkedBankQueue.cpp CustomerNode.h  LinkedQueueInterface.h
	g++ $(CXXFLAGS)  -c linkedBankQueue.cpp   -o linkedBankQueue.o
RandomData.o: RandomData.cpp RandomData.h
	g++ $(CXXFLAGS)  -c RandomData.cpp -o RandomData.o


clean:
	rm *.o PA05 *.txt *.cvs Bonus1 Bonus2

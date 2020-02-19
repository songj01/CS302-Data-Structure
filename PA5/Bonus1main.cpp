#include <iostream>
#include "RandomData.h"
#include <fstream>
#include "EventListNode.h"
#include "eventListPQueue.h"


#include <iostream>

#include "Bonus1.h"



int main()
{

RandomData andomData;

andomData.printToFile();

BankSimulationB1 aptB1;

aptB1.simulate();
aptB1.informationPrint();
}

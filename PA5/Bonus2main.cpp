#include <iostream>
#include "RandomData.h"
#include <fstream>
#include "EventListNode.h"
#include "eventListPQueue.h"


#include <iostream>

#include "Bonus2.h"



int main()
{

RandomData andomData;

andomData.printToFile();

BankSimulationB2 aptB2;

aptB2.simulate();
aptB2.informationPrint();
}

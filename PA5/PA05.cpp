#include <iostream>
#include "RandomData.h"
#include <fstream>
#include "EventListNode.h"
#include "eventListPQueue.h"
#include "banksimulation1F1.h"
#include "banksimulation1F3.h"
#include "banksimulation3F3.h"

int main(){

std::ofstream ofile("PA05result.cvs");

const int runtimes =10;

double C1 = 0,C2 = 0,C3 =0;
int P1 =0, P2 = 0, P3 =0;
float AW1 =0, AW2 =0, AW3 =0;
int MW1 =0, MW2 =0, MW3 =0;
float AL1 =0, AL2 =0, AL3=0;
int ML1 =0, ML2 =0, ML3 =0;
int EL1 ; int *EL2 = nullptr, *EL3 =nullptr;

double totalC1 = 0,totalC2 = 0,totalC3 =0;
int totalP1 =0, totalP2 = 0, totalP3 =0;
float totalAW1 =0, totalAW2 =0, totalAW3 =0;
int totalMW1 =0, totalMW2 =0, totalMW3 =0;
float totalAL1 =0, totalAL2 =0, totalAL3=0;
int totalML1 =0, totalML2=0, totalML3 =0;
int totalEL1 =0, totalEL2[3] ={0}, totalEL3[3] ={0};

for(int i = 0 ; i< runtimes; i++){

  RandomData andomData;
  andomData.printToFile();
  BankSimulation1 apt1;
  BankSimulation2 apt2;
  BankSimulation3 apt3;

  apt1.simulate();
  apt2.simulate();
  apt3.simulate();

  C1 = apt1.getSimulationCPUTime();
  P1 = apt1.getTotalProcessingTime();
  AW1= apt1.getAverageWaitTime();
  MW1= apt1.getMaxWaitTime();
  AL1= apt1.getAverageLineLength();
  ML1= apt1.getMaxLineLength();
  EL1= apt1.getIdleTime();

  C2 = apt2.getSimulationCPUTime();
  P2 = apt2.getTotalProcessingTime();
  AW2= apt2.getAverageWaitTime();
  MW2= apt2.getMaxWaitTime();
  AL2= apt2.getAverageLineLength();
  ML2= apt2.getMaxLineLength();
  EL2= apt2.getIdleTime();

  C3 = apt3.getSimulationCPUTime();
  P3 = apt3.getTotalProcessingTime();
  AW3= apt3.getAverageWaitTime();
  MW3= apt3.getMaxWaitTime();
  AL3= apt3.getAverageLineLength();
  ML3= apt3.getMaxLineLength();
  EL3= apt3.getIdleTime();


  totalC1 += C1; totalC2 += C2; totalC3 += C3;
  totalP1 += P1; totalP2 += P2; totalP3 += P3;
  totalAW1 += AW1; totalAW2 += AW2; totalAW3 += AW3;
  totalMW1 += MW1; totalMW2 += MW2; totalMW3 += MW3;
  totalAL1 += AL1; totalAL2 += AL2; totalAL3 += AL3;
  totalML1 += ML1; totalML2 += ML2; totalML3 += ML3;
  totalEL1 += EL1;
  totalEL2[0] += *EL2; totalEL2[1] += *(EL2+1);  totalEL2[2] += *(EL2+2);
  totalEL3[0] += *EL3; totalEL3[1] += *(EL3+1);  totalEL3[2] += *(EL3+2);
}


ofile<<std::endl<<"1 line with 1 teller"<<std::endl<<std::endl;
ofile<< "the total simulation time (in terms of CPU time)"<<"," << totalC1/runtimes<<std::endl;
ofile<<"the total processing time (in terms of virtual time)" <<","<< totalP1/runtimes<<std::endl;
ofile<<"the maximum wait time" <<","<<totalMW1/runtimes<<std::endl;
ofile<<"the average wait time" <<","<<(int)totalAW1/runtimes<<std::endl;
ofile<<"the average length of the line"<<","<<totalAL1/runtimes<<std::endl;
ofile<<"the maximum length of the line"<<","<<totalML1/runtimes<<std::endl;
ofile<<"the total idle time fo each teller"<<","<<totalEL1/runtimes<<std::endl;

ofile<<std::endl<<"1 line with 3 tellers"<<std::endl<<std::endl;
ofile<< "the total simulation time (in terms of CPU time)"<<"," << totalC2/runtimes<<std::endl;
ofile<<"the total processing time (in terms of virtual time)" <<","<< totalP2/runtimes<<std::endl;
ofile<<"the maximum wait time" <<","<<totalMW2/runtimes<<std::endl;
ofile<<"the average wait time" <<","<<totalAW2/runtimes<<std::endl;
ofile<<"the average length of the line"<<","<< totalAL2/runtimes<<std::endl;
ofile<<"the maximum length of the line"<<","<<totalML2/runtimes<<std::endl;
ofile<<"the total idle time fo each teller"<<","<<totalEL2[0]/runtimes<<" / "<<totalEL2[1]/runtimes<<" / "<<totalEL2[2]/runtimes<<std::endl;

ofile<<std::endl<<"3 line3 with 3 tellers"<<std::endl<<std::endl;
ofile<< "the total simulation time (in terms of CPU time)"<<"," << totalC3/runtimes<<std::endl;
ofile<<"the total processing time (in terms of virtual time)" <<","<< totalP3/runtimes<<std::endl;
ofile<<"the maximum wait time" <<","<<totalMW3/runtimes<<std::endl;
ofile<<"the average wait time" <<","<<totalAW3/runtimes<<std::endl;
ofile<<"the average length of the line"<<","<< totalAL3/runtimes<<std::endl;
ofile<<"the maximum length of the line"<<","<<totalML3/runtimes<<std::endl;
ofile<<"the total idle time fo each teller"<<","<<totalEL3[0]/runtimes<<" / "<<totalEL3[1]/runtimes<<" / "<<totalEL3[2]/runtimes<<std::endl;

std::cout<<std::endl<<"1 line with 1 teller"<<std::endl<<std::endl;
std::cout<< "the total simulation time (in terms of CPU time)"<<"," << totalC1/runtimes<<std::endl;
std::cout<<"the total processing time (in terms of virtual time)" <<","<< totalP1/runtimes<<std::endl;
std::cout<<"the maximum wait time" <<","<<totalMW1/runtimes<<std::endl;
std::cout<<"the average wait time" <<","<<totalAW1/runtimes<<std::endl;
std::cout<<"the average length of the line"<<","<<totalAL1/runtimes<<std::endl;
std::cout<<"the maximum length of the line"<<","<<totalML1/runtimes<<std::endl;
std::cout<<"the total idle time fo each teller"<<","<<totalEL1/runtimes<<std::endl;

std::cout<<std::endl<<"1 line with 3 tellers"<<std::endl<<std::endl;
std::cout<< "the total simulation time (in terms of CPU time)"<<"," << totalC2/runtimes<<std::endl;
std::cout<<"the total processing time (in terms of virtual time)" <<","<< totalP2/runtimes<<std::endl;
std::cout<<"the maximum wait time" <<","<<totalMW2/runtimes<<std::endl;
std::cout<<"the average wait time" <<","<<totalAW2/runtimes<<std::endl;
std::cout<<"the average length of the line"<<","<< totalAL2/runtimes<<std::endl;
std::cout<<"the maximum length of the line"<<","<<totalML2/runtimes<<std::endl;
std::cout<<"the total idle time fo each teller"<<","<<totalEL2[0]/runtimes<<" / "<<totalEL2[1]/runtimes<<" / "<<totalEL2[2]/runtimes<<std::endl;

std::cout<<std::endl<<"3 line3 with 3 tellers"<<std::endl<<std::endl;
std::cout<< "the total simulation time (in terms of CPU time)"<<"," << totalC3/runtimes<<std::endl;
std::cout<<"the total processing time (in terms of virtual time)" <<","<< totalP3/runtimes<<std::endl;
std::cout<<"the maximum wait time" <<","<<totalMW3/runtimes<<std::endl;
std::cout<<"the average wait time" <<","<<totalAW3/runtimes<<std::endl;
std::cout<<"the average length of the line"<<","<< totalAL3/runtimes<<std::endl;
std::cout<<"the maximum length of the line"<<","<<totalML3/runtimes<<std::endl;
std::cout<<"the total idle time fo each teller"<<","<<totalEL3[0]/runtimes<<" / "<<totalEL3[1]/runtimes<<" / "<<totalEL3[2]/runtimes<<std::endl;

}

#include "Bonus1.h"
#include "linkedBankQueue.h"
#include "eventListPQueue.h"
#include "Tellers.h"
#include <fstream>
#include <iostream>
#include <sys/time.h>

/// Inilitialize the data.
BankSimulationB1::BankSimulationB1(){
std::cout<<"please enter the number of tellers: ";
std::cin>>tellerNums;

  customerNum = 0;
  currentTime = 0;
  totalProcessingTime =0;

  waitTime = 0;
  MaxWaitTime = 0;
  totalWaitTime = 0;

  lineLength = 0;
  MaxLineLength =0;
  totalLineLength = 0;
  simulationCPUTime = 0;

  tellers = new Tellers[tellerNums];

  idleTime = new int[tellerNums];
  totalIdleTime = new int[tellerNums];
  for(int i =0; i<tellerNums;i++){idleTime[i] =0; totalIdleTime[i]=0;}
}

/// Delete the dynamic array.
BankSimulationB1::~BankSimulationB1(){
  delete[]tellers;
  delete[]idleTime;
  delete[]totalIdleTime;
}



int BankSimulationB1::idleServiceWindow( Tellers windows[], int a){
 for(int  i =0; i < a; i++){
    if(tellers[i].getTellerAvailable() == true){ return i;}
 }
   return -1;
 }


void BankSimulationB1::simulate(){

  struct timeval t1,t2; ///< Declare the time struct.
  gettimeofday(&t1,NULL);///< Get the time at the beginning of simulation.
  EventPQueue anEventPQueue;///< Define the object of EventPQueue.
  BankQueue aBankQueue;///< Define the object of bankQueue.
  std::ifstream infile("eventdata.txt");
  int a ,t;
/// Create and add arrival events to event list
  while (infile >> a >> t){
   std::cout<<customerNum<<"a = "<<a<<"----"<<"t = "<<t<<std::endl;

   Event newArrivalEvent;///< Define the newArrivalEvent.
   newArrivalEvent.setEventTime(a);///<Assign the data to the newArrivalEvent.
   newArrivalEvent.setEventTimeLenth(t);///<Assign the data to the newArrivalEvent.
   newArrivalEvent.setEventType(-1);// ///<Assign the data to the newArrivalEvent(-1 means arrival).
   anEventPQueue.add(newArrivalEvent);///< Add the arrival event into the priority queue.
   customerNum++;///< Statastic the number of customers.
     }
std::cout<<std::endl<<"-------------"<<tellerNums<<" tellers with 1 line Simulation Begins------------"<<std::endl<<std::endl;
   while (!anEventPQueue.isEmpty()){
    Event* newEvent = anEventPQueue.peek();
    currentTime = newEvent->getEventTime();
    if (newEvent->getEventType()==-1)// -1 means arrival
      {processArrival(newEvent, anEventPQueue, aBankQueue);
       //std::cout<<"t = "<< currentTime<<"            EventType ="<<newEvent->getEventType()<<" (Arrival)"<<std::endl;
      }
    else{
      processDeparture(newEvent, anEventPQueue, aBankQueue);
      if(totalProcessingTime < currentTime) {totalProcessingTime = currentTime;}
       //std::cout<<"t = "<< currentTime<<"            EventType = "<<newEvent->getEventType()<<" (Departure from No."<<newEvent->getEventType()+1<<" teller)"<<std::endl;
    }
    }

    gettimeofday(&t2,NULL);///< Get the time at the end of simulation.
    /// Compute the CPU running time by the difference of two different time.
    simulationCPUTime = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)/1000000.0;
}


/// Processes an arrival event.
void BankSimulationB1::processArrival(Event *&arrivalEvent, EventPQueue &anEventPQueue, BankQueue &aBankQueue){

  std::cout<<"processArrival()   is called"<<"  t = "<< currentTime<<"            EventType ="<<arrivalEvent->getEventType()<<" (Arrival)"<<std::endl;
  Customer aCustomer;
  aCustomer.setArrivalTime(arrivalEvent->getEventTime());
  aCustomer.setDurationTime(arrivalEvent->getEventTimeLenth());

  int i = idleServiceWindow(tellers, tellerNums);
  /** When new customer arrives, if the teller is available,
    * then the customer will go to teller diretly,meanwhile, the teller will become unvailable.
    * Generate the departure event, and the departure time of customer leaving is current time plus durationTime,
    * and add this event into the priority queue.*/
  /// i equals -1 means unavailable.
    if (i!= -1){
      tellers[i].setTellerAvailable(false);
      int departureTime  = currentTime + aCustomer.getDurationTime();
      Event  newDepartureEvent;
      newDepartureEvent.setEventType(i);///< assignment
      newDepartureEvent.setEventTime(departureTime);///< assignment
      anEventPQueue.add(newDepartureEvent);///< Add the event into the anEventPQueue.
    }
    else{
    /** When When new customer arrives, if the line is not empty or teller is unavailable,
      * the customer will be in line to wait.*/
      aBankQueue.enqueue(aCustomer);
      lineLength = aBankQueue.getlength();///< Get the length of wait line.
      if(lineLength > MaxLineLength) MaxLineLength = lineLength;///< Get the maximum length of wait line.
      totalLineLength += lineLength; ///< Get the total length of wait line.
  }
  anEventPQueue.remove();///< Remove the current event.
}


/// Processes a departure event .
void BankSimulationB1::processDeparture(Event *&departureEvent, EventPQueue &anEventPQueue, BankQueue &aBankQueue){

std::cout<<"processDeparture() is called"<<"  t = "<< currentTime<<"            EventType = "<<departureEvent->getEventType()<<" (Departure)"<<std::endl;
int inumber = departureEvent->getEventType();
anEventPQueue.remove();///< Remove the current event.
  if (!aBankQueue.isEmpty()){
  Customer* aCustomer;
  aCustomer = aBankQueue.peekFront();///< Get the first customer of line.
  /// The time that this customer will leave is the current time plus duration time.
  int departureTime = currentTime + aCustomer->getDurationTime();
  /// The wait time of customer is difference between current time and arrival time.
  waitTime = currentTime - aCustomer->getArrivalTime();///< Get the wait time.
  if(MaxWaitTime < waitTime) MaxWaitTime = waitTime;///< Get the maximum wait time.
  totalWaitTime += waitTime;///< Get the total wait time.
  aBankQueue.dequeue();///< After the customer goes to the teller, he will be removed from the line.
  /// Record a new departure event and the event time is the time that teh customer leaves.
  Event newDepartureEvent;
  newDepartureEvent.setEventTime(departureTime);///< assignment
  newDepartureEvent.setEventType(inumber);///< assignment
  anEventPQueue.add(newDepartureEvent);///< Add the event into anEventPQueue.

    }
  else
    tellers[inumber].setTellerAvailable(true);
    if(departureEvent->getEventnext() != nullptr&&departureEvent->getEventnext()->getEventType()==-1)
   {
     idleTime[inumber] = departureEvent->getEventnext()->getEventTime() - currentTime;
       totalIdleTime[inumber] += idleTime[inumber];
  }
  }

  /// Get the CPU running time of simulation.
  double BankSimulationB1::getSimulationCPUTime(){
      return simulationCPUTime;
      }
  /// Get the total processing time of event.
  int BankSimulationB1::getTotalProcessingTime(){
      return totalProcessingTime;
      }
  /// Get the average wait time of customer.
  float BankSimulationB1::getAverageWaitTime(){
      return (float)totalWaitTime/customerNum;
      }
  /// Get the maximum wait time of customer.
  int BankSimulationB1::getMaxWaitTime(){
      return MaxWaitTime;
      }
  /// Get the average line length of customer.
  float BankSimulationB1::getAverageLineLength(){
      return (float)totalLineLength/customerNum;
      }
  /// Get the maximum line length of customer.
  int BankSimulationB1::getMaxLineLength(){
      return MaxLineLength;
      }

   int* BankSimulationB1::getIdleTime(){
      return totalIdleTime;
      }


 void BankSimulationB1::informationPrint(){

  std::cout<< "the total simulation time (in terms of CPU time)"<<"," << simulationCPUTime<<std::endl;
  std::cout<<"the total processing time (in terms of virtual time)" <<","<< totalProcessingTime<<std::endl;
  std::cout<<"the maximum wait time" <<","<< MaxWaitTime<<std::endl;
  std::cout<<"the average wait time" <<","<< (float)totalWaitTime/customerNum<<std::endl;
  std::cout<<"the average length of the line"<<","<< (float)totalLineLength/customerNum<<std::endl;
  std::cout<<"the maximum length of the line"<<","<<MaxLineLength<<std::endl;
  std::cout<<"the total idle time fo each teller"<<","<<totalIdleTime[0]<<" / "<<totalIdleTime[1]<<" / "<<totalIdleTime[2]<<std::endl;




 }

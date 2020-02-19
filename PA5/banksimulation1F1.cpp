#include "banksimulation1F1.h"
#include "linkedBankQueue.h"
#include "eventListPQueue.h"
#include <fstream>
#include <iostream>
#include <sys/time.h>

/// Inilitialize the data.
BankSimulation1::BankSimulation1(){
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
  tellerAvailable = true;

  idleTime = 0;
  totalIdleTime = 0;
}


void BankSimulation1::simulate(){
  std::ofstream flog("PA05.log.txt",std::ofstream::out |std::ofstream::app);
  struct timeval t1,t2; ///< Declare the time struct.
  gettimeofday(&t1,NULL);///< Get the time at the beginning of simulation.
  EventPQueue anEventPQueue;///< Define the object of EventPQueue.
  BankQueue aBankQueue;///< Define the object of BankQueue.
  std::ifstream infile("eventdata.txt");///< Define the name of file that will be input.
  int a ,t;
  ///< Define the variables that will get the arrival time and transction time of customer.
  while (infile >> a >> t){
    //std::cout<<customerNum<<"a = "<<a<<"----"<<"t = "<<t<<std::endl;
    Event newArrivalEvent;///< Define the newArrivalEvent.
    newArrivalEvent.setEventTime(a);///<Assign the data to the newArrivalEvent.
    newArrivalEvent.setEventTimeLenth(t);///<Assign the data to the newArrivalEvent.
    newArrivalEvent.setEventType(-1);// ///<Assign the data to the newArrivalEvent(-1 means arrival).
    anEventPQueue.add(newArrivalEvent);///< Add the arrival event into the priority queue.
    customerNum++;///< Statastic the number of customers.
     }
flog<<std::endl<<"-------------1 teller with 1 line Simulation Begins------------"<<std::endl<<std::endl;
/** while the priority queue is not empty, get the element of it.
  * If the eventt type equals -1, that means arrival event so process arrival event;
  * If the eventt type equals others, that means departure event so process departure event.
  */
  while (!anEventPQueue.isEmpty()){
   Event* newEvent = anEventPQueue.peek();
   currentTime = newEvent->getEventTime();
   if (newEvent->getEventType()==-1)// -1 means arrival
     {processArrival(newEvent, anEventPQueue, aBankQueue);
    //std::cout<<"t = "<< currentTime<<"            EventType ="<<newEvent->getEventType()<<" (Arrival)"<<std::endl;
     }
   else{
     processDeparture(newEvent, anEventPQueue, aBankQueue);
     if(totalProcessingTime < currentTime) {totalProcessingTime = currentTime;} ///< Get the total processing time.
    //std::cout<<"t = "<< currentTime<<"            EventType = "<<newEvent->getEventType()<<" (Departure)"<<std::endl;
     }
   }
 gettimeofday(&t2,NULL);///< Get the time at the end of simulation.
 /// Compute the CPU running time by the difference of two different time.
 simulationCPUTime = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)/1000000.0;
}


/// Processes an arrival event.
void BankSimulation1::processArrival(Event *&arrivalEvent, EventPQueue &anEventPQueue, BankQueue &aBankQueue){
  std::ofstream flog("PA05.log.txt",std::ofstream::out |std::ofstream::app);
  flog<<"processArrival()   is called"<<"  t = "<< currentTime<<"            EventType ="<<arrivalEvent->getEventType()<<" (Arrival)"<<std::endl;
/// new customer arries and assign the arrival time and duration time.
  Customer aCustomer;
  aCustomer.setArrivalTime(arrivalEvent->getEventTime());
  aCustomer.setDurationTime(arrivalEvent->getEventTimeLenth());
/** When new customer arrives, if the line is empty and teller is available,
  * then the customer will go to teller diretly,meanwhile, the teller will become unvailable.
  * Generate the departure event, and the departure time of customer leaving is current time plus durationTime,
  * and add this event into the priority queue.*/
  if(aBankQueue.isEmpty()&&tellerAvailable){
    int departureTime  = currentTime + aCustomer.getDurationTime();
    Event  newDepartureEvent;
    newDepartureEvent.setEventType(1);///< assignment
    newDepartureEvent.setEventTime(departureTime);///< assignment
    anEventPQueue.add(newDepartureEvent);///< Add the event into the anEventPQueue.
    tellerAvailable = false;///< assignment
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
void BankSimulation1::processDeparture(Event *&departureEvent, EventPQueue &anEventPQueue, BankQueue &aBankQueue){
  std::ofstream flog("PA05.log.txt",std::ofstream::out |std::ofstream::app);
  flog<<"processDeparture() is called"<<"  t = "<< currentTime<<"            EventType = "<<departureEvent->getEventType()<<" (Departure)"<<std::endl;
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
    newDepartureEvent.setEventType(1);///< assignment
    anEventPQueue.add(newDepartureEvent);///< Add the event into anEventPQueue.
    }
  else
    tellerAvailable = true;///< assignment
     if(departureEvent->getEventnext() != nullptr&&departureEvent->getEventnext()->getEventType()==-1)
    {
      idleTime = departureEvent->getEventnext()->getEventTime() - currentTime;
        totalIdleTime += idleTime;
    }
  }

  /// Get the CPU running time of simulation.
  double BankSimulation1::getSimulationCPUTime()const{
      return simulationCPUTime;
      }
  /// Get the total processing time of event.
  int BankSimulation1::getTotalProcessingTime()const{
      return totalProcessingTime;
      }
  /// Get the average wait time of customer.
  float BankSimulation1::getAverageWaitTime()const{
      return (float)totalWaitTime/customerNum;
      }
  /// Get the maximum wait time of customer.
  int BankSimulation1::getMaxWaitTime()const{
      return MaxWaitTime;
      }
  /// Get the average line length of customer.
  float BankSimulation1::getAverageLineLength()const{
      return (float)totalLineLength/customerNum;
      }
  /// Get the maximum line length of customer.
  int BankSimulation1::getMaxLineLength()const{
      return MaxLineLength;
      }
  /// Get the idle time of teller.
  int BankSimulation1::getIdleTime()const{
      return totalIdleTime;
      }

 void BankSimulation1::informationPrint(){
  std::cout<< "the total simulation time (in terms of CPU time)"<<"," << simulationCPUTime<<std::endl;
  std::cout<<"the total processing time (in terms of virtual time)" <<","<< totalProcessingTime<<std::endl;
  std::cout<<"the maximum wait time" <<","<< MaxWaitTime<<std::endl;
  std::cout<<"the average wait time" <<","<< (float)totalWaitTime/customerNum<<std::endl;
  std::cout<<"the average length of the line"<<","<< (float)totalLineLength/customerNum<<std::endl;
  std::cout<<"the maximum length of the line"<<","<<MaxLineLength<<std::endl;
  std::cout<<"the total idle time fo each teller"<<","<<totalIdleTime<<std::endl;
 }

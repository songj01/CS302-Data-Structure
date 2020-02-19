#include "banksimulation3F3.h"
#include "linkedBankQueue.h"
#include "eventListPQueue.h"
#include <fstream>
#include <iostream>
#include <sys/time.h>

/// Inilitialize the data.
BankSimulation3::BankSimulation3(){
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

  bankLines = new BankQueue[lineNums];
  tellerAvailable = new bool[lineNums];
  for(int i = 0; i<lineNums;i++){tellerAvailable[i] = true;}

  idleTime[lineNums] = {0};
  totalIdleTime[lineNums] = {0};
}

/// Delete the dynamic array.
BankSimulation3::~BankSimulation3(){
  delete[]bankLines;
  delete[]tellerAvailable;
}

/** Get the number of line which is the shortest,
 * and then customer will be in this line when he arrives.*/
int BankSimulation3::getShortestLine(BankQueue aBankQueue[], int lines){
  int shorest, j =0;
  shorest = aBankQueue[0].getlength();
  for(int i =lines-1; i >=0 ; i--){
    if(tellerAvailable[i]){j = i;}
    ///< If the tell is available, the customer will be in that line.
    /// If all of tellers are not available, the customer will be in the shortest line.
    else if(shorest > aBankQueue[i].getlength()){
      shorest = aBankQueue[i].getlength();
      j = i;
    } ///< End else if.
  }///< End for loop.
  return j; ///< Return the number of teller whose line the customer will be in .
}


void BankSimulation3::simulate(){
  std::ofstream flog("PA05.log.txt",std::ofstream::out |std::ofstream::app);
  struct timeval t1,t2; ///< Declare the time struct.
  gettimeofday(&t1,NULL);///< Get the time at the beginning of simulation.
  EventPQueue anEventPQueue;///< Define the object of EventPQueue.
  std::ifstream infile("eventdata.txt");///< Define the name of file that will be input.
  int a ,t;
  ///< Define the variables that will get the arrival time and transction time of customer.
  while (infile >> a >> t){
    Event newArrivalEvent;///< Define the newArrivalEvent.
    newArrivalEvent.setEventTime(a);///<Assign the data to the newArrivalEvent.
    newArrivalEvent.setEventTimeLenth(t);///<Assign the data to the newArrivalEvent.
    newArrivalEvent.setEventType(-1);// ///<Assign the data to the newArrivalEvent(-1 means arrival).
    anEventPQueue.add(newArrivalEvent);///< Add the arrival event into the priority queue.
    customerNum++;///< Statastic the number of customers.
     }

flog<<std::endl<<"-------------3 teller with 3 line Simulation Begins------------"<<std::endl<<std::endl;
   /** while the priority queue is not empty, get the element of it.
     * If the eventt type equals -1, that means arrival event so process arrival event;
     * If the eventt type equals others, that means departure event so process departure event.
     */
   while (!anEventPQueue.isEmpty()){
    Event* newEvent = anEventPQueue.peek();
    currentTime = newEvent->getEventTime();
    if (newEvent->getEventType()==-1)// -1 means arrival
      {processArrival(newEvent, anEventPQueue, bankLines);
       //std::cout<<"t = "<< currentTime<<"            EventType ="<<newEvent->getEventType()<<" (Arrival)"<<std::endl;
      }
    else{
      processDeparture(newEvent, anEventPQueue, bankLines);
      if(totalProcessingTime < currentTime) {totalProcessingTime = currentTime;}
      //std::cout<<"t = "<< currentTime<<"            EventType = "<<newEvent->getEventType()<<" (Departure)"<<std::endl;
      }
    }
  gettimeofday(&t2,NULL);///< Get the time at the end of simulation.
  /// Compute the CPU running time by the difference of two different time.
  simulationCPUTime = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)/1000000.0;
}



/// Processes an arrival event.
void BankSimulation3::processArrival(Event *&arrivalEvent, EventPQueue &anEventPQueue, BankQueue aBankQueue[]){
  std::ofstream flog("PA05.log.txt",std::ofstream::out |std::ofstream::app);
  flog<<"processArrival()   is called"<<"  t = "<< currentTime<<"            EventType ="<<arrivalEvent->getEventType()<<" (Arrival)"<<std::endl;
  /// new customer arries and assign the arrival time and duration time.
  Customer aCustomer;
  aCustomer.setArrivalTime(arrivalEvent->getEventTime());
  aCustomer.setDurationTime(arrivalEvent->getEventTimeLenth());
  int sLineNo = getShortestLine(aBankQueue,lineNums);///< Get the number of shortest line.
  /** When new customer arrives, if the line is empty and teller is available,
    * then the customer will go to teller diretly,meanwhile, the teller will become unvailable.
    * Generate the departure event, and the departure time of customer leaving is current time plus durationTime,
    * and add this event into the priority queue.*/
  if(aBankQueue[sLineNo].isEmpty()&&tellerAvailable[sLineNo]){
    int departureTime  = currentTime + aCustomer.getDurationTime();
    Event  newDepartureEvent;
    newDepartureEvent.setEventType(sLineNo);///< assignment
    newDepartureEvent.setEventTime(departureTime);///< assignment
    anEventPQueue.add(newDepartureEvent);///< Add the event into the anEventPQueue.
    tellerAvailable[sLineNo] = false;///< assignment
  }
else{
  /** When When new customer arrives, if the line is not empty or teller is unavailable,
    * the customer will be in line to wait.*/
    aBankQueue[sLineNo].enqueue(aCustomer);
    lineLength = aBankQueue[sLineNo].getlength();///< Get the length of wait line.
    std::cout<<"line length: "<< lineLength<<std::endl;///< Get the maximum length of wait line.
    if(lineLength > MaxLineLength) MaxLineLength = lineLength;///< Get the total length of wait line.
    totalLineLength += lineLength; ///< Get the total length of wait line.
  }
  anEventPQueue.remove();///< Remove the current event.
}


// Processes a departure event .
void BankSimulation3::processDeparture(Event *&departureEvent, EventPQueue &anEventPQueue, BankQueue aBankQueue[]){
  std::ofstream flog("PA05.log.txt",std::ofstream::out |std::ofstream::app);
  flog<<"processDeparture() is called"<<"  t = "<< currentTime<<"            EventType = "<<departureEvent->getEventType()<<" (Departure)"<<std::endl;
  //idleTime = departureEvent->getEventTime() - currentTime;
  //std::cout<<"idle time:  "<< idleTime<<std::endl;
  int sLineNo = departureEvent ->getEventType();
  anEventPQueue.remove();///< Remove the current event.
  if(!aBankQueue[sLineNo].isEmpty()){
    Customer* aCustomer;
    aCustomer = aBankQueue[sLineNo].peekFront();///< Get the first customer of  No.sLineNo line.
    /// The time that this customer will leave is the current time plus duration time.
    int departureTime = currentTime + aCustomer->getDurationTime();
    waitTime = currentTime - aCustomer->getArrivalTime();///< Get the wait time.
    if(MaxWaitTime < waitTime) MaxWaitTime = waitTime;///< Get the maximum wait time.
    totalWaitTime += waitTime;///< Get the total wait time.
    aBankQueue[sLineNo].dequeue();///< After the customer goes to the teller, he will be removed from the line.
   /// Record a new departure event and the event time is the time that teh customer leaves.
    Event newDepartureEvent;
    newDepartureEvent.setEventTime(departureTime);///< assignment
    newDepartureEvent.setEventType(sLineNo);///< assignment
    anEventPQueue.add(newDepartureEvent);///< Add the event into anEventPQueue.
    }
  else
    tellerAvailable[sLineNo] = true;///< assignment

       if(departureEvent->getEventnext() != nullptr&&departureEvent->getEventnext()->getEventType()==-1)
      {
        idleTime[sLineNo] = departureEvent->getEventnext()->getEventTime() - currentTime;
          totalIdleTime[sLineNo] += idleTime[sLineNo];
     }
}

/// Get the CPU running time of simulation.
double BankSimulation3::getSimulationCPUTime()const{
    return simulationCPUTime;
    }
/// Get the total processing time of event.
int BankSimulation3::getTotalProcessingTime()const{
    return totalProcessingTime;
    }
/// Get the average wait time of customer.
float BankSimulation3::getAverageWaitTime()const{
    return (float)totalWaitTime/customerNum;
    }
/// Get the maximum wait time of customer.
int BankSimulation3::getMaxWaitTime()const{
    return MaxWaitTime;
    }
/// Get the average line length of customer.
float BankSimulation3::getAverageLineLength()const{
    return (float)totalLineLength/customerNum;
    }
/// Get the maximum line length of customer.
int BankSimulation3::getMaxLineLength()const{
    return MaxLineLength;
    }
/// Get the idle time of teller.
int* BankSimulation3::getIdleTime(){
    return totalIdleTime;
    }

void BankSimulation3::informationPrint(){
  std::cout<<"the total simulation time (in terms of CPU time)"<<"," << simulationCPUTime<<std::endl;
  std::cout<<"the total processing time (in terms of virtual time)" <<","<< totalProcessingTime<<std::endl;
  std::cout<<"the maximum wait time" <<","<< MaxWaitTime<<std::endl;
  std::cout<<"the average wait time" <<","<< (float)totalWaitTime/customerNum<<std::endl;
  std::cout<<"the average length of the line"<<","<< (float)totalLineLength/customerNum<<std::endl;
  std::cout<<"the maximum length of the line"<<","<<MaxLineLength<<std::endl;
  std::cout<<"the total idle time fo each teller"<<","<<totalIdleTime[0]<<" , "<<totalIdleTime[1]<<" , "<<totalIdleTime[2]<<std::endl;
 }

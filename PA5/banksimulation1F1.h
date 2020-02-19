#ifndef BANKSIMULATION1F1_H
#define BANKSIMULATION1F1_H

#include "linkedBankQueue.h"
#include "eventListPQueue.h"


class BankSimulation1{
    public:
      /// Constructor.
      BankSimulation1();
      /// Get the arrival events from the file, and add departure event.
      void simulate();
      /** The method is to process arival event. When the customer arrives,
      * if the line is empty, then the customer will go to the teller directly,
      * if the line is not empty, he will be in line to wait.*/
      void processArrival(Event * &arrivalEvent, EventPQueue &aEventPQueue,BankQueue &aBankQueue);
      /** The method is to process departure event. When the customer departs,
      * if the line is not empty, then the first customer in line will go to the teller,
      * if the line is empty, the teller will be idle.*/
      void processDeparture(Event * &departureEvent, EventPQueue &aEventPQueue,BankQueue &aBankQueue);
      void informationPrint();
      /// Get the CPU running time of simulation.
      double getSimulationCPUTime() const;
      /// Get the total processing time of event.
      int getTotalProcessingTime()const;
      /// Get the average wait time of customer.
      float getAverageWaitTime()const;
      /// Get the maximum wait time of customer.
      int getMaxWaitTime()const;
      /// Get the average line length of customer.
      float getAverageLineLength()const;
      /// Get maximum line length of customer.
      int getMaxLineLength()const;
      /// Get idle time of teller.
      int getIdleTime()const;




    private:
      bool tellerAvailable;///< Declare the status of teller.
      int customerNum; ///< Declare the total number of customers.
      /// Declare the total processing time that means the time of the last customer leaving.
      int totalProcessingTime;
      /// Declare the CPU running time that finish the whole simulation.
      double simulationCPUTime;

      int waitTime; ///< Dcalre the waiting time of customer.
      int MaxWaitTime;///< Dcalre the maximum waiting time of customer.
      long totalWaitTime;///< Dcalre the total waiting time of customer.

      int lineLength;///< Dcalre the length of customer line.
      int MaxLineLength;///< Dcalre the maximum length of customer line.
      long totalLineLength;///< Dcalre the total length of customer line.

      int idleTime;///< Dcalre the idle time of teller.
      int totalIdleTime;///< Dcalre the total idle time of teller.

      int  currentTime;///< ///< Dcalre the current time of event.

};


#endif // BANKSIMULATION1F1_H

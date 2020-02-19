/**
@file linkedBankQueue.h
@author Song Jiang
@date April 4,2018
*/



#ifndef LINKEDBANKQUEUE_H
#define LINKEDBANKQUEUE_H

#include "CustomerNode.h"


class BankQueue{

public:
   	BankQueue();///< DEclare Ctor funtion.
   	virtual ~BankQueue();///< Declare Dtor funtion.
   	bool isEmpty() const;///< Declare isEmpty method.
   	bool enqueue(const Customer &aCustomer);///< Declare enqueue method to push element.
  	bool dequeue(); ///< Declare dequeue method to delete element.
   	Customer* peekFront() const;///< Declare peekFront method to get front noda data.
   	int getlength(); ///< Declare getlength method to get the number of elments in the queue.

private:
  	Customer* frontPtr;///< Declare front pointer of queue.
  	Customer* backPtr;///< Declare back pointer of queue.
  	int queueSize;///< Declare size of queue.
};

#endif // LINKEDBANKQUEUE_H

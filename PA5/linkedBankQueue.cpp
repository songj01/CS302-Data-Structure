#include "linkedBankQueue.h"



BankQueue::BankQueue(){
   frontPtr = nullptr;///<Initialize front Pointer
   backPtr= nullptr;///<Initialize back Pointer
   queueSize = 0;///<Initialize the size of queue
}

/// Delete Queue
BankQueue::~BankQueue(){
	while (!isEmpty()){dequeue();}
}

/// Return nullptr if empty.
bool BankQueue::isEmpty() const{
	return  frontPtr==nullptr;
}

/// Add the element into the queue.
bool BankQueue::enqueue(const Customer& aCustomer){
	Customer* newCustomer = new Customer();///<create new queue.
	newCustomer->setArrivalTime(aCustomer.getArrivalTime());///< assigment to arrivalTime
  newCustomer->setDurationTime(aCustomer.getDurationTime());///< assigment to transctionTime
	newCustomer->setNext(nullptr); ///< assigment to Next
  if(isEmpty()){
    frontPtr = newCustomer;
    backPtr = newCustomer;
  }
  else{
    backPtr-> setNext(newCustomer);///<insert new element from tail.
    backPtr = newCustomer;
  }
  queueSize++;
	return true;
}


/// Remove the element from the queue
bool BankQueue::dequeue(){
  bool result = false ;
  if (!isEmpty()){
    Customer* nodeToDeletePtr = frontPtr; ///< Queue is not empty; remove front
    if (frontPtr == backPtr){ /// Special case: one node in queue
      frontPtr = nullptr ;
      backPtr = nullptr ;
    }
    else
      frontPtr = frontPtr-> getNext();
/// Return deleted node to system
  nodeToDeletePtr->setNext(nullptr);
  delete nodeToDeletePtr;
  nodeToDeletePtr = nullptr ;
  }
  queueSize--;
  result = true ;
  return result;
}


/// Get the first element of queue and return it.
Customer* BankQueue::peekFront() const{
    if(!isEmpty())///<Queue is not empty
        return frontPtr;///< return first element.
}


/// Get the size of queue and return it.
int BankQueue::getlength(){
	return queueSize;
}


/**
@file LinkedQueue.h
@author Song Jiang
@date Mar 4,2018
*/



#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H


#include "LinkedStack.h"
#include "LinkedQueueInterface.h"



class LinkedQueue:public LinkedQueueInterface
{

public:
        ///DEclare Ctor funtion.
   	LinkedQueue();
        ///Declare Dtor funtion.
   	virtual ~LinkedQueue();

   	bool isEmpty() const;///< Declare isEmpty method.
   	bool enqueue(const int &pos);///< Declare enqueue method to push element.
  	bool dequeue(); ///< Declare dequeue method to delete element.
   	int peekFront() const;///< Declare peekFront method to gain front noda data.


private:

  	City* frontPtr;///< Declare front pointer of queue.
  	City* backPtr;///< Declare back pointer of queue.



};

#endif // LINKEDQUEUE_H

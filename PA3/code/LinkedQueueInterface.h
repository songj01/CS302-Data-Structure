
/**
@file LinkedQueueInterface.h
@author Song Jiang
@date Mar 4,2018
*/



#ifndef LINKEDQUEUEINTERFACE_H
#define LINKEDQUEUEINTERFACE_H


#include "LinkedStack.h"


/// Create the interface of linkedstack via pure function.
class LinkedQueueInterface
{

public:

   	virtual bool isEmpty() const = 0;///< Declare isEmpty method.
   	virtual bool enqueue(const int &pos) =0; ///< Declare enqueue method to add element.
  	virtual bool dequeue() = 0; ///< Declare dequeue method to delete element.
   	virtual int peekFront() const =0;///< Declare peekFront method to return first element.


};

#endif // LINKEDQUEUEINTERFACE_H

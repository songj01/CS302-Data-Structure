#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include "CustomerNode.h"

class ArrayQueue
{
    public:
      ///Constructor
      ArrayQueue();
    	bool isEmpty() const;///< Declare isEmpty method.
    	bool enqueue(const Customer &aCustomer);///< Declare enqueue method to push element.
    	bool dequeue(); ///< Declare dequeue method to delete element.
    	Customer peekFront() const;///< Declare peekFront method to gain front data.
    	int getlength();///< Declare a method to get the size of array.

    private:
        static const int Capacity = 99999;
        Customer Item[Capacity];///< Define an array.
        int front;///< Index to front of queue.
        int back;///< Index to back of queue.
        int count;///< the number of elements in queue.
};

#endif // ARRAYQUEUE_H

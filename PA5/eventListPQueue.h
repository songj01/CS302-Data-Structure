
/**
@file eventListPQueue.h
@author Song Jiang
@date April 4,2018
*/


#ifndef EVENTLISTPQUEUE_H
#define EVENTLISTPQUEUE_H

#include "EventListNode.h"

class EventPQueue{
  public:
    EventPQueue();
    ~EventPQueue();
    /** This method is check whether the queue is empty,
      * if the queue is empty, it will retrun true, or return false.*/
    bool isEmpty() const ;
    /** This method is add element into the queue,
      * if successful, it will retrun true, or return false.*/
    bool add( const Event& newEvent);
    /** This method is remove element from the queue,
      * if successful, it will retrun true, or return false.*/
    bool remove();
    /// This method is get the first element of the queue.
    Event* peek() const;

  private:
    /// the head pointer of the priority queue.
    Event *headPtr;
};

#endif // EVENTLISTPQUEUE_H

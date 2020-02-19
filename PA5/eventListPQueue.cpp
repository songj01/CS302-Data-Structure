
#include "eventListPQueue.h"
#include "EventListNode.h"


/// Inilitialize the data.
EventPQueue::EventPQueue(){
  headPtr = nullptr;
}

/// The desctructor will remove the element of queue till the queue is empty.
EventPQueue::~EventPQueue(){
  while(!isEmpty())///< While loop will not end untill the queue is empty.
  remove();
}

/// The method will return true if the queue is empty, or return false.
bool EventPQueue::isEmpty() const{
	return  headPtr==nullptr;///< return nullptr if empty.
}

/// Return the first elment of queue.
Event* EventPQueue::peek() const{
  if(!(isEmpty())) ///< Judge the queue whether the queue is empty or not.
  return headPtr;///< Return the first elment the queue is not empty.
} ///< end peek



bool EventPQueue::add( const Event& anEvent){
  Event* newEventPtr = new Event; ///< Create new event.
  newEventPtr->setEventTime(anEvent.getEventTime());///< Assign the data to the new envent.
  newEventPtr->setEventTimeLenth(anEvent.getEventTimeLenth());///< Assign the data to the new envent.
  newEventPtr->setEventType(anEvent.getEventType());///< Assign the data to the new envent.

  Event* curPtr = headPtr; ///<  Assign headPtr(nullptr) to curPtr.
  Event* prevPtr = nullptr; ///< Inilitialize the pointer.
  /// Trverase the queue.
  while((curPtr != nullptr)&&(newEventPtr-> getEventTime() >= curPtr->getEventTime())){
    prevPtr = curPtr;
    curPtr = curPtr->getEventnext();
    }
    /** If the queue is empty or the priority of the element
      * that will be added is behind the current elements,the element will
      * add at the end of the queue.*/
  if(isEmpty()||(prevPtr == nullptr)){
    headPtr = newEventPtr;
    newEventPtr->setEventnext(curPtr);
//newEventPtr->setEventlist(headPtr);
//headPtr = newEventPtr;
     }
  else{
    /// insert the item between the prevPtr and aftPtr.
    Event* aftPtr = prevPtr->getEventnext();
    newEventPtr->setEventnext(aftPtr);
    prevPtr->setEventnext(newEventPtr);
    }
  return true;
} ///< end add


bool EventPQueue::remove()
{
  bool result = false;
  /// The item will be removed is at the beginning of the queue.
  Event* nodeToDeletePtr = new Event;
  nodeToDeletePtr = headPtr;
  headPtr = headPtr->getEventnext();
  /// Return deleted node to system
  delete nodeToDeletePtr;
  /// Assign the nullptr to the romoved pointer.
  nodeToDeletePtr = nullptr ;
  result = true ;
  return result;
} ///< end remove

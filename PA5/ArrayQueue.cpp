#include "ArrayQueue.h"
#include "CustomerNode.h"


///Inilitialize the data.
ArrayQueue::ArrayQueue(){
  front =-1; back=-1; count=0;
}
/// the size of array is 0, so the queue is empty.
bool ArrayQueue::isEmpty() const{
  return count == 0;
}

/** As the size of array is fixed, so we will check whether the array is full
  * before adding new element into teh araay. If the array is not full,we will
  * add new element after the final element.*/
bool ArrayQueue::enqueue(const Customer &aCustomer){
  bool result = false;
  if(count < Capacity){
    back = (back+1)%Capacity;///< the back index will increase by 1.
    Item[back]=aCustomer;
    count++;///< the size of array will increase 1 due to adding new element.
    result = true;
    }
  return result;
}


/// If the queue is not empty,the front index will go next. 
bool ArrayQueue::dequeue(){
  bool result = false;
  if(!isEmpty()){
    front = (front+1)%Capacity;///< the front index will increase by 1.
    count--;///< the size of array will decrease 1 due to adding new element.
    result = true;
    }
  return result;
}


/// Return the first element of array.
Customer ArrayQueue::peekFront() const{
  return Item[front];
}

/// Return the number of elements in araay.
int ArrayQueue::getlength(){
  return count;
}

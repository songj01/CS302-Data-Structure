#include "LinkedQueue.h"



LinkedQueue::LinkedQueue()
{
   frontPtr = nullptr;///<Initialize front Pointer
   backPtr= nullptr;///<Initialize back Pointer
}

/// delete Queue
LinkedQueue::~LinkedQueue()
{
	while (!isEmpty())
	dequeue();
}




bool LinkedQueue::isEmpty() const
{

	return  frontPtr==nullptr;///< return nullptr if empty.

}


bool LinkedQueue::enqueue(const int & mpos)
{

	City* newCity = new City();///<create new queue.
	newCity->pos = mpos;///< assigment to pos
	newCity->subsquent = nullptr; ///< assigment to subsquent

 if(isEmpty())
    frontPtr = newCity;
else
    backPtr-> subsquent= newCity;///<insert new element from tail.
    backPtr = newCity;

	return true;
}



bool LinkedQueue::dequeue()
{

bool result = false ;
if (!isEmpty())
{
/// Queue is not empty; remove front
City* nodeToDeletePtr = frontPtr;
if (frontPtr == backPtr)
{ /// Special case: one node in queue
frontPtr = nullptr ;
backPtr = nullptr ;
}
else
frontPtr = frontPtr-> subsquent;
/// Return deleted node to system
nodeToDeletePtr->subsquent = nullptr ;
delete nodeToDeletePtr;
nodeToDeletePtr = nullptr ;
}
result = true ;
///< end if
return result;

	}



int LinkedQueue::peekFront() const
{

    if(!isEmpty())///<Queue is not empty

        return frontPtr->pos;///< return first element.
}

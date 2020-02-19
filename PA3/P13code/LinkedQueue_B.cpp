#include "LinkedQueue_B.h"



LinkedQueue::LinkedQueue()
{
   frontPtr = nullptr;
   backPtr= nullptr;
}


LinkedQueue::~LinkedQueue()
{
	while (!isEmpty())
	dequeue();
}




bool LinkedQueue::isEmpty() const
{

	return  frontPtr==nullptr;

}



bool LinkedQueue::enqueue(const int & mpos)
{

	City* newCity = new City();
	newCity->pos = mpos;
	newCity->subsquent = nullptr;

 if(isEmpty())
	    frontPtr = newCity;
    backPtr-> subsquent= newCity;
    backPtr = newCity;

	return true;
}



bool LinkedQueue::dequeue()
{

bool result = false ;
if (!isEmpty())
{
// Queue is not empty; remove front
City* nodeToDeletePtr = frontPtr;
if (frontPtr == backPtr)
{ // Special case: one node in queue
frontPtr = nullptr ;
backPtr = nullptr ;
}
else
frontPtr = frontPtr-> subsquent;
// Return deleted node to system
nodeToDeletePtr->subsquent = nullptr ;
delete nodeToDeletePtr;
nodeToDeletePtr = nullptr ;
}
result = true ;
// end if
return result;

	}



int LinkedQueue::peekFront() const
{

    if(!isEmpty())

        return frontPtr->pos;
}

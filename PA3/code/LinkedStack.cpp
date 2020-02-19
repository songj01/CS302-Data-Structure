#include "LinkedStack.h"


///initialize topPtr
LinkedStack::LinkedStack()
{
   topPtr = nullptr;
}

///clear stack
LinkedStack::~LinkedStack()
{
	while (!isEmpty())
	pop();
}



///topPtr is null if stack is empty.
bool LinkedStack::isEmpty() const
{
	return topPtr == nullptr;
}



bool LinkedStack::push(const int & mpos)
{
	City* newCity = new City();///<create new node
	newCity->pos = mpos;///<assignment to pos
	newCity->subsquent = nullptr;///<assignment to subsquent

        ///insert element from head.
	newCity->subsquent = topPtr;
	topPtr = newCity;
	return true;
}



bool LinkedStack::pop()
{
	bool result = false ;
	if (!isEmpty()){
	City* nodeToDeletePtr = topPtr;
	topPtr = topPtr-> subsquent;
	nodeToDeletePtr->subsquent = nullptr;
	delete nodeToDeletePtr;
	nodeToDeletePtr = nullptr;///< assignment nodeToDeletePtr to nullptr.
	}
	result = true;
	return result;
	}



int LinkedStack::peek() const
{

    if(!isEmpty())

        return topPtr->pos; ///< return first element.
}

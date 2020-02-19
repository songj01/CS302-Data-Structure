
/**
@file LinkedStack.h
@author Song Jiang
@date Mar 4,2018
*/



#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "LinkedStackInterface.h"


/// struct of edge cities.
struct City{

	    City* subsquent;
	    int pos;
	    City(){

	    subsquent = nullptr;
	    pos = 0;
	    }

};


class LinkedStack:public LinkedStackInterface

{

public:
         ///Ctor funtion.
   	LinkedStack();
        ///Dtor function.
   	virtual ~LinkedStack(); 

   	bool isEmpty() const;///< Declare isEmpty method.
   	bool push(const int &pos);///< Declare push method.
  	bool pop();///< Declare pop method.
   	int peek() const;///< Declare peek method.


private:

  	City* topPtr; ///< top pointer of stack.



};

#endif // LINKEDSTACK_H

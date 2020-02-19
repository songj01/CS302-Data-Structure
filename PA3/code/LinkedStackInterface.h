
/**
@file LinkedQueueINterface.h
@author Song Jiang
@date Mar 4,2018
*/


#ifndef LINKEDSTACKINTERFACE_H
#define LINKEDSTACKINTERFACE_H

/// Create the interface of linkedstack via pure function.
class LinkedStackInterface
{

public:

   virtual bool isEmpty() const = 0; ///< Declare isEmpty method.
   virtual bool push( const int & pos) = 0;///< Declare push method.
   virtual bool pop() = 0;///< Declare pop method.
   virtual int peek() const = 0;///< Declare peek method.

};


#endif // LINKEDSTACKINTERFACE_H

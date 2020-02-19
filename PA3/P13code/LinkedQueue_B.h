#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H


#include "LinkedQueueInterface_B.h"



struct City{

	    City* subsquent;
	    int pos;
	    int flightNum;
	    int price;
	    City(){

	    subsquent = nullptr;
	    pos = 0;
        flightNum =0;
	    price =0;
	    }

};




class LinkedQueue:public LinkedQueueInterface
{

public:

   	LinkedQueue();

   	virtual ~LinkedQueue();

   	bool isEmpty() const;
   	bool enqueue(const int &pos);
  	bool dequeue();
   	int peekFront() const;


private:

  	City* frontPtr;
  	City* backPtr;



};

#endif // LINKEDQUEUE_H

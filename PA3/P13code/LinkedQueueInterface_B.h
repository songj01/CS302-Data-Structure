#ifndef LINKEDQUEUEINTERFACE_H
#define LINKEDQUEUEINTERFACE_H





class LinkedQueueInterface
{

public:

   	virtual bool isEmpty() const = 0;
   	virtual bool enqueue(const int &pos) =0;
  	virtual bool dequeue() = 0;
   	virtual int peekFront() const =0;


};

#endif // LINKEDQUEUEINTERFACE_H

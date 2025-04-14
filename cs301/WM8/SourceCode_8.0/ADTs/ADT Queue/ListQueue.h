//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** ADT queue: ADT list implementation.
 @file ListQueue.h */

#ifndef _LIST_QUEUE
#define _LIST_QUEUE

#include <memory>
#include "QueueInterface.h"
#include "LinkedList.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class ListQueue : public QueueInterface<ItemType>
{
private:
   std::unique_ptr<LinkedList<ItemType>> listPtr; // Pointer to list of queue items
   
public:
   ListQueue();
   ListQueue(const ListQueue& originalQueue);
   ~ListQueue();
   bool isEmpty() const;
   bool enqueue(const ItemType& someItem);
   bool dequeue();
   
   /** @throw  PrecondViolatedExcep if queue is empty. */
   ItemType peekFront() const throw(PrecondViolatedExcept);
}; // end ListQueue

#include "ListQueue.cpp"
#endif

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** ADT priority queue: ADT sorted list implementation.
 @file SL_PriorityQueue.h */

#ifndef PRIORITY_QUEUE_
#define PRIORITY_QUEUE_

#include <memory>
#include "PriorityQueueInterface.h"
#include "LinkedSortedList.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class SL_PriorityQueue : public PriorityQueueInterface<ItemType>
{
private:
   std::unique_ptr<LinkedSortedList<ItemType>> slistPtr;  // Pointer to sorted list of
                                          // items in the priority queue

public:
   SL_PriorityQueue();
   SL_PriorityQueue(const SL_PriorityQueue& pq);
   ~SL_PriorityQueue();

   bool isEmpty() const;
   bool enqueue(const ItemType& newEntry);
   bool dequeue();

   /** @throw PrecondViolatedExcep if priority queue is empty. */
   ItemType peek() const;
}; // end SL_PriorityQueue

#include "SL_PriorityQueue.cpp"
#endif

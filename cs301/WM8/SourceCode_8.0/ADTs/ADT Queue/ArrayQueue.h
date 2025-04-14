//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** ADT queue: Circular array-based implementation.
 Listing 10-4.
 @file ArrayQueue.h */

/** ADT Queue: Circular array-based implementation.
 @file ArrayQueue.h */
#ifndef ARRAY_QUEUE_
#define ARRAY_QUEUE_
#include "QueueInterface.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class ArrayQueue : public QueueInterface<ItemType>
{
private:
   static const int DEFAULT_CAPACITY = 50;
   ItemType items[DEFAULT_CAPACITY];        // Array of queue items
   int      front;                          // Index to front of queue
   int      back;                           // Index to back of queue
   int      count;                          // Number of items currently in the queue

public:
   ArrayQueue();
      // Copy constructor supplied by compiler; destructor is inherited
   bool isEmpty() const noexcept;
   bool enqueue(const ItemType& someItem) noexcept;
   bool dequeue() noexcept;

   /** @throw  PrecondViolatedExcept if queue is empty. */
   ItemType peekFront() const;
}; // end ArrayQueue
#include "ArrayQueue.cpp"
#endif

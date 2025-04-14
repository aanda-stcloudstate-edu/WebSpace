//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** ADT queue: Link-based implementation.
 @file LinkedQueue.h */
#ifndef LINKED_QUEUE_
#define LINKED_QUEUE_

#include "QueueInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedQueue : public QueueInterface<ItemType>
{
private:
   // The queue is implemented as a chain of linked nodes that has 
   // two external pointers, a head pointer for front of the queue and
   // a tail pointer for the back of the queue.
   std::shared_ptr<Node<ItemType>> backPtr;
   std::shared_ptr<Node<ItemType>> frontPtr;

public:
   LinkedQueue();
   LinkedQueue  (const LinkedQueue& otherQueue);
   ~LinkedQueue();

	bool isEmpty() const noexcept;
	bool enqueue(const ItemType& someItem);
	bool dequeue() noexcept;
   
	ItemType peekFront() const;
}; // end LinkedQueue

#include "LinkedQueue.cpp"
#endif

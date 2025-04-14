//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** ADT Queue: Circular array-based implementation.
 @file ArrayQueue.cpp */
#include "ArrayQueue.h" // Header file

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue(): front(0), back(DEFAULT_CAPACITY − 1), count(0)
{   }  // end default constructor

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const noexcept
{
   return count == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType& someItem) noexcept
{
   bool result = false;
   if (count < DEFAULT_CAPACITY)
   {
         // Queue has room for another item
      back = (back + 1) % DEFAULT_CAPACITY;
      items[back] = someItem;
      count++;
      result = true;
   }  // end if

   return result;
}  // end enqueue

template<class ItemType>
bool ArrayQueue<ItemType>::dequeue() noexcept
{
   bool result = false;
   if (!isEmpty())
   {
      front = (front + 1) % DEFAULT_CAPACITY;
      count– –;
      result = true;
   }  // end if

   return result;
}  // end dequeue

template<class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const
{
      // Enforce precondition
   if (isEmpty())
      throw PrecondViolatedExcept("peekFront() called with empty queue");

      // Queue is not empty; return front
   return items[front];
}  // end peekFront
   // End of implementation file.

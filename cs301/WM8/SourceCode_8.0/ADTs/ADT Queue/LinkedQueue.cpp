//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** @file LinkedQueue.cpp */

#include "LinkedQueue.h"  
#include "PrecondViolatedExcept.h"

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue()
{     }  // end default constructor

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue& originalQueue)
{  // Implementation left as an exercise (Exercise 1).
   auto origChainPtr = originalQueue.frontPtr;  // Points to nodes in original chain
   
   // Using shared pointers initializes frontPtr/backPtr to nullPtr
   if (origChainPtr != nullptr)
   {
      // Copy first node
      frontPtr = std::make_shared<Node<ItemType>>();
      frontPtr->setItem(origChainPtr->getItem());
      
      // Advance original-chain pointer
      origChainPtr = origChainPtr->getNext(); 

      // Copy remaining nodes
      auto endChainPtr = frontPtr;        // Points to first node in new chain
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
         
         // Create a new node containing the next item 
         auto itemNodePtr = std::make_shared<Node<ItemType>>(nextItem);
         
         // Link new node to end of new chain
         endChainPtr->setNext(itemNodePtr);
         
         // Advance pointers       
         endChainPtr = endChainPtr->getNext();
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      endChainPtr->setNext(nullptr);               // Flag end of chain
      backPtr = endChainPtr;
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedQueue<ItemType>::~LinkedQueue()
{
   //smart pointers will clean-up
   backPtr = nullptr;
   frontPtr = nullptr;
}  // end destructor

template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const noexcept
{
   return backPtr == nullptr;
}  // end isEmpty

template<class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& someItem)
{
   auto itemNodePtr = std::make_shared<Node<ItemType>>(someItem);

   // Insert the new node
   if (isEmpty())
      frontPtr = itemNodePtr;        // Insertion into empty queue
   else
      backPtr->setNext(itemNodePtr); // Insertion into nonempty queue
   
   backPtr = itemNodePtr;            // New node is at back
	return true;
}  // end enqueue

template<class ItemType>
bool LinkedQueue<ItemType>::dequeue() noexcept
{
   bool result = false;
   if (!isEmpty())
   {
      // Queue is not empty; delete front
      if (frontPtr == backPtr)
      {  // Special case: one node in queue
         backPtr = nullptr;
         frontPtr = nullptr;
      }
      else
      {
         frontPtr = frontPtr->getNext();
      }
      result = true;
   }  // end if
   
   return result;
}  // end dequeue

template<class ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const throw(PrecondViolatedExcep)
{
   if (isEmpty())
      throw PrecondViolatedExcep("getFront() called with empty queue.");

   // Queue is not empty; return front
   return frontPtr->getItem();
}  // end peekFront
// End of implementation file.

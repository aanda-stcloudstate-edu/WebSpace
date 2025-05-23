//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** @file LinkedStack.cpp */

#include <cassert>        // For assert
#include "LinkedStack.h"  // Stack class specification file

template<class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(nullptr)
{
}  // end default constructor

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack)
{
   // Point to nodes in original chain
   auto origChainPtr = aStack.topPtr;
   
   if (origChainPtr == nullptr)
      topPtr = nullptr;  // Original stack is empty
   else
   {
      // Copy first node
      topPtr = new Node<ItemType>();
      topPtr->setItem(origChainPtr->getItem());
      
      // Point to last node in new chain
       auto newChainPtr = topPtr;
      
      // Advance original-chain pointer
      origChainPtr = origChainPtr->getNext();
      
      // Copy remaining nodes
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
          auto nextItem = origChainPtr->getItem();
         
         // Create a new node containing the next item
          auto newNodePtr = new Node<ItemType>(nextItem);
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);
         
         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();
         
         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
         
      newChainPtr->setNext(nullptr);               // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedStack<ItemType>::~LinkedStack()
{
	// Pop until stack is empty
	while (!isEmpty())
		pop();
}  // end destructor

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const noexcept
{
	return topPtr == nullptr;
}  // end isEmpty

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newEntry) 
{
    auto newNodePtr = new Node<ItemType>(newEntry, topPtr);
   topPtr = newNodePtr;
   newNodePtr = nullptr;
   
	return true;
}  // end push

template<class ItemType>
bool LinkedStack<ItemType>::pop() noexcept
{
	bool result = false;
	if (!isEmpty())
	{
      // Stack is not empty; delete top
        auto nodeToDeletePtr = topPtr;
		topPtr = topPtr->getNext();
		
		// Return deleted node to system
      nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;
      
      result = true;
	}  // end if
   
	return result;	
}  // end pop

template<class ItemType>	
ItemType LinkedStack<ItemType>::peek() const
{
   // Enforce precondition
   if (isEmpty())
      throw(PrecondViolatedExcept("peek() called with empty stack."));
   
	// Stack is not empty; return top
	return topPtr->getItem();
}  // end peek


// End of implementation file.

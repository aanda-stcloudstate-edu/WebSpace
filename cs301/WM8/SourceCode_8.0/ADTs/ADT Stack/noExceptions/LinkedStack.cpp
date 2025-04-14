//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** 
/** @file LinkedStack.cpp */
#include <cassert>             // For assert
#include "LinkedStack.h"       // Header file

template<class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(nullptr)
{   } // end default constructor

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& originalStack)
{
   // Point to nodes in original chain
   auto originalChainPtr = originalStack.topPtr;
   if (originalChainPtr == nullptr)
      topPtr = nullptr;           // Original stack was empty
   else
   {
      // Copy first node
      topPtr = new Node<ItemType>();
      topPtr->setItem(originalChainPtr->getItem());

      // Point to first node in new chain
      auto myChainTailPtr = topPtr;

      // Advance original-chain pointer
      originalChainPtr = originalChainPtr->getNext();

      // Copy remaining nodes
      while (originalChainPtr != nullptr)
      {
         // Get next item from original chain
         auto nextItem = originalChainPtr->getItem();

         // Create a new node containing the next item
         auto itemNodePtr = new Node<ItemType>(nextItem);

         // Link new node to end of new chain
         myChainTailPtr->setNext(itemNodePtr);

         // Advance pointer to new last node
         myChainTailPtr = myChainTailPtr->getNext();

         // Advance original-chain pointer
         originalChainPtr = originalChainPtr->getNext();
      }  // end while
      myChainTailPtr->setNext(nullptr); // Flag end of chain
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
bool LinkedStack<ItemType>::push(const ItemType& someItem)
{
   auto itemNodePtr = new Node<ItemType>(someItem, topPtr);
   topPtr = itemNodePtr;
   itemNodePtr = nullptr;
   return true;
}  // end push

template<class ItemType>
bool LinkedStack<ItemType>::pop()
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
   assert(!isEmpty()); // Enforce precondition during debugging

   // Stack is not empty; return top
   return topPtr->getItem();
}  // end peek
// end of implementation file


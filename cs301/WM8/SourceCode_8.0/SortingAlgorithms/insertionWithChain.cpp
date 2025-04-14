   //  Created by Frank M. Carrano and Timothy M. Henry.
   //  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

//
#include <iostream>
#include "Node.h"

const int MIN_SIZE = 16;

/** Sorts the items in an linked chain into ascending order.
@pre  None. */
template<class ItemType>
auto insertionSort(std::shared_ptr<Node<ItemType>> headPtr)
{
   auto unsortedPtr = headPtr->getNext();
      // separate the two lists
   headPtr->setNext(nullptr);
   
      // loop and perform insertion
   while (unsortedPtr != nullptr)
   {
         // detach first unsorted node
      auto detachedNodePtr = unsortedPtr;
      unsortedPtr = unsortedPtr->getNext();
      detachedNodePtr->setNext(nullptr);
      
         // find insertion location
      auto currentPtr = headPtr;
      std::shared_ptr<Node<ItemType>> previousPtr = nullptr;
      while ((currentPtr != nullptr) && (currentPtr->getItem() < detachedNodePtr->getItem()))
      {
         previousPtr = currentPtr;
         currentPtr = currentPtr->getNext();
      } // end while searching for insert position
      
         // insert detached node
      if (previousPtr != nullptr)
      {
         previousPtr->setNext(detachedNodePtr);
         detachedNodePtr->setNext(currentPtr);
      }
      else
      {  // insert at head of chain
         detachedNodePtr->setNext(headPtr);
         headPtr = detachedNodePtr;
      } // end if to insert
   } // end while processing unsorted chain
} // end insertionSort

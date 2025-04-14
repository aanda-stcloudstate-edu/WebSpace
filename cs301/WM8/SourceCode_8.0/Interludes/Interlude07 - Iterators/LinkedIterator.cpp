//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/**   @file LinkedIterator.cpp */

#include "LinkedIterator.h"

template <class ItemType>
LinkedIterator<ItemType>::
LinkedIterator(std::shared_ptr<Node<ItemType>> nodePtr): currentItemPtr(nodePtr)
{   }  // end constructor


template <class ItemType>
const ItemType LinkedIterator<ItemType>::operator*()
{
   return currentItemPtr->getItem();
}  // end operator*

template <class ItemType>
LinkedIterator<ItemType>& LinkedIterator<ItemType>::operator++()
{
   currentItemPtr = currentItemPtr->getNext();
   return *this;
}  // end prefix operator++

template <class ItemType>
bool LinkedIterator<ItemType>::operator==(const
                                          LinkedIterator<ItemType>& rightHandSide) const
{
   return (currentItemPtr == rightHandSide.currentItemPtr);
//   return ((containerPtr == rightHandSide.containerPtr) &&
//           (currentItemPtr == rightHandSide.currentItemPtr));
}  // end operator==

template <class ItemType>
bool LinkedIterator<ItemType>::operator!=(const
                                          LinkedIterator<ItemType>& rightHandSide) const
{
   return (currentItemPtr != rightHandSide.currentItemPtr);
}  // end operator!=

//template <class ItemType>
//auto LinkedIterator<ItemType>::begin(const LinkedListwIterator<ItemType>& c)
//{}
//
//template <class ItemType>
//auto LinkedIterator<ItemType>::end(const LinkedListwIterator<ItemType>& c)
//{}
//
//template <class ItemType>
//auto LinkedIterator<ItemType>::begin(LinkedListwIterator<ItemType>& c)
//{}
//
//template <class ItemType>
//auto LinkedIterator<ItemType>::end(LinkedListwIterator<ItemType>& c)
//{}

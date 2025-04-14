//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** @file Node.cpp   */
#include "Node.h"

template<class ItemType>
Node<ItemType>::Node()
{ } // end default constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem): item(anItem)
{ } // end constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem,
                     std::shared_ptr<Node<ItemType>> nextNodePtr)
                : item(anItem), next(nextNodePtr)
{ } // end constructor

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem) noexcept
{
   item = anItem;
}  // end setItem

template<class ItemType>
void Node<ItemType>::setNext(std::shared_ptr<Node<ItemType>> nextNodePtr) noexcept
{
   next = nextNodePtr;
}  // end setNext

template<class ItemType>
ItemType Node<ItemType>::getItem() const noexcept
{
   return item;
}  // end getItem

template<class ItemType>
auto Node<ItemType>::getNext() const noexcept
{
   return next;
}  // end getNext

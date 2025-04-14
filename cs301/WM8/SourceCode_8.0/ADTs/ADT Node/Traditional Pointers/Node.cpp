    //  Created by Frank M. Carrano and Timothy M. Henry.
    //  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** @file Node.cpp */
#include "Node.h"

template<class ItemType>
Node<ItemType>::Node() : next(nullptr)
{   }  // end default constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& someItem)
                    : item(someItem), next(nullptr)
{   }  // end constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& someItem, Node<ItemType>* nextNodePtr)
                    : item(someItem), next(nextNodePtr)
{   }  // end constructor

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& someItem)
{
   item = someItem;
}  // end setItem

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
   next = nextNodePtr;
}  // end setNext

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
   return item;
}  // end getItem

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
   return next;
}  // end getNext

    //  Created by Frank M. Carrano and Timothy M. Henry.
    //  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** @file Node.h */
#ifndef NODE_
#define NODE_

template<class ItemType>
class Node
{
private:
   ItemType        item; // A data item
   Node<ItemType>* next; // Pointer to next node
public:
   Node();
   Node(const ItemType& someItem);
   Node(const ItemType& someItem, Node<ItemType>* nextNodePtr);
   void setItem(const ItemType& someItem);
   void setNext(Node<ItemType>* nextNodePtr);
   ItemType getItem() const;
   Node<ItemType>* getNext() const;
}; // end Node

#include "Node.cpp"
#endif

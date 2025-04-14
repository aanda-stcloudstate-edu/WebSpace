//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.


/** @file Node.h */
#ifndef NODE_
#define NODE_
#include <memory>

template<class ItemType>
class Node
{
private:
   ItemType        item; // A data item
   std::shared_ptr<Node<ItemType>> next; // Pointer to next node
   
public:
   Node();
   Node(const ItemType& anItem);
   Node(const ItemType& anItem, std::shared_ptr<Node<ItemType>> nextNodePtr);
   void setItem(const ItemType& anItem) noexcept;
   void setNext(std::shared_ptr<Node<ItemType>> nextNodePtr) noexcept;
   ItemType getItem() const noexcept;
   auto getNext() const noexcept;

}; // end Node

#include "Node.cpp"
#endif

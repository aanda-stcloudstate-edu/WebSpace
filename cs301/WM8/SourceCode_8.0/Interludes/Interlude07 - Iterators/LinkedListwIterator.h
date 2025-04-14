//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** ADT list: Link-based implementation.

 @file LinkedList.h */

#ifndef LINKED_LIST_WITH_ITERATOR_
#define LINKED_LIST_WITH_ITERATOR_

//#include <memory>
#include "LinkedIterator.h"
#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class LinkedListwIterator : public ListInterface<ItemType>
//                             std::enable_shared_from_this<LinkedListwIterator<ItemType>>
{
private:
   std::shared_ptr<Node<ItemType>> headPtr; // Pointer to first node in the chain;
                                            // (contains the first entry in the list)
   std::shared_ptr<Node<ItemType>> tailPtr; // Pointer to last node in the chain;
   int itemCount;           // Current count of list items
   
   // Locates a specified node in this linked list.
   // @pre  position is the number of the desired node;
   //       position >= 1 and position <= itemCount.
   // @post  The node is found and a pointer to it is returned.
   // @param position  The number of the node to locate.
   // @return  A pointer to the node at the given position.
   auto getNodeAt(int position) const;
   
public:
   LinkedListwIterator();
   LinkedListwIterator(const LinkedListwIterator<ItemType>& aList);
   virtual ~LinkedListwIterator();
   
   bool isEmpty() const noexcept;
   int getLength() const noexcept;
   bool insert(int newPosition, const ItemType& newEntry);
   bool remove(int position);
   void clear();
   
   /** @throw PrecondViolatedExcep if position < 1 or
    position > getLength(). */
   ItemType getEntry(int position) const;
   
   /** @throw PrecondViolatedExcep if position < 1 or
    position > getLength(). */
   void replace(int position, const ItemType& newEntry);

//   auto begin(const LinkedListwIterator<ItemType>& c);
//   auto end(const LinkedListwIterator<ItemType>& c);
//   auto begin(LinkedListwIterator<ItemType>& c);
//   auto end(LinkedListwIterator<ItemType>& c);

   auto begin() const;
   auto end() const;
}; // end LinkedList

#include "LinkedListwIterator.cpp"
#endif 

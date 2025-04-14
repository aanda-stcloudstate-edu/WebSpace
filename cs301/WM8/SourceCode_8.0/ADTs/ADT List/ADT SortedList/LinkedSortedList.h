//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** ADT SortedList: Link-based implementation.
 @file LinkedSortedList.h */

#ifndef LINKED_SORTED_LIST_
#define LINKED_SORTED_LIST_
#include <memory>
#include "SortedListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class LinkedSortedList : public SortedListInterface<ItemType>
{
private:
   std::shared_ptr<Node<ItemType>> headPtr; // Pointer to first node in chain
   int itemCount;                           // Current count of list items

      // Locates the node that is before the node that should or does
      // contain the given entry.
      // @param target  The entry to find.
      // @return  Either a pointer to the node before the node that contains
      //  or should contain the given entry, or nullptr if no prior node exists.
   auto getNodeBefore(const ItemType& target) const;

      // Locates the node at a given position within the chain.
   auto getNodeAt(int position) const;

      // Returns a pointer to a copy of the chain to which origChainPtr points.
   auto copyChain(const std::shared_ptr<Node<ItemType>>& origChainPtr);

public:
   LinkedSortedList();
   LinkedSortedList(const LinkedSortedList<ItemType>& aList);
   virtual ~LinkedSortedList();
   bool insertSorted(const ItemType& someItem);
   bool removeSorted(const ItemType& target);
   int getPosition(const ItemType& target) const;

      // The following member functions are the same as given in ListInterface:
   bool isEmpty() const noexcept;
   int getLength() const noexcept;
   bool remove(int position);
   void clear() noexcept final;
   ItemType getEntry(int position) const;
}; // end LinkedSortedList
#include "LinkedSortedList.cpp"
#endif

    //  Created by Frank M. Carrano and Timothy M. Henry.
    //  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** ADT list: Link-based implementation. 
 @file LinkedList.h */

#ifndef LINKED_LIST_
#define LINKED_LIST_

#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
    std::shared_ptr<Node<ItemType>> headPtr; // Pointer to first node in the chain;
                                             // (contains the first entry in the list)
    int itemCount;                           // Current count of list items

    // Locates a specified node in this linked list.
    // @pre  position is the number of the desired node;
    //       position >= 1 and position <= itemCount.
    // @post  The node is found and a pointer to it is returned.
    // @param position  The number of the node to locate.
    // @return  A pointer to the node at the given position.
    auto getNodeAt(int position) const;

public:
    LinkedList();
    LinkedList(const LinkedList<ItemType>& aList);
    virtual ~LinkedList();

    bool isEmpty() const noexcept;
    int getLength() const noexcept;
    bool insert(int newPosition, const ItemType& newEntry);
    bool remove(int position);
    void clear() noexcept final;

    /** @throw PrecondViolatedExcep if position < 1 or position > getLength(). */
    ItemType getEntry(int position) const;

    /** @throw PrecondViolatedExcep if position < 1 or position > getLength(). */
    void replace(int position, const ItemType& newEntry);
}; // end LinkedList

#include "LinkedList.cpp"
#endif

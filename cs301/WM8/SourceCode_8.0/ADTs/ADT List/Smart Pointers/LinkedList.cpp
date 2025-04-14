    //  Created by Frank M. Carrano and Timothy M. Henry.
    //  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** Implementation file for the class LinkedList.
 @file LinkedList.cpp */

#include "LinkedList.h"  // Header file
#include <cassert>

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{   }  // end default constructor

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) : itemCount(aList.itemCount)
{
    auto origChainPtr = aList.headPtr;  // Points to nodes in original chain

    if (origChainPtr == nullptr)
        headPtr.reset();  // Original list is empty
    else
    {
            // Copy first node
        headPtr = std::make_shared<Node<ItemType>>();
        headPtr->setItem(origChainPtr->getItem());

            // Copy remaining nodes
        auto newChainPtr = headPtr;      // Points to last node in new chain
        origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
        while (origChainPtr != nullptr)
        {
                // Get next item from original chain
            ItemType nextItem = origChainPtr->getItem();

                // Create a new node containing the next item
            auto itemNodePtr = std::make_shared<Node<ItemType>>(nextItem);

                // Link new node to end of new chain
            newChainPtr->setNext(itemNodePtr);

                // Advance pointer to new last node
            newChainPtr = newChainPtr->getNext();

                // Advance original-chain pointer
            origChainPtr = origChainPtr->getNext();
        }  // end while

        newChainPtr->setNext(nullptr);              // Flag end of chain
    }  // end if
}  // end copy constructor

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
    clear();
}  // end destructor

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const noexcept
{
    return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const noexcept
{
    return itemCount;
}  // end getLength

template<class ItemType>
bool LinkedList<ItemType>::insert(int position, const ItemType& someItem)
{
   bool ableToInsert = (position >= 1) && (position <= itemCount + 1);
   if (ableToInsert)
   {
         // Create a new node containing the new entry
      auto someNodePtr = std::make_shared<Node<ItemType>>(someItem);

         // Attach new node to chain
      if (position == 1)
      {
            // Insert new node at beginning of chain
         someNodePtr->setNext(headPtr);
         headPtr = someNodePtr;
      }
      else
      {
            // Find node that will be before new node
         auto previousPtr = getNodeAt(position - 1);
         auto currentPtr = previousPtr->getNext();

            // Insert new node after node to which previousPtr points
         someNodePtr->setNext(currentPtr);
         previousPtr->setNext(someNodePtr);
      }  // end if

      itemCount++;  // Increase count of entries
   }  // end if

   return ableToInsert;
}  // end insert


template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
    bool ableToRemove = (position >= 1) && (position <= itemCount);
    if (ableToRemove)
    {
        if (position == 1)
        {
                // Remove the first node in the chain
            headPtr = headPtr->getNext();
        }
        else
        {
                // Find node that is before the one to delete
            auto prevPtr = getNodeAt(position - 1);

                // Point to node to delete
            auto curPtr = prevPtr->getNext();

                // Disconnect indicated node from chain by connecting the
                // prior node with the one after
            prevPtr->setNext(curPtr->getNext());
        }  // end if

        itemCount--;  // Decrease count of entries
    }  // end if

    return ableToRemove;
}  // end remove

template<class ItemType>
void LinkedList<ItemType>::clear() noexcept
{
    headPtr.reset();
        // headPtr = nullptr; // is OK also
    itemCount = 0;
}  // end clear

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const
{
        // Enforce precondition
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet)
    {
        auto nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    }
    else
    {
        auto message = "getEntry() called with an empty list or invalid position.";
        throw(PrecondViolatedExcept(message));
    }  // end if
}  // end getEntry

template<class ItemType>
void LinkedList<ItemType>::replace(int position, const ItemType& someItem)
{
        // Enforce precondition
    bool ableToSet = (position >= 1) && (position <= itemCount);
    if (ableToSet)
    {
        auto itemNodePtr = getNodeAt(position);
        itemNodePtr->setItem(someItem);
    }
    else
    {
            // auto gives const string literal
        auto message = "replace() called with an invalid position.";
        throw(PrecondViolatedExcept(message));
    }  // end if
}  // end replace

template<class ItemType>
auto LinkedList<ItemType>::getNodeAt(int position) const
{
        // Debugging check of precondition
    assert( (position >= 1) && (position <= itemCount) );

        // Count from the beginning of the chain
    auto curPtr = headPtr;
    for (int skip = 1; skip < position; skip++)
        curPtr = curPtr->getNext();

    return curPtr;
}  // end getNodeAt
   //  End of implementation file.

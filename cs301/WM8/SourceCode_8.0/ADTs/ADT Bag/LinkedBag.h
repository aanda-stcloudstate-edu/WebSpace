//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
/** @file LinkedBag.h */
#ifndef LINKED_BAG_
#define LINKED_BAG_

#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
private:
   Node<ItemType>* headPtr; // Pointer to first node
   int itemCount;           // Current count of bag items
   
   // Returns either a pointer to the node containing a given entry
   // or the null pointer if the entry is not in the bag.
   Node<ItemType>* getReferenceTo(const ItemType& target) const;
      // Fills the vector bagContents with the data in the nodes of
      // the linked chain to which currentPtr points.
   void fillVector(std::vector<ItemType>& bagContents, Node<ItemType>* currentPtr) const;

      // Locates a given entry within this bag.
      // Returns either a pointer to the node containing a given entry or
      // the null pointer if the entry is not in the bag.
   Node<ItemType>* getPointerTo(const ItemType& target, Node<ItemType>* currentPtr) const;


public:
   LinkedBag();
   LinkedBag(const LinkedBag<ItemType>& someBag); // Copy constructor
   int getCurrentSize() const;
   bool isEmpty() const;
   bool add(const ItemType& someItem);
   bool remove(const ItemType& someItem);
   void clear()  noexcept final;
   bool contains(const ItemType& target) const;
   int getFrequencyOf(const ItemType& target) const;
   std::vector<ItemType> toVector() const;
   virtual ~LinkedBag();                       // Destructor should be virtual
}; // end LinkedBag

#include "LinkedBag.cpp"
#endif

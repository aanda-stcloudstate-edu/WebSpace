//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** Header file for an array-based implementation of the ADT bag.
 @file ArrayBag.h */

#ifndef ARRAY_BAG_
#define ARRAY_BAG_

#include "BagInterface.h"

template<class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 6; // Small size to test for a full bag
	ItemType items[DEFAULT_CAPACITY];      // Array of bag items
   int itemCount;                         // Current count of bag items
   int maxItems;                          // Max capacity of the bag
   
   // Returns either the index of the element in the array items that
   // contains the given target or -1, if the array does not contain 
   // the target.
//   int getIndexOf(const ItemType& target) const;
   int getIndexOf(const ItemType& target, int searchIndex) const;
   int countFrequency(const ItemType& target, int searchIndex) const;
public:
	ArrayBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& anEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& target) const;
	int getFrequencyOf(const ItemType& target) const;
   std::vector<ItemType> toVector() const;
}; // end ArrayBag

#include "ArrayBag.cpp"
#endif

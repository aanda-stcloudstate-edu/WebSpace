//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.


/** ADT list: Array-based implementation.
 @file ArrayList.h */

#ifndef ARRAY_LIST_
#define ARRAY_LIST_

#include "ListInterface.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class ArrayList : public ListInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 6; // Small capacity to test for a full list
	ItemType items[DEFAULT_CAPACITY + 1];  // Array of list items (not using element [0])
   int itemCount;                         // Current count of list items 
   int maxItems;                          // Maximum capacity of the list
   
public:
   ArrayList();
   ArrayList(int maxItems);
   // Copy constructor and destructor are supplied by compiler

   bool isEmpty() const noexcept;
   int getLength() const noexcept;
   bool insert(int position, const ItemType& someItem);
   bool remove(int position);
   void clear() noexcept;

   /** @throw PrecondViolatedExcep if position < 1 or
                                       position > getLength(). */
   ItemType getEntry(int position) const;

   /** @throw PrecondViolatedExcep if position < 1 or
                                       position > getLength(). */
   void replace(int position, const ItemType& someItem);
}; // end ArrayList

#include "ArrayList.cpp"
#endif 

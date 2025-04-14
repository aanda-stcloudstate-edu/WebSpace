//  Created by Frank M. Carrano and Timothy M. Henry.

/** ADT sorted list using ADT list.
 @file SortedListHasA.h */

/** ADT SortedList using the ADT List.
 @file SortedListHasA.h */
#ifndef SORTED_LIST_HAS_A_
#define SORTED_LIST_HAS_A_

#include "SortedListInterface.h"
#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class SortedListHasA : public SortedListInterface<ItemType>
{
private:
   std::unique_ptr<ListInterface<ItemType>> listPtr;

public:
   SortedListHasA();
   SortedListHasA(const SortedListHasA<ItemType>& sortedList);
   virtual ~SortedListHasA();

   bool insertSorted(const ItemType& someItem);
   bool removeSorted(const ItemType& target);
   int getPosition(const ItemType& target) const;

   // The following member functions have the same specifications
   // as given in ListInterface in Chapter 12:
   bool isEmpty() const noexcept;
   int getLength() const noexcept;
   bool remove(int position);
   void clear() noexcept final;
   ItemType getEntry(int position) const;
}; // end SortedListHasA
#include "SortedListHasA.cpp"
#endif


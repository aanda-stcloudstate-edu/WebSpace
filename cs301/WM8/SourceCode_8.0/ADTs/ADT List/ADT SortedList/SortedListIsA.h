//  Created by Frank M. Carrano and Timothy M. Henry.

/** ADT sorted list using ADT list.

 @file SortedListIsA.h */

/** ADT SortedList using ADT List.
 @file SortedListIsA.h */
#ifndef SORTED_LIST_IS_A_
#define SORTED_LIST_IS_A_

#include "LinkedList.h"
#include "SortedListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class SortedListIsA : public LinkedList<ItemType>
{
public:
   SortedListIsA();
   SortedListIsA(const SortedListIsA<ItemType>& sortedList);
   virtual ~SortedListIsA();

   bool insertSorted(const ItemType& someItem);
   bool removeSorted(const ItemType& target);
   int getPosition(const ItemType& target) const;

      // The inherited member functions remove, clear, getEntry, isEmpty, and
      // getLength have the same specifications as given in ListInterface.

      // The following member functions must be overridden to disable their
      // effect on a SortedList:
   bool insert(int position, const ItemType& someItem) override;
   void replace(int position, const ItemType& target) override;
}; // end SortedListIsA
#include "SortedListIsA.cpp"
#endif


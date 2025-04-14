//  Created by Frank M. Carrano and Timothy M. Henry.

/** ADT sorted list using ADT list.
 @file SortedListAsA.h */

#ifndef _SORTED_LIST_AS_A
#define _SORTED_LIST_AS_A

#include "SortedListInterface.h"
#include "LinkedList.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class SortedListAsA : public SortedListInterface<ItemType>, private LinkedList<ItemType>
{
public:
   SortedListAsA();
   SortedListAsA(const SortedListAsA<ItemType>& sortedList);
   virtual ~SortedListAsA();

   bool insertSorted(const ItemType& someItem) override;
   bool removeSorted(const ItemType& target) override;
   int getPosition(const ItemType& target) const override;
   
   // The following methods are inherited and have the same 
   // specifications as given in ListInterface:
   bool isEmpty() const noexcept override;
   int getLength() const noexcept override;
   bool remove(int position) override;
   void clear() override final;
   ItemType getEntry(int position) const override;
}; // end SortedListAsA

#include "SortedListAsA.cpp"
#endif 



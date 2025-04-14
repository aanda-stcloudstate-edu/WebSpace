//  Created by Frank M. Carrano and Timothy M. Henry.

/** Implementation file for the class SortedListIsA.
 @file SortedListIsA.cpp */

#include "SortedListIsA.h"  // Header file
#include <cassert>
#include <cmath>
 
template<class ItemType>
SortedListIsA<ItemType>::SortedListIsA()
{   }  // end default constructor

template<class ItemType>
SortedListIsA<ItemType>::SortedListIsA(const SortedListIsA<ItemType>& sortedList)
	:LinkedList<ItemType>(sortedList)
{   }  // end copy constructor

template<class ItemType>
SortedListIsA<ItemType>::~SortedListIsA()
{   }  // end destructor

template<class ItemType>
bool SortedListIsA<ItemType>::insertSorted(const ItemType& someItem)
{
   int position = std::abs(getPosition(someItem));
   
   // We need to call the LinkedList version here since the
	// SortedListIsA version does nothing but return false
   // this->insert(newPosition, someItem); // WRONG as it calls the overriding version
   return LinkedList<ItemType>::insert(position, someItem);
}  // end insertSorted

template<class ItemType>
bool SortedListIsA<ItemType>::removeSorted(const ItemType& target)
{
   int position = getPosition(target);
   bool ableToRemove = position > 0;

   if (ableToRemove)
   {
      ableToRemove = LinkedList<ItemType>::remove(position);
   }  // end if

   return ableToRemove;
}  // end removeSorted

template<class ItemType>
int SortedListIsA<ItemType>::getPosition(const ItemType& target) const
{
   int position = 1;
   int length = LinkedList<ItemType>::getLength();
   
   while ( (position <= length) && (target > LinkedList<ItemType>::getEntry(position)) )
   {
      position++;
   }  // end while
   
   if ( (position > length) || (target != LinkedList<ItemType>::getEntry(position)) )
   {
      position = -position;
   }  // end if
   
   return position;
}  // end getPosition

template<class ItemType>
bool SortedListIsA<ItemType>::insert(int newPosition, const ItemType& someItem)
{ 
	return false;
} // end insert

template<class ItemType>
void SortedListIsA<ItemType>::replace(int position, const ItemType& someItem)
{ 
	throw PrecondViolatedExcept("This is an illegal action!"); 
} // end replace

//  End of implementation file.

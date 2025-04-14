//  Created by Frank M. Carrano and Timothy M. Henry.

/** Implementation file for the class SortedListHasA.
 @file SortedListHasA.cpp */

#include "SortedListHasA.h"  // Header file
#include "LinkedList.h"
#include <cassert>
#include <cmath>
  
template<class ItemType>
SortedListHasA<ItemType>::SortedListHasA()
         : listPtr(std::make_unique<LinkedList<ItemType>>())
{  }  // end default constructor

template<class ItemType>
SortedListHasA<ItemType>::SortedListHasA(const SortedListHasA<ItemType>& sortedList)
         : listPtr(std::make_unique<LinkedList<ItemType>>())
{
	//  add items to our list using public methods
	for(int position = 1; position <= sortedList.getLength(); position++)
	{
		listPtr->insert(position, sortedList.getEntry(position));
	}  // end for	
}  // end copy constructor

template<class ItemType>
SortedListHasA<ItemType>::~SortedListHasA()
{
   clear();
}  // end destructor

template<class ItemType>
bool SortedListHasA<ItemType>::insertSorted(const ItemType& someItem)
{
   int insertPosition = std::abs(getPosition(someItem));
   return listPtr->insert(insertPosition, someItem);;
}  // end insertSorted

template<class ItemType>
bool SortedListHasA<ItemType>::removeSorted(const ItemType& target)
{
   bool ableToRemove = false;
   if (!isEmpty())
   {
      int position = getPosition(target);
             
      ableToRemove = position > 0;
      if (ableToRemove)
      {
         ableToRemove = listPtr->remove(position);
      }  // end if
   }  // end if

   return ableToRemove;
}  // end removeSorted

template<class ItemType>
int SortedListHasA<ItemType>::getPosition(const ItemType& target) const
{
   int position = 1;
   int length = listPtr->getLength();
   
   while ( (position <= length) && (target > listPtr->getEntry(position)) )
   {
      position++;
   } // end while
   
   if ( (position > length) || (target != listPtr->getEntry(position)) )
      position = -position;
   
   return position;
}  // end getPosition

//=====================
// List operations:

template<class ItemType>
bool SortedListHasA<ItemType>::remove(int position)
{
   return listPtr->remove(position);
}  // end remove

template<class ItemType>
void SortedListHasA<ItemType>::clear() noexcept
{
   listPtr->clear();
}  // end clear

template<class ItemType>
ItemType SortedListHasA<ItemType>::getEntry(int position) const 
{
   return listPtr->getEntry(position);
}  // end getEntry

template<class ItemType>
bool SortedListHasA<ItemType>::isEmpty() const noexcept
{
   return listPtr->isEmpty();
}  // end isEmpty

template<class ItemType>
int SortedListHasA<ItemType>::getLength() const noexcept
{
   return listPtr->getLength();
}  // end getLength

//  End of implementation file.

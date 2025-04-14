//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** Implementation file for the class ArrayList.
 @file ArrayList.cpp */

#include "ArrayList.h"  // Header file

template<class ItemType>
ArrayList<ItemType>::ArrayList() : itemCount(0), maxItems(DEFAULT_CAPACITY)
{   }  // end default constructor

template<class ItemType>
ArrayList<ItemType>::ArrayList(int maxItems) : itemCount(0), maxItems(maxItems)
{   }  // end constructor

template<class ItemType>
bool ArrayList<ItemType>::isEmpty() const noexcept
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int ArrayList<ItemType>::getLength() const noexcept
{
   return itemCount;
}  // end getLength

template<class ItemType>
bool ArrayList<ItemType>::insert(int position, const ItemType& someItem)
{
   bool ableToInsert = (position >= 1)
                           && (position <= itemCount + 1)
                           && (itemCount < maxItems);
   if (ableToInsert)
   {
      // Make room for new entry by shifting all entries at
      // positions >= newPosition toward the end of the array
      // (no shift if newPosition == itemCount + 1)
      for (int entryPosition = itemCount; entryPosition >= position; entryPosition--)
         items[entryPosition + 1] = items[entryPosition]; // copy the entry right
         
      // Insert new entry
      items[position] = someItem;
      itemCount++;  // Increase count of entries
   }
   else
   {
       auto message = "insert() called with a full list or invalid position.";
       throw(PrecondViolatedExcept(message));
   } // end if
   
   return ableToInsert;
}  // end insert

template<class ItemType>
bool ArrayList<ItemType>::remove(int position)
{
   bool ableToRemove = (position >= 1) && (position <= itemCount);
   if (ableToRemove)
   {
      // Remove entry by shifting all entries after the one at
      // position toward the beginning of the array
      // (no shift if position == itemCount)
      for (int entryPosition = position; entryPosition < itemCount; entryPosition++)
         items[entryPosition] = items[entryPosition + 1]; // copy entry on the right to left
         
      itemCount--;  // Decrease count of entries
   }
   else
   {
       auto message = "remove() called with an empty list or invalid position.";
       throw(PrecondViolatedExcept(message));
   } // end if

   return ableToRemove;
}  // end remove

template<class ItemType>
void ArrayList<ItemType>::clear() noexcept
{
   itemCount = 0;
}  // end clear

template<class ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const
{
   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
   {
      return items[position];
   }
   else
   {
      std::string message = "getEntry() called with an empty list or ";
      message  = message + "invalid position.";
      throw(PrecondViolatedExcept(message));
   }  // end if
}  // end getEntry

template<class ItemType>
void ArrayList<ItemType>::replace(int position, const ItemType& newEntry)
{
   // Enforce precondition
   bool ableToSet = (position >= 1) && (position <= itemCount);
   if (ableToSet)
   {
      items[position] = newEntry;
   }
   else
   {
      std::string message = "replace() called with an empty list or ";
      message  = message + "invalid position.";
      throw(PrecondViolatedExcept(message));
   }  // end if
}  // end replace

//  End of implementation file.

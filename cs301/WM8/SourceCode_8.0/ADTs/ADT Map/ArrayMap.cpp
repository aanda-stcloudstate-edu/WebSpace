//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** An array-based implementation of the ADT Map
    that organizes its data entries in sorted search-key order.
    Search keys in the Map are unique.
 @file ArrayMap.cpp */

#include "ArrayMap.h"
#include "ArrayMapIterator.h"
#include "PrecondViolatedExcept.h"

template <class KeyType, class ItemType>
void ArrayMap<KeyType, ItemType>::destroyMap()
{
   entries = std::make_unique<MapEntry<KeyType, ItemType>[]>(maxCapacity);
   itemCount = 0;
}  // end destroyMap

template <class KeyType, class ItemType>
int ArrayMap<KeyType, ItemType>::findEntryIndex(int firstIndex, int lastIndex,
                                                       const KeyType& itemKey) const
{
   int middleIndex = firstIndex + (lastIndex - firstIndex) / 2;
   
   if (firstIndex > lastIndex) 
      return -1; // Not found
   
   else if (itemKey == entries[middleIndex].getKey())
      return middleIndex;
   
   else if (itemKey < entries[middleIndex].getKey())
      return findEntryIndex(firstIndex, middleIndex - 1, itemKey);
   
   else
      return findEntryIndex(middleIndex + 1, lastIndex, itemKey);   
}  // end findEntryIndex

template <class KeyType, class ItemType>
ArrayMap<KeyType, ItemType>::ArrayMap(): itemCount(0), maxCapacity(DEFAULT_CAPACITY)
{
   entries = std::make_unique<MapEntry<KeyType, ItemType>[]>(DEFAULT_CAPACITY);
}  // end constructor

template <class KeyType, class ItemType>
ArrayMap<KeyType, ItemType>::ArrayMap(int maxNumberOfEntries):
                                    itemCount(0), maxCapacity(maxNumberOfEntries)
{
   entries = std::make_unique<MapEntry<KeyType, ItemType>[]>(maxNumberOfEntries);
}  // end constructor

template <class KeyType, class ItemType>
ArrayMap<KeyType, ItemType>::ArrayMap(const ArrayMap<KeyType, ItemType>& origMap):
                                    itemCount(origMap.itemCount), maxCapacity(origMap.maxCapacity)
{
   entries = std::make_unique<MapEntry<KeyType, ItemType>[]>(origMap.maxCapacity);
   for (int index = 0; index < origMap.itemCount; index++)
   {
      entries[index] = origMap.entries[index];
   }  // end for
}  // end copy constructor


template <class KeyType, class ItemType>
ArrayMap<KeyType, ItemType>::~ArrayMap()
{
   destroyMap();
}  // end destructor

template <class KeyType, class ItemType>
bool ArrayMap<KeyType, ItemType>::isEmpty() const  noexcept
{
   return (itemCount == 0);
}  // end isEmpty

template <class KeyType, class ItemType>
int ArrayMap<KeyType, ItemType>::getNumberOfItems() const noexcept
{
   return itemCount;
}  // end getNumberOfItems

template <class KeyType, class ItemType>
void ArrayMap<KeyType, ItemType>::clear() noexcept
{
   destroyMap();
}  // end clear

template <class KeyType, class ItemType>
bool ArrayMap<KeyType, ItemType>::add(const KeyType& searchKey, const ItemType& someValue)
{
   bool ableToInsert = (itemCount < maxCapacity);
   if (ableToInsert)
   {
      // Make room for new entry by shifting all entries at
      // positions >= newPosition toward the end of the array
      // (no shift if newPosition == itemCount + 1). Performing
      // a binary search doesn’t help here, because we need to
      // shift the entries while looking for the insertion location.
      int index = itemCount;
      
      // Short-circuit evaluation is important
      while ( (index > 0) && (searchKey < entries[index - 1].getKey()) )
      {
         entries[index] = entries[index - 1];
         index--;
      }  // end while

         // Enforce precondition: Ensure distinct search keys
      if (searchKey != entries[index - 1].getKey())
      {
            // Insert new entry
         entries[index] = MapEntry<KeyType, ItemType>(searchKey, someValue);
         itemCount++; // Increase count of entries
      }
      else
      {
         auto message = "Attempt to add an entry whose search key exists in map.";
         throw(PrecondViolatedExcept(message));
      }  // end if

      // Insert new entry
      entries[index] = MapEntry<KeyType, ItemType>(searchKey, someValue);
      itemCount++; // Increase count of entries
   }  // end if
   
   return ableToInsert;
}  // end add

template <class KeyType, class ItemType>
bool ArrayMap<KeyType, ItemType>::remove(const KeyType& itemKey)
{
   
   int itemIndex = findEntryIndex(0, itemCount-1, itemKey);
   bool ableToRemove = !isEmpty() && (itemIndex >= 0 );
   
   if (ableToRemove)
   {
      // If found, shift entries to left
      while (itemIndex < itemCount - 1)
      {
         entries[itemIndex] = entries[itemIndex + 1];
         itemIndex++;
      }  // end while
      
      itemCount--;  // Decrease count of entries
   }  // end if
   
   return ableToRemove;
}  // end remove

template <class KeyType, class ItemType>
ItemType ArrayMap<KeyType, ItemType>::getItem(const KeyType& itemKey) const
{
   int itemIndex = findEntryIndex(0, itemCount-1, itemKey);
   if (itemIndex < 0)
      throw NotFoundException("\n\nItem not found in Map!\n\n");
   
   return entries[itemIndex].getItem();
}  // end getItem

template <class KeyType, class ItemType>
bool ArrayMap<KeyType, ItemType>::contains(const KeyType& itemKey) const
{
   return (findEntryIndex(0, itemCount-1, itemKey) >= 0);
}  // end contains

template <class KeyType, class ItemType>
void ArrayMap<KeyType, ItemType>::traverse(void visit(ItemType&)) const
{
   // Simple because the array is sorted.
   for (int index = 0; index < itemCount; index++) 
   {
      ItemType currentItem = entries[index].getItem();
      visit(currentItem);
   }  // end for
}  // end traverse

template <class KeyType, class ItemType>
auto ArrayMap<KeyType, ItemType>::begin()
{
   return ArrayMapIterator<KeyType, ItemType>(0);
}
template <class KeyType, class ItemType>
auto ArrayMap<KeyType, ItemType>::end()
{
   return ArrayMapIterator<KeyType, ItemType>(itemCount+1); ;


}


//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** An array-based implementation of the ADT dictionary
    that organizes its data items in sorted search-key order.
    Search keys in the dictionary are unique.
 @file ArrayDictionary.cpp */

#include "ArrayDictionary.h"

template <class KeyType, class ItemType>
void ArrayDictionary<KeyType, ItemType>::destroyDictionary()
{
   items = std::make_unique<Entry<KeyType, ItemType>[]>(maxItems);
   itemCount = 0;
}  // end destroyDictionary

template <class KeyType, class ItemType>
int ArrayDictionary<KeyType, ItemType>::findEntryIndex(int firstIndex, int lastIndex, 
                                                       const KeyType& itemKey) const
{
   int middleIndex = firstIndex + (lastIndex - firstIndex) / 2;
   
   if (firstIndex > lastIndex) 
      return -1; // Not found
   
   else if (itemKey == items[middleIndex].getKey())
      return middleIndex;
   
   else if (itemKey < items[middleIndex].getKey())
      return findEntryIndex(firstIndex, middleIndex - 1, itemKey);
   
   else
      return findEntryIndex(middleIndex + 1, lastIndex, itemKey);   
}  // end findEntryIndex

template <class KeyType, class ItemType>
ArrayDictionary<KeyType, ItemType>::ArrayDictionary(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
   items = std::make_unique<Entry<KeyType, ItemType>[]>(DEFAULT_CAPACITY);
}  // end constructor

template <class KeyType, class ItemType>
ArrayDictionary<KeyType, ItemType>::ArrayDictionary(int maxNumberOfEntries):
                                    itemCount(0), maxItems(maxNumberOfEntries)
{
   items = std::make_unique<Entry<KeyType, ItemType>[]>(maxNumberOfEntries);
}  // end constructor

template <class KeyType, class ItemType>
ArrayDictionary<KeyType, ItemType>::ArrayDictionary(const ArrayDictionary<KeyType, ItemType>& dict):
                                    itemCount(dict.itemCount), maxItems(dict.maxItems)
{
   items = std::make_unique<Entry<KeyType, ItemType>[]>(dict.maxItems);
   for (int index = 0; index < dict.itemCount; index++)
   {
      items[index] = dict.items[index];
   }  // end for
}  // end copy constructor


template <class KeyType, class ItemType>
ArrayDictionary<KeyType, ItemType>::~ArrayDictionary()
{
   destroyDictionary();
}  // end destructor

template <class KeyType, class ItemType>
bool ArrayDictionary<KeyType, ItemType>::isEmpty() const
{
   return (itemCount == 0);
}  // end isEmpty

template <class KeyType, class ItemType>
int ArrayDictionary<KeyType, ItemType>::getNumberOfItems() const
{
   return itemCount;
}  // end getNumberOfItems

template <class KeyType, class ItemType>
void ArrayDictionary<KeyType, ItemType>::clear()
{
   destroyDictionary();
}  // end clear

template <class KeyType, class ItemType>
bool ArrayDictionary<KeyType, ItemType>::add(const KeyType& searchKey, const ItemType& newItem)
{
   bool ableToInsert = (itemCount < maxItems);
   if (ableToInsert)
   {
      // Make room for new entry by shifting all entries at
      // positions >= newPosition toward the end of the array
      // (no shift if newPosition == itemCount + 1). Performing
      // a binary search doesn’t help here, because we need to
      // shift the entries while looking for the insertion location.
      int index = itemCount;
      
      // Short-circuit evaluation is important
      while ( (index > 0) && (searchKey < items[index - 1].getKey()) )
      {
         items[index] = items[index - 1];
         index--;
      }  // end while
      
      // Insert new entry
      items[index] = Entry<KeyType, ItemType>(searchKey, newItem);
      itemCount++; // Increase count of entries
   }  // end if
   
   return ableToInsert;
}  // end add

template <class KeyType, class ItemType>
bool ArrayDictionary<KeyType, ItemType>::remove(const KeyType& itemKey)
{
   
   int itemIndex = findEntryIndex(0, itemCount-1, itemKey);
   bool ableToRemove = !isEmpty() && (itemIndex >= 0 );
   
   if (ableToRemove)
   {
      // If found, shift items to left
      while (itemIndex < itemCount - 1)
      {
         items[itemIndex] = items[itemIndex + 1];
         itemIndex++;
      }  // end while
      
      itemCount--;  // Decrease count of entries
   }  // end if
   
   return ableToRemove;
}  // end remove

template <class KeyType, class ItemType>
ItemType ArrayDictionary<KeyType, ItemType>::getItem(const KeyType& itemKey) const throw (NotFoundException)
{
   int itemIndex = findEntryIndex(0, itemCount-1, itemKey);
   if (itemIndex < 0)
      throw NotFoundException("\n\nItem not found in Dictionary!\n\n");
   
   return items[itemIndex].getItem();
}  // end getItem

template <class KeyType, class ItemType>
bool ArrayDictionary<KeyType, ItemType>::contains(const KeyType& itemKey) const
{
   return (findEntryIndex(0, itemCount-1, itemKey) >= 0);
}  // end contains

template <class KeyType, class ItemType>
void ArrayDictionary<KeyType, ItemType>::traverse(void visit(ItemType&)) const
{
   // Simple because the array is sorted.
   for (int index = 0; index < itemCount; index++) 
   {
      ItemType currentItem = items[index].getItem();
      visit(currentItem);
   }  // end for
}  // end traverse

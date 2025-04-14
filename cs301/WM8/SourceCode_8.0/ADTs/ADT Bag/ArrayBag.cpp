//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** Implementation file for the class ArrayBag.
 @file ArrayBag.cpp */
#include "ArrayBag.h"

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{   }  // end default constructor

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& someItem)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = someItem;
		itemCount++;
	}  // end if

	return hasRoomToAdd;
}  // end add
//template<class ItemType>
//bool ArrayBag<ItemType>::add(const ItemType& newEntry)
//{
//   bool hasRoomToAdd = (itemCount < maxItems);
//   if (!hasRoomToAdd)
//   {
//      ItemType* oldArray = items;
//      items = new ItemType[2 * maxItems];
//      for (int index = 0; index < maxItems; index++)
//           items[index] = oldArray[index];
//      delete [ ] oldArray;
//      maxItems = 2 * maxItems;
//   }  // end if
//      // We can always add the item
//   items[itemCount] = newEntry;
//   itemCount++;
//   return true;
//}  // end ResizableArrayBag add
//


// STUB
// template<class ItemType>
// bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
// {
//    return false; // STUB
// }  // end remove
//
//
template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& someItem)
{
   int locatedIndex = getIndexOf(someItem);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
}  // end remove


 // STUB
// template<class ItemType>
// void ArrayBag<ItemType>::clear()
// {
//    // STUB
// }  // end clear

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& target) const
{
   return countFrequency(target, 0);
}  // end getFrequencyOf

template<class ItemType>
int ArrayBag<ItemType>::countFrequency(const ItemType& target,
                                       int searchIndex) const
{
   int frequency = 0;
   if (searchIndex < itemCount)
   {
      if (items[searchIndex] == target)
      {
         frequency = 1 + countFrequency(target, searchIndex + 1);
      }
      else
      {
         frequency = countFrequency(target, searchIndex + 1);
      }  // end if
   }  // end if
   return frequency;
}  // end countFrequency



//template<class ItemType>
//int ArrayBag<ItemType>::countFrequency(const ItemType& target, int searchIndex) const
//{
//   if (searchIndex < itemCount)
//   {
//      if (items[searchIndex] == target)
//      {
//         return 1 + countFrequency(target, searchIndex + 1);
//      }
//      else
//      {
//         return countFrequency(target, searchIndex + 1);
//      }  // end if
//   }
//   else
//      return 0; // Base case
//}  // end countFrequency


//template<class ItemType>
//int ArrayBag<ItemType>::getFrequencyOf(const ItemType& target) const
//{
//   int frequency = 0;
//
//   for (int curIndex = 0; curIndex < itemCount; curIndex++ )
//   {
//      if (items[curIndex] == target)
//      {
//         frequency++;
//      }  // end if
//
//   }  // end while
//
//   return frequency;
//}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& target) const
{
	return getIndexOf(target) > -1;
}  // end contains

//ALTERNATE 1: First version
//template<class ItemType>
//bool ArrayBag<ItemType>::contains(const ItemType& target) const
//{
//   return getFrequencyOf(target) > 0;
//}  // end contains

// ALTERNATE 2: Second version 
//template<class ItemType>
//bool ArrayBag<ItemType>::contains(const ItemType& target) const
//{
//   bool found = false;
//   int curIndex = 0;        // Current array index
//   while (!found && (curIndex < itemCount))
//   {
//      if (target == items[curIndex])
//      {
//         found = true;
//      } // end if
//
//      curIndex++;           // Increment to next entry
//   }  // end while
//
//   return found;
//}  // end contains


template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
	for (auto currentEntry : items)
		bagContents.push_back(currentEntry);      
   return bagContents;
}  // end toVector

// private
//template<class ItemType>
//int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
//{
//	bool found = false;
//   int result = -1;
//   int searchIndex = 0;
//
//   // If the bag is empty, itemCount is zero, so loop is skipped
//   while (!found && (searchIndex < itemCount))
//   {
//      if (items[searchIndex] == target)
//      {
//         found = true;
//         result = searchIndex;
//      }
//      else
//      {
//         searchIndex++;
//      }  // end if
//   }  // end while
//
//   return result;
//}  // end getIndexOf

template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target, int searchIndex) const
{
   int result = -1;
   if (searchIndex < itemCount)
   {
      if (items[searchIndex] == target)
      {
         result = searchIndex;
      }
      else
      {
         result = getIndexOf(target, searchIndex + 1);
      }  // end if
   }  // end if
   return result;
}  // end getIndexOf


//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

 /** A class of MapEntry objects for an array-based implementation of the ADT dictionary.
 @file MapEntry.h */

#ifndef MAP_ENTRY_
#define MAP_ENTRY_

template <class KeyType, class ItemType>
class MapEntry
{
private:
   KeyType searchKey;
   ItemType item;
   
protected:
   void setKey(const KeyType& itemKey);
   
public:
   MapEntry();
   MapEntry(const KeyType& itemKey, const ItemType& someItem);
   ItemType getItem() const noexcept;
   KeyType getKey() const noexcept;
   void setItem(const ItemType& someItem);
   bool operator==(const MapEntry<KeyType, ItemType>& rightHandItem) const;
   bool operator>(const MapEntry<KeyType, ItemType>& rightHandItem) const;
}; // end MapEntry

#include "MapEntry.cpp"
#endif

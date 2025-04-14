//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** @file  HashedMap.h */

#ifndef HASHED_MAP_
#define  HASHED_MAP_

#include "MapInterface.h"
#include "HashedEntry.h"
#include "NotFoundException.h"

template <class KeyType, class ItemType>
using hashTableType = std::shared_ptr<HashedEntry<KeyType, ItemType>>[];

template <class KeyType, class ItemType>
class HashedMap : public MapInterface<KeyType, ItemType>
{
private:
   // creates a unique pointer to an array of shared HashedEntry pointers
   std::unique_ptr<hashTableType<KeyType, ItemType>> hashTable;  // Array of pointers to entries
   int itemCount;                               // Count of map entries
   int hashTableSize;                           // Table size must be prime
   static const int DEFAULT_CAPACITY = 101;
   
   void destroyMap();   
   int getHashIndex(const KeyType& itemKey) const;   
   int getNextPrime(int number) const;
   bool isPrime(int number) const;
   
public:   
   HashedMap();
   HashedMap(int maxNumberOfEntries);
   HashedMap(const HashedMap<KeyType, ItemType>& otherMap);
   
   virtual ~HashedMap();
   
   bool isEmpty() const;   
   int getNumberOfItems() const;   
   void clear();   
   bool add(const KeyType& itemKey, const ItemType& newItem);   
   bool remove(const KeyType& itemKey);
   ItemType getItem(const KeyType& itemKey) const;   
   bool contains(const KeyType& itemKey) const;   
   void traverse(void visit(ItemType&)) const;   
}; // end HashedMap

#include "HashedMap.cpp"
#endif

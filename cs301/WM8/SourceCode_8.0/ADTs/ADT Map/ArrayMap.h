//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** An array-based implementation of the ADT Map
    that organizes its data items in sorted search-key order.
    Search keys in the Map are unique.
 @file ArrayMap.h */
 
#ifndef ARRAY_MAP_
#define ARRAY_MAP_

#include "MapInterface.h"
#include "MapEntry.h"
#include "NotFoundException.h"

template <class KeyType, class ItemType>
class ArrayMap : public MapInterface<KeyType, ItemType>
{
private:
   static const int DEFAULT_CAPACITY = 21; // Small capacity to test for a full Map
   std::unique_ptr<MapEntry<KeyType, ItemType>[]> entries; // Array of Map entries
   int itemCount;                   // Current count of Map items
   int maxCapacity;                    // Maximum capacity of the Map
   void destroyMap();
   int findEntryIndex(int firstIndex, int lastIndex,
                      const KeyType& searchKey) const;
public:
   ArrayMap();
   ArrayMap(int maxNumberOfEntries);
   ArrayMap(const ArrayMap<KeyType, ItemType>& origMap);
   
   virtual ~ArrayMap();
   
   bool isEmpty() const noexcept;
   int getNumberOfItems() const noexcept;
   bool add(const KeyType& searchKey, const ItemType& someItem);
   bool remove(const KeyType& searchKey);
   void clear() noexcept;
   ItemType getItem(const KeyType& searchKey) const;
   bool contains(const KeyType& searchKey) const;
   
   /** Traverses the items in this Map in sorted search-key order
       and calls a given client function once for each item. */
   void traverse(void visit(ItemType&)) const;

   auto begin();
   auto end();

}; // end ArrayMap

#include "ArrayMap.cpp"
#endif

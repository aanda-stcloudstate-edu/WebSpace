//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** A binary search tree implementation of the ADT Map
    that organizes its data items in sorted search-key order.
    Search keys in the map are unique.
 @file TreeMap.h */
 
#ifndef TREE_MAP_
#define TREE_MAP_

#include "MapInterface.h"
#include "BinarySearchTree.h"
#include "MapEntry.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcept.h"

template <class KeyType, class ItemType>
class TreeMap : public MapInterface<KeyType, ItemType>
{
private:
   // Binary search tree of Map entries
   BinarySearchTree<MapEntry<KeyType, ItemType>> entryTree;
     
public:
   TreeMap();
   TreeMap(const TreeMap<KeyType, ItemType>& origMap);
   virtual ~TreeMap();
   
   // The declarations of the public methods appear here and are the
   // same as given in Listing 18-3 for the class ArrayMap.
 
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



}; // end TreeMap

#include "TreeMap.cpp"
#endif

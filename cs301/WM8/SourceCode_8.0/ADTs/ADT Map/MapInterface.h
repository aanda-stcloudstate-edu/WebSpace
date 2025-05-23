//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

 //#include "MapIteratorInterface.h"
/** An interface for the ADT Map. (Distinct search keys.)
 @file  MapInterface.h */

#ifndef MAP_INTERFACE_
#define MAP_INTERFACE_

#include "NotFoundException.h"

template<class KeyType, class ItemType>
class MapInterface 
{
public:   
   /** Sees whether this Map is empty.
    @return True if the Map is empty;
       otherwise returns false. */
   virtual bool isEmpty() const = 0;
   
   /** Gets the number of items in this Map.
    @return The number of items in the Map. */
   virtual int getNumberOfItems() const = 0;
   
   /** Inserts an item into this Map according to the item’s search key.
    @pre  The search key of the new item differs from all search
       keys presently in the Map.
    @post  If the insertion is successful, newItem is in its
       proper position within the Map.
    @param searchKey  The search key associated with the item to be inserted.
    @param newItem  The item to add to the Map.
    @return  True if item was successfully added, or false if not. */
   virtual bool add(const KeyType& searchKey, const ItemType& someItem) = 0;
   
   /** Removes an item with the given search key from this Map.
    @post  If the item whose search key equals searchKey existed in the Map,
       the item was removed.
    @param searchKey  The search key of the item to be removed.
    @return  True if the item was successfully removed, or false if not. */
   virtual bool remove(const KeyType& searchKey) = 0;
   
   /** Removes all entries from this Map. */
   virtual void clear() = 0;
   
   /** Retrieves an item with a given search key from a Map.
    @post  If the retrieval is successful, the item is returned.
    @param searchKey  The search key of the item to be retrieved.
    @return  The item associated with the search key.
    @throw  NotFoundException if the item does not exist. */
   virtual ItemType getItem(const KeyType& searchKey) const = 0;
   
   /** Sees whether this Map contains an item with a given
       search key.
    @post  The Map is unchanged.
    @param searchKey  The search key of the item to be retrieved.
    @return  True if an item with the given search key exists in the Map. */
   virtual bool contains(const KeyType& searchKey) const = 0;
   
   /** Traverses this Map and calls a given client function once for each item.
    @post  The given function’s action occurs once for each item in the
       Map and possibly alters the item.
    @param visit A client function. */
   virtual void traverse(void visit(ItemType&)) const = 0;

//   virtual MapIteratorInterface<KeyType, ItemType> begin() = 0;
//   virtual MapIteratorInterface<KeyType, ItemType> end() = 0;

   /** Deletes this Map and frees its allocated memory  */
   virtual ~MapInterface() {   }
}; // end MapInterface

#endif

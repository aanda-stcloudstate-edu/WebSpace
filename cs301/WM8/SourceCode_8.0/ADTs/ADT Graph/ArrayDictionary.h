//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** An array-based implementation of the ADT dictionary
    that organizes its data items in sorted search-key order.
    Search keys in the dictionary are unique.
 @file ArrayDictionary.h */
 
#ifndef ARRAY_DICTIONARY_
#define ARRAY_DICTIONARY_

#include "ArrayDictionaryIterator.h"
#include "DictionaryInterface.h"
#include "Entry.h"
#include "NotFoundException.h"

template <class KeyType, class ItemType>
class ArrayDictionary : public DictionaryInterface<KeyType, ItemType>
{
private:
   static const int DEFAULT_CAPACITY = 21; // Small capacity to test for
                                           // a full dictionary
   std::unique_ptr<Entry<KeyType, ItemType>[]> items; // Array of dictionary entries
   int itemCount;                   // Current count of dictionary items
   int maxItems;                    // Maximum capacity of the dictionary
   void destroyDictionary();
   int findEntryIndex(int firstIndex, int lastIndex,
                      const KeyType& searchKey) const;
public:
   ArrayDictionary();
   ArrayDictionary(int maxNumberOfEntries);
   ArrayDictionary(const ArrayDictionary<KeyType, ItemType>& dict);
   
   virtual ~ArrayDictionary();
   
   bool isEmpty() const;
   int getNumberOfItems() const;
   bool add(const KeyType& searchKey, const ItemType& newItem);
   bool remove(const KeyType& searchKey);
   void clear();
   ItemType getItem(const KeyType& searchKey) const throw (NotFoundException);
   bool contains(const KeyType& searchKey) const;
   
   /** Traverses the items in this dictionary in sorted search-key order
       and calls a given client function once for each item. */
   void traverse(void visit(ItemType&)) const;
   
   // For iterators
   ArrayDictionaryIterator<KeyType, ItemType> begin();
   ArrayDictionaryIterator<KeyType, ItemType> end();
   
   friend ArrayDictionaryIterator<KeyType, ItemType>;

}; // end ArrayDictionary

#include "ArrayDictionary.cpp"
#endif

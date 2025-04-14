//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** A class of entry objects for a hashing implementation of the
    ADT dictionary.
 @file HashedEntry.h */
 
#ifndef HASHED_ENTRY_
#define HASHED_ENTRY_

#include <memory>
#include "MapEntry.h"

template<class KeyType, class ItemType>
class HashedEntry : public MapEntry<KeyType, ItemType>
{
private:
   std::shared_ptr<HashedEntry<KeyType, ItemType>> nextPtr;
   
public:
   HashedEntry();
   HashedEntry(KeyType itemKey, ItemType someEntry);
   HashedEntry(KeyType itemKey, ItemType someEntry,
               std::shared_ptr<HashedEntry<KeyType, ItemType>> nextEntryPtr);
   
   void setNext(std::shared_ptr<HashedEntry<KeyType, ItemType>> nextEntryPtr);
   auto getNext() const;
}; // end HashedEntry

#include "HashedEntry.cpp"
#endif

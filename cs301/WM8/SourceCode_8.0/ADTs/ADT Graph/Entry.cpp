//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.
//
//  Entry.cpp
//  DictionaryTest
//


#include "Entry.h"

template <class KeyType, class ItemType>
Entry<KeyType, ItemType>::Entry()
{ }

template <class KeyType, class ItemType>
Entry<KeyType, ItemType>::Entry(ItemType newEntry, KeyType itemKey)
               :item(newEntry), searchKey(itemKey)
{ }

template <class KeyType, class ItemType>
ItemType Entry<KeyType, ItemType>::getItem() const
{
   return item;
}


template <class KeyType, class ItemType>
KeyType Entry<KeyType, ItemType>::getKey() const
{
   return searchKey;
}


template <class KeyType, class ItemType>
void Entry<KeyType, ItemType>::setItem(const ItemType& newEntry)
{
   item = newEntry;
}

template <class KeyType, class ItemType>
void Entry<KeyType, ItemType>::setKey(const KeyType& itemKey)
{
   searchKey = itemKey;
}

template <class KeyType, class ItemType>
bool Entry<KeyType, ItemType>::operator==(const Entry<KeyType, ItemType>& rightHandItem) const
{
   return (searchKey == rightHandItem.getKey());
}  // end operator==


template <class KeyType, class ItemType>
bool Entry<KeyType, ItemType>::operator>(const Entry<KeyType, ItemType>& rightHandItem) const
{
   return (searchKey > rightHandItem.getKey());
}


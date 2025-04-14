//
//  MapEntry.cpp
//  DictionaryTest
//
//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.


#include "MapEntry.h"

template <class KeyType, class ItemType>
MapEntry<KeyType, ItemType>::MapEntry()
{ }

template <class KeyType, class ItemType>
MapEntry<KeyType, ItemType>::MapEntry(const KeyType& itemKey, const ItemType& someItem)
               :searchKey(itemKey), item(someItem)
{ }

template <class KeyType, class ItemType>
ItemType MapEntry<KeyType, ItemType>::getItem() const  noexcept
{
   return item;
}


template <class KeyType, class ItemType>
KeyType MapEntry<KeyType, ItemType>::getKey() const noexcept
{
   return searchKey;
}


template <class KeyType, class ItemType>
void MapEntry<KeyType, ItemType>::setItem(const ItemType& someItem)
{
   item = someItem;
}

template <class KeyType, class ItemType>
void MapEntry<KeyType, ItemType>::setKey(const KeyType& itemKey)
{
   searchKey = itemKey;
}

template <class KeyType, class ItemType>
bool MapEntry<KeyType, ItemType>::operator==(const MapEntry<KeyType, ItemType>& rightHandItem) const
{
   return (searchKey == rightHandItem.getKey());
}  // end operator==


template <class KeyType, class ItemType>
bool MapEntry<KeyType, ItemType>::operator>(const MapEntry<KeyType, ItemType>& rightHandItem) const
{
   return (searchKey > rightHandItem.getKey());
}


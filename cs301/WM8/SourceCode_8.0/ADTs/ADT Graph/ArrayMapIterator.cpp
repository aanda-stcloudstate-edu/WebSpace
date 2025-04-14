//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** An iterator class for the class ArrayDictionary.
 @file ArrayDictionaryIterator.cpp */

#include "ArrayDictionaryIterator.h"

template <class KeyType, class ItemType>
ArrayDictionaryIterator<KeyType, ItemType>::
ArrayDictionaryIterator(): containerPtr(nullptr), currentItemIndex(0)
{
}  // end default constructor

template <class KeyType, class ItemType>
ArrayDictionaryIterator<KeyType, ItemType>::
ArrayDictionaryIterator(const ArrayDictionary<KeyType, ItemType>* someDictionary, int ItemIndex):
                        containerPtr(someDictionary), currentItemIndex(ItemIndex)
{
}  // end constructor

template <class KeyType, class ItemType>
const ItemType ArrayDictionaryIterator<KeyType, ItemType>::operator*()
{
   return (containerPtr->items[currentItemIndex]).getItem();
}  // end operator*

template <class KeyType, class ItemType>
ArrayDictionaryIterator<KeyType, ItemType> ArrayDictionaryIterator<KeyType, ItemType>::operator++()
{
   currentItemIndex++;
   return *this;
}  // end operator++

template <class KeyType, class ItemType>
bool ArrayDictionaryIterator<KeyType, ItemType>::
operator==(const ArrayDictionaryIterator<KeyType, ItemType>& rightHandSide) const
{
   return ((containerPtr == rightHandSide.containerPtr) && 
           (currentItemIndex == rightHandSide.currentItemIndex));
}  // end operator==

template <class KeyType, class ItemType>
bool ArrayDictionaryIterator<KeyType, ItemType>::
operator!=(const ArrayDictionaryIterator<KeyType, ItemType>& rightHandSide) const
{
   return ((containerPtr != rightHandSide.containerPtr) || 
           (currentItemIndex != rightHandSide.currentItemIndex));   
}  // end operator!=

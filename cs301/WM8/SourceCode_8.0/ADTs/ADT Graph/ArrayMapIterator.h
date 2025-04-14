//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** An iterator class for the class ArrayDictionary.
 @file ArrayDictionaryIterator.h */

#ifndef _ARRAY_DICTIONARY_ITERATOR
#define _ARRAY_DICTIONARY_ITERATOR

#include <iterator>
//#include "Entry.h"
#include "ArrayDictionary.h"

template<class KeyType, class ItemType>
class ArrayDictionary;

template <class KeyType, class ItemType>
class ArrayDictionaryIterator : public std::iterator<std::input_iterator_tag, int>
{
private:
   const ArrayDictionary<KeyType, ItemType>* containerPtr;     // Collection associated with iterator
   int                                       currentItemIndex; // Current location in collection
   
public:
   ArrayDictionaryIterator();
   ArrayDictionaryIterator(const ArrayDictionary<KeyType, ItemType>* someDictionary, int ItemIndex);
    
   const ItemType operator*();
   ArrayDictionaryIterator<KeyType, ItemType> operator++();
   bool operator==(const ArrayDictionaryIterator<KeyType, ItemType>& rightHandSide) const;
   bool operator!=(const ArrayDictionaryIterator<KeyType, ItemType>& rightHandSide) const;
}; // end ArrayDictionaryIterator

#include "ArrayDictionaryIterator.cpp"
#endif

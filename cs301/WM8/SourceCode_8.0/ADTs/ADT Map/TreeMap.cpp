//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** @file TreeMap.cpp */

#include "TreeMap.h"
// #include "TreeMapIterator.h"

#include <iostream>
#include <functional>

template <class KeyType, class ItemType>
TreeMap<KeyType, ItemType>::TreeMap()
{   
}  // end default constructor

template <class KeyType, class ItemType>
TreeMap<KeyType, ItemType>::TreeMap(const TreeMap<KeyType, ItemType>& dict) : entryTree(dict.entryTree)
{
}  // end copy constructor

template <class KeyType, class ItemType>
TreeMap<KeyType, ItemType>::~TreeMap()
{
   entryTree.clear();
}  // end destructor

template <class KeyType, class ItemType>
bool TreeMap<KeyType, ItemType>::isEmpty() const noexcept
{
   return entryTree.isEmpty();
}  // end isEmpty

template <class KeyType, class ItemType>
int TreeMap<KeyType, ItemType>::getNumberOfItems() const noexcept
{
   return entryTree.getNumberOfNodes();
}  // end getNumberOfItems

template <class KeyType, class ItemType>
void TreeMap<KeyType, ItemType>::clear() noexcept
{
   entryTree.clear();
}  // end clear

template <class KeyType, class ItemType>
bool TreeMap<KeyType, ItemType>::add(const KeyType& searchKey,
                                            const ItemType& someItem)
{
//   return entryTree.add(MapEntry<KeyType, ItemType>(searchKey, someItem));
   MapEntry<KeyType, ItemType> mapEntryToAdd(searchKey, someItem);

      // Enforce precondition: Ensure distinct search keys
   if (!entryTree.contains(mapEntryToAdd))
   {
      // Add new entry and return boolean result
      return entryTree.add(mapEntryToAdd);
   }
   else
   {
      auto message = "Attempt to add an entry whose search key exists in map.";
      throw(PrecondViolatedExcept(message)); // Exit the member function
   }  // end if

} // end add

template <class KeyType, class ItemType>
bool TreeMap<KeyType, ItemType>::remove(const KeyType& searchKey)
{
   return entryTree.remove(MapEntry<KeyType, ItemType>(searchKey, ItemType()));
}  // end remove   

template <class KeyType, class ItemType>
ItemType TreeMap<KeyType, ItemType>::getItem(const KeyType& searchKey) const
{
   MapEntry<KeyType, ItemType> theEntry = entryTree.getEntry(MapEntry<KeyType, ItemType>(searchKey, ItemType()));
   return theEntry.getItem();
}  // end getItem

template <class KeyType, class ItemType>
bool TreeMap<KeyType, ItemType>::contains(const KeyType& searchKey) const
{
   return entryTree.contains(MapEntry<KeyType, ItemType>(searchKey, ItemType()));
}  // end contains

template <class KeyType, class ItemType>
void TreeMap<KeyType, ItemType>::traverse(void visit(ItemType&)) const
{
   // STUB
//   auto treeVisit = [&](MapEntry<KeyType, ItemType>& someEntry)
//   {
//        auto someItem = someEntry.getItem();
//        visit(someItem);
//   };
//   //  auto test = MapEntry<KeyType, ItemType>();
//   // treeVisit(test);
//   entryTree.preorderTraverse(treeVisit);

   entryTree.preorderTraverse([=](MapEntry<KeyType, ItemType>& someEntry)
                             {
                                auto someItem = someEntry.getItem();
                                visit(someItem);
                             }
);

   
   //   std::cout << "Traverse is stubbed." << std::endl;
}  // end traverse


template <class KeyType, class ItemType>
auto TreeMap<KeyType, ItemType>::begin()
{

}
template <class KeyType, class ItemType>
auto TreeMap<KeyType, ItemType>::end()
{ }

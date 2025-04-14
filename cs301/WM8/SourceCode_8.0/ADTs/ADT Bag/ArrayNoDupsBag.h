//
//  ArrayNoDupsBag.hpp
//
//  Created by Timothy Henry on 1/28/23.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.
//
/**  @file ArrayNoDupsBag.h */
#ifndef ArrayNoDupsBag_hpp
#define ArrayNoDupsBag_hpp

#include "ArrayBag.h"

template<class ItemType>
class ArrayNoDupsBag : public ArrayBag<ItemType>
{
   bool add(const ItemType& anEntry);
}; // end ArrayBag

#include "ArrayNoDupsBag.cpp"

#endif /* ArrayNoDupsBag_h */

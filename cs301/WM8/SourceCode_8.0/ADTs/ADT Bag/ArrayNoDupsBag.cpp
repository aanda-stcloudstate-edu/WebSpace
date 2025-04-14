   //  Created by Frank M. Carrano and Timothy M. Henry.
   //  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.
//  ArrayNoDupsBag.cpp
//
//  Created by Timothy Henry on 1/28/23.
//  Copyright (c) 2024 Pearson Education, Hoboken, New Jersey.
//

#include "ArrayNoDupsBag.h"

template<class ItemType>
bool ArrayNoDupsBag<ItemType>::add(const ItemType& someItem)
{
   bool successfulAdd = false;
   bool itemInBag = ArrayBag<ItemType>::contains(someItem);

   if (!itemInBag)
   {
      successfulAdd = ArrayBag<ItemType>::add(someItem);
   }

   return (!itemInBag && successfulAdd);
}  // end add

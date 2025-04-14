//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.
/* @file BoxInterface.h */
 
#ifndef BOX_INTERFACE_
#define BOX_INTERFACE_

template <class ItemType>
class BoxInterface
{
public:
   virtual void setItem(const ItemType& theItem) = 0;
   virtual ItemType getItem() const = 0;
   virtual ~BoxInterface() { }
}; // end BoxInterface
#endif

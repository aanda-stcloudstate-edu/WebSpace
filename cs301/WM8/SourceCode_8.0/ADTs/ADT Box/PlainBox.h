//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/**     @file PlainBox.h */

#ifndef PLAIN_BOX_
#define PLAIN_BOX_

#include "BoxInterface.h"

template<class ItemType> // Indicates this is a template definition

// Declaration for the class PlainBox
class PlainBox : public BoxInterface<ItemType>
{
private:
   // Data field
   ItemType item;
   
public:
   // Default constructor
   PlainBox();
   
   // Parameterized constructor
   PlainBox(const ItemType& theItem);
   
   // Mutator method that can change the value of the data field
   void setItem(const ItemType& theItem);
   
   // Accessor method to get the value of the data field
   ItemType getItem() const;
}; // end PlainBox

#include "PlainBox.cpp" // Include the implementation file
#endif

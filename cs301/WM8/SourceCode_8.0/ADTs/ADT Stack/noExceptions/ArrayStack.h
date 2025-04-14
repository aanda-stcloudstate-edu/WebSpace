//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** ADT Stack: Array-based implementation.
 @file ArrayStack.h */

#ifndef ARRAY_STACK_
#define ARRAY_STACK_

#include "StackInterface.h"

template<class ItemType>
class ArrayStack : public StackInterface<ItemType>
{
private:
   static const int DEFAULT_CAPACITY = 6;    // Default-size-of-stack
   ItemType items[DEFAULT_CAPACITY];         // Array of stack items
   int      top;                             // Index to top of stack
public:
   ArrayStack();                             // Default constructor
   bool isEmpty() const noexcept;
   bool push(const ItemType& someItem) noexcept;
   bool pop() noexcept;
   ItemType peek() const;
};  // end ArrayStack

#include "ArrayStack.cpp"
#endif

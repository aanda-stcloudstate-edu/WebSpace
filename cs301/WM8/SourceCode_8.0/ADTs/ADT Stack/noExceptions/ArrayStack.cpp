//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** @file ArrayStack.cpp */
#include <cassert>             // For assert
#include "ArrayStack.h"        // Header file

template<class ItemType>
ArrayStack<ItemType>::ArrayStack() : top(-1)
{   }  // end default constructor

// Copy constructor and destructor are supplied by the compiler

template<class ItemType>
bool ArrayStack<ItemType>::isEmpty() const noexcept
{
   return top < 0;
}  // end isEmpty

template<class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& someItem) noexcept
{
   bool result = false;
   if (top < DEFAULT_CAPACITY - 1) // Does stack have room for someItem?
   {
      top++;
      items[top] = someItem;
      result = true;
   }  // end if

   return result;
}  // end push

template<class ItemType>
bool ArrayStack<ItemType>::pop() noexcept
{
   bool result = false;
   if (!isEmpty())
   {
      top--;
      result = true;
   }  // end if

   return result;
}  // end pop

template<class ItemType>
ItemType ArrayStack<ItemType>::peek() const
{
   assert (!isEmpty()); // Enforce precondition during debugging
   // Stack is not empty; return top
   return items[top];
}  // end peek
// end of implementation file

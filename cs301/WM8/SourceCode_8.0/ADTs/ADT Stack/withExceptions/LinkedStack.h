//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** ADT Stack: Link-based implementation.
 @file LinkedStack.h */
#ifndef LINKED_STACK_
#define LINKED_STACK_

#include "PrecondViolatedExcept.h"
#include "StackInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedStack : public StackInterface<ItemType>
{
private:
   Node<ItemType>* topPtr; // Pointer to first node in the chain;
                           // This node contains the stack's top
public:
      // Constructors and destructor:
   LinkedStack();                                            // Default constructor
   LinkedStack(const LinkedStack<ItemType>& originalStack);  // Copy constructor
   virtual ~LinkedStack();                                   // Destructor

   //  Stack operations:
   bool isEmpty() const noexcept;
   bool push(const ItemType& someItem);
   bool pop() noexcept;
   ItemType peek() const;
}; // end LinkedStack

#include "LinkedStack.cpp"
#endif

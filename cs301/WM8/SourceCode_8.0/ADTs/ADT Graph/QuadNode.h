//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

// PARTIALLY COMPLETE

/** A class of nodes for a link-based 2-3-4 tree.
 @file QuadNode.h */
#ifndef QUADNODE_CLASS_
#define QUADNODE_CLASS_

#include <memory>

template<class ItemType>
class QuadNode
{   
private:
   ItemType smallItem, middleItem, largeItem; // Data portion
   std::shared_ptr<QuadNode<ItemType>> leftChildPtr;          // Left-child pointer
   std::shared_ptr<QuadNode<ItemType>> leftMidChildPtr;       // Middle-left-child pointer
   std::shared_ptr<QuadNode<ItemType>> rightMidChildPtr;      // Middle-right-child pointer
   std::shared_ptr<QuadNode<ItemType>> rightChildPtr;         // Right-child pointer
   
   // Constructors, accessor methods, and mutator methods are here.

}; // end QuadNode

#endif

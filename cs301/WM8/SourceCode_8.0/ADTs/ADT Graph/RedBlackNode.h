//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** A class of nodes for a link-based red-black tree.
 @file RedBlackNode.h */
 
// PARTIALLY COMPLETE
#ifndef REDBLACK_CLASS_
#define REDBLACK_CLASS_

#include <memory>


enum Color {RED, BLACK};

template<class ItemType>
class RedBlackNode : public BinaryNode<ItemType>
{
private:
   Color leftColor, rightColor;
   
public:
   // Get and set methods for leftColor and rightColor
   // . . .
   
}; // end RedBlackNode

#endif;

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** A class of nodes for a link-based 2-3 tree.
 @file TriNode.h */
 
#ifndef _TRI_NODE
#define _TRI_NODE

#include <memory>

template<class ItemType>
class TriNode
{
private:
   ItemType smallItem, largeItem;    // Data portion
   std::shared_ptr<TriNode<ItemType>> leftChildPtr;  // Left-child pointer
   std::shared_ptr<TriNode<ItemType>> midChildPtr;   // Middle-child pointer
   std::shared_ptr<TriNode<ItemType>> rightChildPtr; // Right-child pointer
   
public:
   TriNode();
   TriNode(const ItemType& anItem);
   TriNode(const ItemType& anItem, std::shared_ptr<TriNode<ItemType>> leftPtr,
           TriNode<ItemType>* midPtr, std::shared_ptr<TriNode<ItemType>> rightPtr);
   
   bool isLeaf() const;
   bool isTwoNode() const;
   bool isThreeNode() const;
   
   ItemType getSmallItem() const;
   ItemType getLargeItem() const;
   
   void setSmallItem(const ItemType& anItem);
   void setLargeItem(const ItemType& anItem);
   
   auto getLeftChildPtr() const;
   auto getMidChildPtr() const;
   auto getRightChildPtr() const;
   
   void setLeftChildPtr(std::shared_ptr<TriNode<ItemType>> leftPtr);
   void setMidChildPtr(std::shared_ptr<TriNode<ItemType>> midPtr);
   void setRightChildPtr(std::shared_ptr<TriNode<ItemType>> rightPtr);
}; // end TriNode
#include "TriNode.cpp"
#endif

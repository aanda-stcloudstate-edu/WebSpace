//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** Interface for the ADT binary tree
 @file BinaryTreeInterface.h */

#ifndef BINARY_TREE_INTERFACE_
#define BINARY_TREE_INTERFACE_

#include "NotFoundException.h"
#include <functional>

template<class ItemType>
class BinaryTreeInterface
{
public:
   /** Tests whether this binary tree is empty.
    @return True if the binary tree is empty, or false if not. */
   virtual bool isEmpty() const = 0;
   
   /** Gets the height of this binary tree.
    @return The height of the binary tree. */
   virtual int getHeight() const = 0;
   
   /** Gets the number of nodes in this binary tree.
    @return The number of nodes in the binary tree. */
   virtual int getNumberOfNodes() const = 0;
   
   /** Gets the data that is in the root of this binary tree.
    @pre  The binary tree is not empty.
    @post  The root’s data has been returned, and the binary tree is unchanged.
    @return  The data in the root of the binary tree. */
   virtual ItemType getRootData() const = 0;
   
   /** Replaces the data item in the root of this binary tree
       with the given data, if the tree is not empty. However, if
       the tree is empty, inserts a new root node containing the
       given data into the tree.
    @pre  None.
    @post  The data in the root of the binary tree is as given.
    @param someItem  The data for the root. */
   virtual void setRootData(const ItemType& someItem) = 0;
   
   /** Adds a new node containing the given data to this binary tree.
    @param someItem  The data for the new node.
    @post  The binary tree contains a new node.
    @return  True if the addition is successful, or false not. */
   virtual bool add(const ItemType& someItem) = 0;
   
   /** Removes the node containing the given data item from this binary tree.
    @param target  The data value to remove from the binary tree.
    @return  True if the removal is successful, or false not. */
   virtual bool remove(const ItemType& target) = 0;
   
   /** Removes all nodes from this binary tree. */
   virtual void clear() = 0;
   
   /** Gets a specific entry in this binary tree.
    @post  The desired entry has been returned, and the binary tree
       is unchanged. If no such entry was found, an exception is thrown.
    @param target  The entry to locate.
    @return  The entry in the binary tree that matches the given target.
    @throw  NotFoundException if the given entry is not in the tree. */
   virtual ItemType getEntry(const ItemType& target) const = 0;
   
   /** Tests whether a given entry occurs in this binary tree.
    @post  The binary search tree is unchanged.
    @param target  The entry to find.
    @return  True if the entry occurs in the tree, or false if not. */
   virtual bool contains(const ItemType& target) const = 0;
   
   /** Traverses this binary tree in preorder (inorder, postorder) and
       calls the function visit once for each node.
    @param visit A client-defined function that performs an operation on
       or with the data in each visited node. */
   virtual void preorderTraverse(std::function<void (ItemType&)> visit) const = 0;
   virtual void inorderTraverse(void visit(ItemType&)) const = 0;
   virtual void postorderTraverse(void visit(ItemType&)) const = 0;
   
   /** Destroys object and frees memory allocated by object. */
   virtual ~BinaryTreeInterface() {  }
   
}; // end BinaryTreeInterface
#endif

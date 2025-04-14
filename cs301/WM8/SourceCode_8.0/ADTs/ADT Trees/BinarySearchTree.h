//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.


/** Link-based implementation of the ADT binary search tree.
 @file BinarySearchTree.h */
 
#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "BinaryNodeTree.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class BinarySearchTree : public BinaryNodeTree<ItemType>
{
private:
   std::shared_ptr<BinaryNode<ItemType>> rootPtr;
   
protected:
   //------------------------------------------------------------
   // Protected Utility Methods Section:
   // Recursive helper methods for the public methods.
   //------------------------------------------------------------
   // Recursively finds where the given node should be placed and
   // inserts it in a leaf at that point.
  auto placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreeNodePtr,
                                       std::shared_ptr<BinaryNode<ItemType>> newNode);
   
   // Removes the given target value from the tree while maintaining a
   // binary search tree.
   std::shared_ptr<BinaryNode<ItemType>> removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreeNodePtr,
                                     const ItemType target,
                                     bool& success) override;
   
   // Removes a given node from a tree while maintaining a
   // binary search tree.
   auto removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr);
   
   // Removes the leftmost node in the left subtree of the node
   // pointed to by nodePtr.
   // Sets inorderSuccessor to the value in this node.
   // Returns a pointer to the revised subtree.
   auto removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>> subTreeNodePtr,
                                            ItemType& inorderSuccessor);
   
   // Returns a pointer to the node containing the given value,
   // or nullptr if not found.
   auto findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr,
                                  const ItemType& target) const;
   
public:
   //------------------------------------------------------------
   // Constructor and Destructor Section.
   //------------------------------------------------------------
   BinarySearchTree();
   BinarySearchTree(const ItemType& rootItem);
   BinarySearchTree(const BinarySearchTree<ItemType>& tree);
   virtual ~BinarySearchTree();
   
   //------------------------------------------------------------
   // Public Methods Section.
   //------------------------------------------------------------
    bool isEmpty() const noexcept override ;
   int getHeight() const noexcept override;
   int getNumberOfNodes() const noexcept override;
   ItemType getRootData() const override;
   void setRootData(const ItemType& someItem) const noexcept;
   bool add(const ItemType& someItem) override;
   bool remove(const ItemType& target) override;
   void clear() noexcept override;
   ItemType getEntry(const ItemType& target) const override;
   bool contains(const ItemType& target) const override;
   
   //------------------------------------------------------------
   // Public Traversals Section.
   //------------------------------------------------------------
   void preorderTraverse(std::function<void (ItemType&)> visit) const override;
   void inorderTraverse(void visit(ItemType&)) const override;
   void postorderTraverse(void visit(ItemType&)) const override;

   //------------------------------------------------------------
   // Overloaded Operator Section.
   //------------------------------------------------------------
   BinarySearchTree<ItemType>& operator=(const BinarySearchTree<ItemType>& rightHandSide);   
}; // end BinarySearchTree

#include "BinarySearchTree.cpp"

#endif

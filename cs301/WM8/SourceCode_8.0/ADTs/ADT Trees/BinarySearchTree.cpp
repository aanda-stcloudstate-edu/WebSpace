//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** @file BinarySearchTree.cpp */
#include <iostream>

#include "BinarySearchTree.h" 
#include "BinaryNode.h" 

//////////////////////////////////////////////////////////////
//
//      Protected Utility Methods Section
//
//////////////////////////////////////////////////////////////

template<class ItemType>
auto BinarySearchTree<ItemType>::placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreeNodePtr,
                                                                std::shared_ptr<BinaryNode<ItemType>> itemNodePtr)
{
   if (subTreeNodePtr == nullptr)
      return itemNodePtr;
   else
   {
      if (subTreeNodePtr->getItem() > itemNodePtr->getItem())
         subTreeNodePtr->setLeftChildPtr(placeNode(subTreeNodePtr->getLeftChildPtr(), itemNodePtr));
      else 
         subTreeNodePtr->setRightChildPtr(placeNode(subTreeNodePtr->getRightChildPtr(), itemNodePtr));
      
      return subTreeNodePtr;
   }  // end if
}  // end placeNode

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreeNodePtr,
                                                              const ItemType target, 
                                                              bool& success)
{
   if (subTreeNodePtr == nullptr)
   {
      // Not found here
      success = false;
      return subTreeNodePtr;
   }
   if (subTreeNodePtr->getItem() == target)
   {
      // Item is in the root of some subtree
      subTreeNodePtr = removeNode(subTreeNodePtr);
      success = true;
      return subTreeNodePtr;
   }
   else 
   {
      if (subTreeNodePtr->getItem() > target)
      {
         // Search the left subtree
         subTreeNodePtr->setLeftChildPtr(removeValue(subTreeNodePtr->getLeftChildPtr(), target, success));
      }
      else
      {
         // Search the right subtree
         subTreeNodePtr->setRightChildPtr(removeValue(subTreeNodePtr->getRightChildPtr(), target, success));
      }
      return subTreeNodePtr;
   }  // end if
}  // end removeValue

template<class ItemType>
auto BinarySearchTree<ItemType>::removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr)
{
   // Case 1) Node is a leaf - it is deleted
   // Case 2) Node has one child - parent adopts child
   // Case 3) Node has two children:
   //               Traditional implementation: Find successor node.
   //               Alternate implementation: Find successor value and replace node's value;
   //                  alternate does not need pass-by-reference
   if (nodePtr->isLeaf())
   {
      nodePtr.reset();
      return nodePtr; // delete and return nullptr
   }
   else if (nodePtr->getLeftChildPtr() == nullptr)  // Has rightChild only
   {
      return nodePtr->getRightChildPtr();
   }
   else if (nodePtr->getRightChildPtr() == nullptr) // Has left child only
   {
      return nodePtr->getLeftChildPtr();
   }
   else                                             // Has two children
   {
      // Traditional way to remove a value in a node with two children
      ItemType newNodeValue;
      nodePtr->setRightChildPtr(removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue));
      nodePtr->setItem(newNodeValue);
      return nodePtr;
      
      // Alernative way to remove a value in a node with two children; does not require pass-by-reference.
      // We need to check whether this right child has a left child.
      // This is similar to the base case in "findSuccessorValue" but we need to remove the
      // special case where the right child *is* the inorder successor
/*
      std::shared_ptr<BinaryNode<ItemType>> myRightChildPtr = nodePtr->getRightChildPtr();
      std::shared_ptr<BinaryNode<ItemType>> myLeftGrandChildPtr = myRightChildPtr->getLeftChildPtr();
      
      // Special case - right child is successor
      if (myLeftGrandChildPtr == nullptr) 
      {
         nodePtr->setItem(myRightChildPtr->getItem());
         nodePtr->setRightChildPtr(removeNode(myRightChildPtr));
         return nodePtr;
      } 
      else 
      {
         // Now we can recurse
         nodePtr->setItem(findSuccessorValue(nodePtr->getRightChildPtr()));
         return nodePtr;
      }  // end if
*/
   }  // end if
}  // end removeNode

template<class ItemType> 
auto BinarySearchTree<ItemType>::removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr,
                                                                     ItemType& inorderSuccessor)
{
   if (nodePtr->getLeftChildPtr() == nullptr)
   {
      inorderSuccessor = nodePtr->getItem();
      return removeNode(nodePtr);
   }
   else 
   {
      nodePtr->setLeftChildPtr(removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccessor));
      return nodePtr;
   }  // end if      
}  // end removeLeftmostNode

/*
template<class ItemType>
ItemType BinarySearchTree<ItemType>::findSuccessorValue(std::shared_ptr<BinaryNode<ItemType>> subTreeNodePtr)
{
   std::shared_ptr<BinaryNode<ItemType>> myLeftChildPtr = subTreeNodePtr->getLeftChildPtr();
   if (myLeftChildPtr->getLeftChildPtr() == nullptr) {
      ItemType nodeItemValue = myLeftChildPtr->getItem();
      subTreeNodePtr->setLeftChildPtr(removeNode(myLeftChildPtr));
      return nodeItemValue;
   }
   else 
   {
      return findSuccessorValue(subTreeNodePtr->getLeftChildPtr());
   }  // end if  
}  // end findSuccessorValue 
*/

// Override findNode because now we can use a binary search:
template<class ItemType>
auto BinarySearchTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> subTreeNodePtr,
                                                           const ItemType& target) const 
{
   // Uses a binary search 
   if (subTreeNodePtr == nullptr)
      return subTreeNodePtr;                        // Not found
   else if (subTreeNodePtr->getItem() == target)
      return subTreeNodePtr;                     // Found
   else if (subTreeNodePtr->getItem() > target)
      // Search left subtree
      return findNode(subTreeNodePtr->getLeftChildPtr(), target);
   else
      // Search right subtree
      return findNode(subTreeNodePtr->getRightChildPtr(), target);
}  // end findNode


//////////////////////////////////////////////////////////////
//      PUBLIC METHODS BEGIN HERE
//////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////
//      Constructor and Destructor Section
//////////////////////////////////////////////////////////////

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
{   }  // end default constructor

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem)
: rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr))
{  }  // end constructor

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& treePtr)
{
   rootPtr = this->copyTree(treePtr.rootPtr); // Call inherited method
}  // end copy constructor

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
 //  this->destroyTree(rootPtr); // Call inherited method
   rootPtr.reset();
}  // end destructor


//////////////////////////////////////////////////////////////
//      Public BinaryTreeInterface Methods Section
//////////////////////////////////////////////////////////////

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const noexcept
{
   return rootPtr == nullptr;
}  // end isEmpty

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const noexcept
{
   return this->getHeightHelper(rootPtr); // Call inherited method
}  // end getHeight

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const noexcept
{
   return this->getNumberOfNodesHelper(rootPtr); // Call inherited method
}  // end getNumberOfNodes

template<class ItemType>
void BinarySearchTree<ItemType>::clear() noexcept
{
//   this->destroyTree(rootPtr); // Call inherited method
   rootPtr.reset();
}  // end clear

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const 
{
   if (isEmpty())
      throw PrecondViolatedExcept("getRootData() called with empty tree."); 
   
   return rootPtr->getItem();
}  // end getRootData

// Must override setRootData to disable its affect:
template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newItem) const  noexcept
{
   throw PrecondViolatedExcept("Cannot change root value in a BST!");
}  // end setRootData

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& someItem)
{
   auto itemNodePtr = std::make_shared<BinaryNode<ItemType>>(someItem); // Create a new node
   rootPtr = placeNode(rootPtr, itemNodePtr);                           // Add the node to the tree
   
   return true;
}  // end add

template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& target)
{
   bool isSuccessful = false;
   // call may change isSuccessful
   rootPtr = removeValue(rootPtr, target, isSuccessful);
   return isSuccessful; 
}  // end remove

// Override getEntry to use our improved findNode:
template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const
{
   std::shared_ptr<BinaryNode<ItemType>> nodeWithEntry = findNode(rootPtr, anEntry);
   if (nodeWithEntry == nullptr)
      throw NotFoundException("Entry not found in tree.");
   else
      return nodeWithEntry->getItem();
}  // end getEntry

// Override contains to use our improved findNode:
template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const
{
   return (findNode(rootPtr, anEntry) != nullptr);  // nullptr is same as false
}  // end contains

//////////////////////////////////////////////////////////////
//      Public Traversals Section
//////////////////////////////////////////////////////////////

template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(std::function<void (ItemType&)> visit) const
{
   this->preorder(visit, rootPtr); // Call inherited method
}  // end preorderTraverse

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
   this->inorder(visit, rootPtr); // Call inherited method
}  // end inorderTraverse

template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
   this->postorder(visit, rootPtr); // Call inherited method
}  // end postorderTraverse


//////////////////////////////////////////////////////////////
//      Overloaded Operator 
//////////////////////////////////////////////////////////////

template<class ItemType>
BinarySearchTree<ItemType>& BinarySearchTree<ItemType>::
                            operator=(const BinarySearchTree<ItemType>& rightHandSide)
{
   if (!isEmpty())
      clear();
   this = copyTree(&rightHandSide); // Call inherited method
   
   return *this;
}  // end operator=





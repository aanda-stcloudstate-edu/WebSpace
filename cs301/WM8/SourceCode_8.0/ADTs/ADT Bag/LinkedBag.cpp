//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
    @file LinkedBag.cpp */

#include "LinkedBag.h"
#include "Node.h"
#include <cstddef>

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0)
{   }  // end default constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& someBag)
{
	itemCount = someBag.itemCount;
   Node<ItemType>* origChainPtr = someBag.headPtr;  // Points to nodes in original chain
   
   if (origChainPtr == nullptr)
      headPtr = nullptr;  // Original bag is empty
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      Node<ItemType>* endChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
              
         // Create a new node containing the next item
         Node<ItemType>* itemNodePtr = new Node<ItemType>(nextItem);
         
         // Link new node to end of new chain
         endChainPtr->setNext(itemNodePtr);
         
         // Advance pointer to new last node
         endChainPtr = endChainPtr->getNext();

         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      endChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

//template<class ItemType>
//bool LinkedBag<ItemType>::add(const ItemType& someItem)
//{
//   // Add to beginning of chain: new node references rest of chain;
//   // (headPtr is null if chain is empty)        
//   Node<ItemType>* nextNodePtr = new Node<ItemType>();
//   nextNodePtr->setItem(someItem);
//   nextNodePtr->setNext(headPtr);  // New node points to chain
////   Node<ItemType>* nextNodePtr = new Node<ItemType>(anEntry, headPtr); // alternate code
//
//   headPtr = nextNodePtr;          // New node is now first node
//   itemCount++;
//   
//   return true;
//}  // end add

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& someItem)
{
   auto itemNodePtr = new Node<ItemType>(someItem);
   itemNodePtr->setNext(headPtr); // New node points to chain
   headPtr = itemNodePtr;         // New node is now first node
   itemCount++;
   return true;                  // This member function is always successful
}  // end add


template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
   Node<ItemType>* currentPtr = headPtr;
   int counter = 0;
   while ((currentPtr != nullptr) && (counter < itemCount))
   {
		bagContents.push_back(currentPtr->getItem());
      currentPtr = currentPtr->getNext();
      counter++;
   }  // end while
   
   return bagContents;
}  // end toVector

//template<class ItemType>
//bool LinkedBag<ItemType>::remove(const ItemType& someItem)
//{
//   Node<ItemType>* entryNodePtr = getReferenceTo(someItem);
//   bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
//   if (canRemoveItem)
//   {
//      // Copy data from first node to located node
//      entryNodePtr->setItem(headPtr->getItem());
//
//      // Delete first node
//      Node<ItemType>* nodeToDeletePtr = headPtr;
//      headPtr = headPtr->getNext();
//
//      // Return node to the system
//      nodeToDeletePtr->setNext(nullptr);
//      delete nodeToDeletePtr;
//      nodeToDeletePtr = nullptr;
//
//      itemCount--;
//   } // end if
//
//	return canRemoveItem;
//}  // end remove

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& target )
{
   auto targetNodePtr = getReferenceTo(target);
   bool canRemoveItem = !isEmpty() && (targetNodePtr != nullptr);
   if (canRemoveItem)
   {
      // Copy data from first node to located node
      targetNodePtr->setItem(headPtr->getItem());
      // Disconnect first node
      headPtr = headPtr->getNext();
      itemCount--;
   }  // end if
   return canRemoveItem;
}  // end remove

template<class ItemType>
 void  LinkedBag<ItemType>::clear() noexcept
{
   headPtr = nullptr;
   itemCount = 0;
}  // end clear


//template<class ItemType>
//void LinkedBag<ItemType>::clear()
//{
//   Node<ItemType>* nodeToDeletePtr = headPtr;
//   while (headPtr != nullptr)
//   {
//      headPtr = headPtr->getNext();
//
//      // Return node to the system
//      nodeToDeletePtr->setNext(nullptr);
//      delete nodeToDeletePtr;
//
//      nodeToDeletePtr = headPtr;
//   }  // end while
//   // headPtr is nullptr; nodeToDeletePtr is nullptr
//
//   itemCount = 0;
//}  // end clear

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& target) const
{
	int frequency = 0;
   int counter = 0;
   Node<ItemType>* currentPtr = headPtr;
   while ((currentPtr != nullptr) && (counter < itemCount))
   {
      if (target == currentPtr->getItem())
      {
         frequency++;
      } // end if
      
      counter++;
      currentPtr = currentPtr->getNext();
   } // end while
   
	return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& target) const
{
	return (getReferenceTo(target) != nullptr);
}  // end contains

/* ALTERNATE 1
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& target) const
{
   return getFrequencyOf(target) > 0;
} 
*/
/* ALTERNATE 2 
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& target) const
{
   bool found = false;
   Node<ItemType>* currentPtr = headPtr;
   int i = 0;
   while (!found && (currentPtr != nullptr) && (i < entryCount))
   {
      if (target == currentPtr-<getItem())
      {
         found = true;
      }
      else
      {
         i++;
         currentPtr = currentPtr->getNext();
      }  // end if
   }  // end while

   return found;
}  // end contains
*/

// private
// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getReferenceTo(const ItemType& target) const
{
   bool found = false;
   Node<ItemType>* currentPtr = headPtr;
   
   while (!found && (currentPtr != nullptr))
   {
      found = (target == currentPtr->getItem());
      if (!found)
      {
          currentPtr = currentPtr->getNext();
      }
   } // end while
   
   return currentPtr;
} // end getReferenceTo


//template<class ItemType>
//std::vector<ItemType> LinkedBag<ItemType>::toVector() const
//{
//   std::vector<ItemType> bagContents;
//   fillVector(bagContents, headPtr);
//   return bagContents;
//}  // end toVector

//template<class ItemType>
//void LinkedBag<ItemType>::fillVector(std::vector<ItemType>& bagContents, Node<ItemType>* currentPtr) const
//{
//   if (currentPtr != nullptr)
//   {
//      bagContents.push_back(currentPtr->getItem());
//      fillVector(bagContents, currentPtr->getNext());
//   }  // end if
//}  // end fillVector
//template<class ItemType>
//Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& target,
//                                                  Node<ItemType>* currentPtr) const
//{
//   Node<ItemType>* result = nullptr;
//   if (currentPtr != nullptr)
//   {
//      if (target == currentPtr->getItem())
//         result = currentPtr;
//      else
//         result = getPointerTo(target, currentPtr->getNext());
//   }  // end if
//   return result;
//}  // end getPointerTo

//template<class ItemType>
//Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& target, Node<ItemType>* currentPtr) const
//{
//   bool found = false;
//
//   if (!found && (currentPtr != nullptr))
//   {
//      if (target == currentPtr->getItem())
//         found = true;
//      else
//         currentPtr = getPointerTo(target, currentPtr–>getNext());
//   } // end if
//
//   return currentPtr;
//}

//// This member function's return type is the type of the object returned.
//auto changeBoxItem(std::unique_ptr<PlainBox<std::string>> theBox, std::string theItem)
//{
//   theBox->setItem(theItem);
//   return theBox; // theBox surrenders ownership
//}  // end changeBoxItem
//
//template<class ItemType>
//class DoubleNode
//{
//private:
//   ItemType item;                                 // A data item
//   std::shared_ptr<DoubleNode<ItemType>> next;   // Pointer to next node
//   std::weak_ptr<DoubleNode<ItemType>> previous; // Pointer to previous node
//public:
//      // Constructors, destructors, and member functions
//}; // end DoubleNode

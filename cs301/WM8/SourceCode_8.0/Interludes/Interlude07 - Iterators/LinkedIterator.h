//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

 /** ADT list: Link-based implementation.
    @file LinkedIterator.h */

#ifndef _LINKED_ITERATOR
#define _LINKED_ITERATOR

//#include <memory>
//#include <iterator>
//#include <ranges>
#include "Node.h"


//using namespace std;

//template<class ItemType>
//class LinkedListwIterator;

//template <class ItemType>
//static_assert(std::ranges::forward_range<LinkedIterator<ItemType>>);

template <class ItemType>
//class LinkedIterator : public std::iterator<std::input_iterator_tag, int>
class LinkedIterator 
{
private:
   // ADT associated with iterator
//   const std::shared_ptr<LinkedListwIterator<ItemType>> containerPtr;
   
   // Current location in collection
   std::shared_ptr<Node<ItemType>> currentItemPtr;
   
public:

   typedef std::forward_iterator_tag iterator_category;
   typedef std::ptrdiff_t difference_type;
   typedef ItemType value_type;
   typedef ItemType* pointer;
   typedef ItemType& reference;
//
//   using iterator_category = std::input_iterator_tag;
//   using difference_type = std::ptrdiff_t;
//   using value_type = std::remove_cv_t<ItemType>;
//   using pointer = ItemType*;
//   using reference = ItemType&;

//   LinkedIterator();

   LinkedIterator(std::shared_ptr<Node<ItemType>> nodePtr = nullptr);

//   LinkedIterator(std::shared_ptr<LinkedListwIterator<ItemType>> someList,
//                  std::shared_ptr<Node<ItemType>> nodePtr = nullptr);
//
   /** Dereferencing operator overload.
    @return The item at the position referenced by iterator. */
   const ItemType operator*();
   
   /** Prefix increment operator overload.
    @return  The iterator referencing the next position in the list. */
   LinkedIterator<ItemType>& operator++();
   
   /** Equality operator overload.
    @param rightHandSide  The iterator for comparison.
    @return  True if this iterator references the same list and
       the same position as rightHandSide, false otherwise. */    
    bool operator==(const LinkedIterator<ItemType>& rightHandSide) const;
   
    /** Inequality operator overload.
     @param rightHandSide  The iterator for comparison.
     @return  True if this iterator does not reference the same
        list and the same position as rightHandSide, false otherwise. */
   bool operator!=(const LinkedIterator<ItemType>& rightHandSide) const;

}; // end LinkedIterator

#include "LinkedIterator.cpp"
#endif

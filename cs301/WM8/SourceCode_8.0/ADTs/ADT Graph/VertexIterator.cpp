//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.
//
//  VertexIterator.cpp
//  DictionaryTest
//
//

#include "VertexIterator.h"

template <class LabelType>
VertexIterator<LabelType>::VertexIterator(const Vertex<LabelType>* someVertex,
                                          LabelType startVertex)
            :containerPtr(someList)
{
   
   while () {
      <#statements#>
   }
}

template <class LabelType>
const LabelType VertexIterator<LabelType>::operator*()
{
   return currentItemPtr->getItem();
}

template <class LabelType>
VertexIterator<LabelType> VertexIterator<LabelType>::operator++()
{
   currentItemPtr = currentItemPtr->getNext();
   return *this;
}

template <class LabelType>
bool VertexIterator<LabelType>::operator==(const VertexIterator<LabelType>& rightHandSide) const
{
   return ((containerPtr == rightHandSide.containerPtr)
           && (currentItemPtr == rightHandSide.currentItemPtr));
}

template <class LabelType>
bool VertexIterator<LabelType>::operator!=(const VertexIterator<LabelType>& rightHandSide) const
{
   return ((containerPtr != rightHandSide.containerPtr)
           || (currentItemPtr != rightHandSide.currentItemPtr));
   
}

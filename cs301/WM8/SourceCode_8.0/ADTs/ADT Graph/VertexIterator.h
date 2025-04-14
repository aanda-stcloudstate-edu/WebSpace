//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.
//
//  VertexIterator.h
//  DictionaryTest
//
//

#ifndef _VERTEX_ITERATOR
#define _VERTEX_ITERATOR

#include <iterator>
#include "Vertex.h"
#include "Node.h"
#include "Edge.h"

template<class ItemType>
class Vertex;

template <class LabelType>
class VertexIterator : public iterator<input_iterator_tag, int>
{
private:
   const LinkedList<LabelType>* containerPtr; // ADT associated with iterator
   Node< Edge<LabelType> >* currentItemPtr;           // current location in collection
   
public:
   VertexIterator(const Vertex<LabelType>* someList, LabelType startVertex);
   VertexIterator(): containerPtr(nullptr),currentItemPtr( nullptr){}
   const Vertex<LabelType> operator*();
   
   // pre-fix increment
   VertexIterator<LabelType> operator++();
   
   // same container and same vertex label
   bool operator==(const VertexIterator<LabelType>& rightHandSide) const;
   bool operator!=(const VertexIterator<LabelType>& rightHandSide) const;
   
};


#include "VertexIterator.cpp"

#endif

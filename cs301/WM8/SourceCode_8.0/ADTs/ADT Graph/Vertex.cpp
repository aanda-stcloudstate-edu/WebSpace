//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** @file Vertex.cpp */

#include "Vertex.h"

template<class LabelType>
Vertex<LabelType>::
Vertex(LabelType label): vertexLabel(label), visited(false)
{
}  // end constructor

template<class LabelType>
LabelType Vertex<LabelType>::getLabel() const
{
   return vertexLabel;
}  // end getLabel

template<class LabelType>
void Vertex<LabelType>::visit()
{
   visited = true;
}  // end visit

template<class LabelType>
void Vertex<LabelType>::unvisit()
{
   visited = false;
}  // end unvisit

template<class LabelType>
bool Vertex<LabelType>::isVisited() const
{
   return visited;
}  // end isVisited

template<class LabelType>
bool Vertex<LabelType>::connect(const LabelType& endVertex, const int edgeWeight)
{
   Edge<LabelType> thisEdge(endVertex, edgeWeight);
   return adjacencyList.add(endVertex, thisEdge);
}  // end connect

template<class LabelType>
bool Vertex<LabelType>::disconnect(const LabelType& endVertex)
{
   return adjacencyList.remove(endVertex);
}  // end disconnect

template<class LabelType>
int Vertex<LabelType>::getEdgeWeight(const LabelType& endVertex) const
{
   int edgeWeight = -1;
   Edge<LabelType> theEdge = adjacencyList.getItem(endVertex);
   edgeWeight = theEdge.getWeight();
   
   return edgeWeight;
}  // end getEdgeWeight

template<class LabelType>
int Vertex<LabelType>::getNumberOfNeighbors() const
{
   return adjacencyList.getNumberOfItems();
}  // end getNumberOfNeighbors

template<class LabelType>
void Vertex<LabelType>::resetNeighbor()
{
   currentNeighbor = adjacencyList.begin();
}  // end resetNeighbor

template<class LabelType>
LabelType Vertex<LabelType>::getNextNeighbor()
{
   if (currentNeighbor != adjacencyList.end())
   {
      LabelType thisNeighbor = (*currentNeighbor).getEndVertex();
      ++currentNeighbor;
      return thisNeighbor;
   }
   else
      return this->getLabel(); // Signal end of adjacency list
}  // end getNextNeighbor

template<class LabelType>
bool Vertex<LabelType>::operator==(const Vertex<LabelType>& rightHandItem) const
{
   return (vertexLabel == rightHandItem.vertexLabel);
}  // end operator==

template<class LabelType>
int Vertex<LabelType>::getNeighborPosition(const LabelType& neighborVertex) const
{
   int position = 0;
   int length = adjacencyList.getLength();
   bool foundNeighbor = false;
   
   while ( (position < length) &&  !foundNeighbor)
   {
      position++;
      Edge<LabelType> currentEdge = adjacencyList.getEntry(position);
      foundNeighbor = (neighborVertex == currentEdge.getLabel());
   }  // end while
   
   if ( (position > length) || (!foundNeighbor) )
      position = -position;
   
   return position;
}  // end getNeighborPosition



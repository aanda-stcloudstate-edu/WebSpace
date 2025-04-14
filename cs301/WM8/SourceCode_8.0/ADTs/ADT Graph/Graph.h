//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** @file Graph.h */

#ifndef _GRAPH
#define _GRAPH

#include "GraphInterface.h"
#include "Vertex.h"

// NOTE <<<<<<<
// Replace SomeADT in the following statements with the name
// of the ADT that stores the vertices.
// Replace SomeADTIterator with the name of the iterator class
// for these vertices.
// These choices can be different from those used in the class Vertex.

#include "SomeADT.h"         // ADT for Vertex List
#include "SomeADTIterator.h" // Iterator for Vertex List

template<class LabelType>
class Graph : public GraphInterface<LabelType>
{
private:
   int numberOfVertices;
   int numberOfEdges;

   SomeADT<LabelType, std::shared_ptr<Vertex<LabelType>> > vertices;
   SomeADTIterator<LabelType, std::shared_ptr<Vertex<LabelType>> > currentVertex;

   // These are optional helper methods that may be useful
   void depthFirstTraversalHelper(std::shared_ptr<Vertex<LabelType>> startVertex,
                                  void visit(LabelType&));
   
   void breadthFirstTraversalHelper(std::shared_ptr<Vertex<LabelType>> startVertex,
                                    void visit(LabelType&));
   
   auto findOrCreateVertex(const LabelType& vertexLabel);
 
public:
   Graph();   
   int getNumVertices() const;   
   int getNumEdges() const;   
   bool add(LabelType start, LabelType end, int edgeWeight = 0);
   
   // For remove to return true all three of the following must be true:
   // 1) start and end vertices exist
   // 2) Edge start->end is successfully disconnected
   // 3) Edge end->start successfully disconnected
   // Then, if those are successful and either start or end no longer
   // has neighbors, the vertex is removed from the graph
   bool remove(LabelType start, LabelType end);
   
   int getEdgeWeight(LabelType start, LabelType end) const;      
   void depthFirstTraversal(LabelType startLabel, void visit(LabelType&));   
   void breadthFirstTraversal(LabelType startLabel, void visit(LabelType&));
}; // end Graph

#include "Graph.cpp"
#endif

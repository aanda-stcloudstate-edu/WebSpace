//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** @file LinkedGraph.h */

#ifndef _LINKED_GRAPH
#define _LINKED_GRAPH

#include "GraphInterface.h"
#include "Vertex.h"
#include "ArrayDictionary.h" // For adjacency list; this choice can vary
                             // according to how you want to implement the 
                             // adjacency list, and it can differ from
                             // the collection used in the class Vertex.

template<class LabelType>
class LinkedGraph : public GraphInterface<LabelType>
{
private:
   int numberOfVertices;
   int numberOfEdges;
   
   // These can vary depending on how you want to
   // implement the list of vertices in the graph
   ArrayDictionary<LabelType, std::shared_ptr<Vertex<LabelType>> > vertices;
   ArrayDictionaryIterator<LabelType, std::shared_ptr<Vertex<LabelType>> > currentVertex;

   // Marks all verices as unvisited.
   void unvisitVertices();
   
  auto findOrCreateVertex(const LabelType& vertexLabel);
    
   void depthFirstTraversalHelper(std::shared_ptr<Vertex<LabelType>> startVertex,
                                  void visit(LabelType&));
   void breadthFirstTraversalHelper(std::shared_ptr<Vertex<LabelType>> startVertex,
                                    void visit(LabelType&));
public:
   LinkedGraph();   
   int getNumVertices() const;   
   int getNumEdges() const;   
   bool add(LabelType start, LabelType end, int edgeWeight = 0);
   
   // For remove to return true all of the following must be true:
   // 1) start and end vertices exist
   // 2) Edge start->end is successfully disconnected
   // 3) Edge end->start is successfully disconnected
   // Then, if those are successful and either start or end no longer
   // has neighbors, the vertex is removed from the graph
   bool remove(LabelType start, LabelType end);
   
   int getEdgeWeight(LabelType start, LabelType end) const;
   void depthFirstTraversal(LabelType start, void visit(LabelType&));   
   void breadthFirstTraversal(LabelType start, void visit(LabelType&));
}; // end GraphInterface

#include "LinkedGraph.cpp"
#endif

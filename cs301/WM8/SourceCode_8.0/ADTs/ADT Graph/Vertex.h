//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** @file Vertex.h */

// This class does a lot of the work for the graph!

#ifndef _VERTEX
#define _VERTEX

#include "Edge.h"

// The following ADT choices can vary according to how you want
// to implement the adjacency list, and they can be different from
// those used in class Graph.
#include "ArrayDictionary.h"         // ADT for Adjacency List
#include "ArrayDictionaryIterator.h" // Iterator for Adjacency List ADT

template<class LabelType>
class Vertex
{
private:
   LabelType vertexLabel;
   bool      visited;  // True if the vertex is visited
   
   ArrayDictionary<LabelType, Edge<LabelType> >         adjacencyList;
   ArrayDictionaryIterator<LabelType, Edge<LabelType> > currentNeighbor;
      
   // Helper method for finding a specific neighbor
   int getNeighborPosition(const LabelType& neighborVertex) const;

public:
   /** Creates an unvisited vertex, gives it a label, and clears its 
       adjacency list.         
       NOTE: A vertex must have a unique label that cannot be changed. */
   Vertex(LabelType label);
   
   /** @return  The label of this vertex. */
   LabelType getLabel() const;
   
   /** Marks this vertex as visited. */
   void visit();
   
   /** Marks this vertex as not visited. */
   void unvisit();
   
   /** Returns the visited status of this vertex.
    @return  True if the vertex has been visited, otherwise
       returns false/ */
   bool isVisited() const;
   
   /** Adds an edge between this vertex and the given vertex. 
    @return  True if the connection is successful. */
   bool connect(const LabelType& endVertex, const int edgeWeight = 0);
   
   /** Removes the edge between this vertex and the given one. 
   @return  True if the removal is successful. */
   bool disconnect(const LabelType& endVertex);
   
   /** Gets the weight of the edge between this vertex and the given vertex.
    @return  The edge weight. This value is zero for an unweighted graph and
       is negative if the .edge does not exist */
   int getEdgeWeight(const LabelType& endVertex) const;   

   /** Calculates how many neighbors this vertex has.
    @return  The number of the vertex's neighbors. */
   int getNumberOfNeighbors() const;
  
   /** Sets current neighbor to first in adjacency list. */
   void resetNeighbor();
   
   /** Gets this vertex's next neighbor in the adjacency list.
    @return  The label of the vertex's next neighbor. */
   LabelType getNextNeighbor();

   /** Sees whether this vertex is equal to another one.
       Two vertices are equal if they have the same label. */
   bool operator==(const Vertex<LabelType>& rightHandItem) const;
}; // end Vertex

#include "Vertex.cpp"
#endif

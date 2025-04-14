//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** @file LinkedGraph.cpp */

#include "LinkedGraph.h"
#include <queue>

template<class LabelType>
LinkedGraph<LabelType>::
LinkedGraph(): numberOfVertices(0), numberOfEdges(0)
{
}  // end default constructor

template<class LabelType>
int LinkedGraph<LabelType>::getNumVertices() const
{
   return numberOfVertices;
}  // end getNumVertices
   
template<class LabelType>
int LinkedGraph<LabelType>::getNumEdges() const
{
   return numberOfEdges;
}  // end getNumEdges

template<class LabelType>
bool LinkedGraph<LabelType>::add(LabelType start, LabelType end, int edgeWeight)
{
   auto startVertex = findOrCreateVertex(start);
   auto endVertex   = findOrCreateVertex(end);
  
   startVertex->connect(end, edgeWeight);
   endVertex->connect(start, edgeWeight);
   
   numberOfEdges++; // Each bidirectional edge counts as a single edge
   
   return true;
}  // end add

template<class LabelType>
bool LinkedGraph<LabelType>::remove(LabelType start, LabelType end)
{
   bool successful = false;
   auto startVertex = vertices.getItem(start);
   auto endVertex   = vertices.getItem(end);
   
   successful = startVertex->disconnect(end);
   if (successful)
   {
      successful = endVertex->disconnect(start);
      if (successful)
      {
         numberOfEdges--;
         
         // If either vertex no longer has a neighbor, remove it
         if (startVertex->getNumberOfNeighbors() == 0)
            vertices.remove(start);
         if (endVertex->getNumberOfNeighbors() == 0)
            vertices.remove(end);
      }
      else
         successful = false; // Failed disconnect from endVertex
   }
   else
      successful = false;    // Failed disconnect from startVertex

   return successful;
}  // end remove

template<class LabelType>
int LinkedGraph<LabelType>::getEdgeWeight(LabelType start, LabelType end) const
{
   int weight = -1;
   if (vertices.contains(start))
   {
      auto startVertex = vertices.getItem(start);
      weight = startVertex->getEdgeWeight(end);
   }  // end if

   return weight;
}  // end getEdgeWeight

// Mark all vertices as unvisited
template<class LabelType>
void LinkedGraph<LabelType>::unvisitVertices()
{
   currentVertex = vertices.begin();
   while (currentVertex != vertices.end())
   {
      auto loopVertex = *currentVertex;
      loopVertex->unvisit();
      ++currentVertex;
   }  // end while
} // endunvisitVertices

template<class LabelType>
void LinkedGraph<LabelType>::depthFirstTraversal(LabelType startLabel,
                                                 void visit(LabelType&))
{
   // Mark all vertices as unvisited
   unvisitVertices();
   
   auto startVertex = vertices.getItem(startLabel);
   depthFirstTraversalHelper(startVertex, visit);
}  // end depthFirstTraversal

template<class LabelType>
void LinkedGraph<LabelType>::breadthFirstTraversal(LabelType startLabel,
                                                   void visit(LabelType&))
{
   // Mark all vertices as unvisited
   unvisitVertices();
   
   auto startVertex = vertices.getItem(startLabel);
   breadthFirstTraversalHelper(startVertex, visit);
}  // end breadthFirstTraversal

template<class LabelType>
void LinkedGraph<LabelType>::
depthFirstTraversalHelper(std::shared_ptr<Vertex<LabelType>> startVertex,
                          void visit(LabelType&))
{
   startVertex->visit();  // Mark as visited
   LabelType startLabel = startVertex->getLabel();
   visit(startLabel);
   
   startVertex->resetNeighbor(); // Reset reference for adjacency list
   
   for (int index = 1; index <= startVertex->getNumberOfNeighbors(); index++)
   {
      LabelType currentLabel = startVertex->getNextNeighbor();
      if (!((vertices.getItem(currentLabel))->isVisited()))
         depthFirstTraversalHelper(vertices.getItem(currentLabel), visit);
   }  // end for
}  // end depthFirstTraversalHelper

template<class LabelType>
void LinkedGraph<LabelType>::
breadthFirstTraversalHelper(std::shared_ptr<Vertex<LabelType>> startVertex,
                            void visit(LabelType&))
{
   std::queue< std::shared_ptr<Vertex<LabelType>> > vertexQueue;
   LabelType startLabel = startVertex->getLabel();
//   cout << "Enqueue and visit " << startLabel << endl;
   vertexQueue.push(startVertex);
   startVertex->visit();         // Mark as visited
   visit(startLabel);
   startVertex->resetNeighbor(); // Reset reference for adjacency list
   
   while (!vertexQueue.empty())
   {
      // Remove vertex from queue
      auto nextVertex = vertexQueue.front();
      vertexQueue.pop();
      LabelType nextLabel = nextVertex->getLabel();
//      cout << "Dequeue " << nextLabel << endl;
//      cout << "Consider " << nextLabel << "'s " << nextVertex->getNumberOfNeighbors() << " neighbors." << endl;
      
      // Add neighbors of visited vertex to queue
      for (int index = 1; index <= nextVertex->getNumberOfNeighbors(); index++)
      {
         LabelType neighborLabel = nextVertex->getNextNeighbor();
//         cout << "Neighbor " << neighborLabel;
         auto neighbor = vertices.getItem(neighborLabel);
         if (!neighbor->isVisited())
         {
//            cout << " is not visited; enqueue and visit it." << endl;
            vertexQueue.push(neighbor);
            neighbor->visit();         // Mark as visited
            visit(neighborLabel);
            neighbor->resetNeighbor(); // Reset reference for adjacency list
         }
//         else
//            cout << " was visited already; ignore it." << endl;
      }  // end for
   }  // end while
}  // end breadthFirstTraversalHelper

template<class LabelType>
auto LinkedGraph<LabelType>::
findOrCreateVertex(const LabelType& vertexLabel)
{
   std::shared_ptr<Vertex<LabelType>> theVertex = nullptr;
      
   if (vertices.contains(vertexLabel))
   {
      theVertex = vertices.getItem(vertexLabel);
   }
   else
   {
      theVertex = std::make_shared<Vertex<LabelType>>(vertexLabel);
      vertices.add(vertexLabel, theVertex);
      numberOfVertices++;
   }  // end if
   
   return theVertex;
}  // end findOrCreateVertex


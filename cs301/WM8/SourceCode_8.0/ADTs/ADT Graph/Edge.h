//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** A simple class of edges. 
   (Conceptually this is similar to the class "Entry")
 @file Edge.h */
 
#ifndef _EDGE
#define _EDGE

template<class LabelType>
class Edge
{
private:
   LabelType endVertex; // Cannot be changed as doing so changes the edge
   int       edgeWeight;
   
public:
   Edge();
   Edge(const LabelType& end);
   Edge(const LabelType& end, int weight);
   
   LabelType getEndVertex() const;
   int getWeight() const;
   void setWeight(const int newWeight);
}; // end Edge

#include "Edge.cpp"
#endif

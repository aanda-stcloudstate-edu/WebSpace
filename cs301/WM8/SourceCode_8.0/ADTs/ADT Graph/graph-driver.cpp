//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

#include <iostream>
#include <string>
#include <memory>
#include "LinkedGraph.h"


void display(std::string& anItem)
{
   std::cout << "Displaying item - " << anItem << std::endl;
}

void graphTest(std::shared_ptr<LinkedGraph<std::string>> testGraph)
{
   std::string A("A");
   std::string B("B");
   std::string C("C");
   std::string D("D");
   std::string E("E");
   std::string F("F");
   std::string G("G");
   std::string H("H");
   std::string I("I");
   std::string J("J");
   std::string K("K");
   std::string L("L");
   std::string M("M");
   std::string N("N");
   
   testGraph->add(A, B, 0);
   testGraph->add(A, C, 0);
   testGraph->add(A, D, 0);
   testGraph->add(B, E, 0);
   testGraph->add(B, F, 0);
   testGraph->add(C, G, 0);
   testGraph->add(D, H, 0);
   testGraph->add(D, I, 0);
   testGraph->add(F, J, 0);   
   testGraph->add(G, K, 0);
   testGraph->add(G, L, 0);   
   testGraph->add(H, M, 0);
   testGraph->add(I, M, 0);
   testGraph->add(I, N, 0);
   
   std::cout << "Vertices :" << testGraph->getNumVertices() << std::endl;
   std::cout << "Edges :" << testGraph->getNumEdges() << std::endl;
  
   std::cout << "\nDepth-first traversal (should be A B E F J C G K L D H M I N):" << std::endl;
   testGraph->depthFirstTraversal(A, display);
  
   std::cout << "\nBreadth-first traversal (should be A B C D E F G H I J K L M N):" << std::endl;
   testGraph->breadthFirstTraversal(A, display);
}  // end graphTest

int main()
{
   auto myGraph = std::make_shared<LinkedGraph<std::string>>();
 
   std::cout << "Testing Graph . . . ." << std::endl << std::endl ;
   graphTest(myGraph);
   
   return 0;
}  // end main

/*
 Testing Graph . . . .
 
 Vertices :14
 Edges :14
 
 Depth-first traversal (should be A B E F J C G K L D H M I N):
 Displaying item - A
 Displaying item - B
 Displaying item - E
 Displaying item - F
 Displaying item - J
 Displaying item - C
 Displaying item - G
 Displaying item - K
 Displaying item - L
 Displaying item - D
 Displaying item - H
 Displaying item - M
 Displaying item - I
 Displaying item - N
 
 Breadth-first traversal (should be A B C D E F G H I J K L M N):
 Displaying item - A
 Displaying item - B
 Displaying item - C
 Displaying item - D
 Displaying item - E
 Displaying item - F
 Displaying item - G
 Displaying item - H
 Displaying item - I
 Displaying item - J
 Displaying item - K
 Displaying item - L
 Displaying item - M
 Displaying item - N
*/

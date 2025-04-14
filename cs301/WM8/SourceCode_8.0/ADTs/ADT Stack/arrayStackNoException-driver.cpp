//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

#include <iostream>
#include <string>
#include "ArrayStack.h"

void stackTester(StackInterface<std::string>* stackPtr)
{
	std::string items[] = {"zero", "one", "two", "three", "four", "five"};
	std::cout << "Empty: " << stackPtr->isEmpty() << std::endl;
	for (int i = 0; i < 6; i++)
   {
		std::cout<<"Pushing " << items[i] << std::endl;
      bool success = stackPtr->push(items[i]);
      if (!success)
         std::cout << "Failed to push " << items[i] << " onto the stack." << std::endl;
	}
   
	std::cout << "Empty?: " << stackPtr->isEmpty() << std::endl;
	
	for (int i = 0; i < 5; i++)  // NEEDS TO BE 5 TO AVOID ASSERT ERROR
   {
		std::cout << "Loop " << i << std::endl;
      std::cout << "peek1: " << stackPtr->peek() << std::endl;
		std::cout << "pop: " << stackPtr->pop() << std::endl;
		std::cout << "Empty: " << stackPtr->isEmpty() << std::endl;
	}
	std::cout << "Empty: " << stackPtr->isEmpty() << std::endl;
   std::cout << "pop an empty stack: " << std::endl;
	std::cout << "pop: " << stackPtr->pop() << std::endl; // nothing to pop!
   
   std::cout << "peek into an empty stack (should fail): " << std::endl;
	std::cout << "peek: " << stackPtr->peek() << std::endl; // nothing to peek!
}  // end stackTester

int main()
{




	auto stackPtr = new ArrayStack<std::string>();
	std::cout << "Testing the Array-Based Stack:" <<std::endl;
	stackTester(stackPtr);
	
   return 0;
}  // end main

/*
 Testing the Array-Based Stack:
 Empty: 1
 Pushing zero
 Pushing one
 Pushing two
 Pushing three
 Pushing four
 Pushing five
 Failed to push five onto the stack.
 Empty?: 0
 Loop 0
 peek1: four
 pop: 1
 Empty: 0
 Loop 1
 peek1: three
 pop: 1
 Empty: 0
 Loop 2
 peek1: two
 pop: 1
 Empty: 0
 Loop 3
 peek1: one
 pop: 1
 Empty: 0
 Loop 4
 peek1: zero
 pop: 1
 Empty: 1
 Empty: 1
 pop an empty stack:
 pop: 0
 peek into an empty stack:
 Assertion failed: (!isEmpty()), function peek, file ... /ArrayStack.cpp, line 51.
 peek: (lldb)
 */
/** Tests whether a sequence of paths exists between two cells.
 Nonrecursive stack version.
 @pre  entranceCell and exitCell both exist in the maze.
 @post  Cells visited during the search are marked as visited
 in the maze .
 @param entranceCell  The origin cell.
 @param exitCell  The destination cell.
 @return  True if a sequence of paths exists from entranceCell
 to exitCell; otherwise returns false. */
//bool searchWithStack(Cell entranceCell, Cell exitCell)
//{
//   Stack pathStack;
//   unvisitAll(); // Clear marks on all cells
//                 // Push entrance cell onto pathStack and mark it as visited
//   pathStack.push(entranceCell);
//   markVisited(entranceCell);
//   Cell topCell = pathStack.peek();
//   while (!pathStack.isEmpty() && (topCell != exitCell))
//   {
//         // The stack contains a directed path from the entrance cell
//         // at the bottom of the stack to the cell at the top of the stack
//         // Find an unvisited path adjacent to the cell on the top of the stack
//      Cell nextCell = getNextCity(topCell );
//      if (nextCell == NO_PATH)
//         pathStack.pop(); // No cell found; backtrack
//      else              // Visit cell
//      {
//         pathStack.push(nextCell );
//         markVisited(nextCell );
//      }  // end if
//      if (!pathStack.isEmpty())
//         topCell = pathStack.peek();
//   }  // end while
//   return ! pathStack.isEmpty();
//}  // end isPath



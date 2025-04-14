//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

#include "LinkedListwIterator.h" // ADT list operations
#include <iostream>
//#include <string>

auto setList(std::string data[], int numberOfEntries)
{
   auto listPtr = std::make_shared<LinkedListwIterator<std::string>>();
   
	for (int i = 0; i < numberOfEntries; i++)
   {
		if (listPtr->insert(i + 1, data[i]))
         std::cout << "Insert " << listPtr->getEntry(i + 1)
              << " at position " << (i + 1) << std::endl;
      else
         std::cout << "Cannot insert " << data[i] << " at position " << (i + 1) << std::endl;
	}  // end for
	std::cout << std::endl;
   
   return listPtr;
}  // end setList

void displayList(std::shared_ptr<LinkedListwIterator<std::string>> myListPtr)
{
   int currentPosition = 1;
//   while (currentPosition <= myListPtr->getLength())
   while (currentPosition <= myListPtr->getLength())
   {
      std::cout << myListPtr->getEntry(currentPosition) << " "; // O(n) operation
      currentPosition++;
   } // end while
   
	std::cout << std::endl;
}  // end displayList

void displayOneItem(std::string itemToDisplay)
{
   std::cout << itemToDisplay << std::endl;
} // end displayOneItem

int main()
{
   std::string myData[] = {"Jack", "Queen", "King", "Mace", "Joker", "Ace"};
	std::cout << "Creating a list:" << std::endl;
   auto myListPtr = setList(myData, 6);
   
	std::cout << "The list contents using getEntry:" << std::endl;
   displayList(myListPtr);
	std::cout << std::endl;

	std::cout << "The list contents using the list's iterator:" << std::endl;
   auto currentIterator = myListPtr->begin();
//   while (currentIterator != myListPtr->end())
   while (currentIterator != end(*myListPtr))
   {
      std::cout << *currentIterator << " "; // O(1) operation
      ++currentIterator;
   }  // end while
	std::cout << std::endl << std::endl;

 	std::cout << "The list contents using the list's iterator and a for_each loop:" << std::endl;
   for_each(myListPtr->begin(), myListPtr->end(), displayOneItem);

   std::cout << "The list contents using RANGED and a for_each loop:" << std::endl;
   for_each_n(std::begin(*myListPtr), 3, displayOneItem);
   std::cout << std::endl << std::endl;

   std::cout << "Find the entry \"Ace\" in the list:" << std::endl;
   LinkedIterator<std::string> myCard = find(std::begin(*myListPtr), std::end(*myListPtr), "Ace");
   std::cout << *myCard << std::endl;

//   std::cout << "Count the number of occurrences of \"Ace\" in the list:" << std::endl;
//   long aceCount = count(myListPtr->begin(), myListPtr->end(), "Ace");
//   std::cout << aceCount << std::endl << std::endl;

   // Iterator to first position in list
   LinkedIterator<std::string> myIterator = myListPtr->begin();

      // Iterator to first position in list
   myIterator = myListPtr->begin();
   advance(myIterator, 1);
  std::cout<<distance(myIterator, myListPtr->end())<<std::endl;
  // Advance from first position to fifth (4 positions ahead)
   advance(myIterator, 4);
   std::cout << "The entry at position 6 is " << *myIterator << "." << std::endl << std::endl;

//   std::cout << "The number of entries from the iterator's current position to the end of the list is ";
//   long numberRemaining = distance(myIterator, myListPtr->end());
//   std::cout << numberRemaining << "." << std::endl << std::endl;

	std::cout << "Creating another list:" << std::endl;
   std::string yourData[] = {"Jack", "Queen", "King", "Mace", "Joker", "Ace"};
   auto yourListPtr = setList(yourData, 6);

	std::cout << "The first list contains:" << std::endl;
   displayList(myListPtr);
	std::cout << std::endl;

	std::cout << "The second list contains:" << std::endl;
   displayList(yourListPtr);
	std::cout << std::endl;

   bool same = equal(myListPtr->begin(), myListPtr->end(), begin(*yourListPtr));
   if (same)
      std::cout << "The lists are equal.  :-)" << std::endl;
   else
      std::cout << "The lists are NOT equal.  :-(" << std::endl;

	std::cout << "\nAfter removing the second entry from the second list:" << std::endl;
   myListPtr->remove(2);
   same = equal(myListPtr->begin(), myListPtr->end(), yourListPtr->begin());
   if (same)
      std::cout << "The lists are equal.  :-(" << std::endl;
   else
      std::cout << "The lists are NOT equal.  :-)" << std::endl;
   
   return 0;
}  // end main

/*
 Creating a list:
 Insert Jack at position 1
 Insert Queen at position 2
 Insert King at position 3
 Insert Ace at position 4
 Insert Joker at position 5
 Insert Ace at position 6
 
 The list contents using getEntry:
 Jack Queen King Ace Joker Ace
 
 The list contents using the list's iterator:
 Jack Queen King Ace Joker Ace
 
 The list contents using the list's iterator and a for_each loop:
 Jack
 Queen
 King
 Ace
 Joker
 Ace
 
 
 Find the entry "Ace" in the list:
 Ace
 Count the number of occurrences of "Ace" in the list:
 2
 
 The entry at position 5 is Joker.
 
 The number of entries from the iterator's current position to the end of the list is 2.
 
 Creating another list:
 Insert Jack at position 1
 Insert Queen at position 2
 Insert King at position 3
 Insert Ace at position 4
 Insert Joker at position 5
 Insert Ace at position 6
 
 The first list contains:
 Jack Queen King Ace Joker Ace
 
 The second list contains:
 Jack Queen King Ace Joker Ace
 
 The lists are equal.  :-)
 
 After removing the second entry from the second list:
 The lists are NOT equal.  :-)
 
*/

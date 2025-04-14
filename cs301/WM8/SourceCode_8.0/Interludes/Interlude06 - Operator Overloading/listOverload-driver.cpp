//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

#include "LinkedList.h" // ADT list operations
#include <iostream>
#include <string>

using namespace std;

void displayList(shared_ptr<ListInterface<string>> listPtr)
{
   for (int pos = 1; pos <= listPtr->getLength(); pos++)
   {
      cout << listPtr->getEntry(pos) << " ";
   } // end for
	cout << endl;
}  // end displayList

int main()
{
   cout << "Testing the == operator:" << endl;
   
   shared_ptr<LinkedList<string>> list1Ptr = std::make_shared<LinkedList<string>>();
	string data[] = {"one", "two", "three", "four", "five", "six"};
	for (int i = 0; i < 6; i++)
      list1Ptr->insert(i + 1, data[i]);
   cout << "List 1:" << endl;
   displayList(list1Ptr);
   cout << endl;
   
   shared_ptr<LinkedList<string>> list2Ptr = std::make_shared<LinkedList<string>>();
	for (int i = 0; i < 6; i++)
      list2Ptr->insert(i + 1, data[i]);
   cout << "List 2:" << endl;
   displayList(list2Ptr);
   cout << endl;
   
   cout << "Comparing Lists 1 and 2:\n";
   if (*list1Ptr == *list2Ptr)
      cout << "Lists 1 and 2 are equal\n";
   else
      cout << "Lists 1 and 2 are NOT equal -- ERROR!\n";
   
   cout << endl;
   list1Ptr->remove(2);
   cout << "List 1:" << endl;
   displayList(list1Ptr);
   cout << endl;
   cout << "List 2:" << endl;
   displayList(list2Ptr);
   cout << endl;
   cout << "Comparing Lists 1 and 2:\n";
   
   if (list1Ptr == list2Ptr)
      cout << "Lists 1 and 2 are equal-- ERROR!\n";
   else
      cout << "Lists 1 and 2 are NOT equal \n";
   
   cout << endl;
   list1Ptr->insert(2, "TWO");
   cout << "List 1:" << endl;
   displayList(list1Ptr);
   cout << endl;
   cout << "List 2:" << endl;
   displayList(list2Ptr);
   cout << endl;
   cout << "Comparing Lists 1 and 2:\n";
   
   if (list1Ptr == list2Ptr)
      cout << "Lists 1 and 2 are equal-- ERROR!\n";
   else
      cout << "Lists 1 and 2 are NOT equal \n";
   //===============================================================
   cout << endl;
   cout << "Testing the + operator by concatenating the previous two lists:" << endl;
   LinkedList<string> list3 = *list1Ptr + *list2Ptr;
   displayList(std::make_shared<LinkedList<string>>(list3));
   
   
   //===============================================================
   cout << endl;
   cout << "Testing the = operator:" << endl;
   
   LinkedList<string> assignedList = *list1Ptr;
   cout << "List 1:" << endl;
   displayList(list1Ptr);
   cout << "List assigned:" << endl;
   displayList(std::make_shared<LinkedList<string>>(assignedList));
   
   //===============================================================
   cout << endl;
   cout << "Testing the << operator by displaying List 1:" << endl;
   *list1Ptr = *list1Ptr;
   cout << *list1Ptr;
   
   return 0;
}  // end main

/*
 Testing the == operator:
 List 1:
 one two three four five six
 
 List 2:
 one two three four five six
 
 Comparing Lists 1 and 2:
 Lists 1 and 2 are equal
 
 List 1:
 one three four five six
 
 List 2:
 one two three four five six
 
 Comparing Lists 1 and 2:
 Lists 1 and 2 are NOT equal
 
 List 1:
 one TWO three four five six
 
 List 2:
 one two three four five six
 
 Comparing Lists 1 and 2:
 Lists 1 and 2 are NOT equal
 
 Testing the + operator by concatenating the previous two lists:
 one TWO three four five six one two three four five six
 
 Testing the = operator:
 List 1:
 one TWO three four five six
 List assigned:
 one TWO three four five six
 
 Testing the << operator by displaying List 1:
 1	one
 2	TWO
 3	three
 4	four
 5	five
 6	six
 */

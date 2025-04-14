//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.


#include <iostream>
#include <map>

int main ()
{
   std::map<char, int> myMap;
   myMap.insert(std::pair<char, int>('A', 100));
   myMap.insert(std::pair<char, int>('B', 200));
   myMap.insert(std::pair<char, int>('C', 300));

   for (auto mapIterator : myMap)
   {
      std::cout << "Key: " << mapIterator.first;
      std::cout << " Value: " << mapIterator.second << std::endl;
   }
   return 0;
} // end main
